// Maximum Sum

#include <algorithm>
#include <cstdio>
using namespace std;

int n, A[101][101], maxSubRect, subRect, negMax;

int main() {     // O(n^3) 1D DP + greedy (Kadane's) solution, 0.008 s in UVa
    while(scanf("%d", &n) != EOF){                   // the dimension of input square matrix
        negMax = -127*100*100;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
            if (A[i][j] < 0) if (A[i][j] > negMax) negMax = A[i][j];
            if (j > 0) A[i][j] += A[i][j - 1];      // only add columns of this row i
        }

        maxSubRect = -127*100*100;    // the lowest possible value for this problem
        for (int l = 0; l < n; l++) for (int r = l; r < n; r++) {
            subRect = 0;
            for (int row = 0; row < n; row++) {
            // Max 1D Range Sum on columns of this row i
            if (l > 0) subRect += A[row][r] - A[row][l - 1];
            else       subRect += A[row][r];

            // Kadane's algorithm on rows
              if (subRect < 0) subRect = 0;     // greedy, restart if running sum < 0
            maxSubRect = max(maxSubRect, subRect);
        } }
        if (maxSubRect == 0) printf("%d\n",negMax);
        else printf("%d\n", maxSubRect);
    }
  return 0;
}