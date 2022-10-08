#include <iostream>

const int max_b = 20;
const int max_v = 1000;
int bnotes[max_b];

bool ans = false;

void solver(int cb, int cd, int tb)
{
    if(cd < 0) return;
    if(cb > tb) return;
    if(cd == 0)
    {
        ans=true;
        return;
    }

    solver(cb+1, cd-bnotes[cb], tb);
    solver(cb+1, cd, tb);
}

int main(void)
{
    int tc, tb, d;

    std::cin >> tc;

    for(int c=0;c<tc;++c)
    {
        std::cin >> tb >> d;
        for(int b=0;b<tb;++b)
        {
            int money;
            std::cin >> money;
            bnotes[b] = money;
        }

        solver(0, d, tb);
        if(ans) std::cout << "Yes" << std::endl;
        else std::cout << "No" << std::endl;
        ans = false;
    }

    return 0;
}

