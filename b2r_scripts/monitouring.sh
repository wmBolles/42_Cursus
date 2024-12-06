#!/bin/bash

Usage_per=$(df -h --total | tail -1 | awk '{printf "(%s)", $5}')

wall "#Architecture: $(uname -a)
#CPU physical : $(lscpu | grep "Socket(s)" | cut -d":" -f2 | tr -d ' ')
#vCPU : $(lscpu | grep "CPU(s):" | cut -d':' -f2 | tr -d ' ' | head -n1)
#Memory Usage: $(free -m | awk '/Mem/{printf "%s/%sMB (%.2f%%)\n", $3, $2, ($3 * 100 / $2)}')
#Disk Usage: $(df -m --total | tail -1 | awk '{printf "%s/", $3}')$(df -h --total | tail -1 | awk '{printf "%sb", $3}') $Usage_per
#CPU load: $(top -bn1 | grep "Cpu(s)" | awk '{printf "%d%%", $2 + $4}')
#Last boot: $Reboot_Year$(who --boot | awk '{printf "%s %s", $3, $4}')
#LVM use: $(if [ $(lsblk | grep "lvm" | wc -l ) -eq 0 ]; then echo "no"; else echo "yes"; fi)
#Connections TCP : $(netstat -a | grep "ESTABLISHED" | wc -l) ESTABLISHED
#User log: $(who | wc -l)
#Network: IP $(hostname -I)$(ip link  | grep "ether" | awk '{printf "(%s)", $2}')
#Sudo : $(journalctl -q | grep COMMAND | wc -l) cmd"


da39a3ee5e6b4b0d3255bfef95601890afd80709
