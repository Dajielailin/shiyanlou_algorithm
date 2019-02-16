/*
*@param k: The numebr k
*@return : The Kth Ugly number
*@Requirement: O(k) or O(klogK)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long binarySearch(vector<long long> &vv, int base)
{
	int num = vv[vv.size() -1];
	int start = -1, end = vv.size(), mid;
	while(start + 1 < end)
	{
		mid = start + (end - start) / 2;
		if(vv[mid] * base > num)
		{
			end = mid;
		}
		else{
			start = mid;
		}
	}
	if(vv[end] * base > num)
		return vv[end] * base;
	else
		return -1;
}

long long findKthUglyNum(int k)
{
	if(k < 1)
		return -1;
	vector<long long>vc;
	vc.push_back(1);
	long long minTmp;
	for(int i = 0; i < k; i++)
	{
		minTmp = min(binarySearch(vc, 3), binarySearch(vc, 5));
		minTmp = min(binarySearch(vc, 7), minTmp);
		if(minTmp > -1)
			vc.push_back(minTmp);
	}
	return vc[vc.size() -1];
}

int main()
{
	int k;
	cin >> k;
	cout << findKthUglyNum(k) <<endl;
	return 0;
}
