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
        ll n,q; cin >> n >> q;
        ll b = 64 - __builtin_clzll(n);
        ll maxv = (1<<(b))-1;
        while(q--){
            ll s,d; cin >> s >> d;
            if(s==d){
                cout << 0 << "\n";
                continue;
            }
            if((s==maxv)||(d==maxv)){
                cout << -1 << "\n";
                continue;
            }
            if((s&d)==0){
                cout << s+d << "\n";
                continue;
            }
            ll sempty = 1;
            while((sempty&s)!=0){
                sempty<<=1;
            }
            ll dempty = 1;
            while((dempty&d)!=0){
                dempty<<=1;
            }
            ll res2 = LLONG_MAX;
            ll val = 1;
            bool found = false;
            while(val<=n){
                val<<=1;
                if((val&s)==0 && (val&d)==0){
                    res2 = min(res2,s+d+2*val);
                    found = true;
                    break;
                }
            }

            ll res1 = s+d+2*sempty+2*dempty;
            if((1&s)==0 && (1&d)==0){
                res1 = min(res1,s+d+2);
            }
            if(found) res1 = min(res1,res2);
            cout << res1 << "\n";
        }        
    }
}