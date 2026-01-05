#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> trees;

    double totalCount = 0;
    string t;
    while (getline(cin, t))
    {
        if (trees.find(t) == trees.end())
        {
            trees[t] = 1;
        }
        else ++trees[t];

        totalCount += 1;
    }

    cout << fixed;
    cout.precision(4);
    for (auto iter = trees.begin(); iter != trees.end(); ++iter)
    {
        double p = (*iter).second / totalCount * 100;
        cout << (*iter).first << " " << p << "\n";
    }

    return 0;
}