#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,wt; cin >> n >> wt;
    vi w(n), v(n); 
    for(int i=0; i<n; i++) cin >> w[i] >> v[i];
    ll sum = accumulate(v.begin(),v.end(),0LL);
    vi dp(sum+1,1e15);
    dp[0] = 0;
    for(int i=0; i<n; i++){
        for(int j=sum; j>=v[i]; j--){
            dp[j] = min(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    int res = 0;
    for(int i=0; i<=sum; i++){
        if(dp[i]<=wt){
            res = i; 
        }
    }
    cout << res;
}