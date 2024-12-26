#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int c1Size = cards1.size();
    int c2Size = cards2.size();
    int c1Index = 0;
    int c2Index = 0;
    
    for(int i = 0, size = goal.size(); i < size; ++i)
    {
        if(c1Index < c1Size && goal[i].compare(cards1[c1Index]) == 0)
        {
            ++c1Index;
        }
        else if(c2Index < c2Size && goal[i].compare(cards2[c2Index]) == 0)
        {
            ++c2Index;
        }
        else
        {
            return "No";
        }
    }
    
    return "Yes";
}