#include <stdio.h>
#include <string.h>

char M[25001], W[25001];

int CanMarry(int len_m, int len_w, char M[], char W[])
{
    int cm = 0; // current_match
    int ret = -1;
    for(int w=0;w<len_w;++w)
    {
        if(M[cm] == W[w])
        {
            cm++;
            if(cm == len_m)
            {
                ret = 1;
                break;
            }
        }
    }

    return ret;
}

int main(void)
{
    int tc;
    scanf("%d", &tc);

    for(int t=0; t<tc; ++t)
    {
        scanf("%s %s\n", &M, &W);
        int len_m = strlen(M);
        int len_w = strlen(W);

        int res1 = CanMarry(len_m, len_w, M, W);
        int res2 = CanMarry(len_w, len_m, W, M);
        int res = res1 > res2 ? res1 : res2;
        if(res == 1) printf("YES\n");
        if(res == -1) printf("NO\n");
    }

    return 0;
}

