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
        ll l,r; cin >> l >> r;
        if(r==0){
            cout << 0 << "\n";
            cout << 0 << "\n";
            continue;
        }
        ll temp = 1;
        while(temp<=r) temp*=2;
        ll n = r+1;
        vi arr(n);
        vector<bool> vis(n,false);
        ll mask = temp-1;
        ll res = 0;
        while(mask>0){
            for(ll i=r; i>=0; i--){
                if(vis[i]) continue;
                ll xorv = mask^i;
                if(xorv<=r && !vis[xorv]){
                    vis[i] = true; vis[xorv] = true;
                    arr[xorv] = i;
                    arr[i] = xorv;
                    res += (2*mask);
                }
            }
            mask/=2;
        }   
        
        cout << res << "\n";
        for(auto a : arr) cout << a << " ";
        cout << "\n"; 
    }
}