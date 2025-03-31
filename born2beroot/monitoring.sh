#!/bin/bash

# Architecture and Kernel Version
architecture=$(uname -a)

# Number of Physical and Virtual Processors
physical_processors=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)
virtual_processors=$(nproc)

# RAM Usage
total_ram=$(free -m | awk '/Mem:/ {print $2}')
used_ram=$(free -m | awk '/Mem:/ {print $3}')
ram_usage=$(awk "BEGIN {printf \"%.2f\", ($used_ram/$total_ram)*100}")

# Disk Usage
disk_total=$(df -h --total | awk '/total/ {print $2}')
disk_used=$(df -h --total | awk '/total/ {print $3}')
disk_usage=$(df -h --total | awk '/total/ {print $5}')

# CPU Load
cpu_usage=$(top -bn1 | grep "Cpu(s)" | awk '{print $2 + $4}')
# Last Reboot
last_reboot=$(who -b | awk '{print $3, $4}')

# LVM Check
lvm_active=$(lsblk | grep -q "lvm" && echo "Yes" || echo "No")

# Active Connections
active_connections=$(ss -tun | grep -v 'State' | wc -l)

# Active Users
active_users=$(who | wc -l)

# IPv4 and MAC Address
ipv4_address=$(hostname -I | awk '{print $1}')
mac_address=$(ip link show | awk '/ether/ {print $2; exit}')

# Sudo Commands Executed
sudo_count=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

# Display Information
echo "------------------ System Monitoring Script ------------------"
echo "#Architecture: $architecture"
echo "#CPU physical: $physical_processors"
echo "#vCPU: $virtual_processors"
echo "#Memory Usage: $used_ram/$total_ram MB ($ram_usage%)"
echo "#Disk Usage: $disk_used/$disk_total GB ($disk_usage)"
echo "#CPU load: $cpu_usage%"
echo "#Last boot: $last_reboot"
echo "#LVM use: $lvm_active"
echo "#Connections TCP: $active_connections ESTABLISHED"
echo "#User log: $active_users"
echo "#Network: IP $ipv4_address ($mac_address)"
echo "#Sudo: $sudo_count cmd"
echo "--------------------------------------------------------------"