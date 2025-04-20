#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

long long N, K;
vector<long long> weights;

bool isPossible(long long maxCost)
{
	long long farriesUsed = 1, currentSum = 0;
	for (auto weight : weights)
	{
		if (weight > maxCost)
		{
			return false;
		}
		if (weight + currentSum > maxCost)
		{
			farriesUsed++;
			currentSum = weight;
			if (farriesUsed > K)
			{
				return false;
			}
		}
		else
		{
			currentSum += weight;
		}
	}
	return true;
}

long long findMinCost()
{
	long long left = 0, right = 0, mid, result = 0;
	for (auto weight : weights)
	{
		right += weight;
	}
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (isPossible(mid))
		{
			result = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return result;
}

int main()
{
	ifstream fin("feribot.in");
	ofstream fout("feribot.out");

	fin >> N >> K;
	weights.resize(N);
	for (long long i = 0; i < N; i++)
	{
		fin >> weights[i];
	}

	fout << findMinCost() << endl;

	fin.close();
	fout.close();
	return 0;
}
