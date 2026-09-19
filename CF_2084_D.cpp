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
        ll n,m,k; cin >> n >> m >> k;
        ll rem = n - (m*k);
        ll limit = n/(m+1);
        ll val = ((rem*(m+1)<n) ? k : limit);
        vi res(n);
        for(ll i=0; i<n; i++){
            res[i] = i%val;
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}