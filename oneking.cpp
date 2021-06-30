#include <stdio.h>
#include <bits/stdc++.h>

std::vector<std::pair<int, int>> kingdoms;

bool compare(std::pair<int, int> a, std::pair<int, int> b)
{
    return a.second < b.second;
}

int solver(int C, int first)
{
    std::sort(kingdoms.begin(), kingdoms.end(), compare);
    int min_first = first-1;
    int count = 0;
    for(int c=0;c<C;++c)
    {
        if(kingdoms[c].first > min_first)
        {
            //printf("%d %d \n", min_first, kingdoms[c].second);
            count++;
            min_first = kingdoms[c].second;
        }
    }
    return count;
}

int main(void)
{
    int T, C;

    scanf("%d\n", &T);

    for(int t=0;t<T;++t)
    {
        scanf("%d\n", &C);
        int first = 9876543210;
        for(int c=0;c<C;++c)
        {
            int l, h;
            scanf("%d %d \n", &l, &h);
            kingdoms.push_back(std::make_pair(l, h));
            first = std::min(first, l);
        }
        printf("%d\n", solver(C, first));
        kingdoms.clear();
    }

    return 0;
}

