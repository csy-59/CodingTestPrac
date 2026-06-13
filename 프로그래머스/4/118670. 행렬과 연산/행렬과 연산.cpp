#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    int h = rc.size();
    int w = rc[0].size();

    deque<int> left;
    deque<int> right;
    deque<deque<int>> mid;

    for(int i = 0; i < h; ++i)
    {
        left.push_back(rc[i][0]);
        right.push_back(rc[i][w - 1]);

        deque<int> row;
        for(int j = 1; j < w - 1; ++j)
        {
            row.push_back(rc[i][j]);
        }

        mid.push_back(std::move(row));
    }

    for(const string& op : operations)
    {
        if(op[0] == 'S') // ShiftRow
        {
            left.push_front(left.back());
            left.pop_back();

            right.push_front(right.back());
            right.pop_back();

            mid.push_front(std::move(mid.back()));
            mid.pop_back();
        }
        else // Rotate
        {
            if(w == 2)
            {
                right.push_front(left.front());
                left.pop_front();

                left.push_back(right.back());
                right.pop_back();
            }
            else
            {
                mid.front().push_front(left.front());
                left.pop_front();

                right.push_front(mid.front().back());
                mid.front().pop_back();

                mid.back().push_back(right.back());
                right.pop_back();

                left.push_back(mid.back().front());
                mid.back().pop_front();
            }
        }
    }

    vector<vector<int>> answer(h, vector<int>(w));

    for(int i = 0; i < h; ++i)
    {
        answer[i][0] = left[i];
        answer[i][w - 1] = right[i];

        for(int j = 1; j < w - 1; ++j)
        {
            answer[i][j] = mid[i][j - 1];
        }
    }

    return answer;
}