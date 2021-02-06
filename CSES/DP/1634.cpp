# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
# define f first
# define s second
# define all(x) x.begin(), x.end()
# define pb push_back

using namespace std;
using ll = long long; 

void debug() { cerr << "\n";}
template<typename Head, typename... Tail>
void debug(Head a, Tail... b) {cerr << a << " "; debug(b...);}

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (auto &i : c) cin >> i;
  vector<int> dp(x + 1, 1e9);
  dp[0] = 0;
  for (int i = 1; i <= x; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i - c[j] >= 0) {
        dp[i] = min(dp[i], dp[i - c[j]] + 1);
      }
    }
  }
  cout << (dp[x] == 1e9 ? -1 : dp[x]);
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  //cin >> t;
  while (t--) solve();
}