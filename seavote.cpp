#include <stdio.h>
#include<bits/stdc++.h>

int main(void)
{
    int tc, N;

    scanf("%d\n", &tc);
    for(int i=0;i<tc;++i)
    {
        int votes[10000];
        scanf("%d\n", &N);
        for(int j=0;j<10000;++j)
            votes[j] = 0;

        int sum = 0;
        int non_zero = 0;
        for(int n=0;n<N;++n)
        {
            scanf("%d ", &votes[n]);
            if(votes[n] > 0)
            {
                sum += votes[n];
                non_zero++;
            }
        }

        if(sum - non_zero < 100 && sum >= 100) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


