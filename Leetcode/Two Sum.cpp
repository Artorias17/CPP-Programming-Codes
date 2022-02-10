class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, unsigned short> mp;

        for(unsigned short i = 0; i < (unsigned short)nums.size(); ++i){
            if(mp.find(target-nums[i])!=mp.end())
                return {mp[target-nums[i]], i};
            else
                mp[nums[i]] = i;
        }
        return {};
    }
};

/* Logic:
* Create an unordered map and loop through the given vector. 
* For each number in the vector check if (target - current number) exist in map. 
* If so return the current index i and the stored index in map's (target - current number) entry.
* Else add current number as key and its index as value in the map.
*/
