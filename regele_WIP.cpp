#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ifstream fin("regele.in");
	ofstream fout("regele.out");

	int N, Q;
	fin >> N;

	// Citim coordonatele orașelor (indexare de la 1)
	vector<int> coord(N + 1);
	for (int i = 1; i <= N; i++)
	{
		fin >> coord[i];
	}

	// Citim numărul de interogări
	fin >> Q;

	// dp[i][j] va reprezenta numărul minim de negustori necesari
	// pentru a activa rutele din intervalul [i,j] (1 ≤ i < j ≤ N)
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

	// Cazul de bază: orașe consecutive
	for (int i = 1; i < N; i++)
	{
		dp[i][i + 1] = coord[i + 1] - coord[i];
	}

	// Calculăm dp pentru fiecare segment de lungime >= 2
	// len reprezintă numărul de orașe din intervalul [i,j]
	for (int len = 2; len <= N; len++)
	{
		for (int i = 1; i + len - 1 <= N; i++)
		{
			int j = i + len - 1;
			// Costul de bază: activarea directă a rutei de la coord[i] la coord[j]
			dp[i][j] = coord[j] - coord[i];
			// Încercăm divizarea intervalului la un punct intermediar k
			for (int k = i + 1; k < j; k++)
			{
				dp[i][j] = min(dp[i][j], (coord[j] - coord[i]) + dp[i][k] + dp[k][j]);
			}
		}
	}

	// Preprocesăm costul pentru fiecare mărime X de bloc (X = număr de orașe active garantate)
	// Pentru un bloc de X orașe, costul necesar este maximul,
	// luat peste toate subintervalele continue de lungime X.
	// Pentru X = 1, costul este 0 (un singur oraș e întotdeauna activ).
	vector<int> cost(N + 1, 0);
	cost[1] = 0;
	for (int X = 2; X <= N; X++)
	{
		int worst = 0;
		for (int i = 1; i + X - 1 <= N; i++)
		{
			int j = i + X - 1;
			worst = max(worst, dp[i][j]);
		}
		cost[X] = worst;
	}

	// Răspundem la interogări:
	// pentru fiecare query, avem un număr M de negustori disponibili.
	// Răspunsul este cel mai mare X astfel încât cost[X] ≤ M.
	for (int q = 1; q <= Q; q++)
	{
		int merchants;
		fin >> merchants;
		int ans = 0; // cel puțin un oraș e întotdeauna activ
		for (int X = 1; X <= N; X++)
		{
			// Deoarece cost[X] este monoton (sau cel puțin nu scade), putem opri dacă costul depășește M.
			if (cost[X] <= merchants)
				ans = X;
			else
				break;
		}
		fout << ans << "\n";
	}

	fin.close();
	fout.close();
	return 0;
}
