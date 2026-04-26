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
        vector<ll> arr(n); for(auto &x : arr) cin >> x;
        vector<ll> b = arr;
        sort(b.begin(),b.end());
        ll median = b[n/2];
        for(ll i=0; i<n; i++){
            if(arr[i]==median) arr[i]=0;
            else if(arr[i]<median) arr[i]=-1;
            else arr[i]=1;
        }
        vector<ll> dp(n,0);
        for(ll i=0; i<n; i++){
            ll sum=0, zero=0;
            for(ll j=i; j>=0; j--){
                sum+=arr[j];
                if(arr[j]==0) zero++;
                ll len = i-j+1;
                if(len%2==0) continue;
                if(abs(sum)<zero){
                    if(j==0){
                        dp[i] = max(dp[i],1LL);
                    }else if(dp[j-1]>0){
                        dp[i] = max(dp[i],dp[j-1]+1);
                    }
                }
            }
        }
        cout << dp[n-1] << "\n";
    }
}