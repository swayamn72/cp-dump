#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        set<pair<ll,ll>> arr;
        for(ll i=0; i<m; i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            arr.insert({u,v});
        }    
        vi pos(n);    
        for(ll i=0; i<n; i++){
            pos[i] = n-i-1;
        }
        bool flag = false;
        ll op = 0;
        while(op<n){
            bool changed = false;
            for(auto a : arr){
                if(pos[a.first]==1-pos[a.second]){
                    swap(pos[a.first],pos[a.second]);
                    changed = true;
                    op++;
                    arr.erase(a);
                }
            }
            if(!changed) break;
        }
        if(op!=m){
            cout << "No" << "\n";
            continue;
        }
        vi res;
        cout << "Yes" << "\n";
        for(auto a : pos) res.push_back(a+1);
        reverse(res.begin(),res.end());
        for(auto a : res) cout << a << " ";
        cout << "\n"; 
    }
} 