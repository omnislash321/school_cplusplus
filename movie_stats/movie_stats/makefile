#-------------------------------------------------------------------------------
# Project Name: Movie Stats
# Written By: Roberto Hong Xu Kuang
# Last Modified: 11/19/2014
#-------------------------------------------------------------------------------

.PHONY: clean all tarball

all: movie_stats

clean:
	rm -f movie_stats
	rm -f movie_stats.exe
	rm -f *.o
	rm -fr input
	rm -fr output
	rm -fr my-output

tarball: rxu-movie_stats.tar.gz

rxu-movie_stats.tar.gz: clean
	cd .. &&		tar -czvf rxu-movie_stats.tar.gz ./movie_stats/*	

movie_stats: movie_stats.o
	g++ movie_stats.o -o movie_stats

movie_stats.o: movie_stats.cpp
	g++ -c movie_stats.cpp
