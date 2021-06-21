#include <stdio.h>
#include<bits/stdc++.h>

const int max_n = 100001;

long findMaxTipsDP(int N, long A[], long B[], int X, int Y)
{
    long total_tips[N+1][N+1];
    long max_tip = 0L;

    total_tips[0][0] = 0L;
    for(int i=1;i<=N;++i)
    {
        if(i <= Y)
            total_tips[i][0] = total_tips[i-1][0] + B[i-1];
        else
            total_tips[i][0] = total_tips[i-1][0];
    }
    for(int i=0;i<=X;++i)
        total_tips[0][i] = 0L;

    for(int i=1;i<=N;++i)
    {
        for(int j=1;j<=X;++j)
        {
            long prev_A = total_tips[i-1][j-1] + A[i-1];
            long prev_B = total_tips[i-1][j] + B[i-1];

            //if(i-j > Y) total_tips[i][j] = prev_A;
            if(prev_A > prev_B) total_tips[i][j] = prev_A;
            else total_tips[i][j] = prev_B;
        }
    }

    for(int j=0;j<=X;++j)
    {
        max_tip = std::max(max_tip, total_tips[N][j]);
    }

    return max_tip;
}

bool compare(std::pair<long, long> A, std::pair<long, long> B)
{
    return A.first > B.first;
}

long findMaxTipsGreedy(int N, long A[], long B[], int X, int Y)
{
    long max_tip = 0L;
    std::vector<std::pair<long, long>> tip_diff;

    for(int i=0;i<N;++i)
    {
        std::pair<long, long> diff = std::make_pair(std::abs(A[i] - B[i]), i);
        tip_diff.push_back(diff);
    }
    std::sort(tip_diff.begin(), tip_diff.end(), compare);

    int x = 0, y = 0;
    long sum = 0L;
    for(int i=0;i<N;++i)
    {
        //printf("%ld\n", tip_diff[i].first);
        long idx = tip_diff[i].second;
        if(A[idx] > B[idx])
        {
            if(x + 1 <= X)
            {
                x++;
                sum += A[idx];
            }
            else
            {
                y++;
                sum += B[idx];
            }
        }
        else
        {
            if(y + 1 <= Y)
            {
                y++;
                sum += B[idx];
            }
            else
            {
                x++;
                sum += A[idx];
            }
        }
    }
    max_tip = sum;

    return max_tip;
}

int main(void)
{
    int N, X, Y;

    long A[max_n] = {0L};
    long B[max_n] = {0L};

    scanf("%d %d %d\n", &N, &X, &Y);
    for(int n=0;n<N;++n)
        scanf("%ld ", &A[n]);

    for(int n=0;n<N;++n)
        scanf("%ld ", &B[n]);
    printf("%ld\n", findMaxTipsGreedy(N, A, B, X, Y));
    
    return 0;
}


