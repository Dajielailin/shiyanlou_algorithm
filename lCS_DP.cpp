#include<iostream>
#include<string>

using namespace std;
#define NUM 101
int dp[NUM][NUM];

int findLCS(string &s1, string &s2)
{
	if(s1.empty() || s2.empty())
		return 0;
	int i, j;
	for(i=0;i<s1.size();++i)
	{
		for(j=0;j<s2.size();++j)
		{
			if(s1[i] == s2[j])
				dp[i+1][j+1] =dp[i][j] +1;
			else	dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
		}
	}	
	return dp[i][j];
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<findLCS(s1, s2)<<endl;
	return 0;
}
