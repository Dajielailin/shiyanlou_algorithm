/*
*@course source: https://www.shiyanlou.com/courses/running
*@param num: Given a string as a key and the size of hash table.
Hash function is used to convert a string into an integer smaller than hash size and bigger or equal to zero. A widely used hash function algorithm is using a magic number 33, consider any string as a 33 based big integer like follow:
hashcode("abcd") = (ascii(a) * 33^3 + ascii(b)*33^2 + ascii(c)*33^1 + ascii(d)) % hash_size
*@return : the hash value of this key.
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

long long pow(int base, int num, int mod)
{
	if(num == 0)
		return 1;
	else if(num == 1)
		return base;
	else if(num % 2 == 0)
	{
		long long tmp = pow(base, num/2, mod);
		return (tmp % mod) * (tmp % mod);
	}
	else
	{
		return (base % mod) * (pow(base, num-1, mod) % mod);
	}
}

int hashFunc(string &key, int mod)
{
	int len = key.size();
	if(len == 0)
		return 0;
	long long res = 0;
	for(int i = 0; i < len; i++)
	{
		res += (key[i]) * pow(33, len-1-i, mod);
		res %= mod;
	}
	return (int)(res % mod);
}

int main()
{
	string key;
	int size;
	cin >> key >> size;
	cout << hashFunc(key, size) << endl;	
	return 0;
}
