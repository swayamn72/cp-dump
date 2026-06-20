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
        if(n==1){
            cout << 1 << "\n";
            continue;
        }
        ll total = n*(n+1)/2;
        ll rem0 = 1, rem1 = 0, rem2 = 0;
        ll zeros = 0, ones = 0;
        for(auto a : s){
            if(a=='0') zeros++;
            else ones++;
            ll diff = (zeros-ones+3)%3;
            if(diff==0) rem0++;
            else if(diff==1) rem1++;
            else rem2++;
        }

        ll bad = 0;
        bad += (rem0*(rem0-1))/2;
        bad += (rem1*(rem1-1))/2;
        bad += (rem2*(rem2-1))/2;

        
        ll temp = 1;
        for(ll i=1; i<n; i++){
            if(s[i]!=s[i-1]){
                temp++;
                if(temp%3==0) bad++;
            }else{
                temp=1;
            }
        }
        cout << total - bad << "\n";
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