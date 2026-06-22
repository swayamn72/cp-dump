#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,q; cin >> n >> q;
    vi arr(n);
    for(auto &x : arr){
        cin >> x; x--;
    } 
    ll l = 30;
    vector<vector<ll>> up(n, vector<ll>(l+1,0)), sum(n, vector<ll>(l+1,0));
    for(ll i=0; i<n; i++){
        up[i][0] = arr[i];
        sum[i][0] = i+1;
    }
    for(ll j=1; j<=l; j++){
        for(ll i=0; i<n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
            sum[i][j] = sum[i][j-1] + sum[up[i][j-1]][j-1];
        }
    }
    while(q--){
        ll t,b; cin >> t >> b; b--;
        ll total = 0;
        for(ll i=0; i<=l; i++){
            if((t>>i)&1){
                total += sum[b][i];
                b = up[b][i];
            }
        }
        cout << total << "\n";
    }
}