#include <iostream>
#include <utility>
#include <queue>
#include <tuple>
using namespace std;

int n, m, h;

int grid[100][100][100] = { 0 };
std::queue<std::tuple<int, int, int>> tomato;

int notRipCount;
int result = 0;

void BFS()
{
	static const int addX[] = { -1,1,0,0,0,0 };
	static const int addY[] = { 0,0,-1,1,0,0 };
	static const int addZ[] = { 0,0,0,0,-1,1 };

	int newx, newy, newz;
	while (tomato.empty() == false)
	{
		const int size = tomato.size();
		for (int count = 0; count < size; ++count)
		{
			std::tuple data = tomato.front();
			int z = std::get<0>(data);
			int x = std::get<1>(data);
			int y = std::get<2>(data);
			tomato.pop();

			for (int i = 0; i < 6; ++i)
			{
				newz = z + addZ[i];
				newx = x + addX[i];
				newy = y + addY[i];

				if (newx < 0 || newx > n - 1 || newy < 0 ||
					newy > m - 1 || newz < 0 || newz > h - 1)
					continue;

				if (grid[newz][newx][newy] != 0)
					continue;

				tomato.push({ newz, newx, newy });
				grid[newz][newx][newy] = 1;

				--notRipCount;
			}
		}
		++result;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
	cin >> m >> n >> h;

	notRipCount = n * m * h;

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				cin >> grid[i][j][k];
				if (grid[i][j][k] == -1)
				{
					--notRipCount;
				}
				else if (grid[i][j][k] == 1)
				{
					--notRipCount;
					tomato.emplace(i, j, k);
				}
			}
		}
	}

	BFS();

	if (notRipCount <= 0)
	{
		cout << result - 1;
	}
	else
	{
		cout << "-1";
	}

	return 0;
}