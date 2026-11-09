#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    cin >> t;
    while(t--){
        ll l,r; cin >> l >> r;
        ll sum = 0;
        for(ll i=l; i<=r; i++) sum += i;
        if(sum>=l && sum<=r){
            cout << 0 << "\n";
            continue;
        }        
        ll res = 0;
        while(true){
            if(sum<l){
                l++; sum -= (l-1); res++;
            }else{
                r--; sum -= (r+1); res++;
            }
            if(sum>=l && sum<=r) break;
        }
        cout << res << "\n";
    }
}