// In this algorithm just take the min element and place at its right place
// TC : O(n2) 
// Selection Sort is an unstable Algorithm (Doesn't guarantee to preserve the order)

#include<iostream>
using namespace std;

int main()
{
  int arr[]={64,25,12,22,11};
  int n=5;
  for(int i=0;i<n-1;i++)
  {
    int minIndex=i;
    for(int j=i+1;j<n;j++)
    {
      if(arr[j]<arr[minIndex])
      {
        minIndex=j;
      }
    }
    swap(arr[i],arr[minIndex]);
  }
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
}