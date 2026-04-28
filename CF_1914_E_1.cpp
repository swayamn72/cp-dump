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
        vector<ll> a(n); for(auto &x : a) cin >> x;
        vector<ll> b(n); for(auto &x : b) cin >> x;
        priority_queue<pair<ll,ll>> pq1, pq2;
        for(ll i=0; i<n; i++){
            pq1.push({a[i],i}); pq2.push({b[i],i});
        }
        ll alice=0, bob=0;
        while(!pq1.empty()&&!pq2.empty()){
            
        }
    }
}