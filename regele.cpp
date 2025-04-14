#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ifstream fin("regele.in");
	ofstream fout("regele.out");
	int N, Q, M, X;
	fin >> N;
	vector<int> coord(N + 2, -1);
	for (int i = 1; i <= N; i++)
	{
		fin >> coord[i];
	}
	fin >> Q;
	// distanta e coord[i+1] - coord[i]

	fin.close();
	fout.close();
	return 0;
}
