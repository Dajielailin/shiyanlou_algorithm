/*
* @param numbers : An Array of Integers
* @param sum : 0 
* @return : a set, include all the possible triplets in the array which gives the sum of z* ero.
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool cmp_const(const int& x, const int& y)
{
	return x > y;
}

set<vector<int> > findTripletsSum0(vector<int> sou)
{
	set<vector<int> > tripSets;
	int length = sou.size();
	if(length == 0)
		return tripSets;
	unordered_multiset<int > hash;
	for(int i =0; i < length; i++)
	{
		hash.clear();
		for(int j = i+1; j < length; j++)
		{
			auto it = hash.find(0 - sou[i] - sou[j]); 
			if(it != hash.end())
			{
				vector<int> vc(3);
				vc[0] = sou[i];
				vc[1] = sou[j];
				vc[2] = *it;
				sort(vc.begin(), vc.end(), cmp_const);
				tripSets.insert(vc);
				hash.erase(it);
			}
			else
			{
				hash.insert(sou[j]);
			}
		}		
	}
	return tripSets;
}

int main()
{
	int num, tmp;
	cin >> num;
	vector<int> source(num);
	for(int i =0; i < num; i++)
	{
		cin >> tmp;
		source[i] = tmp;
	}	
	set<vector<int> > result = findTripletsSum0(source);
	for(auto &vc : result)
	{
		for(auto &element : vc)
		{
			cout << element << " ";
		}
		cout << endl;
	}
	return 0;
}
