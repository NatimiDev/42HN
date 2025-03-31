# Prometheus Monitoring for WordPress on a Virtual Machine

## Prerequisites

- A Virtual Machine with **Debian/Ubuntu**
    
- A running **WordPress** site
    
- Installed **Prometheus**
    
- Installed **Node Exporter** & **WordPress Exporter**
    

---

## 1️⃣ Install Prometheus

```bash
sudo apt update && sudo apt install -y prometheus
```

Check if Prometheus is running:

```bash
sudo systemctl status prometheus
```

Enable it to start on boot:

```bash
sudo systemctl enable --now prometheus
```

---

## 2️⃣ Configure Prometheus

Edit the Prometheus configuration file:

```bash
sudo nano /etc/prometheus/prometheus.yml
```

Add the following job configuration:

```yaml
global:
  scrape_interval: 15s

scrape_configs:
  - job_name: 'wordpress'
    static_configs:
      - targets: ['localhost:9100']  # Node Exporter
      - targets: ['localhost:9001']  # WordPress Exporter
```

Save and exit (`CTRL + X`, then `Y`, then `Enter`).

Restart Prometheus:

```bash
sudo systemctl restart prometheus
```

---

## 3️⃣ Install Node Exporter (System Metrics)

```bash
sudo apt install -y prometheus-node-exporter
```

Enable and start Node Exporter:

```bash
sudo systemctl enable --now prometheus-node-exporter
```

---

## 4️⃣ Install WordPress Exporter

Install required dependencies:

```bash
sudo wget https://github.com/aorfanos/wordpress-exporter/archive/refs/heads/main.zip
sudo apt update
sudo apt install unzip

```

Create a systemd service file:

```bash
sudo nano /etc/systemd/system/wordpress_exporter.service
```

Add the following content:

```ini
[Unit]
Description=WordPress Prometheus Exporter
After=network.target

[Service]
ExecStart=/usr/local/bin/prometheus-wordpress-exporter --wp-url http://your-wordpress-site.com --wp-username admin --wp-password yourpassword
Restart=always
User=nobody
Group=nogroup

[Install]
WantedBy=multi-user.target
```

Save and exit, then reload systemd and start the service:

```bash
sudo systemctl daemon-reload
sudo systemctl enable --now wordpress_exporter
```

---

## 5️⃣ Access Prometheus UI

Don't forget to update ufw and tunnel ports

Open **`http://your-vm-ip:9090`** in a web browser.

Check WordPress metrics:
- Go to **`http://your-vm-ip:9001/metrics`**
- You should see WordPress-related metrics

---

## 6️⃣ (Optional) Install Grafana for Visualization

```bash
sudo apt install -y grafana
sudo systemctl enable --now grafana-server
```

Access Grafana at: **`http://your-vm-ip:3000`**

- Default login: **admin/admin**
    
- Add Prometheus as a data source for monitoring WordPress
    

---

## 🎉 Add common php script to put info to prometheus

Create .php script in document-root folder
```bash
grep "server.document-root" /etc/lighttpd/lighttpd.conf
```

to check script is in the right place run
```bash
curl -v http://localhost/metrics.php
```

put the minimal script 
```php
<?php
header("Content-Type: text/plain");
echo "# HELP wordpress_user_count Number of registered users\n";
echo "# TYPE wordpress_user_count gauge\n";
echo "wordpress_user_count 42\n";
?>
```
more advanced
```bash
<?php

// wordpress_simple_metrics.php - Simple WordPress Metrics for Prometheus

// Database Configuration (Securely store these!)
$db_host = 'localhost';
$db_user = 'wordpressuser';
$db_pass = 'your_strong_password';
$db_name = 'wordpress';

// Connect to the database
$mysqli = new mysqli($db_host, $db_user, $db_pass, $db_name);

if ($mysqli->connect_error) {
    die("Database connection failed: " . $mysqli->connect_error);
}

// Function to output Prometheus metrics
function prometheusMetric($name, $value, $type = 'gauge') {
    echo "# TYPE " . $name . " " . $type . "\n";
    echo $name . " " . $value . "\n";
}

// Get post count
$result = $mysqli->query("SELECT COUNT(*) FROM wp_posts WHERE post_status = 'publish' AND post_type = 'post'");
$row = $result->fetch_row();
$postCount = $row[0];
prometheusMetric('wordpress_posts_total', $postCount);

// Get comment count
$result = $mysqli->query("SELECT COUNT(*) FROM wp_comments WHERE comment_approved = 1");
$row = $result->fetch_row();
$commentCount = $row[0];
prometheusMetric('wordpress_comments_total', $commentCount);

// Close the database connection
$mysqli->close();

?>
```

change the prometheus yml
```bash
sudo nano /etc/prometheus/prometheus.yml
```

add this ploc
```bash
scrape_configs:
  - job_name: 'wordpress'
    metrics_path: 'metrics.php'
    static_configs:
      - targets: ['localhost:80']
```

restart prometheus

```bash
sudo systemctl restart prometheus
```
