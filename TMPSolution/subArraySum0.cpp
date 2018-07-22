#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> subArraySum0(vector<int> &vc)
{
	vector<int> res;
	if(vc.empty())
		return res;
	const int len = vc.size();
	//sum[0] = (0, 0), considering the start index is 0
	//the first element of pair is the sum of vc[0]-vc[i], the second element is the ravelant index
	vector<pair<int, int>> sum(len+1);
	for(int i=0;i<len;++i)
	{
		sum[i+1].first = vc[i] + sum[i].first;
		sum[i+1].second = i+1;
	}	
	//firstly, sort by the sum; secondly, sort by the index
	sort(sum.begin(), sum.end());
	for(int i=1;i<len+1;++i)
	{
		if(sum[i].first == sum[i-1].first)
		{
			res.push_back(sum[i-1].second);
			res.push_back(sum[i].second-1);
		}
	}
	return res;
}
int main()
{
	int n, tmp;
	cin>>n;
	vector<int> vc(n);
	for(int i=0;i<n;++i)
	{
		cin>>tmp;
		vc[i] = tmp;	
	}
	vector<int> res = subArraySum0(vc);
	for(auto it = res.begin();it != res.end();++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}
