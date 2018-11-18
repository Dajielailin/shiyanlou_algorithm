/*
*@param A : a list of integers
*@target: remove Duplicates, the duplicates are allow at most twice
*@target: the solution should be O(n) time , O(1) space
*@return: the removed array, and its length.
*/
#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> & vc)
{
	if(vc.size() < 3)
		return vc.size();
	int realIndex = 1;
	for(int i = 2; i < vc.size(); i++)
	{
		if(vc[i] != vc[realIndex] || vc[i] != vc[realIndex-1])
		{
			realIndex++;
			vc[realIndex] = vc[i];
		}
	}
	return realIndex +1;
}
int main()
{
	int num, tmp;
	cin >> num;
	vector<int> vc1(num);
	for(int i= 0; i < num; i++)
	{
		cin >> tmp;
		vc1[i] = tmp;
	}
	int len = removeDuplicates(vc1);
	for(int i =0; i < len; i++)
	{
		cout << vc1[i] << " ";
	}
	cout << endl;
}
