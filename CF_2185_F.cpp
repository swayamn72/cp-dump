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
        ll n,q; cin >> n >> q;
        
        ll pown = n;
        n = (1<<n);
        vi arr(n+1); for(ll i=1; i<=n; i++) cin >> arr[i];
        vi pref(n+1,0);
        for(ll i=1; i<=n; i++) pref[i] = pref[i-1]^arr[i];
        
        for(ll i=0; i<q; i++){
            ll b,c; cin >> b >> c;
            ll res = 0;

            for(ll k=1; k<=pown; k++){
                ll s = (1<<(k-1));
                ll block = (b-1)/s;
                ll oppblock = 1 ^ block;

                ll oppl = oppblock * s + 1;
                ll oppr = oppl + s - 1;
                ll oppskill = pref[oppr] ^ pref[oppl-1];

                ll l = block*s+1;
                ll r = l+s-1;
                ll skill = pref[r]^pref[l-1]^arr[b]^c;

                bool flag = false;
                if(skill>oppskill){
                    flag = true;
                }else if(skill==oppskill){
                    if(!(block%2)) flag = true;
                }
                if(!flag) res += s;
            }
            cout << res << "\n";
        }
        
    }
} 