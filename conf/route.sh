# enp2s8: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
#         inet 192.168.66.88  netmask 255.255.255.0  broadcast 192.168.66.255
#         inet6 fe80::21b:38ff:fe37:75a9  prefixlen 64  scopeid 0x20<link>
#         ether 00:1b:38:37:75:a9  txqueuelen 1000  (Ethernet)
#         RX packets 762  bytes 53896 (52.6 KiB)
#         RX errors 0  dropped 0  overruns 0  frame 0
#         TX packets 186  bytes 48606 (47.4 KiB)
#         TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
# 
# lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
#         inet 127.0.0.1  netmask 255.0.0.0
#         inet6 ::1  prefixlen 128  scopeid 0x10<host>
#         loop  txqueuelen 0  (Local Loopback)
#         RX packets 132  bytes 10708 (10.4 KiB)
#         RX errors 0  dropped 0  overruns 0  frame 0
#         TX packets 132  bytes 10708 (10.4 KiB)
#         TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
# 
# wlp16s0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
#         inet 192.168.1.114  netmask 255.255.255.0  broadcast 0.0.0.0
#         inet6 fe80::21b:77ff:feae:9172  prefixlen 64  scopeid 0x20<link>
#         ether 00:1b:77:ae:91:72  txqueuelen 1000  (Ethernet)
#         RX packets 239  bytes 52240 (51.0 KiB)
#         RX errors 0  dropped 0  overruns 0  frame 0
#         TX packets 639  bytes 57329 (55.9 KiB)
#         TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

echo 1 > /proc/sys/net/ipv4/ip_forward 
ifconfig enp2s8 192.168.66.88
iptables -F
iptables -P FORWARD ACCEPT
iptables -P INPUT ACCEPT
iptables -t nat -A POSTROUTING -o wlp16s0 -j MASQUERADE
