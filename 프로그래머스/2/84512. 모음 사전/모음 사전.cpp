#include <string>
#include <vector>

using namespace std;

int GetIndex(char a)
{
    switch(a)
    {
        case 'A': return 0;
        case 'E': return 1;
        case 'I': return 2;
        case 'O': return 3;
        case 'U': return 4;
    }
}

int solution(string word) {
    int answer = 1;
    
    char letters[5] = {'A', 'E', 'I', 'O', 'U'};
    
    string temp = "A";
    
    while(word.compare(temp) != 0)
    {
        if(temp.length() < 5)
        {
            temp.push_back('A');
        }
        else
        {
            while(temp.length() > 0 && GetIndex(temp.back()) == 4)
            {
                temp.pop_back();
            }
            
            if(temp.length() == 0)
            {
                temp.push_back('A');
            }
            else
            {
                char nextLetter = letters[GetIndex(temp.back()) + 1];
                temp.pop_back(); temp.push_back(nextLetter);
            }
        }
        
        ++answer;
    }
    
    return answer;
}