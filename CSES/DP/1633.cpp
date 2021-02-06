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

const int mod = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<ll> dp(n + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      if (i - j >= 0) {
        dp[i] += dp[i - j];
        dp[i] %= mod;
      }
    }
  }
  cout << dp[n];
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  //cin >> t;
  while (t--) solve();
}