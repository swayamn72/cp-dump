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
        ll n,m; cin >> n >> m;
        vi arr(m); for(auto &x : arr) cin >> x;
        set<ll> s;
        ll res = 0;
        for(auto a : arr){
            if(s.count(a)) res++;
            s.insert(a);
        }
        cout << res << "\n";
    }
}