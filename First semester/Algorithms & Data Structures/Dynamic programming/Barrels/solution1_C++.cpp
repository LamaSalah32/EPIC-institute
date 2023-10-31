#include <bits/stdc++.h
using namespace std;

int main() {
    int n;  cin >> n;
    int dp[n + 1][3];
    dp[1][0] = 1, dp[1][1] = 1, dp[1][2] = 1;

    for (int i = 2; i <= n; i++){
        for (int j = 0; j < 3; j++){
            if (j == 0 || j == 1)
                dp[i][j] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
            else
                dp[i][j] = dp[i-1][0] + dp[i-1][1];
        }
    }

    cout << dp[n][0] + dp[n][1] + dp[n][2];

    return 0;
}