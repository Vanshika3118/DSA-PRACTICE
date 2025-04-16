#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int res = arr[n - 1] - arr[0];
        
        for (int i = 1; i < n; i++) {
            if (arr[i] - k < 0)
                continue;

            int minH = min(arr[0] + k, arr[i] - k);
            int maxH = max(arr[i - 1] + k, arr[n - 1] - k);
            res = min(res, maxH - minH);
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr = {1, 5, 8, 10};
    int k = 2;

    int result = sol.getMinDiff(arr, k);
    cout << "Minimum difference is: " << result << endl;

    return 0;
}
