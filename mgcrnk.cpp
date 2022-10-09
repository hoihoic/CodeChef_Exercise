#include <iostream>
#include <stdio.h>

const int max_t = 20;
const int max_n = 100;

long S[max_n][max_n];
long cache[max_n][max_n];

void solver(int N)
{
    for(int n=0;n<N;++n)
    {
        for(int n2=0;n2<N;++n2)
        {
            if(n==0 && n2==0)
            {
                cache[n][n2] = 0;
                continue;
            }

            if(n==0)
            {
                cache[n][n2] = cache[n][n2-1] + S[n][n2];
                continue;
            }
            if(n2==0)
            {
                cache[n][n2] = cache[n-1][n2] + S[n][n2];
                continue;
            }

            long tmp1 = cache[n][n2-1] + S[n][n2]; 
            long tmp2 = cache[n-1][n2] + S[n][n2]; 

            cache[n][n2] = tmp1 > tmp2 ? (tmp1) : (tmp2);
        }
    }

    double ans = double(cache[N-1][N-1]) / (2*N - 3);

    //if(ans >= 0.) std::cout << ans << std::endl;
    if(ans >= 0.) printf("%lf\n", ans);
    else std::cout << "Bad Judges" << std::endl; }

int main(void)
{
    int tc, N;
    std::cin >> tc;
    
    for(int t=0;t<tc;++t)
    {
        std::cin >> N;
        for(int n=0;n<N;++n)
        {
            for(int n2=0;n2<N;++n2)
            {
                long score;
                std::cin >> score;
                S[n][n2] = score;
            }
        }
        solver(N);
    }

    return 0;
}

