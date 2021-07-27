#include <stdio.h>
#include<bits/stdc++.h>


std::vector<int> getPartialMatch(const std::string& N)
{
    int m = N.size();
    std::vector<int> pi(m, 0);

    int matched = 0;
    for(int i=1;i<m;++i)
    {
        while(matched > 0 && N[matched] != N[i])
            matched = pi[matched-1];

        if(matched == N[i])
        {
            matched++;
            pi[i] = matched;
        }
    }

    return pi;
}

//std::vector<int> kmpSearch(const std::string& H, const std::string& N)
int kmpSearch(const std::string& H, const std::string& N)
{
    int n=H.size(), m=N.size();
    //std::vector<int> ret;
    std::vector<int> pi = getPartialMatch(N);

    int matched = 0;
    int max_matched = 0;
    int position = 0;
    for(int i=0;i<n;++i)
    {
        while(matched > 0 && N[matched] != H[i])
            matched = pi[matched-1];

        if(N[matched] == H[i])
        {
            matched++;
            if(matched > max_matched)
            {
                max_matched = matched;
                position = i-matched+1;
            }
            if(matched == m)
            {
                //ret.push_back(i-m+1);
                matched = pi[matched-1];
            }
        }
    }
    //ret.push_back(0);

    //return ret;
    return position;
}

int main(void)
{
    int N;
    std::string A, B;

    scanf("%d\n", &N);
    std::cin >> A;
    std::cin >> B;
    //A = A + A;
    B = B + B;
    //kmpSearch(A, B);
    //std::cout << kmpSearch(A, B)[0];
    std::cout << kmpSearch(B, A);
    //printf("%d\n", kmpSearch(A, B)[0]);
    return 0;
}

