#include <stdio.h>
#include<bits/stdc++.h>

const int max_n = 5000000;
long long seg_tree[max_n];
long long lazy[max_n];

long long query(int node, int start, int end, int l, int r)
{
    if(lazy[node])
    {
        seg_tree[node] = (r - l + 1) - seg_tree[node];
        lazy[node] = 0;
        if(l != r)
        {
            lazy[2*node+1] = !lazy[2*node+1];
            lazy[2*node+2] = !lazy[2*node+2];
        }
    }
    if(r < start || l > end)
        return 0LL;
    if(l >= start && r <= end)
    {
        return seg_tree[node];
    }

    int mid = (l + r) / 2;
    //printf("lr: %d %d\n", l, r);
    //printf("seg: %d\n", seg_tree[node]);
    return query(2*node+1, start, end, l, mid) + query(2*node+2, start, end, mid+1, r);
}

void update(int node, int start, int end, int l, int r)
{
    if(r < start || l > end)
    {
        if(lazy[node])
        {
            lazy[node] = 0;
            seg_tree[node] = (r - l + 1) - seg_tree[node];
            if(l != r)
            {
                //lazy[2*node] = 1;
                //lazy[2*node+1] = 1;
                lazy[2*node+1] = !lazy[2*node+1];
                lazy[2*node+2] = !lazy[2*node+2];
            }
        }
        return;
    }

    if(l >= start && r <= end)
    {
        if(lazy[node])
        {
            lazy[node] = 0;
            return;
        }
        //printf("lr : %d %d\n", l, r);
        //printf("se : %d %d\n", start, end);
        seg_tree[node] = (r - l + 1) - seg_tree[node];
        //printf("n : %d\n", seg_tree[node]);
        if(l != r)
        {
            //lazy[node*2] = 1;
            //lazy[node*2+1] = 1;
            lazy[2*node+1] = !lazy[2*node+1];
            lazy[2*node+2] = !lazy[2*node+2];
        }
        return;
    }
    if(lazy[node])
    {
        lazy[node] = 0;
        //lazy[2*node] = 1;
        //lazy[2*node+1] = 1;
        lazy[2*node+1] = !lazy[2*node+1];
        lazy[2*node+2] = !lazy[2*node+2];
    }

    int mid = (l + r) / 2;
    update(2*node+1, start, end, l, mid);
    update(2*node+2, start, end, mid+1, r);

    seg_tree[node] = seg_tree[2*node+1] + seg_tree[2*node+2];
}

void executer(int cmd, int start, int end, int n)
{
    if(cmd == 1)
        printf("%d\n", query(0, start, end, 0, n));
    else
    {
        update(0, start, end, 0, n);
    }
}

int main(void)
{
    int N, Q;

    scanf("%d %d\n", &N, &Q);
    for(int i=0;i<max_n;++i)
    {
        seg_tree[i] = 0;
        lazy[i] = 0;
    }

    for(int i=0;i<Q;++i)
    {
        int cmd, start, end;
        scanf("%d %d %d\n", &cmd, &start, &end);
        executer(cmd, start, end, N-1);
    }
    return 0;
}


