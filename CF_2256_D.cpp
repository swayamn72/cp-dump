#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        vi pref(n); 
        pref[0] = (s[0]=='0' ? 1 : -1);
        for(ll i=1; i<n; i++){
            pref[i] = pref[i-1] + (s[i]=='0' ? 1 : -1);
        }
        // for(auto a : pref) cout << a << " ";
        // cout << "\n";
        ll res = 1;
        ll ones=0, zeros=0;
        map<ll,ll> mp1, mp0;
        for(ll i=0; i<n; i++){
            if(s[i]=='1'){
                ll count = mp1[pref[i]];
                res += (ones-count);
                ones++;
                mp1[pref[i]]++;
            }else{
                ll count = mp0[pref[i]];
                res += (zeros-count);
                zeros++;
                mp0[pref[i]]++;
            }
        }
        cout << res << "\n";
    }
}