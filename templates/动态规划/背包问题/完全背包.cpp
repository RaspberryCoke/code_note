int w[MAX_LEN];
int v[MAX_LEN];
int dp[MAX_LEN][MAX_LEN];
int N, V;
//完全
int backpack() {
 // 对第0行进行初始化操作
 for (int i = 0; i <= V; ++i) {
  // 如果只能选择第一个数据，而且能选无数次
  // 那就将所有的容量都哪来装第一个物品
  dp[0][i] = i / v[0] * w[0];
 }
 for (int i = 1; i < N; ++i) {
  for (int j = 0; j <= V; ++j) {
   if (j >= v[i]) {
    dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + w[i]);
   }else {dp[i][j] = dp[i - 1][j];}
  }
 }return dp[N - 1][V];
}

// 作者：牧牛的铃铛
// 链接：https://www.zhihu.com/question/484180920/answer/2574186966
// 来源：知乎
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。