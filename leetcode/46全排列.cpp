// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> res;
//         func(nums,res,0);
//         return res;
//     }
//     void func(vector<int>& nums,vector<vector<int>>& res,int level){
//         if(level<0||level>=nums.size())return;
//         if(level==(nums.size()-1)){
//             res.push_back(nums);
//             return;
//         }
//         for(int i=level;i<nums.size();i++){
//             swap(nums[i],nums[level]);
//             func(nums,res,level+1);
//             swap(nums[i],nums[level]);
//         }
//     }
// };
class Solution {
    public://全排列
        void dfs(vector<int>& nums, vector<bool> &used, vector<vector<int>> &res, vector<int> &path) {
            // 处理递归的边界情况
            if (path.size() == nums.size()) {
                res.push_back(path);
                return;
            }
            // 进行循环遍历
            for (int i = 0; i < nums.size(); ++i) {
                // 需要进行 used 修改并判断 continue，防止死循环
                if (used[i] == true) continue;
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, used, res, path);
                path.pop_back();
                used[i] = false;
            }
        }
    
        vector<vector<int>> permute(vector<int>& nums) {
            // 第一个数组用于存放结果数组
            // 第二个数组用于存放是否遍历过的标识数组
            vector<vector<int>> res;
            vector<bool> used(nums.size(), false);
            vector<int> path;
            // 需要一个用于进行递归的函数,这个函数需要传递进行三个参数：
            //used数组，res数组以及nums数组以及path数组
            dfs(nums, used, res, path);
            return res;
            // 最后返回结果即可
        }
};