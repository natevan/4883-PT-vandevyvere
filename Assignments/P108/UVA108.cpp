#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, e, lmax, gmax;
    cin >> N;
    vector<vector<int> > A(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> e;
            A[i].push_back(e);
        }
    }
    gmax = INT32_MIN;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            lmax = 0;
            for(int r = 0; r<N;r++){
                if(i>0) lmax+=A[r][j]-A[r][i-1];
                else lmax +=A[r][j];
            }
        }
    }
}