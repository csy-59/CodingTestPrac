#include <string>
#include <cmath>

using namespace std;

bool IsPrime(long long num)
{
    if(num < 2) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;

    for(long long i = 3; i * i <= num; i += 2)
    {
        if(num % i == 0) return false;
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;

    string converted = "";

    while(n > 0)
    {
        converted.insert(0, 1, '0' + (n % k));
        n /= k;
    }

    string t = "";

    for(char c : converted)
    {
        if(c == '0')
        {
            if(!t.empty())
            {
                if(IsPrime(stoll(t))) answer++;
                t = "";
            }
        }
        else
        {
            t.push_back(c);
        }
    }

    if(!t.empty())
    {
        if(IsPrime(stoll(t))) answer++;
    }

    return answer;
}