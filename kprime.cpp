#include <iostream>

const long max_num = 100000L;
int cache[max_num] = {0};

void build_cache(void)
{
    for(long i=2;i<=max_num;++i)
    {
        if(cache[i] == 0)
        {
            for(long j=i;j<=max_num;j+=i)
            {
                cache[j]++;
            }
        }
    }
}

int main(void)
{
    int T, K;
    long A, B;

    build_cache();

    std::cin >> T;

    for(int t=0;t<T;++t)
    {
        std::cin >> A;
        std::cin >> B;
        std::cin >> K;
        long ans = 0L;
        for(long n=A;n<=B;++n)
        {
            if(cache[n] == K) ans++;
        }
        std::cout << ans << std::endl;
    }

    return 0;
}

