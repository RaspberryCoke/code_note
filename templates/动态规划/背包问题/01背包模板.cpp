#include<iostream>
using namespace std;
int v[1010], w[1010]; 
int f[1010][1010]; 

auto main() -> int
{
    ios::sync_with_stdio(false);
    int N, V; cin >> N >> V;          
    // 01  N件物品, 背包最大容量为V
    for(int i = 1; i <= N; ++i) cin >> v[i] >> w[i];   
    // 输入第 i 件物品的体积 和 价值 (体积为整数 > 0)
    
    for(int i = 1; i <= N; ++i)       // 先枚举物品
        for(int j = 0; j <= V; ++j)   
        // 再枚举体积  体积从0 开始，然后 ++, 最大不超过V 
        {
            f[i][j] = f[i - 1][j];                    
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    cout << f[N][V] << endl;    // 最后输出我们的方案, 即从1 ~ N种物品种选, 所选物品体积不超过V的最大价值
    return 0;
}

// 作者：写代码的火车
// 链接：https://leetcode.cn/discuss/post/KPsfIC/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。