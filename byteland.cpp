#include <stdio.h>
#include<bits/stdc++.h>

long long maxDollar(long long N, std::unordered_map<long long, long long> &m)
{
    if(N == 0) return 0;
    if(m.find(N) != m.end())
        return m[N];

    long long div2 = maxDollar(N/2, m);
    long long div3 = maxDollar(N/3, m);
    long long div4 = maxDollar(N/4, m);

    m[N] = std::max(N, div2 + div3 + div4);

    return m[N];
}

int main(void)
{
    long long N;

    while(scanf("%lld\n", &N)==1)
    {
        std::unordered_map<long long, long long> m;
        printf("%lld\n", maxDollar(N, m));
    }
    return 0;
}

