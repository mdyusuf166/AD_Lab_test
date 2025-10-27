#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target)
{
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == target)
      return mid;
    else if (arr[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main()
{
  int arr[] = {2, 3, 4, 10, 40};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 10;

  int result = binarySearch(arr, n, target);
  if (result == -1)
    cout << "Element not found";
  else
    cout << "Element found at index " << result;
}
