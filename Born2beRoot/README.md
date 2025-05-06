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


### Groups
`groupadd user42`
`usermod -aG sudo alebedev` or with `/usr/sbin/usermod`
`usermod -aG user42 alebedev` (same)


