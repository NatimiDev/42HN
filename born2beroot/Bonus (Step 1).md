!!! You might want to switch all the paths from /var to /srv
# Setting up Lighttpd on a UTM Debian Virtual Machine

This guide details the steps to install Lighttpd on a Debian virtual machine running within UTM and to view the default Lighttpd webpage from your host browser.

## Step 1: Update and Install Lighttpd on the Debian VM

1.  **Start your Debian VM in UTM.**
2.  **Open a terminal.**
3.  **Update the package lists:**
```bash
sudo apt update
```

4.  **Install Lighttpd:**
```bash
sudo apt install lighttpd -y
```

5.  **Start the Lighttpd service:**
```bash
sudo systemctl start lighttpd
```

6.  **Verify Lighttpd is running:**
```bash
sudo systemctl status lighttpd
```
You should see that the service is active and running.

## Step 2: Configure UTM Port Forwarding

1.  **Find the IP address of your Debian VM.** In the VM's terminal, run:
```bash
ip a
```
Look for the `inet` address associated with your network interface (usually `eth0` or `enp0sX`). Note this IP address.
2.  **Open UTM and go to your VM's settings.**
3.  **Navigate to the "Network" section.**
4.  **Add a port forwarding rule:**
    * Host Port: `8080`
    * Guest Port: `80`
    * Guest IP: The IP address you found in the previous step.
5.  **Save the changes to your VM's settings.**

## Step 3: Access the Default Lighttpd Page from Your Host Browser

1.  **Open a web browser on your host machine.**
2.  **Enter `localhost` in the address bar.**
    * Because you've set up port forwarding, `localhost:8080` on your host machine will be forwarded to port 80 of your Debian VM.
3.  **You should see the default Lighttpd "It works!" webpage.**

## Troubleshooting

* **Page Not Loading:**
    * Double-check your UTM port forwarding settings.
    * Ensure that the Lighttpd service is running inside the VM (`sudo systemctl status lighttpd`).
    * Verify that the Debian VM has network connectivity.
    * If you have any firewall active on the debian VM, make sure port 80 is open.
* **Incorrect IP Address:**
    * Make sure you've entered the correct IP address of your Debian VM in the UTM port forwarding settings.
* **No Network in VM:**
    * Double check that the network adapter is enabled in the UTM VM settings.
* **Firewall on Host:**
    * Though unlikely to affect localhost, ensure that your host machine firewall is not blocking connections to port 80.
