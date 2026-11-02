class Solution {
public:
    void findcmb(int ind, int n, int sum, vector<int>& ds, vector<vector<int>>& res) {
        if(sum < 0 || sum == 0 || ind == 10 || ds.size() == n) {
            if(sum == 0 && ds.size() == n) res.push_back(ds);
            return;
        }

        ds.push_back(ind);
        findcmb(ind + 1, n, sum - ind, ds, res);
        ds.pop_back();
        findcmb(ind + 1, n, sum, ds, res);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ds;
        findcmb(1, k, n, ds, res);
        return res;
    }
};