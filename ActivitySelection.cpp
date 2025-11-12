#include <bits/stdc++.h>
using namespace std;
struct Activity
{
  int start, finish;
};
bool compare(Activity a, Activity b)
{
  return a.finish < b.finish;
}
void activitySelection(Activity arr[], int n)
{
  sort(arr, arr + n, compare);
  cout << "Selected activities : ";
  int last = 0;
  cout << "(" << arr[last].start << "," << arr[last].finish << ") ";
  for (int i = 1; i < n; i++)
  {
    if (arr[i].start >= arr[last].finish)
    {
      cout << "(" << arr[i].start << "," << arr[i].finish << ") ";
      last = i;
    }
  }
}

int main()
{
  int n;
  cout << "Enter number of activitives : ";
  cin >> n;
  Activity arr[n];
  cout << "Enter start and finish times: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i].start >> arr[i].finish;
  }
  activitySelection(arr, n);
  return 0;
}