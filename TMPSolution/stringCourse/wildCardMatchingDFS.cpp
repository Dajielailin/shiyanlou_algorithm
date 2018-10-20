#include<string>
#include<iostream>

using namespace std;

/*
target: Implement wildcard pattern matching with support for '?' and '*'
solution: DFS
*/

bool isMatch(string & des, int i, string & sou, int j)
{
	if(i == des.size() || j == sou.size())
	{
		if(i == des.size() && j == sou.size())
			return true;
		else
			return false;
	}
	if(sou[j] == '*')
	{
		while(sou[j] == '*') j++;
		while(i <= des.size())
		{	
			if(isMatch(des, i++, sou, j))
				return true;
		}
		
	}
	else if(sou[j] == '?' || sou[j] == des[i])
		return isMatch(des, ++i, sou, ++j);
	else
		return false;

}

int main()
{
	string source, destination;
	getline(cin, destination);
	getline(cin, source);
	if(isMatch(destination, 0, source, 0))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}
