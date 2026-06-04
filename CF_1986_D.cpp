#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        if(n==2){
            cout << (s[0]-'0')*10 + (s[1]-'0') << "\n";
            continue;
        }        
        ll res = LLONG_MAX;
        for(ll i=0; i<n-1; i++){
            ll twodigit = (s[i]-'0')*10 + s[i+1]-'0';
            ll ones = 0, zeros = 0, sum = 0;
            for(ll j=0; j<n; j++){
                if(j==i || j==i+1) continue;
                if(s[j] == '1') ones++;
                else if(s[j] == '0') zeros++;
                sum += s[j]-'0';
            }
            ll ans = 0;
            if(twodigit == 0 || zeros > 0) {
                ans = 0;
            } else {
                ll total = 0;
                if (twodigit>1) total += twodigit;
                total += (sum-ones); 
                if (total==0) total = 1;
                ans = total;
            }
            res = min(res, ans);
        }
        cout << res << "\n";
    }
}