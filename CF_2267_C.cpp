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
    cin >> t;
    ll maxn = 3e5+2;
    vi spf(maxn);
    for(ll i=0; i<maxn; i++) spf[i] = i;
    for(ll i=2; i<maxn; i++){
        if(spf[i]==i){
            for(ll j=i*i; j<maxn; j+=i){
                if(spf[j]==j){
                    spf[j] = i;
                }
            }
        }
    }
    // for(ll i=0; i<20; i++) cout << spf[i] << " ";
    while(t--){
        ll n,x; cin >> n >> x;
        ll res = 0;
        vi arr; 
        for(ll i=0; i<n; i++){
            ll a; cin >> a;
            if(a%x==0) res += a;
            else arr.push_back(a);
        }
        
        // for(auto a : arr) cout << a << " ";
        // cout << "\n";
        if(x==1){
            cout << 0 << "\n";
            continue;
        }        
        vi primesx;
        while(x>1){
            ll p = spf[x];
            primesx.push_back(p);
            while(x%p==0){
                x/=p;
            }
        }
        ll maxv = 0;
        for(auto p : primesx){
            ll ans = 0;
            for(auto a : arr){
                if(a%p==0){
                    ans += a;
                }
            }
            maxv = max(maxv,ans);
        }
        cout << res+maxv << "\n";
    }
}

// 2,3,4 