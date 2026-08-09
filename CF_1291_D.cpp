#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    ll n = s.size();
    vector<vector<ll>> pref(n, vi(26,0));
    pref[0][s[0]-'a']++;
    for(ll i=1; i<n; i++){
        for(ll j=0; j<26; j++){
            pref[i][j] = pref[i-1][j];
        }
        pref[i][s[i]-'a']++;
    }
    ll q; cin >> q;
    while(q--){
        ll l,r; cin >> l >> r;
        l--; r--;
        if(l==r){
            cout << "Yes" << "\n";
            continue;
        }
        if(s[r]!=s[l]){
            cout << "Yes" << "\n";
            continue;
        }
        vi v = pref[r];
        if(l!=0){
            l--;
            for(ll i=0; i<26; i++){
                v[i] -= pref[l][i];
            }
        }
        ll count = 0;
        for(auto a : v) if(a>0) count++;
        if(count>2) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}