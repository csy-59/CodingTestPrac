#include <iostream>
#include <vector>

using namespace std;

string solution(vector<string>& v, int size, int startX, int startY)
{
	string num(1, v[startX][startY]);
	if (size <= 1)
		return num;

	bool isAllSame = true;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (v[startX + i][startY + j] != num[0])
			{
				isAllSame = false;
				break;
			}
		}
		if (isAllSame == false) break;
	}

	if (isAllSame)
	{
		return num;
	}

	int newSize = size / 2;
	num = "(";
	num += solution(v, newSize, startX, startY);
	num += solution(v, newSize, startX, startY + newSize);
	num += solution(v, newSize, startX + newSize, startY);
	num += solution(v, newSize, startX + newSize, startY + newSize);
	num += ")";

	return num;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<string> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	cout << solution(v, n, 0, 0);

	return 0;
}