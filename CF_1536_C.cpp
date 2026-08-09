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
        vi pref(n);
        ll d = 0, k = 0;
        map<pair<ll,ll>,ll> mp;
        vi res(n,0);
        for(ll i=0; i<n; i++){
            if(s[i]=='D') d++;
            else k++;
            ll gcdv = gcd(d,k);
            ll tempd = d/gcdv;
            ll tempk = k/gcdv;
            mp[{tempd,tempk}]++;
            res[i] = mp[{tempd,tempk}];
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}