#include <stdio.h>
#include<bits/stdc++.h>

long long possibilities(long long n, long long k)
{
    // it's repetive combination
    // N_H_R = n+r-1_C_n-1
    // each color should be selected
    // ex) n=30, k=7, 7 marbles which have different colors needed
    //     So, 7_H_30-7 = 7_H_23 = 7+23-1_C_7-1 = 29_C_6
    long long res = 1;
    long long N = n-1;
    long long K = k-1;
    if(N-K < K) K = N-K;
    for(long long i=0;i<K;++i)
    {
        res *= (N-i);
        res /= (i+1);
    }

    return res;
}

int main(void)
{
    long long tc, k, n;

    scanf("%d\n", &tc);
    for(int i=0;i<tc;++i)
    {
        scanf("%lld %lld\n", &n, &k);
        printf("%lld\n", possibilities(n, k));
    }
    return 0;
}

