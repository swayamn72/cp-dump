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
        string s; cin >> s;
        if(s[0]=='1'){
            ll zeros = 0;
            for(auto a : s) if(a=='0') zeros++;
            cout << zeros << "\n";
            continue;
        }        
        ll last0 = -1,first1 = -1;
        for(ll i=0; i<n; i++){
            if(s[i]=='1' && first1==-1){
                first1 = i;
            }else if(s[i]=='0'){
                last0 = i;
            }
        }
        if(last0<first1){
            cout << 0 << "\n";
            continue;
        }
        vi pref(n+1,0);
        for(ll i=1; i<=n; i++){
            pref[i] = pref[i-1];
            if(s[i-1]=='1') pref[i]++;
        }
        ll res = LLONG_MAX;
        for(ll i=1; i<n; i++){
            ll ans = pref[i];
            ll suffones = pref[n]-pref[i];
            ll suffzeros = n-i-suffones;
            ans += suffzeros;
            res = min(res,ans);
        }
        res = min(res,pref[n]);
        cout << res << "\n";
    }
}