class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int>mpp;
        // bool used = false;
        for(int it : nums) {
            mpp[it]++;
        }
        int cnt = 0;
        for(int i = 0; i< n; i++) {
            if(mpp[nums[i]] <= 0) continue;
            mpp[nums[i]]--;
            int partner = k - nums[i];
            if(mpp[partner] <= 0) {
                mpp[nums[i]]++;
                continue;
            }
            mpp[partner]--;
            cnt++;
        }
        return cnt;
    }
};