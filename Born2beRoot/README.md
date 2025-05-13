# My Born2beRoot configuration
Below are the notes and step I took to complete and remember the Born2beRoot project.
## Info
### Partitioning
#### LVM
LVM (Logical Volume Management) is a system that allows you to manage disk space more flexibly. It adds a layer of abstraction between your physical disks and the file systems. The main benefits of LVM include:
- Ability to resize volumes easily
- Combining multiple physical disks into a single logical volume
- Creating snapshots of volumes
- Moving data between physical disks without downtime

### Packages
#### apt vs aptitude
- aptitude has more sophisticated dependency resolution - it suggests alternative solutions when conflicts arise
- aptitude installs recommended packages by default, while apt doesn't unless configured to do so
- aptitude remembers why a package was installed (as dependency vs. explicit)

### Security
#### AppArmor
- Installed and turned on by default in modern Debian distributions (since Debian 10 "Buster")
- Security enhancement that restricts programs to a limited set of resources
- The "enforce mode" means these restrictions are actively being applied
- A PDF viewer like Evince can be confined to only read PDF files in specific directories
- AppArmor can limit which programs connect to networks and how they do so
- Follows the principle of least privilege
- Complain mode. AppArmor can log what a program attempts to do without blocking it, helping create accurate profiles
- Profiles to define what actions/resources programs can access
- Processes are running program that may be confined by a profile
- AppArmor can restrict memory, CPU, and other resource usage
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

### Sudo

`vim /etc/sudoers.d/sudo_config` and add:

```sh
Defaults        passwd_tries=3
Defaults        badpass_message="Custom error message for wrong password"
Defaults        logfile="/var/log/sudo/sudo.log"
Defaults        log_input,log_output # Logging when using sudo
Defaults        iolog_dir="/var/log/sudo/"
Defaults        requiretty # This setting requires users to have a TTY (terminal) open when using sudo
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin" # (Is this all the paths that need to be secured?)

```

`mkdir -p /var/log/sudo`

### Font
Run `sudo dpkg-reconfigure console-setup` to change font size and weigth (optional)

### Firewall
`apt install ufw`
`/usr/sbin/ufw enable`
`/usr/sbin/ufw allow 4242`

### SSH
`vim /etc/ssh/sshd_config` and edit `#Port 22` to `Port 4242`, and add line `PermitRootLogin no` to prevent SSH root login
`systemctl restart sshd` after that

### Password quality
`apt install libpam-pwquality` for password policies

`login.defs` - controls password aging and expiration
`pam.d/common-password` - connects the authentication system to your password rules

in `vim /etc/login.defs` add the following (it controls password aging and expiration policies)
```sh
PASS_MAX_DAYS 30
PASS_MIN_DAYS 2
PASS_WARN_AGE 7
```

in `vim /etc/pam.d/common-password` add this
```sh
password requisite pam_pwquality.so minlen=10 difok=7 maxrepeat=3 dcredit=-1 ucredit=-1 lcredit=-1 reject_username enforce_for_root
```

Here's the breakdown of the PAM configuration line and all parameters:

**The line structure:**
- `password` - Specifies this rule applies to password authentication
- `requisite` - This module is required; if it fails, the authentication will immediately fail (won't try other modules)
- `pam_pwquality.so` - The PAM module that performs password quality checking

**Complete parameter list:**

2. `minlen=10` - Password must be at least 10 characters long
3. `difok=7` - At least 7 characters must be different from the previous password
4. `maxrepeat=3` - No more than 3 identical consecutive characters allowed
5. `dcredit=-1` - Requires at least 1 digit in the password
   - Negative value means "require at least this many"
   - Positive value would mean "award up to this many credits for digits"
6. `ucredit=-1` - Requires at least 1 uppercase letter in the password
7. `lcredit=-1` - Requires at least 1 lowercase letter in the password
8. `reject_username` - Rejects passwords containing the username
9. `enforce_for_root` - Applies all these rules to the root user as well

**Additional parameters that could be used:**

10. `ocredit=-1` - Would require at least 1 special character
11. `gecoscheck=1` - Would check if password contains parts of user's GECOS field (full name, etc.)
12. `dictcheck=1` - Would check against dictionary words
13. `dictpath=/path/to/dict` - Specifies a custom dictionary path
14. `enforce=users` - Enforces the checks only for regular users (not root)
15. `local_users_only` - Only applies to local users, not NIS/LDAP users
16. `remember=N` - Remember N previous passwords and prevent reuse (requires pam_unix.so with "remember" too)

For the Born2beRoot project, the parameters in your original line are sufficient to meet all the requirements specified in the project document. The configuration ensures passwords are complex enough, don't contain usernames, and applies these rules universally including to the root user.

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
`apt install net-tools`
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

# Things to know

- `sudo hostnamectl set-hostname new-hostname` to change hostname
- `getent passwd | cut -d: -f1` to list all users
- `sudo ufw` commands for opening ports and deleting rules

# Questions for evaluating others
- "For security reasons too, the paths that can be used by sudo must be restricted."
What does that mean? What is currently ensuring that?

- `sudo chage -l root` to check if the users have right password policies

- Check sudo count in monitoring script.

- `nc -l 4242` & `nc localhost 4242` in another terminal to test port 4242 and TCP

- `sudo crontab -e`

- `cat /etc/group | grep 'user42'`
- `cat /etc/group | grep 'sudo'`
