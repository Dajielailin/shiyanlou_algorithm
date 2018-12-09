/*
*@param num : n pieces of wood with length L[i]. Cut them into small pieces to guarantee you could have equal or more than k pieces with the same legth.
*@return : What is longest length you can get from the n pieces of wood? return it
*@changllenge: O(nlog(len)) time, where len is the longest length of the wood.
*/

#include <iostream>
#include <vector>
using namespace std;

bool ismatch(vector<int> & vv, int len, int k)
{
	long long tmp = 0;
	for(int i = 0; i < vv.size(); i++)
	{
		tmp += vv[i] / len;
	}
	return tmp >= k ? true : false;
}

int findLongestWood(vector<int> & vv, int k)
{
	if(vv.empty() || k < 0)
		return 0;
	long long sum = 0;
	int max = 0, length = vv.size();
	for(int i = 0; i < length; i++)
	{
		if(vv[i] > max)
			max = vv[i];
		sum += vv[i];
	}
	if(k == 0)
		return max;
	int len = sum / k;
	int left = -1, right = len + 1;
	while(left + 1 < right)
	{
		int mid = left + (right - left) / 2;
		if(!ismatch(vv, mid, k))
			right = mid;
		else
			left = mid;
	} 
	if(ismatch(vv, left, k))
		return left;
}

int main()
{
	int n, k, tmp;
	cin >> n >> k;
	vector<int> vc(n);
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		vc[i] = tmp;
	}
	cout << findLongestWood(vc, k);
	return 0;
}
