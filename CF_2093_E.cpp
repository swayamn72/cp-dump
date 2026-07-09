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
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll left = 0, right = n;
        ll res = 0;
        while(left<=right){
            ll m = left + (right-left)/2;
            vector<ll> vis(m,0);
            ll ptr = 0;
            ll blocks = 0;
            for(auto a : arr){
                if(a<m && vis[a]<=blocks){
                    vis[a] = blocks+1;
                } 
                while(ptr<m && vis[ptr]==blocks+1){
                    ptr++;
                } 
                if(ptr==m){
                    blocks++;
                    ptr = 0;
                }
            }
            if(blocks>=k){
                res = m;
                left = m+1;
            }else{
                right = m-1;
            }
        }        
        cout << res << "\n";
    }
}