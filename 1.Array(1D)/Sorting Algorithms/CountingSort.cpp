// Use a frequency count of elements from min to max
// TC : O(n)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int arr[]={64,25,12,22,11};
  int n=5;

  int freq[100000]={0};
  int minVal=INT_MAX,maxVal=INT_MIN;
  for(int i=0;i<n;i++){
    minVal=min(minVal,arr[i]);
    maxVal=max(maxVal,arr[i]);
  }
  for(int i=0;i<n;i++)
  {
    freq[arr[i]]++;
  }
  for(int i=minVal,j=0;i<=maxVal;i++)
  {
    while(freq[i]>0)
    {
      arr[j++]=i;
      freq[i]--;
    }
  }
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
}