class Solution {
public:
    vector<int> direction{-1,0,1,0,-1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()||grid[0].empty())return 0;
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    res=max(res,dfs(grid,i,j));
                }
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>&grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size())return 0;
        if(grid[i][j]==0)return 0;
        grid[i][j]=0;
        int area=1;
        for(int a=0;a<4;a++){
            area+=dfs(grid,i+direction[a],j+direction[a+1]);
        }
        return area;
    }
};