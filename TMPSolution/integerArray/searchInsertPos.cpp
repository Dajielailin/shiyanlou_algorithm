/*
*@param nums: A sorted array and a target number
*@result: find the proper index of the target when it was inserted in Array
*@requirement: O(log n) time
*/

#include <iostream>
#include <vector>

using namespace std;

int findInsertPosition(vector<int> & sou, int tar)
{
	if(sou.empty())
		return -1;
	int left = 0, right = sou.size();
	while( left < right)
	{
		int mid = left + (right - left) / 2;
		if(sou[mid] == tar)
			return mid;
		else if(sou[mid] > tar)
			right = mid;
		else
			left = mid + 1;
	}
	if(left != right)
		return -1;
	else
		return left;
	
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
	cout << findInsertPosition(vc, target);
	return 0;
}
