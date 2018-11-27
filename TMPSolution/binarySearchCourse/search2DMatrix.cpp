#include<iostream>
#include<vector>

using namespace std;

bool searchTarInMatrix(vector<vector<int> > & vc, int tar)
{
	bool res = false;
	int low = -1, high = vc.size(), mid;
	while(low + 1 < high)
	{
		mid = low + (high - low) / 2;
		if(vc[mid][0] < tar)
			low = mid;
		else
			high = mid;
	}
	if(high < vc.size() && vc[high][0] == tar)
		return true;
	else
		high = high -1;
	int left = -1, right = vc[0].size();
	while(left + 1 < right)
	{
		mid = left + (right - left) / 2;
		if(vc[high][mid] < tar)
			left = mid;
		else
			right = mid;
	}
	if(right < vc.size() && vc[high][right] == tar)
		return true;

	return res;
}

int main()
{
	int m, n, tmp, target;
	cin >> m >> n >> target;
	vector<vector<int> > vc(m);
	for(int i = 0; i < m; i++)
	{
		vector<int> vv(n);
		for(int j = 0; j < n; j++)
		{
			cin >> tmp;
			vv[j] = tmp;
		}
		vc[i] = vv;
	}
	if(searchTarInMatrix(vc, target))
		cout<<"True" << endl;
	else
		cout << "false" << endl;
	return 0;
}
