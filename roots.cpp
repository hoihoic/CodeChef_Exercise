#include <stdio.h>
#include<bits/stdc++.h>


int main(void)
{
    int tc, N;

    scanf("%d\n", &tc);
    for(int i=0;i<tc;++i)
    {
        scanf("%d\n", &N);
        int res = 0;
        int id, sum;
        for(int n=0;n<N;++n)
        {
            scanf("%d %d\n", &id, &sum);
            //printf("%d %d\n", id, sum);
            res += (id - sum);
        }
        printf("%d\n", res);
    }
    return 0;
}


