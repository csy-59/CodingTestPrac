#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

bool solution(string s) {
    int size = s.size();
    if(size != 4 && size != 6)
        return false;
    
    for(int i = 0; i < size; ++i)
    {
        if(isdigit(s[i]) == 0)
        {
            return false;
        }
    }
    return true;
}