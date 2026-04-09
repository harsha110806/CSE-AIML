def fibonacci_dp(n):
    dp = [0] * n

    dp[0] = 0
    dp[1] = 1

    for i in range(2, n):
        dp[i] = dp[i-1] + dp[i-2]

    for i in range(n):
        print(dp[i], end=" ")


# Input
n = 7
fibonacci_dp(n)