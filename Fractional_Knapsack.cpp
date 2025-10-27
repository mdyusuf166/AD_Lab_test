//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double FracKnap(vector<int> p1, vector<int> w2, int capacity, int n)
{
  vector<pair<double, pair<int, int>>> items;

  for (int i = 0; i < n; i++)
  {
    double ratio = (double)p1[i] / w2[i];
    items.push_back({ratio, {p1[i], w2[i]}});
  }

  sort(items.rbegin(), items.rend());

  double totalp = 0.0;
  int rem_capacity = capacity;

  for (int i = 0; i < n; i++)
  {
    int p = items[i].second.first;
    int w = items[i].second.second;

    if (w <= rem_capacity)
    {
      totalp += p;
      rem_capacity -= w;
    }
    else
    {
      totalp += rem_capacity * items[i].first;
      break; // knapsack full
    }
  }

  return totalp;
}

int main()
{
  int n;
  cout << "Enter number of items: ";
  cin >> n;

  int capacity;
  cout << "Enter knapsack capacity: ";
  cin >> capacity;

  vector<int> p1, w2;

  cout << "Enter profits: ";
  for (int i = 0; i < n; i++)
  {
    int price;
    cin >> price;
    p1.push_back(price);
  }

  cout << "Enter weights: ";
  for (int i = 0; i < n; i++)
  {
    int weight;
    cin >> weight;
    w2.push_back(weight);
  }

  double maxProfit = FracKnap(p1, w2, capacity, n);
  cout << "Maximum Profit = " << maxProfit << endl;

  return 0;
}