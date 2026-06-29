#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m; cin >> n >> m;
    vi a(n), d(n), b(n);
    for(ll i=0; i<n; i++){
        cin >> a[i] >> d[i] >> b[i];
    }
    vector<vector<ll>> v(n,vector<ll>(3));
    for(ll i=0; i<n; i++){
        v[i] = {d[i],a[i],b[i]};
    }
    sort(v.begin(),v.end());
    map<ll,ll> mp;
    for(auto x : a) mp[x]++;
    ll ptr = 0;
    
    for(ll i=1; i<=m; i++){
        if(ptr>=n){
            cout << mp.size() << "\n";
            continue;
        }
        if(v[ptr][0]!=i){
            cout << mp.size() << "\n";
            continue;
        }
        while(ptr<n && v[ptr][0]==i){
            mp[v[ptr][1]]--;
            if(mp[v[ptr][1]]==0) mp.erase(v[ptr][1]);
            mp[v[ptr][2]]++;
            ptr++;
        }
        cout << mp.size() << "\n";
    }
}