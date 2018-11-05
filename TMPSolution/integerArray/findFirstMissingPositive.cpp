#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& vc, int fir, int sec)
{
	int tmp = vc[fir];
	vc[fir] = vc[sec];
	vc[sec] = tmp;
}
unsigned int findFirstMissingPositive(vector<int> &vc)
{
	unsigned int res;
	for(int i =0; i < vc.size(); i++)
	{
		if(vc[i] > 0)
		{
			swap(vc, vc[i]-1, i);
		}
	}
	for(int i = 0; i < vc.size(); i++)
	{
		if(vc[i] != i+1)
			return i+1;
	}
	return vc.size() + 1;
}
int main()
{
	int n, tmp;
	cin >> n;
	vector<int> vc(n);
	for(int i =0; i < n; i++)
	{
		cin >> tmp;
		vc[i] = tmp;
	}
	cout << findFirstMissingPostive(vc) << endl;
	return 0;
}
