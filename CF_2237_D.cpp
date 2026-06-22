#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        ll count0 = 1, count1 = 0, count2 = 0;
        ll curr = 0;
        ll res = 0;
        for(ll i=0; i<n; i++){
            curr += (s[i]=='1' ? 1 : -1);
            ll mod = ((curr%3)+3)%3;
            if(mod==0){
                res += count1;
                res += count2;
                count0++;
            }else if(mod==1){
                res += count0;
                res += count2;
                count1++;
            }else{
                res += count0;
                res += count1;
                count2++;
            }
        }
        ll temp = 1;
        for(ll i=1; i<n; i++){
            if(s[i]!=s[i-1]){
                temp++;
            }else{
                temp = 1;
            }
            res -= (temp-1)/2;
        }
        cout << res << "\n";
        // vi dp0(n,0);
        // vi dp1(n,0);
        // if(s[0]=='0') dp0[0] = 1;
        // else dp1[0] = 1;
        // if(s[1]=='0'){
        //     dp0[1] = dp0[0]+1;
        // }else{
        //     dp1[1] = dp1[0]+1;
        // }
        // for(ll i=2; i<n; i++){
        //     if(s[i]=='0'){
        //         if(s[i-1]=='1'){
        //             dp1[i] = dp0[i-1]+1;
        //             dp0[i] = 1;
        //         }else{

        //         }
        //     }else{
        //         if(s[i-1]=='0'){
        //             dp0[i] = dp1[i-1]+1;
        //             dp1[i] = 1;
        //         }
        //     }
        // }

        // cout << accumulate(dp0.begin(),dp0.end(),0LL) + accumulate(dp1.begin(),dp1.end(),0LL) << "\n";
    }
}