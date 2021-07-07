#include <stdio.h>
#include <bits/stdc++.h>

int dp[100][100];

int get_color(int s, int e, int A[])
{
    int sum = 0;

    for(int i=s;i<=e;++i)
    {
        sum += A[i];
        sum %= 100;
    }

    return sum;
}

int solver(int s, int e, int A[])
{
    int ans = 987654321;

    if(s >= e) return 0;
    if(dp[s][e] != -1) return dp[s][e];

    for(int i=s;i<e;++i)
    {
        ans = std::min(ans, solver(s, i, A)+solver(i+1, e, A)+get_color(s, i, A)*get_color(i+1, e, A));
    }
    dp[s][e] = ans;

    return ans;
}

int main(void)
{
    int N, A[101];

    while(scanf("%d\n", &N) != -1)
    {
        memset(A, 0, sizeof(A));
        memset(dp, -1, sizeof(dp));

        for(int n=0;n<N;++n)
        {
            scanf("%d ", &A[n]);
        }

        printf("%d\n", solver(0, N-1, A));
    }

    return 0;
}

