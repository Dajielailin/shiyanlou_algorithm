/*
*@param num: one non-negtive num x
*@return : the integer part of x'sqrt
*/

#include <iostream>

using namespace std;

int sqrt(int x)
{
	if(x < 0)
		return -1;
	int left = -1, right =x + 1;
	long long tmp;
	while(left + 1 < right)
	{
		int mid = left + (right - left) / 2;
		tmp = mid * mid;
		if(tmp < x)
			left = mid;
		else
		{
			if(tmp == x)
				return mid;
			else
				right = mid;
		}
	}
	return left;
}
int main()
{
	int x;
	cin >> x;
	cout << sqrt(x);
	return 0;
}
