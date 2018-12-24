/*
*@param num: Given two numbers A and B
*@return : return the sum without any arithmetic operators.(bit operators)
*/

#include<iostream>

using namespace std;

int sum(int a, int b)
{
	int result = a ^ b;
	int count = a & b;
	count <<= 1;
	if(count != 0)
		return sum(result, count);
	return result; 
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << sum(a, b) << endl;
	return 0;
}
