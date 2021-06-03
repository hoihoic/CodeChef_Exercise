#include <stdio.h>
#include<bits/stdc++.h>

int numFacts[1000002];

void findFacts(int num)
{
    for(int i=2;i<=num;i++)
    {
        while(num % i == 0)
        {
            numFacts[i]++;
            num /= i;
        }
    }
}

int main(void)
{
    int tc, N;

    scanf("%d\n", &tc);
    for(int i=0;i<tc;++i)
    {
        scanf("%d\n", &N);
        int res = 0;
        int A[10];
        for(int j=0;j<1000002;++j)
            numFacts[j] = 0;

        for(int n=0;n<N;++n)
        {
            scanf("%d ", &A[n]);
            findFacts(A[n]);
        }
        int sum = 1;
        for(int j=0;j<1000002;++j)
        {
            if(numFacts[j] > 0)
                sum *= numFacts[j] + 1;
        }
        printf("%d\n", sum);
    }
    return 0;
}


