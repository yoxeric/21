#!/bin/bash

arc=$(hostnamectl | grep "Operating System" | cut -d ' ' -f5- ` `awk -F':' '/^model name/ {print $2}' /proc/cpuinfo | uniq | sed -e 's/^[ \t]*//')
pcpu=$(cat /proc/cpuinfo | grep processor | wc -l) 
vcpu=$(grep "^processor" /proc/cpuinfo | wc -l)
ram=$(free -m | awk 'NR==2{printf "#Memory Usage: %s/%sMB (%.2f%%)", $3,$2,$3*100/$2 }')
disk=$(df -h | awk '$NF=="/"{printf "#Disk Usage: %d/%dGB (%s)", $3,$2,$5}')
cpul=$(top -bn1 | grep load | awk '{printf "#CPU Load: %.2f\n", $(NF-2)}')
lb=$(who -b | awk '{print $3" "$4" "$5}')
lvmu=$(lsblk |grep lvm | awk '{if ($1) {print "yes";exit;} else {print "no"} }')
ctcp=$(netstat -an | grep ESTABLISHED |  wc -l)
ulog=$(who | cut -d " " -f 1 | sort -u | wc -l)
ip=$(hostname -I)
mac=$(ip a | grep link/ether | awk '{print $2}')
cmds=$(grep 'sudo ' /var/log/auth.log | wc -l)

wall "	#Architecture: $arc
	#CPU physical: $pcpu
	#vCPU: $vcpu
	#Memory Usage: $ram
	#Disk Usage: $disk
	#CPU load: $cpul
	#Last boot: $lb
	#LVM use: $lvmu
	#Connections TCP: $ctcp ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $cmds cmd"