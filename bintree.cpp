#include <iostream>

int main(void)
{
    int N;
    std::cin >> N;

    for(int n=0;n<N;++n)
    {
        long long i, j;
        long long ans = 0LL;
        std::cin >> i >> j;

        while(i != j)
        {
            if(i > j) i /= 2;
            else if(i < j) j /= 2;
            ans++;
        }
        std::cout << ans << std::endl;
    }
}

