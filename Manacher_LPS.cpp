#include<iostream>
#include<string>
#include<vector>

#define NUM 1001
using namespace std;

string manacherLPS(string &tar, string &T, vector<int> &P)
{
	string res;
	if(tar.empty())
		return res;
	int L=0, R=2, c=1, ii, l, r;
	for(int i=2; i<T.size(); ++i)
	{
		ii = 2*c-i;
		if(P[ii]+i < R)
			P[i] = P[ii];
		else
		{
			l=2*i-R-1;
			r=R+1;
			while(l>=0 && r<T.size() && T[l]==T[r])
				--l, ++r;
			c=i, L=l+1, R=r-1;
			P[i] = R-c;
		}
	} 
	int index=0, max=0;
	for(int i=0; i<P.size(); ++i)
	{
		if(P[i] > max)
			index = i, max = P[i];
	}
	int start = index/2 - max/2;
	res = tar.substr(start, max);
	return res;
}
int main()
{
	string target, T;
	cin>>target;
	vector<int> P(target.size()*2+1, 0);
	P[1] = 1;	
	for(int i=0; i<target.size(); ++i)
	{
		T.push_back('#');
		T.push_back(target[i]);
	}
	T.push_back('#');
	cout<<manacherLPS(target, T, P)<<endl;
	return 0;
}

