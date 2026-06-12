#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct job{
    int number;
    int requestTime;
    int jobTime;
    
    job() { number = requestTime = jobTime = 0; }
    job(int n, int r, int j): number(n), requestTime(r), jobTime(j) {}
    
    void Set(int n, int r, int j)
    {
        number = n;
        requestTime = r;
        jobTime = j;
    }
    
    bool operator>(const job& other) const
    {
        if(jobTime != other.jobTime) return jobTime > other.jobTime;
        if(requestTime != other.requestTime) return requestTime > other.requestTime;
        return number > other.number;
    }
};

bool cmp(job& a, job& b)
{
    if(a.requestTime != b.requestTime)
        return a.requestTime < b.requestTime;
    
    return a.number < b.number;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    vector<job> Jobs;
    
    for(int i = 0, size = jobs.size(); i < size; ++i)
    {
        Jobs.push_back(job(i, jobs[i][0], jobs[i][1]));
    }
    
    sort(Jobs.begin(), Jobs.end(), cmp);
    
    priority_queue<job, vector<job>, greater<job>> q;
    q.push(Jobs[0]);

    int time = Jobs[0].requestTime, index = 1;
    while(q.empty() == false || index < Jobs.size())
    {
        if(q.empty() == true || index < Jobs.size() && Jobs[index].requestTime <= time)
        {
            if(q.empty() == true)
            {
                time = max(Jobs[index].requestTime, time);
            }
            
            while(index < Jobs.size() && time >= Jobs[index].requestTime)
            {
                q.push(Jobs[index]);
                ++index;   
            }
        }
        
        job j = q.top(); q.pop();
        
        time += j.jobTime;
        answer += time - j.requestTime;
    }
    
    return answer / jobs.size();
}