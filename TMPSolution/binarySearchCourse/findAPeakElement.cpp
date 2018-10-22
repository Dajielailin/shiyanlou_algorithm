#include<vector>
#include<iostream>

using namespace std;

int findAPeakNum(vector<int>& vi)
{
	int res = -1;
	if(vi.empty())
		return res;
	int left = 0, right = vi.size() - 1;
	int mid = right / 2;
	while(left <= right)
	{
		if(mid == 0)
		{
			if(vi[mid] > vi[mid + 1])
				res = mid;
			break;
		}
		else if(mid == vi.size() - 1)
		{
			if(vi[mid] > vi[mid - 1])
				res = mid;
			break;
		}
		else 
		{
			if(vi[mid] > vi[mid -1] && vi[mid] > vi[mid + 1])
				return mid;
			else if(vi[mid] < vi[mid + 1])
				left = mid + 1;
			else 
				right = mid - 1;
		}
		mid = (right + left) / 2;		
	}
	return res;
}

int main()
{
	int size, tmp;
	cin >> size;
	vector<int> vin(size);
	for(int i = 0; i < size; i++ )
	{
		cin >> tmp;
		vin[i] = tmp;
	}
	cout << findAPeakNum(vin)<<endl;
	return 0;
}
