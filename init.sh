#!/bin/bash
sudo apt-get -y install build-essential libtcmalloc-minimal4 && sudo ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so
sudo apt-get -y install libncurses-dev

if [ "$(ls -l /dev/input/ | grep event4 | awk '{print $3}')"="root" ]; then
    echo -n 'linten keyboard need root!'
    echo
fi


read -n1 -p "Do you wnat to include devlopment mode? [Y/n]" doit

case ${doit} in
y | Y) sudo apt install libboost-all-dev libssl-dev ;;
n | N)
    echo
    echo "Abort"
    exit 0
    ;;
*) echo "Don\'t do that!" ;;
esac
