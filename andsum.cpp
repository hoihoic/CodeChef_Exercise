#include <stdio.h>
#include<bits/stdc++.h>

const int max_bit = 31;

long long SumOfAnd(long long A[], int N)
{
    long long ret = 0LL;
    long long bit_start = 1LL;

    for(int n=max_bit;n>=0;--n)
    {
        long long count = 0LL;
        for(int i=0;i<N;++i)
        {
            long long src = bit_start << n;
            if(src & A[i])
                count++;
        }
        ret += ((count*(count-1)) / 2) * (bit_start << n);
    }

    return ret;
}

int main(void)
{
    int N;
    long long A[100000];

    scanf("%lld\n", &N);
    for(int i=0;i<N;++i)
    {
        scanf("%lld ", &A[i]);
    }
    printf("%lld\n", SumOfAnd(A, N));
    return 0;
}

