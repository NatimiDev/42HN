# Installing WordPress on Lighttpd (HTTP Only)
This guide outlines the steps to install WordPress on a Lighttpd web server running on a Debian virtual machine within UTM, using only HTTP on port 80.

## Prerequisites
* A Debian virtual machine running in UTM.
* Lighttpd, MariaDB, and PHP installed and configured.
* Basic command-line knowledge.
* UTM port forwarding for port 80.

## Step 1: Create a Database and User for WordPress

1.  Log in to MariaDB:
```bash
sudo mysql -u root -p
```

2.  Create a database:
```sql
CREATE DATABASE wordpress;
```

3.  Create a user and grant privileges:
```sql
CREATE USER 'nmikuka'@'localhost' IDENTIFIED BY '1234';
GRANT ALL PRIVILEGES ON wordpress.* TO 'nmikuka'@'localhost';
FLUSH PRIVILEGES;
EXIT;
```
## Step 2: Download and Install WordPress

1.  Create a directory for WordPress:
```bash
sudo mkdir /srv/www/
sudo mkdir /srv/www/wordpress
sudo chown www-data:www-data /srv/www/wordpress
```

2.  Navigate to the directory and download WordPress:
```bash
cd /srv/www/wordpress
sudo apt install wget
sudo wget https://wordpress.org/latest.tar.gz
sudo tar -xzf latest.tar.gz --strip-components=1
sudo rm latest.tar.gz
```

3.  Set correct permissions:
```bash
sudo chown -R www-data:www-data /srv/www/wordpress
```

## Step 3: Configure Lighttpd for WordPress HTTP

1.  Edit your Lighttpd configuration file (e.g., `/etc/lighttpd/conf-available/wordpress.conf`). If the file does not exist, create it.
```bash
sudo vim /etc/lighttpd/conf-available/wordpress.conf
```

2.  Add the following configuration:

```
server.document-root = "/srv/www/wordpress"
server.errorlog = "/var/log/lighttpd/error.log"
 accesslog.filename = "/var/log/lighttpd/access.log"

index-file.names = ( "index.php", "index.html", "index.lighttpd.html" )

url.rewrite-once = (
	"^/(wp-admin|wp-includes|wp-content|xmlrpc.php|wp-app\.php|feed|)", "$0",
	"^/(.*\.php)(.*)?$", "/index.php$2",
	"^/(.*)?$", "/index.php/$1"
)
```

3.  Enable the configuration:

```bash
sudo lighty-enable-mod rewrite
sudo lighttpd-enable-mod fastcgi
sudo lighttpd-enable-mod fastcgi-php
sudo systemctl restart lighttpd
```
You might have to change the root in the /etc/lighttpd/lighttpd.conf 
```bash
server.document-root = "/srv/www/"
```
## Step 4: Complete the WordPress Installation via Web Browser

1.  Open your host browser.
2.  Enter `http://localhost` (or `http://your_vm_ip_address` if you are not using port forwarding) in the address bar.
3.  Follow the WordPress installation prompts:
    * Enter the database name (`wordpress`).
    * Enter the database username (`wordpressuser`).
    * Enter the database password (`your_strong_password`).
    * Enter the database host (`localhost`).
    * Set your WordPress site title, username, password, and email.

## Step 5: Access the WordPress Placeholder Page
After the installation is complete, you should see the default WordPress placeholder page (the "Hello World" post) in your host browser at `http://localhost`.

## Troubleshooting

* **Database Connection Errors:**
    * Ensure MariaDB is running.
    * Verify the database credentials.
* **WordPress Installation Errors:**
    * Check the Lighttpd error log (`/srv/log/lighttpd/error.log`).
    * Ensure the `www-data` user has the correct permissions on the WordPress files.
* **Page is blank:**
    * Check the PHP error log if you have enabled it, or check the lighttpd error log.
* **Page is not shown:**
    * Make sure lighttpd is running.
    * Make sure the port forwarding is correctly configured in UTM.
    * Make sure that the lighttpd configuration is correct.