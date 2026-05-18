#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
ll ncr(ll n, ll r){
    if(r>n || r<0) return 0;
    r = min(r,n-r);
    ll res = 1;
    for(ll i=1; i<=r; i++){
        res = res * (n-r+i)/i;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,t; cin >> n >> m >> t;
    ll res = 0;
    for(ll i=4; i<=t-1; i++){
        ll boys = i, girls = t-i;
        if(boys<=n && girls<=m){
            res += ncr(n,boys) * ncr(m,girls);
        }
    }
    cout << res;
}