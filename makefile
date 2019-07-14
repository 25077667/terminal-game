cc = g++
flags = -std=c++1y

all: 
	# exe and services

services:
	$(cc) header/testServer/hw.cpp $(flags) -lboost_system -lpthread -o crw_server

headers:
	$(cc) header/userOperate.hpp -lpthread -lncurses
	$(cc) header/screen.hpp
	$(cc) header/role.hpp header/skillSet.hpp -lboost_system
	$(cc) $(flags) header/networking.hpp -lboost_system -lpthread
	$(cc) header/writeJson.hpp

clean:

test:
	$(cc) main.cpp -lpthread -lncurses -lboost_system