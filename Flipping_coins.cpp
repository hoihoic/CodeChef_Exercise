#include <stdio.h>
#include<bits/stdc++.h>

const int max_n = 1000000;
int num_head[max_n];
bool state_head[max_n];

void executer(int cmd, int A, int B)
{
    if(cmd == 1)
    {
        int head_prev = A > 0 ? num_head[A-1] : 0;
        printf("%d\n", num_head[B] - head_prev);
        return;
    }

    for(int i=A;i<=B;++i)
    {
        int head_prev = i > 0 ? num_head[i-1] : 0;
        if(state_head[i] == true)
        {
            num_head[i] = head_prev;
            state_head[i] = false;
        }
        else
        {
            num_head[i] = head_prev + 1;
            state_head[i] = true;
        }
    }
}

int main(void)
{
    int N, Q;

    scanf("%d %d\n", &N, &Q);
    for(int i=0;i<N;++i)
    {
        num_head[i] = 0;
        state_head[i] = false;
    }

    for(int i=0;i<Q;++i)
    {
        int cmd, start, end;
        scanf("%d %d %d\n", &cmd, &start, &end);
        executer(cmd, start, end);
    }
    return 0;
}


