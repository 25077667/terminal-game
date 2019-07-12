cc = g++
flags = -std=c++1y

all: 
	# exe and services

services:
	$(cc) header/testServer/hw.cpp $(flags) -lboost_system -lpthread -o crw_server

headers:
	$(cc) header/userOperate.hpp -lncurses - o 
	$(cc) header/screen.hpp
	$(cc) header/role.hpp
	$(cc) $(flags) header/networking.hpp -lboost_system -lpthread
	$(cc) header/writeJson.hpp

clean: