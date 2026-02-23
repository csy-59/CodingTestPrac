#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Score
{
public:
    string name;
    int kor;
    int eng;
    int math;

    Score() : name(""), kor(0), eng(0), math(0) {}
    Score(string name, int kor, int eng, int math)
    {
        Set(name, kor, eng, math);
    }

    void Set(string name, int kor, int eng, int math)
    {
        this->name = name;
        this->kor = kor;
        this->eng = eng;
        this->math = math;
    }

    static int cmp(const Score& a, const Score& b)
    {
        if (a.kor != b.kor)
            return a.kor > b.kor;

        if (a.eng != b.eng)
            return a.eng < b.eng;

        if (a.math != b.math)
            return a.math > b.math;

        return a.name < b.name;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Score> v(n);
    for (int i = 0; i < n; ++i)
    {
        string name; int kor, eng, math;
        cin >> name >> kor >> eng >> math;
        v[i].Set(name, kor, eng, math);
    }

    sort(v.begin(), v.end(), Score::cmp);

    for (int i = 0; i < n; ++i)
    {
        cout << v[i].name << "\n";
    }

    return 0;
}