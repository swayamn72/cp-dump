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
        ll s,q; cin >> s >> q;
        vi d;
        for(ll i=1; i*i<=s; i++){
            if(s%i==0){
                d.push_back(i);
                d.push_back(s/i);
            }
        }       
        sort(d.begin(),d.end());
        d.erase(unique(d.begin(),d.end()),d.end());
        // sort(d.rbegin(),d.rend());
        // for(auto a : d) cout << a << " ";
        // cout << "\n";
        ll m = d.size();
        vi pref(m,0);
        pref[0] = d[0]*(s/d[0]);
        for(ll i=1; i<m; i++){
            pref[i] = pref[i-1] + (d[i]-d[i-1])*(s/d[i]);
        }

        while(q--){
            ll x,y; cin >> x >> y;
            if(x*y<=s){
                cout << x*y << "\n";
                continue;
            }
            if(y>x) swap(x,y);
            ll ans = 0;
            for(ll i=0; i<y; i++){

            }

            ll idx1 = upper_bound(d.begin(),d.end(),s/y) - d.begin() - 1;
            ll idx2 = upper_bound(d.begin(),d.end(),x) - d.begin() - 1;

            if(idx1>=0) ans += (d[idx1]*y);
            ans += pref[idx2];
            if(idx1>=0) ans -= pref[idx1];

            if(x>d[idx2]){
                ll w = 0;
                if(idx2 < m-1) w += s/d[idx2+1];
                ans += (x-d[idx2]) * w;
            }
            cout << ans << "\n";
        }
    }
} 