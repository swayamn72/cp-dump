#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    map<string,ll> mp;
    ll res = 0;
    for(ll i=0; i<n; i++){
        string s; cin >> s;
        for(auto &a : s){
            if(isupper(a)) a += 32;
        }
        mp[s]++;
        res = max(res,mp[s]);
    }
    cout << res;
}