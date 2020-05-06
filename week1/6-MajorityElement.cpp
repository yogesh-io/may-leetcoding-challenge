'''
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
'''

//method 1:  hashmap
class Solution {
public: Solution() {ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);}
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto n : nums) {
            if (++m[n] > nums.size()/2)
                return n;
        }
        return 0;
    }
};


//method 2: sort
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};