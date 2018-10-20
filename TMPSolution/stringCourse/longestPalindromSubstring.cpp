#include<string>
#include<vector>
#include<iostream>

using namespace std;

string longestPalinSubstr(string & tt, vector<int> & pp, string & input)
{
	string res;
	if(input.empty())
		return res;
	int left, right, center, ii;
	left = 0;
	right = 2;
	center = 1;
	pp[1] = 1;
	for(int i = 2; i < pp.size(); i++)
	{
		ii = 2 * center - i;
		if(pp[ii] < right - i)
			pp[i] = pp[ii];
		else
		{
			left = 2 * i - right - 1;
			right++;
			while(left >= 0 && right < tt.size() && tt[left] == tt[right])
				left--, right++;
			left++, right--;
			pp[i] = right - i;
			center = i;
		}
	}
	int index = 1, max = 1;
	for(int i = 2; i < pp.size(); i++)
	{
		if(pp[i] > max)
		{
			index = i;
			max = pp[i];
		}
	}
	res = index > 1 ? input.substr(index/2 - max/2, max) : input.substr(0, 1);
	return res;
}

int main()
{
	string input, tmpIn;
	getline(cin, input);
	vector<int> palinLen(2*input.size()+1, 0);
	for(int i =0 ; i < input.size(); i++)
	{
		tmpIn.push_back('#');
		tmpIn.push_back(input[i]);
	}
	tmpIn.push_back('#');
	cout << longestPalinSubstr(tmpIn, palinLen, input) << endl;
	return 0;

}
