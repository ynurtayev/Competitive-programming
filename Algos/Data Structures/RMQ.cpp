struct RMQ {
  const ll maxN = 1e5 + 5;
  int logs[N], table[N][17];
 
  void init(vector<int> & a) {
    for (int i = 2; i < N; ++i) 
      logs[i] = logs[i >> 1] + 1;
    for (int i = 1; i <= sz(a); ++i) {
      table[i][0] = a[i];
    }
    for (int i = 1; i <= logs[sz(a)]; ++i) {
      int len = 1 << i;
      for (int j = 1; j + len - 1<= sz(a); ++j) 
        table[j][i] = min(table[j][i - 1], table[j + (len >> 1)][i - 1]);
    }
  }
 
  int get(int l, int r) {
    int p = logs[r - l + 1];
    int len = 1 << p;
    return min(table[l][p], table[r - len + 1][p]);
  }
};