#include <iostream>
#include <climits>
using namespace std;

int minCoins(int coins[], int n, int sum)
{
  int dp[sum + 1];
  dp[0] = 0;

  for (int i = 1; i <= sum; i++)
    dp[i] = INT_MAX;

  for (int i = 1; i <= sum; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (coins[j] <= i)
      {
        int sub = dp[i - coins[j]];
        if (sub != INT_MAX && sub + 1 < dp[i])
          dp[i] = sub + 1;
      }
    }
  }
  return dp[sum];
}

int main()
{
  int coins[] = {1, 3, 4};
  int n = sizeof(coins) / sizeof(coins[0]);
  int sum = 6;
  cout << "Minimum coins required: " << minCoins(coins, n, sum);
}
