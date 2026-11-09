#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        if(n==1){
            cout << 1 << "\n";
            continue;
        }
        ll ones = n, twos = n*(n-1)/2;
        ll res = ones+twos;
        // 1 2 3  5 6 7  9 10 11
        // 1 2  4 5 6 
        set<ll> s; for(auto a : arr) s.insert(a);

        vector<vi> dp(n,vi(3,0));
        // 0 : last gap was 2
        // 1 : last gap was 1 and before not 1 
        // 2 : last two gaps were 1 
        ll temp = 0;
        for(ll i=0; i<n; i++){
            // gap 1 added
            if(s.count(arr[i]+1)){
                dp[i+1][1] = (dp[i+1][1]+1)%mod;
                dp[i+1][2] = (dp[i+1][2]+dp[i][1])%mod;
                dp[i+1][1] = (dp[i+1][1]+dp[i][0])%mod;
                temp = (temp+dp[i][0]+dp[i][1])%mod;
            }
            // gap 2 added
            ll idx = i+1;
            if(s.count(arr[i]+2)){
                if(arr[i+1]!=arr[i]+2) idx++;
                dp[idx][0] = (dp[idx][0]+1+dp[i][1]+dp[i][2])%mod;
                temp = (temp+dp[i][1]+dp[i][2])%mod;
            }
        }
        res = (res+temp)%mod;
        cout << res << "\n";
    }
}