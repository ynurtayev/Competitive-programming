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

const int N = 2e6;
int dp[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < N; ++i) dp[i] = 1e9;
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j > 0; j /= 10) {
      if (i - j % 10 >= 0) {
        dp[i] = min(dp[i], dp[i - j % 10] + 1);
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