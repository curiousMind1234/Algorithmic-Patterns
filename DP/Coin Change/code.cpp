int coinChange(vector<int>& coins, int amount) {

    vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {

        for (int coin : coins) {

            if (coin <= i) {
                dp[i] = min(dp[i],
                            dp[i - coin] + 1);
            }
        }
    }

    if (dp[amount] == amount + 1)
        return -1;

    return dp[amount];
}

If:

A = amount
C = number of coins

Then:

Time  = O(A × C)
Space = O(A)



/*we initialize dp with amount + 1
This means initially:
dp[0]  = amount + 1
dp[1]  = amount + 1
dp[2]  = amount + 1
...
dp[amount] = amount + 1

amount + 1 is chosen because it's larger than any possible valid answer.

coins = [2]
amount = 3
We can make:
0 → yes
2 → yes
but cannot make:3

So dp[3] never gets updated:

dp[3] = 4
because amount + 1 = 4.

Therefore:
if (dp[3] == 4)
    return -1;

Meaning:
"If the answer is still our initial impossible value, no combination of coins can make the amount."*/
