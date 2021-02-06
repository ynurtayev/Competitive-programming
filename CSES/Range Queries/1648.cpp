# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
# define f first
# define s second
# define all(x) x.begin(), x.end()

using namespace std;
using ll = long long; 

void debug() { cerr << "\n";}
template<typename Head, typename... Tail>
void debug(Head a, Tail... b) {cerr << a << " "; debug(b...);}

const int N = 2e5 + 5;
const int mod = 998244353;

ll fact[N], inv[N];

ll binPower(ll a, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1; 
  }
  return res; 
} 

ll Cnk(ll n, ll k) {
  if (k > n) return 0;
  ll res = fact[n];
  res *= binPower(fact[k], mod - 2);
  res %= mod;
  res *= binPower(fact[n - k], mod - 2);
  res %= mod;
  return res;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  fact[0] = inv[0] = fact[1] = inv[1] = 1;
  for (ll i = 2; i <= n; ++i) {
    fact[i] = fact[i - 1] * i % mod;
    inv[i] = mod - mod / i * inv[mod % i] % mod;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i].f >> a[i].s;
  }
  sort(all(a));
  vector<int> v;
  ll ans = 0;
  multiset<int> s;
  for (int i = 0; i < n; i++) {
    while (!s.empty() && *s.begin() < a[i].f) {
      s.erase(s.begin());
    }
    ans += Cnk(sz(s), k - 1);
    ans %= mod;
    s.insert(a[i].s);

  }
  cout << ans;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  //cin >> t;
  while (t--) solve();
}