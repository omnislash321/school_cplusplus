#-------------------------------------------------------------------------------
# Project Name  : ISP
# Written by    : Roberto Hong Xu Kuang
# Last Modified : 10/19/2014
#-------------------------------------------------------------------------------


# Notice the '.PHONY' target. 
# This target tells Make that 'all' and 'clean' are not files. This is usually
# not required, but useful if for some reason
.PHONY: clean all tarball

all: isp

# The clean target should be used before you create your tarball to remove the
# binaries created during compilation
clean:
	rm -f isp
	rm -f isp.exe
	rm -f *.o
	rm -fr input
	rm -fr my-output
	rm -f *.tar.gz
	rm -fr output

# The following targets automate the process of creating a tarball. To activate
# it simply remove the leading '# ' and replace '<username>' with your own.
tarball: rxu-isp.tar.gz

rxu-isp.tar.gz: clean
	cd .. &&	tar -czvf rxu-isp.tar.gz ./isp/*

# These targets take care of the compilation process.
isp: isp.o
	g++ isp.o -o isp

isp.o: isp.cpp
	g++ -c isp.cpp
