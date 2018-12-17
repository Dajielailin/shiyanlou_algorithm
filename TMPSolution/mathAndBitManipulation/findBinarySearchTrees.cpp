/*
*@param num : an integer num n
*@return : how many structurally unique BSTs(binary search trees) that store values 
* 1...n?
*/

#include <iostream>
#include <vector>

using namespace std;
/*
int findBST(vector<int> & vv, int root, int remain)
{
	if(remain == 1)
		return 1;
	int left , right;
	for(int i = 0; i <= root; i++)
	{
		left = right = 1;
		for(int j = root + 1; j <vv.size(); j++)
		{
			if(i != root && vv[i] == 1)
			{
				vv[i]--;
				left = findBST(vv, i, remain-1);
				vv[i]++;
			}
			if(j != vv.size()-1 && vv[j] == 1)
			{
				vv[j]--;
				right = findBST(vv, j, remain-1);
				vv[j]++;
			}
		}
	}
	
	return left * right;
}

int findBST(vector<int> & vc)
{
	int len = vc.size();
	if(len < 2)
		return len;
	int res = 0;
	for(int i = 0; i < len; i++)
	{
		vc[i]--;
		res += findBST(vc, i, len - 1);
		vc[i]++;
	}
	return res;
}
*/

int findBST(int n)
{
	if(n < 0)
		return -1;
	vector<int> vv(n+1, 0);
	vv[0] = 1;
	for(int i = 1; i < n+1; i++)
	{
		for(int j = 0; j < i; j++)
		{
			vv[i] += vv[j] * vv[i-1-j];
		}
	}
	return vv[n];
}

int main()
{
	int n;
	cin >> n;
	//vector<int> help(n, 1);
	//cout << findBST(help);
	cout << findBST(n) << endl;
	return  0;
}
