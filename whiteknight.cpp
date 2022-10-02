#include <iostream>

const int max_n = 1000;
const int actions = 4;
int board[max_n][max_n];
int dp[max_n][max_n];

int x_start, y_start;

int solve(int x, int y, int N)
{
    if(x >= N) return 0;
    if(x < 0) return 0;
    if(y < 0) return 0;
    if(y >= N) return 0;

    if(dp[y][x] > 0) return dp[y][x];

    int ps = 0;
    if(board[y][x] == 1){
        ps = 1;
    }

    int ret1 = solve(x+1, y-2, N) + ps;
    int ret2 = solve(x+1, y+2, N) + ps;
    int ret3 = solve(x+2, y-1, N) + ps;
    int ret4 = solve(x+2, y+1, N) + ps;

    int ret = ret1;
    if(ret < ret2) ret = ret2;
    if(ret < ret3) ret = ret3;
    if(ret < ret4) ret = ret4;

    dp[y][x] = ret;

    return dp[y][x];
}

int main(void)
{
    int N;
    int TC;

    std::cin >> TC;
    for(int tc=0;tc<TC;++tc)
    {
        std::cin >> N;
        for(int n=0;n<N;++n)
        {
            for(int nn=0;nn<N;++nn)
            {
                char tmp;
                std::cin >> tmp;
                if(tmp == 'P') board[n][nn] = 1;
                else if(tmp == 'K')
                {
                    board[n][nn] = -1;
                    x_start = nn;
                    y_start = n;
                }
                else board[n][nn] = 0;
                dp[n][nn] = -1;
            }
        }
        std::cout << solve(x_start, y_start, N) << std::endl;
    }

    return 0;
}

