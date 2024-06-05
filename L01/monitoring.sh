#!bin/bash
#• The architecture of your operating system and its kernel version.
architecture=$(uname -a)

#• The number of physical processors.
phcpu=$(lscpu | grep 'CPU(s):' --max-count=1  | awk '{print $2}')

#• The number of virtual processors.
vcpu=$(grep "processor" /proc/cpuinfo | wc -l)

#• The current available RAM on your server and its utilization rate as a percentage.
r_total=$(free -m | awk '$1 == "Mem:" {print $2}')
r_used=$(free -m | awk '$1 == "Mem:" {print $3}')
r_ratio=$(free -m | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

#• The current available memory on your server and its utilization rate as a percentage.
d_total=$(df | grep "/dev/" | grep -v "/boot" | awk '{total += $2} END {printf ("%.1fGb"), total/(1024 * 1024)}')
d_used=$(df | grep "/dev/" | grep -v "/boot" | awk '{used += $3} END {printf ("%.2fMb",used/(1024 * 1024))}')
d_percent=$(df | grep "/dev/" | grep -v "/boot" | awk '{used += $3} {total+= $2} END {printf("%d"), used/total*100}')

#• The current utilization rate of your processors as a percentage.
cpu_load=$(mpstat | grep "all" | awk '{print  100 - $13}')

#• The date and time of the last reboot.
last_boot=$(who -b | awk '$1 == "system" {print $3 " " $4 " "$5 $6}')

#• Whether LVM is active or not.
lvm_usage=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

#• The number of active connections.
tcp_connections=$(ss -t | grep "ESTAB" | wc -l)

#• The number of users using the server.
usr=$(users | wc -w)
#• The IPv4 address of your server and its MAC (Media Access Control) address.
host_ip=$(hostname -I)
mac_address=$(ip link | grep "link/ether" | awk '{print $2}')

#• The number of commands executed with the sudo program.
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "	
	#Architecture: $architecture
	#CPU physical: $phcpu
	#vCPU: $vcpu
	#Memory Usage: $r_used/${r_total}MiB ($r_ratio%)
	#Disk Usage: $d_used/${d_total} ($d_percent%)
	#CPU load: $cpu_load%
	#Last boot: $last_boot
	#LVM use: $lvm_usage
	#Connections TCP: $tcp_connections ESTABLISHED
	#User log: $usr
	#Network: IP $host_ip ($mac_address)
	#Sudo: $cmnd cmd
	"
