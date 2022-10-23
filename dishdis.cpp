#include <iostream>

const int n_max=101, m_max=101;

long long int dp[n_max][m_max] = {-1};
const long long int mod_const = 1000000007;
int xi[m_max];
int yi[m_max];

long long int solve(int n, int m, int N, int M)
{
    if(n < 0) return 0; // not enough dishes
    else if(m > M) return 0; // not enough cooks
    else if(n==0 && m == M) return 1;
    else if(dp[n][m] != -1) return dp[n][m];

    long long int ret = 0;
    for(int i=xi[m];i<=yi[m];++i)
    {
        ret = (ret + solve(n-i, m+1, N, M)) % mod_const;
    }
    dp[n][m] = ret;

    return ret;
}

int main(void)
{
    int T;

    std::cin >> T;

    for(int t=0;t<T;++t)
    {
        int N, M;
        std::cin >> N >> M;
        for(int m=0;m<M;++m)
        {
            std::cin >> xi[m] >> yi[m];
        }
        for(int n=0;n<=N;++n)
        {
            for(int m=0;m<=M;++m)
            {
                dp[n][m] = -1;
            }
        }
        std::cout << solve(N, 0, N, M) << std::endl;
    }

    return 0;
}

