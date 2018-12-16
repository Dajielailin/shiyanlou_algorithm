/*
*@param num : an integer N
*@return : the number of trailing zeros in n factorial 
*@requirement: O(log N) time
*/
#include <iostream>
#include <vector>

using namespace std;

int findNumofTrailingZeros(int n)
{
	if(n == 0)
		return 0;
	else if(n < 0)

		return -1;
	else
		return n/5 + findNumofTrailingZeros(n/5);
}


int main()
{
	int n;
	cin >> n;
	cout << findNumofTrailingZeros(n) << endl;
	return  0;
}
