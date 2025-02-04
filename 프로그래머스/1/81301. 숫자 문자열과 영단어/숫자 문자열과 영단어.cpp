#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string numbers[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for(int i = 0; i < 10; ++i)
    {
        while(true)
        {
            auto iter = s.find(numbers[i]);
            if(iter == string::npos)
                break;
            
            s.replace(iter, numbers[i].length(), to_string(i));
        }
    }
    
    return stoi(s);
}