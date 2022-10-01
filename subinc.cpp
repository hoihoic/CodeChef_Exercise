#include <iostream>

const int max_n = 100000;
long long A[max_n];
long long counts[max_n];

long long CountSubArr(int N)
{
    long long chain=1;
    counts[0] = 1;
    for(int n=1;n<N;++n)
    {
        if(A[n] >= A[n-1])
        {
            chain++;
        }
        else
        {
            chain=1;
        }
        counts[n] = counts[n-1] + chain;
    }

    return counts[N-1];
}

int main(void)
{
    int tc;

    std::cin >> tc;

    for(int t=0;t<tc;++t)
    {
        int N;
        std::cin >> N;

        for(int n=0;n<N;++n)
        {
            std::cin >> A[n];
        }
        std::cout << CountSubArr(N) << std::endl;
    }
}

