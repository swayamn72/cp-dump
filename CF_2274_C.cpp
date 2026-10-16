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
    while(t--){
        ll n; cin >> n;
        
        ll l = 1, r = n;
        ll res = n;
        while(l<=r){
            ll m = l + (r-l)/2;

            ll total = 0;
            for(ll i=1; i<=m; i++){
                total += (i*(m/i));
            }
            if(total>=n){
                res = m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        vi arr(n); 

        ll temp = 1;
        ll i=0;
        for(ll j=2; j<=res; j++){
            if(i>=n) break;
            ll div = res/j;
            for(ll k=0; k<div; k++){
                ll rem = n-i;
                if(rem<j) break;
                if(i>=n) break;
                for(ll p=1; p<=j; p++){
                    if(i>=n) break;
                    arr[i++] = temp;
                }
                if(i>=n) break;
                temp++;
            }
            if(i>=n) break;
        }
        while(i<n){
            arr[i++] = temp++;
        }
        cout << res << "\n";
        for(auto a : arr) cout << a << " ";
        cout << "\n";
    }
}