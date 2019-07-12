cc = g++
flags = -std=c++1y

all: 
	# exe and services

services:
	$(cc) header/testServer/hw.cpp $(flags) -lboost_system -lpthread -o crw_server

exe:
	$(cc) $(flags) header/*.hpp

clean: