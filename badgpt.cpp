#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;

long long int fibo1(long long int n)
{
	long long int a = 0, b = 1;
	long long aux;
	for (long long int i = 1; i <= n; i++)
	{
		aux = b;
		b = b + a;
		b = b % MOD;
		a = aux;
	}
	return b;
}

pair<long long, long long> fiboPair(long long n)
{
	if (n == 0)
		return {0, 1};
	auto p = fiboPair(n >> 1);
	long long a = p.first, b = p.second;
	long long c = (a * ((2 * b % MOD + MOD - a) % MOD)) % MOD;
	long long d = ((a * a) % MOD + (b * b) % MOD) % MOD;
	if (n & 1)
		return {d, (c + d) % MOD};
	else
		return {c, d};
}

long long fibo(long long n)
{
	return fiboPair(n).second;
}

int main()
{
	ifstream fin("badgpt.in");
	ofstream fout("badgpt.out");
	long long result = 1;

	string s;
	getline(fin, s); // citim întreaga linie

	for (size_t i = 0; i < s.size();)
	{
		char c = s[i];
		// procesăm doar caracterele m,n,w,u
		if (c == 'm' || c == 'n' || c == 'w' || c == 'u')
		{
			i++; // trecem la cifrele de după caracter
			string numStr = "";
			// citim toate cifrele imediat consecutive
			while (i < s.size() && isdigit(s[i]))
			{
				numStr.push_back(s[i]);
				i++;
			}
			// reverse(numStr.begin(), numStr.end());
			//  convertim șirul de cifre în număr
			long long count = stoll(numStr);
			result = (result * fibo(count)) % MOD;
		}
		else
		{
			i++; // dacă caracterul nu e unul din cele care ne interesează, continuăm
		}
	}
	fout << result;
	fin.close();
	fout.close();
	return 0;
}