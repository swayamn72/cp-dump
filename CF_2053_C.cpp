#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    // cout << 38416403456028 - 38416399073312 << "\n";
    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        ll tempn = n;
        ll tempn2 = n;
        ll res = 0;
        ll temp = 1;
        while(n>=k){
            if(n&1){
                res += (temp)*(tempn+1)/2;
            }
            n>>=1;
            temp*=2;
        }
        
        // if(k==1){
        //     ll val = 1;
        //     while(tempn&1==0){
        //         val*=2;
        //         tempn>>=1;
        //     } 
        //     res += tempn2/(2*val);
        // }
        cout << res << "\n";
    }
}
