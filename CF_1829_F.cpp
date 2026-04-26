#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<ll> arr(n,0);
        for(ll i=0; i<m; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            arr[u]++; arr[v]++;
        }
        set<ll> s;
        for(auto a : arr) if(a!=1) s.insert(a);
        if(s.size()==1){
            ll val = 1;
            for(auto a : s) val = a;
            cout << val << " " << val-1 << "\n";
        }else{
            map<ll,ll> mp;
            for(auto a : arr) if(a!=1) mp[a]++;
            ll val1 = -1; ll val2 = -1;
            for(auto a : mp){
                if(a.second==1) val1 = a.first;
                else val2 = a.first;
            }
            cout << val1 << " " << val2-1 << "\n";
        }   
    }
}