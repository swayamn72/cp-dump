#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    vector<vector<ll>> xy, yx;
    for(ll i=0; i<n; i++){
        ll x,y; cin >> x >> y;
        xy.push_back({x,y});
    }
    sort(xy.begin(),xy.end());
    ll res = 1;
    ll minv = xy[0][1];
    for(ll i=1; i<n; i++){
        if(xy[i][1]<minv){
            minv = xy[i][1];
            res++;
        }
    }
    cout << res;
}