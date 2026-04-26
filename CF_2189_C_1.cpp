#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        if(n%2==0){
            vector<ll> res(n); res[0] = n; res[n-1] = 1;
            for(ll i=1; i<n-1; i++){
                if(i%2==1) res[i] = i+2;
                else res[i] = i;
            }
            for(auto a : res) cout << a << " ";
            cout << "\n";
        }else{
            vector<ll> res(n);
            res[0] = n-1; res[n-1] = n; res[n-2] = 1;
            for(ll i=1; i<n-2; i++){
                if(i%2==1) res[i] = i+2;
                else res[i] = i;
            }
            for(auto a : res) cout << a << " ";
            cout << "\n";
        }
    }
}