#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m; cin >> n >> m;
    if(m>n){
        cout << -1;
        return 0;
    }
    ll minv = (n+1)/2;
    ll res;
    for(ll i=minv; i<=n; i++){
        if(i%m==0){
            res = i;
            break;
        }
    }
    cout << res;
}