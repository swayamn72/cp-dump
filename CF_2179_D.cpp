#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        set<ll> s; for(ll i=0; i<n; i++) s.insert(i);
        vector<ll> res(n); ll index = 0;
        ll val = pow(2,n)-1;
        ll temp = n-1;
        while(val>1){
            res[index] = val; s.erase(val);
            val -= pow(2,temp); temp--; index++;
        }
        for(ll i=3; i<n; i=i+2){
            if(s.count(i)) continue;
            res[index] = i; s.erase(i); index++;
        }
        for(ll i=0; i<n; i++){
            if(s.count(i)) continue;
            res[index] = i; s.erase(i); index++;
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}