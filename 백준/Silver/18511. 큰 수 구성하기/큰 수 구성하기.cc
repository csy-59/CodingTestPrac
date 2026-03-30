#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, K;
vector<int> digits;
int answer = 0;

void dfs(string current)
{
    if (!current.empty())
    {
        int num = stoi(current);
        if (num <= N)
            answer = max(answer, num);
    }

    if (current.length() > to_string(N).length())
        return;

    for (int i = 0; i < K; ++i)
    {
        dfs(current + char(digits[i] + '0'));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    digits.resize(K);
    for (int i = 0; i < K; ++i)
        cin >> digits[i];

    dfs("");

    cout << answer;
    return 0;
}