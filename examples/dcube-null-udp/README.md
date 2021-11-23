sudo sysctl -w net.ipv6.conf.all.forwarding=1
sudo ip route add fd00::/64 via fd01::MY_BR_MAC dev tun0
sudo ../../tools/serial-io/tunslip6 -s /dev/ttyACM2 fd01::1/64 -B 115200
