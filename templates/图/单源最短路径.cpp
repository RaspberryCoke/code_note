//链接：https://leetcode.cn/problems/network-delay-time/solutions/909575/wang-luo-yan-chi-shi-jian-by-leetcode-so-6phc/
/*
g 为图的邻接表表示，dist[i] 表示从起点 k 到节点 i 的最短路径长度。
如果 dist[i] 的值为 inf，表示节点 i 不可达。
使用优先队列 q 存储待处理的节点，按照 dist[i] 的值从小到大排序。
每次从 q 中取出 dist 最小的节点 x，更新其相邻节点 y 的最短路径长度。
如果 dist[y] > dist[x] + weight(x, y)，则更新 dist[y]
并将 y 加入 q。
最后，返回 dist 中的最大值，如果所有节点都不可达，则返回 -1。


*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        const int inf = INT_MAX / 2;
        vector<vector<pair<int,int>>> g(n);
        for(auto&t:times){
            int x=t[0]-1;
            int y=t[1]-1;
            g[x].push_back(make_pair(y,t[2]));
        }
        vector<int> dist(n,inf);
        dist[k-1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
        q.emplace(0,k-1);
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            int time=p.first,x=p.second;
            if(dist[x]<time){
                continue;
            }
            for(auto&e:g[x]){
                int y=e.first;
                int d=dist[x]+e.second;
                if(d<dist[y]){
                    dist[y]=d;
                    q.emplace(d,y);
                }
            }
        }
        int ans=*max_element(dist.begin(),dist.end());
        return ans==inf?-1:ans;
    }
};
