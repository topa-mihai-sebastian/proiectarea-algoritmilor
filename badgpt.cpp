#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;

long long fibo1(long long n)
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
// log n
pair<long long, long long> fast_fibo(long long n)
{
	if (n == 0)
	{
		return {0, 1};
	}
	auto fibo = fast_fibo(n / 2);
	long long a = fibo.first, b = fibo.second;
	long long c = (a * ((2 * b) % MOD - a + MOD) % MOD) % MOD;
	long long d = ((a * a) % MOD + (b * b) % MOD) % MOD;

	if (n % 2 == 1)
	{
		return {d, (c + d) % MOD};
	}
	return {c, d};
}

long long fibo(long long n)
{
	return fast_fibo(n).second;
}

int main()
{
	ifstream fin("badgpt.in");
	ofstream fout("badgpt.out");
	long long result = 1;

	string s;
	getline(fin, s);
	// complexitate : s.size() * log(count)
	for (size_t i = 0; i < s.size();)
	{
		char c = s[i];
		if (c == 'm' || c == 'n' || c == 'w' || c == 'u')
		{
			i++;
			string numStr = "";

			while (i < s.size() && isdigit(s[i]))
			{
				numStr.push_back(s[i]);
				i++;
			}
			// folosesc stoll (string => long long)
			long long count = stoll(numStr);
			result = (result * fibo(count)) % MOD;
		}
		else
		{
			i++; // daca nu este n,m,w,u
		}
	}
	fout << result;
	fin.close();
	fout.close();
	return 0;
}
