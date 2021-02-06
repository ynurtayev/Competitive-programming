struct BIT{
  vector<int> f;
  int sz;
 
  void init(int n) {
    sz = n;
    f.assign(n, 0);
  }
 
  void add(int i, int val) {
    for (; i <= sz; i += i & (-i)) 
      f[i] += val;
  }
 
  int get(int i) {
    int res = 0;
    for (; i > 0; i -= i & (-i)) res += f[i];
    return res;
  }
 
  int get(int l, int r) {
    return get(r) - get(l - 1);
  }
};