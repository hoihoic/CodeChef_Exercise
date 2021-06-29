#include <stdio.h>
#include<bits/stdc++.h>

const int max_n = 100;
int a[max_n];

void solver(int a[], int N, int K)
{
    std::map<int, int> qcount;

    for(int n=0;n<N;++n)
    {
        qcount[a[n] % (K+1)]++;
    }
    if(qcount.size() > 2)
    {
        printf("NO\n");
        return;
    }
    bool ok = false;
    for(auto it : qcount)
    {
        if(it.second >= N-1)
            ok = true;
    }
    if(ok) printf("YES\n");
    else printf("NO\n");
}

int main(void)
{
    int T;
    int N, K;

    scanf("%d\n", &T);
    for(int t=0;t<T;++t)
    {
        scanf("%d %d ", &N, &K);
        for(int n=0;n<N;++n)
        {
            scanf("%d ", &a[n]);
        }
        solver(a, N, K);
    }
    return 0;
}

