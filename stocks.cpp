#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ifstream fin("stocks.in");
	ofstream fout("stocks.out");
	int profit = 0;
	int N, B, L;
	fin >> N >> B >> L;
	vector<int> buy_price(N + 1), min_sell_price(N + 1), max_sell_price(N + 1);
	for (int i = 1; i <= N; i++)
	{
		fin >> buy_price[i] >> min_sell_price[i] >> max_sell_price[i];
	}
	vector<vector<int>> dp(B + 1, vector<int>(L + 1, 0));

	for (int i = 1; i <= N; i++)
	{
		for (int used = B; used >= 0; used--)
		{
			for (int loss = 0; loss <= L; loss++)
			{
				// daca imi permit sa cumpar
				if (used + buy_price[i] <= B)
				{
					int new_used = used + buy_price[i];
					int new_loss = loss + (buy_price[i] - min_sell_price[i]);

					// daca nu depasesc pierderea maxima
					if (new_loss <= L)
					{
						// daca cumpar
						int aux = dp[used][loss] + max_sell_price[i];

						dp[new_used][new_loss] = max(dp[new_used][new_loss], aux);
					}
				}
			}
		}
	}

	for (int used = 0; used <= B; used++)
	{
		for (int loss = 0; loss <= L; loss++)
		{
			int aux = dp[used][loss] - used;
			profit = max(profit, aux);
		}
	}
	fout << profit;
	fin.close();
	fout.close();
	return 0;
}