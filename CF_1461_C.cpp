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
        vi arr(n); for(auto &x : arr) cin >> x;
        vector<pair<ll,double>> v(m); for(auto &[u,v] : v) cin >> u >> v;  
        sort(v.rbegin(),v.rend());
        ll idx = -1;
        for(ll i=n-1; i>=0; i--){
            if(arr[i]!=(i+1)){
                idx = i+1;
                break;
            }
        }     
        if(idx==-1){
            cout << 1 << "\n";
            continue;
        }
        double fail = 1.0;
        for(auto [a,b] : v){
            if(a>=idx) fail *= (1.0-b);
        }
        cout << fixed << setprecision(6) << 1-fail << "\n";
    }
} 