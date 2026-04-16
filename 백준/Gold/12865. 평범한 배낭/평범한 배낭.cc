#include <iostream>
#include <algorithm>
using namespace std;
int item[101][2] = { 0 };
int D[101][100001] = { 0 };

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> item[i][0] >> item[i][1];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			D[i][j] = D[i - 1][j];
			if (j - item[i][0] >= 0) {
				D[i][j] = max(D[i][j], D[i - 1][j - item[i][0]] + item[i][1]);
			}
		}
	}

	cout << D[n][k];

	return 0;
}