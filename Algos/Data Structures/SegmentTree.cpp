struct segtree{
  vector<ll> tree;
  int sz;
  const int NO_OPERATION = INT_MIN;
 
  void init(int n) {
    sz = 1;
    while (sz < n) sz *= 2;
    tree.assign(2 * sz - 1, 0);
  }
 
  void propagate(int x, int lx, int rx) {
    if (tree[x] == NO_OPERATION || rx - lx == 1) return;
    tree[2 * x + 1] = tree[x];
    tree[2 * x + 2] = tree[x];
    tree[x] = NO_OPERATION;
  }
 
  void updrange(int l, int r, int v, int x, int lx, int rx) {
    propagate(x, lx, rx);
    if (l >= rx || r <= lx) return;
    if (lx >= l && rx <= r) {
      tree[x] = v;
      return;
    }
    int m = lx + rx >> 1;
    updrange(l, r, v, 2 * x + 1, lx, m);
    updrange(l, r, v, 2 * x + 2, m, rx);
  }
 
  void updrange(int l, int r, int v){
    updrange(l, r, v, 0, 0, sz);
  }
 
  ll get(int i, int x, int lx, int rx) {
    propagate(x, lx, rx);
    if (rx - lx == 1) return tree[x];
    int m = lx + rx >> 1;
    if (i < m) return get(i, 2 * x + 1, lx, m);
    else return get(i, 2 * x + 2, m, rx);
  }
 
  ll get(int i){
    return get(i, 0, 0, sz);
  }
};