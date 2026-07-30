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
        vi arr(n); for(auto &x : arr) cin >> x;
        vi odd, even;
        for(auto a : arr){
            if(a%2) odd.push_back(a);
            else even.push_back(a);
        }        
        if(odd.size()==0){
            cout << 0 << "\n";
            continue;
        }
        sort(odd.begin(),odd.end());
        ll res = accumulate(even.begin(),even.end(),0LL);
        ll m = (odd.size()+1)/2;
        for(ll i=odd.size()-1; i>=(ll)odd.size()-m; i--){
            res += odd[i];
        }
        cout << res << "\n";
    }
}