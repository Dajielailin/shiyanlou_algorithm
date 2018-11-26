#include<iostream>
#include<vector>

using namespace std;

void searchForRange(vector<int> & vc, int tar, vector<int> & res)
{
	if(vc.empty())
		return ;
	int left = -1, right = vc.size();
	int mid;
	while(left + 1 < right)
	{
		mid = left + (right - left) / 2;
		if(vc[mid] < tar)
			left = mid;
		else
			right = mid;
	}
	if(right < vc.size() && vc[right] == tar)
		res[0] = right;
	else
	{
		res[0] = -1;
		return;
	}
	right = vc.size();
	while(left + 1 < right)
	{
		mid = left + (right - left) / 2;
		if(vc[mid] > tar)
			right = mid;
		else
			left = mid;
	}
	if(left < vc.size() && vc[left] == tar)
		res[1] = left;
}

int main()
{
	int num, tmp, target;
	cin >> num >> target;
	vector<int> vc;
	for(int i = 0; i < num; i++)
	{
		cin >> tmp;
		vc.push_back(tmp);
	}
	vector<int> res(2, -1);
	searchForRange(vc, target, res);
	cout<< res[0] << " " << res[1] << endl;
	return 0;
}
