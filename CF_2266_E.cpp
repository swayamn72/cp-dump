#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vi spf(2e5+1,0);
    for(ll i=0; i<=2e5; i++) spf[i] = i;
    for(ll i=2; i<=2e5; i++){
        if(spf[i]==i){
            for(ll j=i*i; j<=2e5; j+=i){
                if(spf[j]==j) spf[j] = i;
            }
        }
    }
    // for(ll i=1; i<=20; i++) cout << spf[i] << " ";
    ll t=1; 
    cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;     
        map<ll,ll> mp; for(auto a : arr) mp[a]++;
        auto it = mp.end();
        it--;
        ll maxv = it->first;
        if(k>=maxv){
            cout << 0 << "\n";
            continue;
        }
        vi v(maxv+1,LLONG_MAX);
        for(ll i=0; i<=k; i++) v[i] = 0;
        for(ll i=k+1; i<=maxv; i++){
            ll val = i;
            while(val>1){
                ll p = spf[val];
                v[i] = min(v[i],1+p*v[i/p]);
                while(val%p==0) val/=p;
            }
            
        }
        ll res = 0;
        for(auto a : mp){
            ll ans = v[a.first];
            ans *= a.second;
            res += ans;
        }
        cout << res << "\n";
    }
}