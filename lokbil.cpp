#include <iostream>
#include <iomanip>
#include <queue>

double bfs(std::vector<std::vector<long long>>& adj, long long s, long long t)
{
    std::queue<long long> q;
    std::vector<bool> visited(t, false);

    q.push(s);
    visited[s] = true;

    double notoreity = 0.;
    long long dist = 0;

    while(!q.empty())
    {
        long long count = q.size();

        for(long long c=0;c<count;++c)
        {
            long long n = q.front();

            notoreity += dist;
            q.pop();

            for(long long i=0;i<adj[n].size();++i)
            {
                if(!visited[adj[n][i]])
                {
                    q.push(adj[n][i]);
                    visited[adj[n][i]] = true;
                }
            }
        }
        dist++;
    }
    return notoreity / t;
}

int main(void)
{
    int G;
    std::cout << std::fixed << std::setprecision(6);

    std::cin >> G;
    while(G-- > 0)
    {
        int num;
        std::cin >> num;

        std::vector<std::vector<long long>> adj(num);
        for(long long i=0;i<num;++i)
        {
            while(true)
            {
                long long x;
                std::cin >> x;

                adj[i].push_back(x-1);

                if(std::cin.peek() == '\n' || std::cin.peek() == -1)
                {
                    break;
                }
            }
        }
        
        double notoreity = bfs(adj, 0, num);
        long long leader = 0;
        for(long long i=1;i<num;++i)
        {
            double _notoreity = bfs(adj, i, num);

            if(_notoreity < notoreity)
            {
                notoreity = _notoreity;
                leader = i;
            }
        }
        std::cout << leader + 1 << " " << notoreity << std::endl;
    }
    return 0;
}

