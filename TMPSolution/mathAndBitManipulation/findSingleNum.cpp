/*
*@param num : Given an array of integer, every element appears k times except for one.
*@return : the single one which appears l times.
*@requirement : O(kn) time, and the extra space O(k)
*/

#include <iostream>
#include <vector>

using namespace std;

int findSingleNumLOfN(vector<int> &vv, int k, int l)
{
	if(vv.empty())
		return -1;
	int t;
	vector<int> xx(k);
	xx[0] = ~0;
	for(int i = 0; i < vv.size(); i++)
	{
		t = xx[k-1];
		for(int j = k-1; j > 0; j--)
		{
			xx[j] = (xx[j-1] & vv[i]) | (xx[j] & ~vv[i]);
		}
		xx[0] = (t & vv[i]) |( xx[0] & ~vv[i]);
	}
	return xx[l];
}

int main()
{
	int m, k, l, tmp;
	cin >> m >> k >> l;
	vector<int> vc(m);
	for(int i = 0; i < m; i++)
	{
		cin >> tmp;
		vc[i] = tmp;
	}
	cout << findSingleNumLOfN(vc, k, l);
	return 0;
}
