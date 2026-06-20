#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set<ll> s;
    map<ll,ll> mp;
    ll q; cin >> q;
    while(q--){
        char ch; cin >> ch;
        ll x; cin >> x;
        // cout << ch << " " << x << "\n";
        if(ch=='?'){
            ll i = x;
            if(mp.count(i)) i = mp[i];
            while(s.count(i)) i+=x;
            mp[x] = i;
            cout << i << "\n";
        }else{
            s.insert(x);
        }
    }
}