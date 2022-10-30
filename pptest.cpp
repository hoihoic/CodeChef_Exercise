#include <iostream>

const int max_N = 101;
const int max_W = 101;

int C[max_N];
int P[max_N];
int T[max_N];
int dp[max_N][max_W];

int solve(int N, int W)
{
    for(int n=1;n<=N;++n)
        dp[0][W] = 0;

    for(int n=1;n<=N;++n)
    {
        int score = C[n] * P[n];
        for(int w=1;w<=W;++w)
        {
            if(T[n] > w)
            {
                dp[n][w] = dp[n-1][w];
                continue;
            }

            int c1 = dp[n-1][w-T[n]]+ score;
            int c2 = dp[n-1][w];

            dp[n][w] = (c1) > (c2) ? (c1) : (c2);
        }
    }

    int ans = 0;
    for(int w=1;w<=W;++w)
    {
        if(ans < dp[N][w]) ans = dp[N][w];
    }

    return ans;
}

int main(void)
{
    int TC;

    std::cin >> TC;
    for(int tc=0;tc<TC;++tc)
    {
        int N, W;
        std::cin >> N >> W;
        for(int n=1;n<=N;++n)
        {
            int c, p, t;
            std::cin >> c >> p >> t;
            //std::cout << c << p << t <<std::endl;
            C[n] = c;
            P[n] = p;
            T[n] = t;
        }

        std::cout << solve(N, W) << std::endl;
    }
    return 0;
}

