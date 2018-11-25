/*
*@param nums: A list of integer numbers
*@return: The K-th Largest Element in an array
*@requirement: O(n) time, O(1) extra memory
*/

#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> & sou, int i, int j)
{
	int tmp = sou[i];
	sou[i] = sou[j];
	sou[j] = tmp;
}

int quickSort(vector<int> & sou, int l, int r, int k)
{
	if(l >= r)
		return sou[r];
	int pos = l;
	for(int i = l + 1; i <= r; i++)
	{
		if(sou[i] < sou[l])
		{
			pos++;
			swap(sou, i, pos);	
		}
	}
	swap(sou, pos, l);
	if(pos == k)
		return sou[pos];
	else if(pos < k)
		return quickSort(sou, pos+1, r, k);
	else
		return quickSort(sou, l, pos-1, k);

}

int findKthLargeNum(vector<int> & sou, int k)
{
	int left = 0, right = sou.size() - 1;
	return 	quickSort(sou, left, right, k);
}

int main()
{
	int num, kth, tmp;
	cin >> num >> kth;
	vector<int> vc;
	for(int i = 0; i < num; i++)
	{
		cin >> tmp;
		vc.push_back(tmp);
	}
	if(!vc.empty())
		cout << findKthLargeNum(vc, num-kth);
	return 0;
}
