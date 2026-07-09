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
        ll n,x,p; cin >> n >> x >> p;
        p = min(p,2*n);
        bool flag = false;
        for(ll i=1; i<=p; i++){
            ll val = (i*(i+1))/2;
            ll pos = (x+val)%n;
            if(pos==0){
                flag = true;
                break;
            }
        }        
        cout << (flag ? "Yes" : "No") << "\n";
    }
}