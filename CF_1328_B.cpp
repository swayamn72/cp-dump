#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        ll pos = n-1;
        ll val = 1;
        ll temp = 2;
        while(val+temp <= k){
            val += temp;
            temp++;
            pos--;
        }
        // cout << val << "\n";
        ll diff = k-val;
        // cout << diff << "\n";
        string res(n,'a');
        if(diff==0){
            res[pos] = 'b';
            res[pos-1] = 'b';
            cout << res << "\n";
            continue;
        }
        pos--;
        res[pos-1] = 'b';
        ll idx = n-1;
        for(ll i=1; i<diff; i++) idx--;
        res[idx] = 'b';
        cout << res << "\n";
    }
}