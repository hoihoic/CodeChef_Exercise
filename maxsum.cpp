#include <iostream>

int maxSum[101][101];
int nums[100][100];

int findMaxSum(int N)
{
    int ret = 0;
    for(int n=1;n<N+1;++n)
    {
        for(int a=1;a<n+1;++a)
        {
            int sumUp = maxSum[n-1][a] + nums[n-1][a-1];
            int sumLeft = maxSum[n-1][a-1] + nums[n-1][a-1];

            if(sumUp > sumLeft) maxSum[n][a] = sumUp;
            else                maxSum[n][a] = sumLeft;
        }
    }

    for(int i=1;i<N+1;++i)
    {
        if(maxSum[N][i] > ret) ret = maxSum[N][i];
    }

    return ret;
}

int main(void)
{
    int T,N;

    std::cin >> T;
    for(int i=0;i<101;++i)
    {
        maxSum[0][i] = 0;
        maxSum[i][0] = 0;
    }

    for(int tc=0;tc<T;++tc)
    {
        std::cin >> N;
        for(int n=0;n<N;++n)
        {
            for(int a=0;a<n+1;++a)
            {
                std::cin >> nums[n][a];
            }
        }
        int ret = findMaxSum(N);
        std::cout << ret << std::endl;
    }


    return 0;
}

