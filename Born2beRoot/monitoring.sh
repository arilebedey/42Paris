#!/bin/bash

# Architecture and kernel
arch=$(uname -a)

# CPU physical
cpu_phys=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)

# vCPU
v_cpu=$(grep "processor" /proc/cpuinfo | wc -l)

# Memory usage
mem_used=$(free -m | awk '$1 == "Mem:" {print $3}')
mem_total=$(free -m | awk '$1 == "Mem:" {print $2}')
mem_percent=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

# Disk usage
disk_used=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.0f", disk_t/1024)}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t += $2} END {printf("%.2f"), disk_u/disk_t*100}')

# CPU load
cpu_load=$(top -bn1 | grep "Cpu(s)" | awk '{print $2 + $4}')

# Last boot
last_boot=$(who -b | awk '{print $3 " " $4}')

# LVM check
lvm_check=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# TCP connections
tcp_connections=$(netstat -ant | grep ESTABLISHED | wc -l)

# User count
user_count=$(who | wc -l)

# IP and MAC
ip_addr=$(hostname -I)
mac_addr=$(ip link | grep "link/ether" | awk '{print $2}')

# Sudo commands
sudo_count=$(grep "COMMAND" /var/log/sudo/sudo.log | wc -l)

# Display results with wall command
echo "
#Architecture: $arch
#CPU physical: $cpu_phys
#vCPU: $v_cpu
#Memory Usage: $mem_used/${mem_total}MB ($mem_percent%)
#Disk Usage: $disk_used/${disk_total}GB ($disk_percent%)
#CPU load: $cpu_load%
#Last boot: $last_boot
#LVM use: $lvm_check
#Connections TCP: $tcp_connections ESTABLISHED
#User log: $user_count
#Network: IP $ip_addr ($mac_addr)
#Sudo: $sudo_count cmd"
