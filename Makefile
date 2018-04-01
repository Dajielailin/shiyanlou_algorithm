cc=g++
cflag=-std=c++14
all: kmp lcs_1 lcs_dp
kmp: KMP.cpp
	$(cc) $(cflag) KMP.cpp -o kmp
lcs_1: lCS_1.cpp
	$(cc) $(cflag) lCS_1.cpp -o lcs_1
lcs_dp: lCS_DP.cpp
	$(cc) $(cflag) lCS_DP.cpp -o lcs_dp
