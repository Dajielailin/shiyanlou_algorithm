#include<iostream>
#include<string>

using namespace std;

bool dfs_help(string &s, int si, string &p, int sj)
{
	//index out of range check
	if(si == s.size() || sj == p.size())
	{
		if(si == s.size() && sj == p.size())
			return true;
		else	return false;
	}
	if( p[sj] == '*')	
	{	
		while(++sj < p.size() && p[sj] == '*')
			;
		if(sj == p.size())	return true;
		//compare remaining part of p after * with s
		while(!dfs_help(s, si, p, sj) && si<s.size())
			si++;
		//substring of p equals to s, return true, or return false
		return si != s.size();
	}
	else if(p[sj] == '?' || p[sj] == s[si])
	{	
		dfs_help(s, si+1, p, sj+1);
	}
	else
	{	return false;}
}
bool patternMatch(string &s, string &p)
{
	if(s.empty() || p.empty())
		return false;
	return dfs_help(s, 0, p, 0);
}
int main()
{
	string s, p;
	cin>>s>>p;
	cout<<(patternMatch(s, p) ? "True" : "False")<<endl;
	return 0;
}
