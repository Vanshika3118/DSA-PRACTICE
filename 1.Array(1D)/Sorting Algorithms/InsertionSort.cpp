// In this , take cards ony by one compare and then insert them ai its right position. 
// TC : O(n)
// Best Case O(n) Already sorted
// Stable 

#include<iostream>
using namespace std;

int main()
{
  int arr[]={64,25,12,22,11};
  int n=5;

  for(int i=1;i<n;i++)
  {
    int temp=arr[i];
    int j=i-1;
    for( ;j>=0;j--)
    {
      if(arr[j]>temp)
      {
        arr[j+1]=arr[j];
      }
      else
      {
        break;
      }
    }
    arr[j+1]=temp;
  }

  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
}
