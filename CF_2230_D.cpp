#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;
        ll res = 0;
        map<ll,ll> mp1, mp2;
        vi dp(n+2,n);
        for(ll i=n-1; i>=0; i--){
            if(a[i]==b[i]){
                ll val = a[i];
                dp[val] = dp[val+1];
            }else{
                dp[a[i]] = i;
                dp[b[i]] = i;
            }
            res += (dp[1]-i);
        }
        cout << res << "\n";
    }
}