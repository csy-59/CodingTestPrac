#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{
public:
    char c;
    int childrenCount = 0;
    unordered_map<char, Node*> children;

    Node() { c = ' '; childrenCount = 0; }
    Node(char c) : c(c), childrenCount(0) {}

    ~Node()
    {
        for (auto iter = children.begin(); iter != children.end(); ++iter)
        {
            delete iter->second;
        }
    }

    void Insert(const string& s, int index)
    {
        ++childrenCount;

        if (index >= s.length())
            return;

        Node* n = FindInChildren(s[index]);
        if (n != nullptr)
        {
            n->Insert(s, index + 1);
        }
        else
        {
            children[s[index]] = new Node(s[index]);
            children[s[index]]->Insert(s, index + 1);
        }
    }

    Node* FindInChildren(char c)
    {
        if (children.find(c) == children.end())
        {
            return nullptr;
        }

        return children[c];
    }

    int FoundUntilSolo(const string& s, int index)
    {
        if (index >= s.length())
            return index;

        Node* n = FindInChildren(s[index]);
        if (n != nullptr)
        {
            if (n->childrenCount == 1)
                return index + 1;

            return n->FoundUntilSolo(s, index + 1);
        }

        return -1;
    }
};

int solution(vector<string> words) {
    int answer = 0;
    Node head(' ');

    for (int i = 0, size = words.size(); i < size; ++i)
    {
        head.Insert(words[i], 0);
    }

    for (int i = 0, size = words.size(); i < size; ++i)
    {
        answer += head.FoundUntilSolo(words[i], 0);
    }

    return answer;
}