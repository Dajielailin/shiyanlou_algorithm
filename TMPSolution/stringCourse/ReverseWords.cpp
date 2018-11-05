#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void reverseWordsInString(string &str, string &result)
{
	int len=str.size();
	int pre, back;
	pre=back=len-1;
	while(pre>=0 && str[pre] == ' ')
		--pre, --back;
	string tmp;
	for(;pre>=0;)
	{
		while(pre>=0 && str[pre] != ' ')
			--pre;
		tmp = str.substr(pre+1, back-pre);
		result.append(tmp+" ");	
		while(pre>=0 && str[pre] == ' ')
			--pre;
		back=pre;
	}
	result.pop_back();
	
}
int main()
{
	string input, result;
	//cin>>input;  //cin is end at where there is a space, so the input is always the first word
	getline(cin, input);	//input the string with space
	//input = "the sky is blue ";
	reverseWordsInString(input, result);
	cout<<result<<endl;
	return 0;
}
