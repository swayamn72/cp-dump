#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(m); for(auto &x : b) cin >> x;

        vi pref(n);
        ll ptr = 0;
        for(ll i=0; i<n; i++){
            if(ptr<m && b[ptr]<=a[i]) ptr++;
            pref[i] = ptr;
        }
        // for(auto a : pref) cout << a << " ";
        // cout << "\n";

        vi suff(n); ptr = m-1; ll temp = 0;
        for(ll i=n-1; i>=0; i--){
            if(ptr>=0 && b[ptr]<=a[i]){
                ptr--; temp++;
            } 
            suff[i] = temp;
        }
        // for(auto a : suff) cout << a << " ";
        // cout << "\n";

        ll res = LLONG_MAX;
        for(ll i=0; i<n-1; i++){
            if(pref[i]+suff[i+1] >= m){
                res = 0; break;
            }else if(pref[i]+suff[i+1]==(m-1)){
                res = min(res,b[pref[i]]);
            }
        }
        if(pref[n-1]==(m-1)) res = min(res,b[m-1]);
        if(suff[0]==(m-1)) res = min(res,b[0]);
        if(pref[n-1]==m || suff[0]==m) res = 0;
        if(res==LLONG_MAX) res = -1;
        cout << res << "\n";
    }
}
// 3 5 2 3 3 5 8 1 2
// 4 6 2 4 6
// 0 1 1 1 1 1 2 2 3
// 3 3 3 3 3 2 1 0 0

// 1 2 6 8 2 1
// 5 4 3
// 0 0 1 2 2 2
// 2 2 2 1 0 0 

// 4 3 5 4 3
// 7 4 5