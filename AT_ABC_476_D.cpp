#include <algorithm>
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
        ll n,m,k; cin >> n >> m >> k;
        ll x,y; cin >> x >> y;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(m); for(auto &x : b) cin >> x;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        vi pref(n); pref[0] = a[0];
        for(ll i=1; i<n; i++) pref[i] = pref[i-1]+a[i];

        ll total = x+y*k;
        ll res = upper_bound(pref.begin(),pref.end(),total)-pref.begin();

        ll used = 0;
        ll sum = 0;
        for(ll i=0; i<m; i++){
            sum += b[i];
            ll need = (b[i]+k-1)/k;
            if(need+used>y) break;
            ll ones = (need+used)*k - sum;
            used += need;
            auto it = upper_bound(pref.begin(),pref.end(),ones+x+(y-used)*k);
            ll items = 0;
            if(it!=pref.begin()){
                it--; items = it-pref.begin()+1;
            }
            res = max(res,i+1+items);
        }
        cout << res;
    }
}