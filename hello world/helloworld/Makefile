all: helloworld

clean:
	rm ./*.o
	rm helloworld

helloworld: helloworld.o
	g++ helloworld.o -o helloworld

helloworld.o: helloworld.cpp
	g++ -c helloworld.cpp
