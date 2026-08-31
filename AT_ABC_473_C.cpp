#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi v(k);
        for(auto a : arr){
            v[a-1]++;
        }
        ll maxv = *max_element(v.begin(),v.end());
        ll res = 0;
        for(auto a : v){
            if(a==maxv || a==maxv-1) res++;
        }
        cout << res;
    }
} 