Below are the step I took to complete the Born2beRoot project.

## Info
### Partitioning
#### LVM
LVM (Logical Volume Management) is a system that allows you to manage disk space more flexibly. It adds a layer of abstraction between your physical disks and the file systems. The main benefits of LVM include:
- Ability to resize volumes easily
- Combining multiple physical disks into a single logical volume
- Creating snapshots of volumes
- Moving data between physical disks without downtime

### Packages
#### apt vs aptstianstia
- aptitude has more sophisticated dependency resolution - it suggests alternative solutions when conflicts arise
- aptitude installs recommended packages by default, while apt doesn't unless configured to do so
- aptitude remembers why a package was installed (as dependency vs. explicit)

### Security
#### AppArmor
- Security enhancement that restricts programs to a limited set of resources
- Follows the principle of least privilege
- Uses profiles to define what actions/resources programs can access
- Located in `/etc/apparmor.d/`
- Check if AppArmor is running: `sudo aa-status`
- List loaded profiles: `sudo apparmor_status`

## Instructions
### Debian installation: networking and users
- [ ] Create alebedev user (change `alebedev` to your username)
- [ ] Set alebedev42 as hostname
- [ ] add alebedev user to `user42` and `sudo` groups
- [ ] Set password, e.g. `Sunshine123` or `Rainbows123`

### Partitioning
- [ ] Create new empty part table on vdisk
- [ ] Create new /boot part with bootable flag on
- [ ] Create encrypted parts (not LVM, as it's not encrypted) (see ## Info)
- [ ] Configure encrypted volumes (setting passwords)
- [ ] Configure LVM

### Passwords
(note) `pass` for encrypted volumes 

### Packages
`su` to enter root (if logged in as user)
`apt update && apt upgrade -y` 
If facing an issue with the installation where it's requesting the Debian installation disc:
edit the APT sources list `nano /etc/apt/sources.list`, look for a line that starts with deb cdrom: and comment it out by adding a `#` 
`apt install sudo` to get sudo command
`apt install vim` ;)

### Groups
`groupadd user42`
`usermod -aG sudo alebedev` or with `/usr/sbin/usermod`
`usermod -aG user42 alebedev` (same)

### Firewall
`apt install ufw`
`/usr/sbin/ufw enable`
`/usr/sbin/ufw allow 4242`

### SSH
`vim /etc/ssh/sshd_config` and edit `#Port 22` to `Port 4242`, and add line `PermitRootLogin no` to prevent SSH root login
`systemctl restart sshd` after that

### Password quality
`apt install libpam-pwquality` for password policies
`vim /etc/security/pwquality.conf` and add:

```sh
minlen = 10
ucredit = -1 # At least one uppercase
lcredit = -1 # At least one lowercase
dcredit = -1 # At least one digit
maxrepeat = 3
usercheck = 1 # Should not contain username
difok = 7 # At least 7 different chars for previous password
enforce_for_root = difok=0 # Apply previous rules to root + change difok rule
```

`vim /etc/pam.d/common-password` (anything to check here? idk)

`vim /etc/login.defs`

```sh
PASS_MAX_DAYS 30
PASS_MIN_DAYS 2
PASS_WARN_AGE 7
```

### Sudo

`vim /etc/sudoers.d/sudo_config` and add:

```sh
Defaults        passwd_tries=3
Defaults        badpass_message="Custom error message for wrong password"
Defaults        log_input,log_output # Logging when using sudo
Defaults        iolog_dir="/var/log/sudo/"
Defaults        requiretty # This setting requires users to have a TTY (terminal) open when using sudo
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin" # (Is this all the paths that need to be secured?)

```

`mkdir -p /var/log/sudo`

### Monitoring script

`touch /usr/local/bin/monitoring.sh`
`chmod +x /usr/local/bin/monitoring.sh`

`crontab -e` to set up cron for monitoring regularly
`*/10 * * * * /usr/local/bin/monitoring.sh` add this line. The five asterisks represent minute, hour, day of month, month, and day of week

#### The architecture of your operating system and its kernel version.
`uname -a`

#### The number of physical processors.
`grep "physical id" /proc/cpuinfo | sort | uniq | wc -l`
`uniq` remove adjacent duplicates so `sort` is used before it! Duplicates physical CPU id because CPUs have multiple cores, and also hyperthredding (appearing as multiple cores) can do that.

#### The number of virtual processors.
Here each processor entry represents one schedulable CPU unit from the operating system's perspective
Thus we can just `grep "processor" /proc/cpuinfo | wc -l`

#### The current available RAM on your server and its utilization rate as a percentage.
`free -m` display memory in Mb
The awk command looks for lines where the first column equals "Mem:"
`$n` represents the nth column
```sh
mem_used=$(free -m | awk '$1 == "Mem:" {print $3}')
mem_total=$(free -m | awk '$1 == "Mem:" {print $2}')
mem_percent=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
```

#### The current available storage on your server and its utilization rate as a percentage.
`df -m` is disk usage in Mb
`/dev` contains device files (special files that represent various devices connected to the system)
`grep -v` excludes the boot partition
`awk` adds up the used space (column 3) from all remaining partitions into a variable called disk_u
```sh
# Disk usage
disk_used=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.0f", disk_t/1024)}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t += $2} END {printf("%.2f"), disk_u/disk_t*100}')
```

#### The current utilization rate of your processors as a percentage.
`top -bn1` runs the top command in `-b` batch mode (send output to stdout) and `-n1` runs top only once
```sh
pcpu_load=$(top -bn1 | grep "Cpu(s)" | awk '{print $2 + $4}')
```

#### The date and time of the last reboot.
`who -b` shows last time boot
```sh
who -b | awk '{print $3 " " $4}'
```

#### Whether LVM is active or not.
```sh
lvm_check=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)
```

#### The number of active connections.
`-n` skips DNS lookup
`-a` shows all connections and listening ports
`-t` TCP only
"ESTABLISHED" are active TCP connections that have completed the handshake process
```sh
tcp_connections=$(netstat -nat | grep ESTABLISHED | wc -l)
```

#### The number of users using the server.
```sh
user_count=$(who | wc -l)
```

#### The IPv4 address of your server and its MAC (Media Access Control) address.
```sh
ip_addr=$(hostname -I)
mac_addr=$(ip link | grep "link/ether" | awk '{print $2}')
```

#### The number of commands executed with the sudo program.
```sh
sudo_count=$(grep "COMMAND" /var/log/sudo/sudo.log | wc -l)

```

## Notes
- Are all the paths that can be used by sudo currently restricted?
- What about `/etc/pam.d/common-password`?
- Why we need both  /etc/login.defs and /etc/security/pwquality.conf ?
- Change echo to `wall`
