#include <iostream>
#include <string>

using namespace std;

string reverseWords(string& inStr)
{
	string res;
	if(!inStr.empty())
	{
		string tmp;
		int start, end;
		start = end = inStr.size() - 1;
		for(int rindex = end; rindex >= 0; rindex--)
		{
			if(inStr[rindex] != ' ')
			{
				start--;
			}
			else
			{
				if(start != end)
				{
					tmp = inStr.substr(start+1, end-start);
					res += tmp;
					end = start;
				}
				end--, start--;
			}
		}
		if(start != end)
		{
			tmp = inStr.substr(start+1, end-start);
			res += tmp;
			end = start;
		}
		
	}
	return res;
}

int main()
{
	string input, output;
	getline(cin, input);
	output = reverseWords(input);
	cout << output;
	return 0;
}
