#-------------------------------------------------------------------------------
# Project: Hello World
# Written By: Roberto Hong Xu Kuang
# Last Modified: 10/09/2014
#-------------------------------------------------------------------------------


.PHONY: clean all tarball

all: hello_world

tarball: rxu-hello_world.tar.gz

rxu-hello_world.tar.gz: clean
	cd .. &&	tar -czvf rxu-hello_world.tar.gz ./hello_world/*

hello_world:hello_world.o
	g++ hello_world.o -o hello_world

hello_world.o: hello_world.cpp
	g++ -c hello_world.cpp

clean:
	rm -rf *o hello_world
