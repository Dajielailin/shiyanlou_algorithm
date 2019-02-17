/*
*@param : int munber k
*@return : the Kth ugly number, ugly number is a number that only have factors 3, 5 and 7
*@requirement : O(k) time.
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long findKthUglyNumber(int k)
{
	if(k < 1)
		return -1;
	vector<long long> vc(k+1);
	vc[0] = 1;
	int index = 0, index3 = 0, index5 = 0, index7 = 0;
	long long  minTmp;
	while(index < k)
	{
		minTmp = min(vc[index3] * 3, vc[index5] * 5);
		minTmp = min(vc[index7] * 7, minTmp);

		if(minTmp == vc[index3] * 3) index3++;
		if(minTmp == vc[index5] * 5) index5++;
		if(minTmp == vc[index7] * 7) index7++;
		
		vc[++index] = minTmp;
	}
	return vc[k];
}

int main()
{
	int k;
	cin >> k;
	cout << findKthUglyNumber(k) << endl;
	return 0;
}
