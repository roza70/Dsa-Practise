// solution 1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == target - nums[i]) {
                    return {i, j};
                }
            }
        }
        // Return an empty vector if no solution is found
        return {};
    }
};
// solution 2
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> mp;
        for (int i = 0; i < nums.size(); i++){
            int comp=target - nums[i];
            if (mp.find(comp) != mp.end()){
                return {mp[comp],i};
            }
            mp[nums[i]]= i;

        }
    };
}