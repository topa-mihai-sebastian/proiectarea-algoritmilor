#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("stocks.in");
	ofstream fout("stocks.out");
	int N, B, L;
	fin >> N >> B >> L;
	int profit = 0;
	// luam pe coloane
	// prima coloana =1 pret initial samd.
	vector<int> current_price(N + 1), min_price(N + 1), max_price(N + 1);
	for (int i = 1; i <= N; i++)
	{
		fin >> current_price[i] >> min_price[i] >> max_price[i];
	}
	// dp[i][j] buget cheltui i si pierderi maxime j => profit maxim
	vector<vector<int>> dp(B + 1, vector<int>(L + 1, 0));

	// pt fiecare actiune
	for (int i = 1; i <= N; i++)
	{
		// pornim de la intregul buget initial
		for (int buget = B; buget >= 0; buget--)
		{
			for (int loss = 0; loss <= L; loss++)
			{
				int current_cost = current_price[i];
				if (buget + current_cost <= B)
				{
					int new_used = buget + current_cost;
					// pierderea deja acumulata plus noua pierdere
					int new_loss = loss + (current_cost - min_price[i]);
					if (new_loss <= L)
					{
						int current_stock = dp[buget][loss] + max_price[i];
						dp[new_used][new_loss] = max(dp[new_used][new_loss], current_stock);
					}
				}
			}
		}
	}

	// aflam maximul
	for (int buget = 0; buget <= B; buget++)
	{
		for (int loss = 0; loss <= L; loss++)
		{
			int partial_res = dp[buget][loss] - buget;
			profit = max(profit, partial_res);
		}
	}
	fout << profit;
	fin.close();
	fout.close();
}