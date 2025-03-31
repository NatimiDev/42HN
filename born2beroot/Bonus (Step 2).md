# Installing MariaDB and PHP (Crucial Step Before WordPress)

This guide outlines the steps to install and configure MariaDB (database server) and PHP on your Debian system, which are essential prerequisites before setting up WordPress.

## 1. Install MariaDB (Database Server)

MariaDB will store your WordPress database.

1.  **Update package lists:**
```bash
sudo apt update
```

2.  **Install MariaDB server:**
```bash
sudo apt install mariadb-server -y
```

3.  **Secure MariaDB installation:**
```bash
sudo mysql_secure_installation
```
* Follow the prompts. It's crucial to set a strong root password and answer "yes" to the security questions.

## 2. Install PHP and Required Modules

WordPress requires PHP and several PHP extensions to function correctly.

1.  **Install PHP and necessary modules:**

```bash
sudo apt install php php-cgi php-mysql php-gd php-curl php-xml php-mbstring php-zip -y
```
* These modules provide essential functionality for WordPress, such as database connectivity, image processing, and URL handling.

## 3. Configure PHP for Lighttpd

Lighttpd uses FastCGI to communicate with PHP.

1.  **Enable the FastCGI module:**

```bash
sudo lighty-enable-mod fastcgi fastcgi-php
sudo systemctl restart lighttpd
```
# Stop and Remove Apache2 on Debian

To stop and remove Apache2 from your Debian system, follow these steps:

## 1. Stop Apache2:

Use the `systemctl` command to stop the Apache2 service:

```bash
sudo systemctl stop apache2
sudo apt purge apache2
sudo apt autoremove
sudo systemctl status apache2
```
