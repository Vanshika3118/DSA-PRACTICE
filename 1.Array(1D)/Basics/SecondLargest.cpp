#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n=arr.size();
        if(n<2) return -1;
        
        sort(arr.begin(),arr.end());
        
        int largest=arr[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]!=largest)
            return arr[i];
        }
        return -1;;
    }
};

int main() {
  Solution sol;
  vector<int> arr = {12, 35, 1, 10, 34, 1};

  int secondLargest = sol.getSecondLargest(arr);
  if (secondLargest != -1) {
      cout << "Second largest element is: " << secondLargest << endl;
  } else {
      cout << "No second largest element found." << endl;
  }

  return 0;
}
