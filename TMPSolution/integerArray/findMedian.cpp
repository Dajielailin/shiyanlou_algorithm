/*
*@param nums: A list of integers.
*@return: An integer denotes the middle number of the array.
*@requirement: O(n) time, const number spaces
*
*/
#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int> & vv, int i, int j)
{
	int tmp = vv[i];
	vv[i] = vv[j];
	vv[j] = tmp;
}

int helper(vector<int> &sou, int left, int right, int tar)
{
	if(left >= right)
		return sou[right];
	int pos = left;
	int tmp = pos;
	for(int i = left + 1; i <= right; i++)
	{
		if(sou[i] < sou[tmp])
		{
			pos++;
			swap(sou, pos, i);
		}
	}
	swap(sou, tmp, pos);
	if(pos == tar)
		return sou[pos];
	else if(pos > tar)
		return helper(sou, left, pos-1, tar);
	else
		return helper(sou, pos+1, right, tar);
}

int findMedian(vector<int> & sou)
{
	int index = (sou.size() + 1) / 2 - 1;
	return helper(sou, 0, sou.size()-1, index);
}

int main()
{
	int num, tmp;
	cin >> num;
	vector<int> vc(num);
	for(int i = 0; i < num; i++)
	{
		cin >> tmp;
		vc[i] = tmp;
	}
	if(!vc.empty())
		cout << findMedian(vc);

	return 0;

}
