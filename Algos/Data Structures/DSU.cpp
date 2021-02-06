struct DSU{
  vector<int>p, sz;
 
  void init(int n){
    p.assign(n + 1, 0);
    sz.assign(n + 1, 1);
    for(int i = 1;i <= n; ++i)p[i] = i;
  }
 
  int get(int x){
    return p[x] = (p[x] == x ? x : get(p[x]));
  }
 
  void merge(int a, int b){
    a = get(a), b = get(b);
    if(a == b) return;
    if(sz[a] > sz[b])swap(a, b);
    p[a] = b;
    sz[b]+=sz[a];
  }
};