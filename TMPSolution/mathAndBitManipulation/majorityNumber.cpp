/*
*@param : Given an array of integers
*@return : the majority number is the number that occurs more than 1/3* of the size of the array. Find it.
*@requirement: O(n) time and O(1) extra space.
*/
#include<iostream>
#include<vector>

using namespace std;

int findMajorityNum(vector<int> &vv)
{
	if(vv.empty())
		return -1;
	int fir, sec, count_fir, count_sec;
	fir = sec = -1;
	count_fir = count_sec = 0;
	for(auto num : vv)
	{
		if(!count_fir)	
			fir = num;
		else if(!count_sec && fir != num)
			sec = num;
		if(fir == num)	
			count_fir++;
		else if(sec == num)	 
			count_sec++;
		else
			count_fir--, count_sec--;
	}
	if(count_fir > count_sec)
		return fir;
	else if(count_fir < count_sec)
		return sec;
	return -1;
}

int main()
{
	int n, tmp;
	cin >> n;
	vector<int> vc(n);
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		vc[i] = tmp;
	}
	cout << findMajorityNum(vc) << endl;
	return 0;
}
