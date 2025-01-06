#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    int first[5] = {1,2,3,4,5};
    int second[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int third[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> answer;
    
    int f_count = 0, s_count = 0, t_count = 0;
    int f_index = 0, s_index = 0, t_index = 0;
    
    for(int i = 0, size = answers.size(); i < size; ++i)
    {
        int a = answers[i];
        f_count += first[f_index] == a ? 1 : 0;
        s_count += second[s_index] == a ? 1 : 0;
        t_count += third[t_index] == a ? 1 : 0;
        
        f_index = (f_index + 1) % 5;
        s_index = (s_index + 1) % 8;
        t_index = (t_index + 1) % 10;
    }
    
    int max = f_count > s_count ? f_count : s_count;
    max = t_count > max ? t_count : max;
    
    if(f_count == max) answer.push_back(1);
    if(s_count == max) answer.push_back(2);
    if(t_count == max) answer.push_back(3);
    
    return answer;
}