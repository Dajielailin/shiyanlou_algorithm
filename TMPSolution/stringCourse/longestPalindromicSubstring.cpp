#include<iostream>
#include<string>

using namespace std;

string palinSubstring(string &tar, int l, int r)
{
	while(l>=0 && r<tar.size() && tar[l]==tar[r])
		--l, ++r;
	return tar.substr(l+1, r-l-1);
}
string findLPS(string &tar)
{
	string tmp, res;
	for(int i=0; i<tar.size();++i)
	{
		tmp = palinSubstring(tar, i, i);
		if(tmp.size() > res.size())
			res = tmp;
		tmp = palinSubstring(tar, i, i+1);
		if(tmp.size() > res.size())
			res = tmp;
	
	}
	return res;	
}
int main()
{
	string target;
	cin>>target;
	cout<<findLPS(target)<<endl;
	return 0;
}
