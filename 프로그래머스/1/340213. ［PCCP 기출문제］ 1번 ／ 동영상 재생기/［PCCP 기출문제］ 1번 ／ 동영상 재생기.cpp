#include <string>
#include <vector>

using namespace std;

int GetSecond(string t)
{
    vector<string> tok;
    int count = t.length();
    int start = 0;
    for(int i = 0; i<count; ++i)
    {
        if(t[i] == ':')
        {
            tok.push_back(t.substr(0, i));
            tok.push_back(t.substr(i+1, count));
            break;
        }
    }
    
    int min = stoi(tok[0]);
    int sec = stoi(tok[1]);
    
    return sec + min * 60;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int video_sec = GetSecond(video_len);
    int pos_sec = GetSecond(pos);
    int opStart_sec = GetSecond(op_start);
    int opEnd_sec = GetSecond(op_end);
    
    if(pos_sec >= opStart_sec && pos_sec <= opEnd_sec)
    {
        pos_sec = opEnd_sec;
    }
    
    int count = commands.size();
    for(int i = 0; i<count; ++i)
    {
        string co = commands[i];
        if(co.compare("prev") == 0)
        {
            pos_sec -= 10;
            if(pos_sec < 0)
                pos_sec = 0;
        }
        else if(co.compare("next") == 0)
        {
            pos_sec += 10;
            if(pos_sec > video_sec)
                pos_sec = video_sec;
        }
        
        if(pos_sec >= opStart_sec && pos_sec <= opEnd_sec)
        {
            pos_sec = opEnd_sec;
        }
    }
    
    int min = pos_sec/60;
    int sec = pos_sec % 60;
    
    if(min < 10)
    {
        answer = "0" + to_string(min);
    }
    else
    {
        answer = to_string(min);
    }
    answer += ":";
    if(sec < 10)
    {
        answer += "0" + to_string(sec);
    }
    else
    {
        answer += to_string(sec);
    }
    
    return answer;
}