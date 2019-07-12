#!/bin/bash
sudo apt-get install build-essential libtcmalloc-minimal4 && sudo ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so

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
