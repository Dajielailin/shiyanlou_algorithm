#include<iostream>
#include<string>

using namespace std;

int findLCS(string &s1, string &s2)
{
	if(s1.size()<1 || s2.size()<1)
		return 0;
	int len, tmp_len;
	len=tmp_len=0;
	for(int i=0;i<s1.size();++i)
	{
		for(int j=0;j<s2.size();++j)
		{
			tmp_len =0;
			while(i+tmp_len<s1.size() && j+tmp_len<s2.size())
			{
				if(s1[i+tmp_len] == s2[j+tmp_len])
					tmp_len++;
				else
					break;		
			}
			if(tmp_len > len)
				len = tmp_len;
		}
	}
	return len;
}
int main()
{
	string s1, s2;
	cin>>s1>>s2;
	cout<<findLCS(s1, s2)<<endl;
	return 0;
}
