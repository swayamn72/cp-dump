#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m,d; cin >> n >> m >> d;
        vi p(m), r(m);
        for(ll i=0; i<m; i++){
            cin >> p[i] >> r[i];
        }
        if(m==0){
            cout << "NO" << "\n";
            continue;
        }
        vi pref(m);
        pref[0] = r[0];
        for(ll i=1; i<m; i++) pref[i] = pref[i-1] + r[i];

        map<ll,ll> mp;
        for(ll i=0; i<m; i++) mp[p[i]] = pref[i];

        ll cycle = pref[m-1] + d*n;
        // cout << cycle << "\n";
        auto calc = [&](ll a, ll n)->ll{
            ll div = a/n;
            ll res = div*cycle;
            ll rem = a%n;
            res += (d*rem);
            auto it = mp.upper_bound(rem);
            if(it != mp.begin()){
                it--;
                res += (*it).second;
            }
            return res;
        };
        bool flag = false;
        for(ll i=0; i<m; i++){
            for(ll j=i; j<m; j++){
                ll len = p[i] + p[j] + 1;
                
                ll all1 = calc(len,n);
                ll notall = (p[i]*d + pref[i]) + (p[j]*d + pref[j]);
                if(notall>all1){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        cout << (flag ? "YES" : "NO") << "\n";
        
    }
}