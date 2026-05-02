#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        int n = nums.size();
        
        // 1. Sort the array
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            // If the fixed number is > 0, no triplet can sum to 0 anymore
            if (nums[i] > 0) break;

            // 2. Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    // Found a triplet
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    // 3. Skip duplicates for the second and third elements
                    int last_left = nums[left];
                    int last_right = nums[right];
                    while (left < right && nums[left] == last_left) left++;
                    while (left < right && nums[right] == last_right) right--;
                }
            }
        }
        return res;
    }
};
