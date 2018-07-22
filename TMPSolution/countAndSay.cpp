#include<iostream>
#include<string>

using namespace std;

//Given an integer n, generate the nth sequence
//the nth sequence is relevant with the (n-1)th sequence
//for example, the first sequnece is "1" ,the 2thsequence is "the num of 1"+"1" = "11"
string countAndSay(int n)
{
	if(n == 0)	return "";
	string res, tmp;
	int count;
 	res = "1";
	for(int i=2; i<=n; ++i)
	{
		tmp = "";
		for(int j=0; j<res.size();++j )
		{
			count = 1;
			while(j+1 < res.size() && res[j] == res[j+1])
				count++, j++;
			tmp.push_back(count+'0');
			tmp.push_back(res[j]);
		}
		res = tmp;
	}
	return res;
}
int main()
{
	int n;
	cin>>n;
	//string res = countAndSay(n);
	cout<<countAndSay(n)<<endl;
	return 0;
}
