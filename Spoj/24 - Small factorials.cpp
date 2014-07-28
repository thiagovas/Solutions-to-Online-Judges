#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;
// http://www.spoj.com/problems/FCTRL2/

string itos(long long int input)
{
	stringstream ss;
	ss << input;
	return ss.str();
}

int atoi(char input)
{
	return input-'0';
}

string mul(string a, string b)
{
	string result(max(a.size(), b.size())+2, '0');
	int inicio=result.size()-1;
	for(int i = b.size()-1; i >= 0; i--)
	{
		int vai=0;
		int k=inicio;
		for(int j = a.size()-1; j >= 0; j--)
		{
			int temp = atoi(b[i])*atoi(a[j])+atoi(result[k])+vai;
			result[k] = (temp%10)+'0';
			vai = temp/10;
			k--;
		}
		result[k] = atoi(result[k])+vai+'0';
		inicio--;
	}

	for(int i = 0; i < result.size(); i++)
	{
		if(result[i] == '0') result.erase(result.begin()+i--);
		else break;
	}
	return result;
}

int main()
{
	vector<string> fat(1, "1");
	long long int temp=1;
	int t, input;

	for(int i = 1; i <= 20; i++)
	{
		temp*=i;
		fat.push_back(itos(temp));
	}
	
	for(int i = 21; i < 101; i++)
	{
		string neue = mul(*fat.rbegin(), itos(i));
		fat.push_back(neue);
	}
	
	cin >> t;
	while(t-- > 0)
	{
		cin >> input;
		cout << fat[input] << endl;
	}
	
	return 0;
}

