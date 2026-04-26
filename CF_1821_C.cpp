#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        string s; cin >> s;
        ll n = s.size();
        ll res = LLONG_MAX;
        for(ll i=0; i<26; i++){
            char ch = 'a' + i;
            ll ans = 0;
            ll left = -1;
            for(ll j=0; j<n; j++){
                if(s[j]==ch){
                    ll val = j-left-1;
                    if(val>0){
                        ans = max(ans, (ll)floor(log2(val)) + 1);
                    } 
                    left = j;
                }
            }
            if(n-left-1>0){
                ans = max(ans, (ll)floor(log2(n-left-1)) + 1);
            }
            res = min(res, ans);
        }
        cout << res << "\n";
    }
}