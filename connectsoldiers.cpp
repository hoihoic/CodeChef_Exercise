#include <stdio.h>
#include<bits/stdc++.h>

int max_length[31];
int min_length[31];

void build()
{
    max_length[0] = 0;
    min_length[0] = 0;
    for(int i=1;i<=30;++i)
    {
        min_length[i] = min_length[i/2] + min_length[i-1-i/2] + i+1;
        max_length[i] = max_length[i-1] + i+1;
    }
}

int main(void)
{
    int T;
    int N, M;

    build();
    scanf("%d\n", &T);
    for(int t=0;t<T;++t)
    {
        scanf("%d %d ", &N, &M);
        if(min_length[N] > M) printf("%d\n", -1);
        else if(max_length[N] >= M) printf("%d\n", 0);
        else printf("%d\n", M - max_length[N]);
    }
    return 0;
}

