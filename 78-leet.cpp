class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0) return {{}}; 
        vector<vector<int>> result;
        result.push_back({});
        vector<int> curr;
        for(int i=0 ; i<nums.size(); i++){
            combinations(i, result, curr, nums);
        };
        return result;
    }

    void combinations(int index,vector<vector<int>> &res, vector<int> &curr, vector<int>& nums){
        if(!(index < nums.size())) return;

        curr.push_back(nums[index]);
        res.push_back(curr);

        for(int i = index+1; i<nums.size(); i++){
            combinations(i, res, curr, nums);
        }
        curr.pop_back();
        return;
    }
};

//this is the solution proposed using backtracking, but we can also solve this using bit manipulation. We can use the fact that for a set of size n, 
// there are 2^n subsets. We can represent each subset as a binary number from 0 to 2^n - 1, where the j-th bit of the binary number indicates whether 
// the j-th element of the set is included in the subset or not.

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subset = 1<<n;
        vector<vector<int>> result;

        for(int i=0 ; i < subset; i++){
            vector<int> curr;
            for(int j = 0; j < n; j++){
                if((i >> j) & 1){
                    curr.push_back(nums[j]);
                }
            }
            result.push_back(curr);
        }
        return result;
    }
};