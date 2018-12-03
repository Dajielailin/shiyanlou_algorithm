/*
*param A : an integer rotated sorted array
*param target : an integer to be searched
*return : the index of target or -1
*requirement: O(lon(n))
*/
#include<iostream>
#include<vector>

using namespace std;

int findTargetInArray(vector<int> & vv, int target)
{
	int res = -1;
	int left = 0;
	int right = vv.size() - 1;
	while(left + 1 < right)
	{
		int mid = left + (right - left) / 2;
		if(vv[mid] == target)
			return mid;
		if(vv[left] < vv[mid])
		{
			if(vv[left] <= target && vv[mid] > target)
				right = mid;
			else
				left = mid;
		}
		else{
			if(vv[mid] < target && vv[right] >= target )
				left = mid;
			else
				right = mid;
		}
	}
	if(vv[left] == target)
		return left;
	if(vv[right] == target)
		return right;
	return res;
}

int main()
{
	int num, tar, tmp;
	cin >> num >> tar;
	vector<int> vc(num);
	for(int i = 0; i < num; i++)
	{
		cin >> tmp;
		vc[i] = tmp;
	}
	cout << findTargetInArray(vc, tar);
	return 0;
}
