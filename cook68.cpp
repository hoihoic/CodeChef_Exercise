#include <iostream>

const int num_array = 100001;
int A[num_array];
int sub[num_array]; // length of subarray

void GetSubLen(int n)
{
    sub[1] = 1; 
    for(int x=1;x<=n;++x)
    {
        if(x == n)
        {
            std::cout << 1 << std::endl;
            break;
        }

        if(sub[x-1] > 1)
        {
            sub[x] = sub[x-1] - 1;
            std::cout << sub[x] << " ";
            continue;
        }

        int length = 1;
        for(int i=x+1;i<=n;++i)
        {
            if(A[i-1] * A[i] < 0)
            {
                length++;
                if(i == n)
                {
                    sub[x] = length;
                    std::cout << sub[x] << " ";
                }
            }
            else
            {
                sub[x] = length;
                std::cout << sub[x] << " ";
                break;
            }
        }
    }
}

int main(void)
{
    int T, N;

    A[0] = 1;
    std::cin >> T;
    for(int tc=0;tc<T;++tc)
    {
        std::cin >> N;
        for(int n=1;n<=N;++n)
        {
            long long num;
            //std::cin >> A[n];
            std::cin >> num;
            if(num > 0) A[n] = 1;
            else        A[n] = -1;
        }
        GetSubLen(N);
    }

    return 0;
}

