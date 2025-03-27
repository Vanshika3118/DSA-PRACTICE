// In this we compare neighbour element and swap it after comparing . In this
// TC : O(n2) 
// Best case O(n)
// Stable Algorithm (Preserve the order)


#include<iostream>
using namespace std;

int main()
{
  int arr[]={64,25,12,22,11};
  int n=5;

  for(int i=1;i<n;i++)
  {
    bool swapped=false;
    for(int j=0;j<(n-i);j++) // (n-i) because at every level last element got its right place
    {
      if(arr[j]>arr[j+1])
      {
        swap(arr[j],arr[j+1]);
        swapped=true;
      }
    }
    if(swapped==false)
    break;
  }
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
}