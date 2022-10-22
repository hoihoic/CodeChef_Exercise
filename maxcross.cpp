#include <iostream>
#include <vector>

#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> A(n + 2, vector<char>(n + 2));

    for (int i = 1; i < n+1; i++)
        for (int j = 1; j < n+1; j++)
            cin >> A[i][j];

    vector<vector<vector<int>>> ans(8, vector<vector<int>>(n+2, vector<int>(n+2, 0)));

    // from left
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (A[i][j] == 'X')
                ans[0][i][j] = 1 + ans[0][i][j - 1];
        }
    }

    // from left-top
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (A[i][j] == 'X')
                ans[1][i][j] = 1 + ans[1][i - 1][j - 1];
        }
    }

    // from top
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (A[i][j] == 'X')
                ans[2][i][j] = 1 + ans[2][i - 1][j];
        }
    }

    // from right-top
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (A[i][j] == 'X')
                ans[3][i][j] = 1 + ans[3][i - 1][j + 1];
        }
    }

    // from right
    for (int i = 1; i < n + 1; i++) {
        for (int j = n; j > 0; j--) {
            if (A[i][j] == 'X')
                ans[4][i][j] = 1 + ans[4][i][j + 1];
        }
    }

/*    // from right
    for (int i = n; i > 0; i--) {
        for (int j = n; j > 0; j--) {
            if (A[i][j] == 'X')
                ans[4][i][j] = 1 + ans[4][i][j + 1];
        }
    }*/

    // from right-corner-down
    for (int i = n; i > 0; i--) {
        for (int j = n; j > 0; j--) {
            if (A[i][j] == 'X')
                ans[5][i][j] = 1 + ans[5][i + 1][j + 1];
        }
    }

    // from bottom up
    for (int i = n; i > 0; i--) {
        for (int j = n; j > 0; j--) {
            if (A[i][j] == 'X')
                ans[6][i][j] = 1 + ans[6][i + 1][j];
        }
    }

    // from bottom left corner
    for (int i = n; i > 0; i--) {
        for (int j = n; j > 0; j--) {
            if (A[i][j] == 'X')
                ans[7][i][j] = 1 + ans[7][i + 1][j - 1];
        }
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (A[i][j] == 'X') {
                int a, b, c, d;
                a = ans[0][i][j] + ans[4][i][j] - 1;
                b = ans[1][i][j] + ans[5][i][j] - 1;
                c = ans[2][i][j] + ans[6][i][j] - 1;
                d = ans[3][i][j] + ans[7][i][j] - 1;
                cout << max(a, max(b, max(c, d))) << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    fast
    solve();
    return 0;
}
