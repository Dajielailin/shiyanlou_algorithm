/*
*@param nums: A sorted array and a target number
*@result: find the first index of the target in Array
*@requirement: O(log n) time
*/

#include <iostream>
#include <vector>

using namespace std;

int findFirstIndexOfTarget(vector<int> & sou, int tar)
{
	if(sou.empty())
		return -1;
	int left = 0, right = sou.size() - 1;
	while( left < right)
	{
		int mid = left + (right - left) / 2;
		if(sou[mid] >= tar)
			right = mid;
		else
			left = mid + 1;
	}
	if(sou[right] != tar)
		return -1;
	else
		return right;
	
}

int main()
{
	int num, target, tmp;
	cin >> num >> target;
	vector<int> vc;
	for(int i = 0; i < num; i++)
	{
		cin >> tmp;
		vc.push_back(tmp);
	}
	cout << findFirstIndexOfTarget(vc, target);
	return 0;
}
