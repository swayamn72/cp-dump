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
        ll n; cin >> n;
        string s; cin >> s;
        vi pref(n+1); pref[0] = 0;
        for(int i=1; i<=n; i++){
            pref[i] = pref[i-1] + (s[i-1]-'0');
        }
        map<ll,ll> mp; mp[1]++;
        ll res = 0;
        for(int i=1; i<=n; i++){
            ll val = i+1-pref[i];
            res += mp[val];
            mp[val]++;
        }
        cout << res << "\n";
    }
}
// i-l+1 = pref[i] - pref[l-1]
// i+1-pref[i] = l - pref[l-1];