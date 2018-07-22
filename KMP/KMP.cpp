#include<iostream>
#include<vector>
#include<string>

using namespace std;
#define NUM 1001

int Next[NUM];

void getNext(string &tar)
{
	Next[0]=-1;
	int i = 1;
	for(; i < tar.size(); ++i)
	{
		int t = Next[i-1];
		while(tar[t+1] != tar[i] && t > -1)
		{
			t = Next[t];
		}	
		if(tar[t+1] == tar[i])
			Next[i] = Next[t] +1;
		else
			Next[i] = -1;
	}	
}
int findTinS(string &sou, string &tar)
{
	if(sou.size() < tar.size())
		return -1;
	else
	{
		int l1=tar.size(), l2=sou.size();
		getNext(tar);
		int i=0,j=0;
		for(;j<l2;)
		{
			if(tar[i] == sou[j])
			{
				i++, j++;
				if(i == l1)
					return j-i;
			}
			else{
				if(i==0) ++j;
				else	i = Next[i-1] +1;
			}
			
		}
		return -1;
	}
	
}
int main()
{
	string source, target;
	cin >> source >>target;
	cout<<findTinS(source, target);	
	return 0;
}
