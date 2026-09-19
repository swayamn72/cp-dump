#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto ask = [&](char c, ll k)->ll{
        cout << "? " << c << " " << k << endl;
        ll a; cin >> a; return a;
    };
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<pair<ll,ll>> v(n);
        for(auto &[a,b] : v) cin >> a >> b;

        sort(v.begin(),v.end(),[&](const pair<ll,ll>&a, const pair<ll,ll> &b){
            if((a.first+a.second)!=(b.first+b.second)){
                return (a.first+a.second) > (b.first+b.second);
            }
            return a.first > b.first;
        });
        auto [c,d] = v[0];
        sort(v.begin(),v.end(),[&](const pair<ll,ll>&a, const pair<ll,ll> &b){
            if((-a.first+a.second)!=(-b.first+b.second)){
                return (-a.first+a.second) > (-b.first+b.second);
            }
            return a.first > b.first;
        });
        auto [p,q] = v[0];

        ll d1 = ask('R',1e9);
        d1 = ask('R',1e9);
        d1 = ask('U',1e9);
        d1 = ask('U',1e9);

        ll d2 = ask('L',1e9);
        d2 = ask('L',1e9);
        d2 = ask('L',1e9);
        d2 = ask('L',1e9);
        d2 = ask('L',1e9);
        

        ll y = (c+d+d1+d2+q-p-5000000000LL)/2;
        ll x = (c+d+d1-y);
        cout << "! " << x-2000000000LL << " " << y-2000000000LL << endl;
    }
}