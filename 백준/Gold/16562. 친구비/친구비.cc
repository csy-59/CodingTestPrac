#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    vector<int> pay;
    vector<int> parent;
    int size;

    UnionFind(int size): size(size)
    {
        pay = vector<int>(size, 0);
        parent = vector<int>(size, -1);
    }

    int GetParentIndex(int n)
    {
        if (parent[n] == -1 || parent[n] == n)
        {
            parent[n] = n;
            return n;
        }

        return GetParentIndex(parent[n]);
    }

    int GetParentPay(int n)
    {
        return pay[GetParentIndex(n)];
    }

    void SetParent(int n, int p)
    {
        parent[n] = p;

        for (int i = 0; i < size; ++i)
        {
            if (parent[i] == n)
                parent[i] = p;
        }
    }

    int GetMinTotal()
    {
        vector<bool> isVisited(size, false);

        int result = 0;
        for (int i = 0; i < size; ++i)
        {
            int pindex = GetParentIndex(i);
            if (isVisited[pindex] == false)
            {
                isVisited[pindex] = true;
                result += pay[pindex];
            }
        }

        return result;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    UnionFind ufind(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> ufind.pay[i];
    }

    for (int i = 0; i < m; ++i)
    {
        int v, w;
        cin >> v >> w;

        int vP = ufind.GetParentIndex(v - 1);
        int wP = ufind.GetParentIndex(w - 1);

        // 이미 같은 친구를 둠
        if (vP == wP)
        {
            continue;
        }

        if (ufind.pay[vP] >= ufind.pay[wP])
        {
            ufind.SetParent(vP, wP);
        }
        else
        {
            ufind.SetParent(wP, vP);
        }
    }

    int result = ufind.GetMinTotal();
    if (result > k)
        cout << "Oh no";
    else
        cout << result;

	return 0;
}