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
        ll a,b,m,k; cin >> a >> b >> m >> k;
        bool found = false;
        ll res = 0;
        while(a>0 && b>0){
            if(a==1 && b==1){
                found = true;
                break;
            }
            if(a==b) break;
            if(a>b){
                ll steps = a/b;
                if(a%b==0) steps--;
                __int128_t cost = min((__int128_t)steps, (__int128_t)(steps/m)*k+(steps%m));
                res += cost;
                a -= steps*b;
            }else{
                ll steps = b/a;
                if(b%a==0) steps--;
                __int128_t cost = min((__int128_t)steps, (__int128_t)(steps/m)*k+(steps%m));
                res += cost;
                b -= steps*a;
            }
        }
        if(!found) cout << -1 << "\n";
        else cout << res << "\n";
    }
}