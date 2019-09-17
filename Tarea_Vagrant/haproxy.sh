#!/usr/bin/env bash
sudo apt-get update
sudo apt-get -y install haproxy --fix-missing
sudo echo ENABLED=1 >> "/etc/default/haproxy"
sudo mv /etc/haproxy/haproxy.cfg{,.original}
sudo mv -v /tmp/tmp /tmp/haproxy.cfg
sudo mv /tmp/haproxy.cfg /etc/haproxy/
sudo service haproxy start
sudo service haproxy reload
