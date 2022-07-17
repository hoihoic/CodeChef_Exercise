// Solving the equation
#include <iostream>

long GetDistance(int n)
{
    return ((long)n*n + 3*n) / 2;
}

int main(void)
{
    int tc, N;

    std::cin >> tc; 
    for(int c=0;c<tc;++c)
    {   
        std::cin >> N;
        std::cout << GetDistance(N) << std::endl;
    }   

    return 0;
}

// Dynamic Programming
//#include <iostream>
//
//long dist_mem[100001];
//
//long GetDistance(long long n_lights)
//{
//    if(dist_mem[n_lights] > 0) return dist_mem[n_lights];
//    if(n_lights == 1)
//    {
//        dist_mem[n_lights] = 2;
//    }
//    else
//    {
//        dist_mem[n_lights] = GetDistance(n_lights-1) + n_lights + 1;
//    }
//
//    return dist_mem[n_lights];
//}
//
//int main(void)
//{
//    int tc, N;
//
//    std::cin >> tc;
//    for(int c=0;c<tc;++c)
//    {
//        std::cin >> N;
//        std::cout << GetDistance((long)N) << std::endl;
//    }
//
//    return 0;
//}
//
