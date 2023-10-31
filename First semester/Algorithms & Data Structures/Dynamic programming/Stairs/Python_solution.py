n = 6
a = [0, -1, 1, 2, -1, 2]
dp = [0]*n
dp[0] = 0
dp[1] = a[1]

for i in range(2, n):
    dp[i] = max(dp[i-1], dp[i-2]) + a[i]

print(dp[n-1])