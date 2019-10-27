#sudo ./VpnEditConfig.out
#sudo systemctl start privoxy.service
sudo /etc/init.d/privoxy restart
sudo sslocal -c /etc/shadowsocks/us.json -d start
