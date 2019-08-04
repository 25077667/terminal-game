#!/bin/bash
sudo apt-get -y install build-essential libtcmalloc-minimal4 && sudo ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so
sudo apt-get -y install libncurses-dev
sudo apt-get -y install libboost-all-dev libssl-dev

#install all tool for setting entire env. 