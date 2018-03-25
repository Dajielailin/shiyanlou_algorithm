cc=g++
cflag=-std=c++14
all: kmp
kmp: KMP.cpp
	$(cc) $(cflag) KMP.cpp -o kmp
