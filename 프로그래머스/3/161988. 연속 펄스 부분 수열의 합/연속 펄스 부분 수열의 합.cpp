#include <string>
#include <vector>

using namespace std;

long long GetMax(vector<long long>& arr)
{
    long long cur = arr[0];
    long long best = arr[0];
    
    for(int i = 1, size = arr.size(); i < size; ++i)
    {
        cur = max(arr[i], cur + arr[i]);
        best = max(best, cur);
    }
    
    return best;
}

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    int sequenceLength = sequence.size();
    
    vector<long long> plusSequence(sequenceLength, 0); // 1부터 시작하는 펄스 수열 곱하기
    vector<long long> minusSequence(sequenceLength, 0); // -1부터 시작하는 펄스 수열 곱하기
    
    int t = 1;
    for(int i = 0; i < sequenceLength; ++i)
    {
        plusSequence[i] = (long long)sequence[i] * t;
        minusSequence[i] = (long long)sequence[i] * -t;
        t *= -1;
    }
    
    answer = max(GetMax(plusSequence), GetMax(minusSequence));
    
    return answer;
}