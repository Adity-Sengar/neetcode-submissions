#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        // 1. Count frequencies of each number
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        // 2. Create buckets where index = frequency
        // We use n + 1 because a number can appear at most n times
        vector<vector<int>> buckets(n + 1);
        for (auto const& [num, freq] : count) {
            buckets[freq].push_back(num);
        }
        
        // 3. Collect the top k elements starting from the end of buckets
        vector<int> res;
        for (int i = n; i >= 0; i--) {
            for (int num : buckets[i]) {
                res.push_back(num);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        
        return res;
    }
};