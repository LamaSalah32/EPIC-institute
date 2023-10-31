n = 1
dp = []
for i in range(0, n+1):
    dp.append([0]*3)

dp[1][0] = 1
dp[1][1] = 1
dp[1][2] = 1

for i in range(2, n+1):
    for j in range(0, 3):
        if (j == 0) | (j == 1):
            dp[i][j] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2]
        else:
            dp[i][j] = dp[i - 1][0] + dp[i - 1][1]

print(dp[n][0] + dp[n][1] + dp[n][2])