#include <stdio.h>
#include <iostream>


int maxDollar(long N)
{
    int dollar_prev = 0;
    for(long i=0; i<N; ++i)
    {
        dollar_new = dollar_prev / 2 + dollar_prev / 3 + dollar_prev / 4;
        dollar_prev = std::max(dollar_prev, dollar_new);
    }

    return dollar_prev;
}

int main(void)
{
    int tc;

    scanf("%d\n", &tc);
    for(int i=0; i<tc; ++i)
    {
        long N;
        scanf("%ld\n", &N);
        printf("%d\n", maxDollar(N));
    }
    return 0;
}
