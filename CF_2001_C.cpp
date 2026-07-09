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
        vector<vector<ll>> res;
        auto query = [](ll a, ll b)->ll{
            cout << "? " << a << " " << b << endl;
            ll x; cin >> x;
            return x;
        };
        set<ll> s1, s2;
        s1.insert(1);
        for(ll i=2; i<=n; i++) s2.insert(i);
        while(s2.size()>0){
            ll a = *s1.begin();
            ll b = *s2.begin();
            while(true){
                ll x = query(a,b);
                if(x==a || x==b){
                    res.push_back({a,b});
                    s1.insert(b);
                    s2.erase(b);
                    break;
                }else{
                    a = x;
                }
            }
        }
        cout << "! ";
        for(auto a : res) cout << a[0] << " " << a[1] << " " << endl;     
    }
}