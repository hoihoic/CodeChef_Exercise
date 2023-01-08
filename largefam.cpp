#include <iostream>
#include <algorithm>

std::vector<int> A;

int solve(int N)
{
    std::sort(A.begin(), A.end());

    int ret = 0;
    int rem = N-1;

    for(int n=0;n<N;++n)
    {
        if(A[n] <= rem)
        {
            ret++;
            rem -= A[n];
        }
    }
    return ret;
}

int main(void)
{
    int T, N;

    std::cin >> T;
    
    for(int t=0;t<T;++t)
    {
        A.clear();
        std::cin >> N;
        for(int n=0;n<N;++n)
        {
            int a;
            std::cin >> a;
            A.push_back(a);
        }
        std::cout << solve(N) << std::endl;
    }
    return 0;
}

