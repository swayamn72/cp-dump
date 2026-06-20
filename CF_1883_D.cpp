#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll q; cin >> q;
    multiset<ll> l, r;
    while(q--){
        char ch; ll a; ll b; cin >> ch >> a >> b;
        if(ch=='+'){
            l.insert(a); r.insert(b);
        }else{
            l.erase(l.find(a)); r.erase(r.find(b));
        }
        if(l.size()<2){
            cout << "NO" << "\n";
            continue;
        }
        auto it = l.end(); it--; ll last = *it;
        ll first = *r.begin();
        if(last>first){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
}