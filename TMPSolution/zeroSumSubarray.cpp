#include<iostream>
#include<map>
#include<vector>

using namespace std;
/*
* @param nums: An array of integers
* @return: A list of integers includes all the index of the first number and  the second number whose sum is zero
*/
vector<int> subArraySum0(vector<int> &vc)
{
	vector<int>res;
	if(vc.empty())
		return res;
	//use hashmap to improve the time efficiency of finding one sum
	map<int, int> hash;
	//when current sum == 0
	hash[0] = 0;
	int sum_t=0;
	for(int i=0; i<vc.size(); ++i)
	{
		sum_t += vc[i];
		if(hash.find(sum_t) != hash.end())
		{
			res.push_back(hash[sum_t]);
			res.push_back(i);
		}
		else	hash[sum_t] = i+1;
	}
	return res;
	
}
int main()
{
	vector<int> vc;
	int n, tmp;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>tmp;
		vc.push_back(tmp);
	}
	vector<int> res = subArraySum0(vc);
	for(auto it = res.begin(); it != res.end(); ++it)
		cout<<*it<<" ";
	cout<<endl;
	return 0;
}
