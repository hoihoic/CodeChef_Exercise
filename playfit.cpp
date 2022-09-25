#include <iostream>

const long N = 100000L;
const long G = 1000000L;

long gdiff[N];
long goals[N];

void findMaxDiff(long nn)
{
    gdiff[0] = 0;
    long min_goal = goals[0];

    for(long n=1;n<nn;++n)
    {
        if(goals[n] < gdiff[n-1])
        {
            gdiff[n] = gdiff[n-1];
            if(goals[n] < min_goal)
            {
                min_goal = goals[n];
            }

            continue;
        }
        if(goals[n] - min_goal > gdiff[n-1])
        {
            gdiff[n] = goals[n] - min_goal;
        }
        else
        {
            gdiff[n] = gdiff[n-1];
        }

        if(goals[n] < min_goal)
        {
            min_goal = goals[n];
        }
    }
}

int main(void)
{
    int tc;
    
    std::cin >> tc;
    for(int c=0; c<tc; ++c)
    {
        long nn;
        std::cin >> nn;
        for(long n=0; n<nn ;++n)
        {
            std::cin >> goals[n];
        }
        findMaxDiff(nn);
        if(gdiff[nn-1] > 0)
        {
            std::cout << gdiff[nn-1] << std::endl;
        }
        else
        {
            std::cout << "UNFIT" << std::endl;
        }
    }

    return 0;
}

