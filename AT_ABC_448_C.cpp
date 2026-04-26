#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,q; cin >> n >> q;
    vi arr(n); for(auto &x : arr) cin >> x;
    map<ll,ll> mp;
    for(auto a : arr) mp[a]++;
    while(q--){
        ll k; cin >> k; vi queries(k); for(auto &x : queries) cin >> x;
        for(auto a : queries){
            mp[arr[a-1]]--;
            if(mp[arr[a-1]] == 0) mp.erase(arr[a-1]);
        }
        for(auto a : mp){
            cout << a.first << "\n";
            break;
        }
        for(auto a : queries){
            mp[arr[a-1]]++;
        }
    }
}