#include <string>
#include <cstring>
#include <vector>

using namespace std;

bool isVisited[50] = { false };

int differRate(string target, string word)
{
    int differ = 0;
    for (int i = 0, size = target.size(); i < size; ++i)
    {
        if (target[i] != word[i])
            ++differ;
    }
    return differ;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    int size = words.size();
    int word2Go = size;
    string next = begin;
    int nextIndex = -1;
    while (differRate(next, target) > 0)
    {
        if (word2Go == 0)
            return 0;

        ++answer;

        bool isFound = false;
        int maxDiffer = target.size();
        string temp = "";
        for (int i = 0; i < size; ++i)
        {
            if (isVisited[i])
                continue;

            if (differRate(next, words[i]) == 1)
            {
                int differ = differRate(target, words[i]);
                if (maxDiffer > differ)
                {
                    temp = words[i];
                    nextIndex = i;
                    maxDiffer = differ;
                    isFound = true;
                }
            }
        }

        if (isFound == false)
            return 0;

        isVisited[nextIndex] = true;
        next = temp;
        --word2Go;
    }

    return answer;
}
