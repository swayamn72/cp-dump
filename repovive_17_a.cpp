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
        map<char,ll> mp;
        for(auto a : s) mp[a]++;
        if(mp['a']>0 && mp['s']>1 && mp['n']>0 && mp['e']>0 && mp['r']>0) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}