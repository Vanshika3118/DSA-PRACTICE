// Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n=arr.size();
        d=d%n;
        // while(d--)  // TC:O(n*d) SC:O(1)
        // {
        //     int first=arr[0];
        //     for(int i=1;i<n;i++)
        //     {
        //         arr[i-1]=arr[i];
        //     }
        //     arr[n-1]=first;
        // }
        
        vector<int>ans;
        for(int i=d;i<n;i++)  // TC:O(n) SC:O(n)
        {  
            ans.push_back(arr[i]);
        }
        for(int i=0;i<d;i++)
        {
            ans.push_back(arr[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            arr[i]=ans[i];
        }
        
    }
};

int main() {
  int n, d;
  cout << "Enter size of array: ";
  cin >> n;
  
  vector<int> arr(n);
  cout << "Enter array elements:\n";
  for (int i = 0; i < n; i++) {
      cin >> arr[i];
  }

  cout << "Enter number of rotations: ";
  cin >> d;

  Solution sol;
  sol.rotateArr(arr, d);

  cout << "Rotated array:\n";
  for (int num : arr) {
      cout << num << " ";
  }
  cout << endl;

  return 0;
}
