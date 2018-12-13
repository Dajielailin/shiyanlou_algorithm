/*
*@param num : Given 2*n + 2 numbers, every numbers occurs twice except two
*@return : the two single num
*@requirement: O(n) time, O(1) extra space.
*/

#include <iostream>
#include <vector>

using namespace std;

void findTwoSingleNum(vector<int> &vc, vector<int> & vv)
{
	if(vc.empty())
		return ;
	int res = 0, len = vc.size();
	for(int i = 0; i < len; i++)
	{
		res ^= vc[i];
	}
	int init = res;
	for(int i = 0; i < sizeof(int) * 8; i ++)
	{
		if((res & (1 << i)) != 0)
		{
			for(int j = 0; j < len; j++)
			{
				if((vc[j] & (1 << i)) != 0 )
					res ^= vc[j];
			}
			break;	
		}
	}
	vv[0] = res;
	vv[1] = res ^ init;
}

int main()
{
	int n, tmp;
	cin >> n;
	vector<int> vc(n);
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		vc[i] = tmp;
	}
	vector<int> vv(2, -1);
	findTwoSingleNum(vc, vv);
	cout << vv[0] << " " << vv[1] << endl;
	return 0;
}
	
