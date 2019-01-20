/*
*@param : Given an array of integers and a numebr k
*@return : Find the numebr which occurs more than 1/k of the size of teh array.
*@requirement: O(n) time and O(k) eatra space.
*/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int findKMajorityNum(vector<int> &vc, int k)
{
	unordered_map<int, int> help;
	for(auto num : vc)
	{
		if(help.size() < k)
		{
			help[num]++;
		}
		else
		{
			if(help.count(num) == 1)
				help[num]++;
			else
			{
				help[num] = 1;
				vector<int> tmp;
				for(auto &it: help)
				{
					it.second--;
					if(it.second == 0)
						tmp.push_back(it.first);
				}
				for(auto it : tmp)
					help.erase(it);
			}
		}
	}
	int max = 0;
	int res = 0;
	for(auto &it : help)
	{
		if(it.second > max)
		{
			max = it.second;
			res = it.first;
		}
	}
	return res;

}

int main()
{
	int n, k, tmp;
	cin >> n >> k;
	vector<int> vc(n);
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		vc[i] = tmp;
	}
	cout << findKMajorityNum(vc, k);
	return 0;
}
