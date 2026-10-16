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
        ll n; cin >> n;
        vi res;

        for(ll i=2; i<=2*n; i+=2) res.push_back(i);
        for(ll i=2*n-1; i>=3; i-=2) res.push_back(i);
        for(ll i=2; i<=2*n; i+=2) res.push_back(i);
        res.push_back(2*n-1);

        // for(ll i=2*n; i>=2; i-=2) res.push_back(i);
        // for(ll i=3; i<=2*n; i+=2) res.push_back(i);
        // for(ll i=2*n; i>=2; i-=2) res.push_back(i);
        // res.push_back(3);

        cout << res.size() << "\n";
        for(auto a : res) cout << a << " ";
        cout << "\n";      
    }
}