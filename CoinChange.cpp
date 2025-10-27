#include <iostream>
using namespace std;

int countWays(int coins[], int n, int sum)
{
  int dp[sum + 1] = {0};
  dp[0] = 1; // Base case: One way to make sum 0

  // Dynamic programming approach
  for (int i = 0; i < n; i++)
  {
    for (int j = coins[i]; j <= sum; j++)
    {
      dp[j] += dp[j - coins[i]];
    }
  }
  return dp[sum];
}

int main()
{
  int n, sum;

  cout << "Enter number of coin types: ";
  cin >> n;

  int coins[n];
  cout << "Enter coin denominations: ";
  for (int i = 0; i < n; i++)
    cin >> coins[i];

  cout << "Enter target sum: ";
  cin >> sum;

  cout << "\nNumber of ways to make " << sum << " = " << countWays(coins, n, sum) << endl;
}
