#include <stdio.h>
#include<bits/stdc++.h>

const int max_n = 300001;
int A[max_n];
bool flag[max_n] = {0};
int max_and = 0;
int N;

int solver(int layer)
{
    if(layer < 0) return 0;

    int count[32] = {0};
    int ans = 0;
    int bit = 1 << layer;

    for(int i=0;i<N;++i)
    {
        if(flag[i]) continue;
        if(bit & A[i]) count[layer]++;
    }
    
    if(count[layer] > 1){
        ans += bit;
        for(int i=0;i<N;++i)
        {
            if((bit & A[i]) == 0) flag[i] = true;
        }
    }
    
    return ans + solver(layer-1);
}

int main(void)
{

    scanf("%d\n", &N);
    for(int n=0;n<N;++n)
    {
        scanf("%d\n", &A[n]);
    }
    printf("%d\n", solver(31));
    return 0;
}

