//Given an integer array arr[]. You need to find the maximum sum of a subarray.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr) {
        int sum = 0;
        int maxsum = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            maxsum = max(sum, maxsum);
            if (sum < 0)
                sum = 0;
        }

        return maxsum;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};

    int result = sol.maxSubarraySum(arr);

    cout << "Maximum subarray sum is: " << result << endl;

    return 0;
}
