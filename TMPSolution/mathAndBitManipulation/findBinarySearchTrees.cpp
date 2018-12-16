/*
*@param num : an integer num n
*@return : how many structurally unique BSTs(binary search trees) that store values 
* 1...n?
*/

#include <iostream>
#include <vector>

using namespace std;

int findBST(vector<int> & vv, int root, int remain)
{
	if(remain == 0)
		return 1;
	int res = 0;
	for(int i = 0; i <= root; i++)
	{
		for(int j = root + 1; j <vv.size(); j++)
		{
			if(i == root)
			{
				vv[i]
			}
		}
		if(vv[i] == 1)
		{
			vv[i]--;
			res += findBST(vv, i, remain -1);
			vv[i]++;
		}
	}
	
	return res;
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

int main()
{
	int n;
	cin >> n;
	vector<int> help(n, 1);
	cout << findBST(help);
	return  0;
}
