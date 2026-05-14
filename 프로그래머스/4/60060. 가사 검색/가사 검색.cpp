#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int count;
    Node* child[26];
    
    Node(): count(0) {
        for(int i = 0; i < 26; ++i)
        {
            child[i] = nullptr;
        }
    }
    ~Node() {
        for(int i = 0; i< 26; ++i)
        {
            if(child[i] != nullptr)
                delete(child[i]);
        }
    }
    
    void Insert(string& word, int index, bool way)
    {
        ++count;
        
        if(index == word.length() || index == -1)
            return;
        
        if(child[word[index] - 'a'] == nullptr)
            child[word[index] - 'a'] = new Node;
        
        child[word[index] - 'a']->Insert(word, (way == true ? index + 1: index - 1), way);
    }
    
    int Find(string& word, int index, bool way)
    {
        if(index == -1 || index == word.length() || word[index] == '?')
            return count;
        
        if(child[word[index] - 'a'] == nullptr)
            return 0;
        
        return child[word[index] - 'a']->
            Find(word, (way == true ? index + 1: index - 1), way);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    unordered_map<int, Node> pre;
    unordered_map<int, Node> suf;
    for(int i = 0, size = words.size(); i < size; ++i)
    {
        pre[words[i].length()].Insert(words[i], 0, true);
        suf[words[i].length()].Insert(words[i], words[i].length() - 1, false);
    }
    
    for(int i = 0, size = queries.size(); i < size; ++i)
    {
        int len = queries[i].length();
        if(queries[i][0] == '?' && queries[i][len - 1] == '?')
            answer.push_back(pre[len].count);
        else if(queries[i][0] == '?')
            answer.push_back(suf[len].Find(queries[i], len - 1, false));
        else
            answer.push_back(pre[len].Find(queries[i], 0, true));
    }
    
    return answer;
}