#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> isPrime(101, true);
vector<int> primes;

void SearchPrime(int a)
{
    for(int i = 2; i <= a; ++i)
    {
        if(isPrime[i] == false)
            continue;
        
        primes.push_back(i);
        for(int j = i + i; j <= a; j = j + i)
        {
            isPrime[j] = false;
        }
    }
}

int solution(vector<int> arr) {
    primes.push_back(1);
    int max = 0;
    for(int i = 0 ; i < arr.size(); ++i)
    {
        if(arr[i] > max)
            max = arr[i];
    }
    
    SearchPrime(max);
    
    int ans = 1;
    for(int i = 1 ; i < primes.size(); ++i)
    {
        int maxCount = 0;
        for(int j = 0; j < arr.size(); ++j)
        {
            int temp = 0;
            int curNum = arr[j];
            while(curNum > 1)
            {
                if(curNum % primes[i] != 0)
                    break;
                curNum /= primes[i];
                ++temp;
            }
            
            if(temp > maxCount)
            {
                maxCount = temp;
            }
        }
        
        if(maxCount == 0)
            continue;
        
        while(maxCount > 0)
        {
            ans *= primes[i];
            --maxCount;
        }
    }
    
    
    return ans;
}