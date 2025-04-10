#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void pushZerosToEnd1(vector<int>& arr) {
        // code here
        int i=0,j=0;
        while(j<arr.size())
        {
            if(arr[j]!=0)
            {
                arr[i]=arr[j];
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        while(i<arr.size())
        {
            arr[i]=0;
            i++;
        }
    }

    void pushZerosToEnd2(vector<int>& arr) {
      int i = 0;
      for (int j = 0; j < arr.size(); j++) {
          if (arr[j] != 0) {
              swap(arr[i], arr[j]);
              i++;
          }
      }
  }
};

int main() {
  Solution sol;
  vector<int> arr = {0, 1, 0, 3, 12};

  cout << "Original array: ";
  for (int num : arr) {
      cout << num << " ";
  }
  cout << endl;

  sol.pushZerosToEnd1(arr);

  cout << "Array after pushing zeros to the end: ";
  for (int num : arr) {
      cout << num << " ";
  }
  cout << endl;

  sol.pushZerosToEnd2(arr);

  cout << "Array after pushing zeros to the end: ";
  for (int num : arr) {
      cout << num << " ";
  }
  cout << endl;

  return 0;
}
