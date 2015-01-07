
ifconfig wlan0 up
iwlist wlan0 scanning | grep 21
iwconfig wlan0 essid Room-2105 key 87570400
wpa_passphrase Room-2105  87570400 > xxx.conf
wpa_supplicant -B -i wlan0 -Dwext -c ./xxx.conf 