#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int currentSum = numbers[left] + numbers[right];

            if (currentSum == target) {
                // Return 1-indexed indices
                return {left + 1, right + 1};
            } else if (currentSum < target) {
                // Sum is too small, move left pointer right
                left++;
            } else {
                // Sum is too large, move right pointer left
                right--;
            }
        }
        
        // Return empty if no solution is found (though problem guarantees one)
        return {};
    }
};