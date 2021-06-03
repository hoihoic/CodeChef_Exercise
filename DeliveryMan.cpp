#include <stdio.h>
#include<bits/stdc++.h>

const int max_n = 100001;
long long total_tips[max_n][2];

long long findMaxTips(int N, long long A[], long long B[], int X, int Y)
{
    //total_tips[0][0] = {0LL};
    //total_tips[0][1] = {0LL};

    long long max_tip = 0LL;

    for(int i=1;i<=N;++i)
    {
        //for(int j=0;j<2;++j)
        {
            //max_tip = std::max(max_tip + A[i-1], max_tip + B[i-1]);
            long long selectA = max_tip;
            long long selectB = max_tip;
            if(X > 0) selectA = max_tip + A[i-1];
            if(Y > 0) selectB = max_tip + B[i-1];
            if(selectA > selectB)
            {
                max_tip = selectA;
                X--;
            }
            else
            {
                max_tip = selectB;
                Y--;
            }
        }
    }
    return max_tip;
}

int main(void)
{
    int N, X, Y;

    long long A[max_n] = {0LL};
    long long B[max_n] = {0LL};

    scanf("%d %d %d\n", &N, &X, &Y);
    for(int n=0;n<N;++n)
        scanf("%lld ", &A[n]);

    for(int n=0;n<N;++n)
        scanf("%lld ", &B[n]);
    printf("%lld\n", findMaxTips(N, A, B, X, Y));
    
    return 0;
}


