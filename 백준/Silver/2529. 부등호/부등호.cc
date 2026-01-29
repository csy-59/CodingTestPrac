#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> maxV;
vector<int> minV;

bool isBigger(vector<int>& a, vector<int>& b)
{
	for (int i = 0; i < n + 1; ++i)
	{
		if (a[i] == b[i]) continue;
		return a[i] > b[i];
	}
	return false;
}

void bt(vector<char>& in, vector<int>& v, int isVisited)
{
	int size = v.size();
	if (size == n + 1)
	{
		if (isBigger(v, maxV))
			maxV = v;
		if (isBigger(minV, v)) 
			minV = v;
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		if ((isVisited & (1 << i)) != 0) continue;
		if (size != 0)
		{
			if (in[size - 1] == '<' && v[size - 1] > i) continue;
			else if (in[size - 1] == '>' && v[size - 1] < i) continue;
		}
	
 		v.push_back(i);
		bt(in, v, isVisited | 1 << i);
		v.pop_back();
	}
}

int main()
{
	cin >> n;

	maxV = vector<int>(n + 1, 0);
	minV = vector<int>(n + 1, 9);

	vector<char> in(n);
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		cin >> in[i];
	}

	bt(in, v, 0);

	for (int i = 0; i < n + 1; ++i)
	{
		cout << maxV[i];
	}
	cout << "\n";
	for (int i = 0; i < n + 1; ++i)
	{
		cout << minV[i];
	}

	return 0;
}