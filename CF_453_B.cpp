#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vi primes;
    vector<bool> isprime(60,true);
    isprime[0] = isprime[1] = false;
    for(ll i=2; i<60; i++){
        if(isprime[i]){
            primes.push_back(i);
            for(ll j=i*i; j<60; j+=i){
                isprime[j] = false;
            }
        } 
    }
    // for(auto a : primes) cout << a << " ";
    // cout << "\n";

    ll n; cin >> n;
    vi arr(n); for(auto &x : arr) cin >> x;

    vi primemask(60,0);
    for(ll i=1; i<60; i++){
        for(ll p=0; p<17; p++){
            if(i%primes[p]==0){
                primemask[i] |= (1<<p);
            }
        }
    }
    
    ll states = 1<<17;

    vector<vector<ll>> dp(n+1,vector<ll>(states,LLONG_MAX));
    vector<vector<ll>> choice(n+1,vector<ll>(states,0LL));
    dp[0][0] = 0;

    for(ll i=0; i<n; i++){
        for(ll mask=0; mask<states; mask++){
            if(dp[i][mask]==LLONG_MAX) continue;
            for(ll v=1; v<60; v++){
                if((mask&primemask[v])==0){
                    ll nextmask = mask | primemask[v];
                    ll cost = dp[i][mask] + abs(arr[i]-v);
                    if(cost<dp[i+1][nextmask]){
                        dp[i+1][nextmask] = cost;
                        choice[i+1][nextmask] = v;
                    }
                }
            }
        }
    }
    ll best = 0;
    for(ll mask=0; mask<states; mask++){
        if(dp[n][mask]<dp[n][best]){
            best = mask;
        }
    }
    vi res(n);
    for(ll i=n; i>=1; i--){
        res[i-1] = choice[i][best];
        best ^= primemask[res[i-1]];
    }
    for(auto a : res) cout << a << " ";
}