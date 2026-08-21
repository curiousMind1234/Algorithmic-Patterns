LCS
----
MATCH:
    dp[i][j] = dp[i-1][j-1] + 1

NO MATCH:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

ANSWER:
    dp[m][n]


LONGEST COMMON SUBSTRING
------------------------
MATCH:
    dp[i][j] = dp[i-1][j-1] + 1

NO MATCH:
    dp[i][j] = 0

ANSWER:
    maximum value anywhere in dp[][]
