A substring must be continuous. When the current characters don't match, the continuous sequence is broken, so we reset dp[i][j] to 0. We cannot carry the previous result using max(top, left) because that would allow gaps, which is LCS behavior."


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
