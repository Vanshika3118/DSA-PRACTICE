#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        unordered_set<int> s;

        for(int i = 0; i < arr.size(); i++) {
            s.insert(arr[i]);
        }

        int i = 1;
        while(s.find(i) != s.end()) {
            i++;
        }

        return i;
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {3, 4, -1, 1};
    cout << "Smallest missing positive number is: " << sol.missingNumber(arr1) << endl; // Output: 2

    vector<int> arr2 = {1, 2, 0};
    cout << "Smallest missing positive number is: " << sol.missingNumber(arr2) << endl; // Output: 3

    vector<int> arr3 = {7, 8, 9, 11, 12};
    cout << "Smallest missing positive number is: " << sol.missingNumber(arr3) << endl; // Output: 1

    return 0;
}
