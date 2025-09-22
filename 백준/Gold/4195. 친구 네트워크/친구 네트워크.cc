#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_map>
using namespace std;

struct UnionFindSet {
    vector<int> parent, size;

    UnionFindSet(int n = 0) 
    {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int Find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = Find(parent[x]);
    }

    int Merge(int a, int b) {
        a = Find(a); 
        b = Find(b);

        if (a == b) 
            return size[a];
        
        if (size[a] < size[b]) 
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
        
        return size[a];
    }

    int sizeOf(int x) 
    { 
        return size[Find(x)]; 
    }
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int f;
        cin >> f;

        unordered_map<string, int> id(f * 2);

        UnionFindSet s(f * 2);
        int nextId = 0;

        for (int i = 0; i < f; ++i) {
            string a, b;
            cin >> a >> b;

            if (!id.count(a)) id[a] = nextId++;
            if (!id.count(b)) id[b] = nextId++;

            int sz = s.Merge(id[a], id[b]);
            cout << sz << '\n';
        }
    }
    return 0;
}