#### Partitioning
	30.8 GB
	boot 500MB -> 524 -> 499!!!!! -> 525
	LVM 30.3GB
		/root 10GB -> 10737 MIB
		[swap] 2.3GB -> 2470
		/home 5GB -> 5369
		/var 3GB -> 3.221
		/srv 3GB -> 3221
		/tmp 3GB ->  3222
		/var/log 4GB -> 4295

#### Check the partitions
```bash
lsblk
```

#### Install  sudo and add your user to sudo group
```bash
su root
apt update 
apt upgrade
apt install sudo

gpasswd -a <user> sudo
or usermod -aG <group> <user>

```

#### Install and configure ssh
```bash
apt install openssh-server
apt install vim
sudo vim /etc/ssh/sshd-config
```
Port 4242
PermitRootLogin no

connect from host using
```bash
ssh nmikuka@localhost -p 4242
```
!!! Don't forget to tunnel 4242 from guest to host

#### Install and configure ufw (Uncomplicated firewall)
```bash
sudo apt install ufw
sudo ufw status verbose/nubered
sudo ufw enable
sudo ufw allow 4242
```

#### Setup a strong password
Edit `/etc/login.defs` and find "password aging controls". Modify them as per subject instructions:
```shell
PASS_MAX_DAYS 30
PASS_MIN_DAYS 2
PASS_WARN_AGE 7
```

Apply changes to existing users 
```shell
sudo chage -M 30 -m 2 -W 7 <username/root>
```
Use `chage -l <username/root>` to check user settings.

Install password quality verification library with
```shell
sudo apt install libpam-pwquality
```
Then, edit the `/etc/security/pwquality.conf` file like so:
```shell
# Number of characters in the new password that must not be present in the 
# old password.
difok = 7
# The minimum acceptable size for the new password (plus one if 
# credits are not disabled which is the default)
minlen = 10
# The maximum credit for having digits in the new password. If less than 0 
# it is the minimun number of digits in the new password.
dcredit = -1
# The maximum credit for having uppercase characters in the new password. 
# If less than 0 it is the minimun number of uppercase characters in the new 
# password.
ucredit = -1
# ...
lcredit = -1
# ...
# The maximum number of allowed consecutive same characters in the new password.
# The check is disabled if the value is 0.
maxrepeat = 3
# ...
# Whether to check it it contains the user name in some form.
# The check is disabled if the value is 0.
usercheck = 1
# ...
# Prompt user at most N times before returning with error. The default is 1.
retry = 3
# Enforces pwquality checks on the root user password.
# Enabled if the option is present.
enforce_for_root
# ...
```

Change user passwords to comply with password policy:
```shell
$ sudo passwd <user/root>
```
to check the permissions
```bash
passwd -S root
```
#### Hostname
The hostname must be `your_intra_login42`, but the hostname must be changed during the Born2beroot evaluation. The following commands might help:
```bash
sudo hostnamectl set-hostname <new_hostname>
hostnamectl status
```
Change file

#### Create a new user and group
```bash
groups <username> #to list all groups of the user

sudo useradd <username>
sudo passwd <username>
sudo groupadd <group>
sudo usermod -aG <group> <username>
```
#### Adding a strong configuration for sudo group
Edit sudoers.tmp file as root with the command:

```shell
# sudo visudo
```

And add these default settings as per subject instructions:

```shell
Defaults     passwd_tries=3
Defaults     badpass_message="Wrong password. Try again!"
Defaults     logfile="/var/log/sudo/sudo.log"
Defaults     log_input
Defaults     log_output
Defaults     requiretty
```

If `var/log/sudo` directory does not exist, `mkdir var/log/sudo`.
#### Cronjob
Save script to /etc/cron.d/monitoring.sh and configure cron job using

```bash
sudo crontab -e

add line 
*/10 * * * * /etc/cron.d/monitoring.sh
```
don't forget to change the permissions to execute the script
