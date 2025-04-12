//You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 

//Note: The answer should be returned in an increasing format.You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 

//Note: The answer should be returned in an increasing format.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        vector<int> ans;
        unordered_map<int, int> mp;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        for (auto& i : mp) {
            if (i.second > n / 3) {
                ans.push_back(i.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};
    vector<int> result = sol.findMajority(arr);

    cout << "Majority elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
