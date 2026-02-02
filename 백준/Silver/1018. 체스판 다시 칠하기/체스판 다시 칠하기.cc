#include <iostream>
using namespace std;

int main(void)
{

	int n, m;
	cin >> n >> m;

	string* arr = new string[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	string check[2] = { "BWBWBWBW", "WBWBWBWB" };

	int min = 82;

	for (int row = 0; row <= n - 8; ++row)
	{
		for (int colum = 0; colum <= m - 8; ++colum)
		{
			int blackChange = 0;
			int whiteChange = 0;

			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (blackChange <= min)
					{
						if (arr[row + i][colum + j] != check[i % 2][j])
						{
							blackChange++;
						}
					}

					if (whiteChange <= min)
					{
						if (arr[row + i][colum + j] != check[(i + 1) % 2][j])
						{
							whiteChange++;
						}
					}
					
				}
			}

			if (min > blackChange)
			{
				min = blackChange;
			}

			if (min > whiteChange)
			{
				min = whiteChange;
			}
		}
	}

	cout << min;

	delete[] arr;

	return 0;
}