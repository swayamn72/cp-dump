#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,x0,y0; cin >> n >> x0 >> y0;
        vector<pair<ll,ll>> points(n);
        for(auto &[a,b] : points) cin >> a >> b;
        ll res = 0;
        auto crossproduct = [&](pair<ll,ll> a, pair<ll,ll> b)->ll{
            return (a.first-x0)*(b.second-y0)-(a.second-y0)*(b.first-x0);
        };
        vector<bool> dead(n,false);
        for(ll i=0; i<n; i++){
            if(dead[i]) continue;
            res++;
            dead[i] = true;
            for(ll j=i+1; j<n; j++){
                if(!dead[j]&&crossproduct(points[i], points[j])==0){
                    dead[j] = true;
                }
            }
        }
        cout << res << "\n";
    }
}