#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll inf = 1e11;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,x; cin >> n >> x;
    vi arr(n); for(auto &x : arr) cin >> x;
    ll states = 1<<n;
    vector<pair<ll,ll>> dp(states);
    dp[0] = {1,0};
    for(ll mask=1; mask<states; mask++){
        dp[mask] = {n+1,0};
        for(ll i=0; i<n; i++){
            if(mask&(1<<i)){
                auto [rides,wt] = dp[mask^(1<<i)];
                pair<ll,ll> next;
                if(wt+arr[i]<=x){
                    next = {rides,wt+arr[i]};
                }else{
                    next = {rides+1,arr[i]};
                }
                dp[mask] = min(dp[mask],next);
            }
        }
    }
    cout << dp[states-1].first;
}