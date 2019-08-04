#!/bin/bash

# install crow env. 
sudo apt-get -y install build-essential libtcmalloc-minimal4 && sudo ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so
sudo apt-get -y install libboost-all-dev libssl-dev
sudo apt-get -y install libboost-dev

# install curses for listen keyboard
sudo apt-get -y install libncurses-dev

#install zip packages
sudo apt-get -y install zip unzip 
wget https://github.com/nlohmann/json/releases/download/v3.7.0/include.zip
unzip include.zip -d /usr/
rm include.zip

#install all tool for setting entire env. 