/*
*@param num : the number of bits of integer-N
*@return : Prints numbers from 1 to the largest number with N digits by recursion
*@requirement: do it in a way to recursive with at most N depth
*/

#include<iostream>
#include<vector>

using namespace std;

int pow(int x, int n)
{
	if(n == 0)
		return 1;
	else if(n % 2 == 0)
	{
		int tmp = pow(x, n/2);
		return tmp * tmp;
	}
	else
	{
		return x * pow(x, n-1);
	}
}

void printNumByRecursion(int n, vector<int> &vv)
{
	if(n == 0)
		return ;
	printNumByRecursion(n-1, vv);
	int base = pow(10, n-1);
	int size = vv.size();
	for(int i = 1; i < 10; i++)
	{
		vv.push_back(i * base);
		for(int j = 0; j < size; j++)
		{
			vv.push_back(i*base + vv[j]);
		}
	}
}

int main()
{
	int n, tmp;
	cin >> n;
	vector<int> vc;
	printNumByRecursion(n, vc);
	for(auto it : vc)
	{
		cout << it << " ";
	}
	cout << endl;
	return 0;
}
