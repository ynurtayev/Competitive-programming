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
  int n;
  ll s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll sum = 0;
  int j = 0, ans = 1e9;
  for (int i = 0; i < n; ++i) {
    while (j < n && sum + a[j] <= s) {
      sum += a[j++];
    }
    sum -= a[i];
    if (sum >= s) ans = min(j - i, ans);
  }
  cout << (ans == 1e9 ? - 1 : ans);
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  //cin >> t;
  while (t--) solve();
}