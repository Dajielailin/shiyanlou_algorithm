/*
*@param num: two sorted arrays A and B size m and n respectively
*@return : the median of the two sorted arrays
*@requirement: O(log(m + n)) time
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findKth(vector<int> & va, int aStart, vector<int> & vb, int bStart, int k )
{
	if(aStart > va.size() -1)
		return vb[bStart + k - 1];
	if(bStart > vb.size() -1)
		return va[aStart + k -1];
	if(k == 1)
		return va[aStart] > vb[bStart] ? vb[bStart] : va[aStart];
	
	int aKey = aStart + k/2 - 1 < va.size() ? va[aStart + k/2 -1] : INT_MAX;
	int bKey = bStart + k/2 - 1 < vb.size() ? vb[bStart + k/2 -1] : INT_MAX;

	if(aKey >= bKey)
		return findKth(va, aStart, vb, bStart + k/2, k - k/2);
	else
		return findKth(va, aStart + k/2, vb, bStart, k - k/2);
		
}

float findMedianOfTwoArrays(vector<int> & va, vector<int> & vb)
{
	if(va.empty() && vb.empty())	
		return -1.0;
	vector<int> vv;
	if(va.empty())	
		vv = vb;
	if(vb.empty())
		vv = va;
	if(!vv.empty())
	{
		
		if(vv.size() % 2 == 0)
			return (vv[vv.size() / 2 - 1] + vv[vv.size() / 2]) / 2.0;
		else
			return vv[vv.size() / 2];
	}
	int lenA = va.size(), lenB = vb.size();
	int len = lenA + lenB;
	if(len % 2 == 0)
		return (findKth(va, 0, vb, 0, len / 2) + findKth(va, 0, vb, 0, len / 2 + 1)) / 2.0;
	else
		return findKth(va, 0, vb, 0, len / 2 + 1);  
		
}

int main()
{
	int m, n, tmp;
	cin >> m >> n;
	vector<int> va(m);
	vector<int> vb(n);
	for(int i = 0; i < m; i++)
	{
		cin >> tmp;
		va[i] = tmp;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		vb[i] = tmp;
	
	}
	cout << findMedianOfTwoArrays(va, vb);
	return 0;
}
