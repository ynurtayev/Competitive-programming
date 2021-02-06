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
ll dp[1005][1005];

void solve() {
  int n;
  cin >> n;
  dp[1][1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char c;
      cin >> c;
      if (c == '*') dp[i][j] = 0;
      if (i == 1 && j == 1) continue;
      if (c == '.') dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
    }
  }
  cout << dp[n][n];
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  //cin >> t;
  while (t--) solve();
}