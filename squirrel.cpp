#include <iostream>

std::vector<long long> P;
std::vector<long long> T;

long long solve(std::vector<long long>& P, std::vector<long long>&T,
        long long n, long long k, long long K, long long c)
{
    if(k == K) return 0;
    if(n == 0) return 0;
}

int main(void)
{
    int tc;

    std::cin >> tc;

    while(tc-- > 0)
    {
        long long M, N, K;
        std::cin >> M >> N >> K;

        for(long long m=0;m<M;++m)
        {
            long long p;
            std::cin >> p;
            P.push_back(p);
        }

        for(long long m=0;m<M;++m)
        {
            long long t;
            std::cin >> t;
            T.push_back(t);
        }
    }


    return 0;
}

