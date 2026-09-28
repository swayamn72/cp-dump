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
        if(n==1){
            cout << 1 << "\n";
            continue;
        }        
        if(n==2){
            cout << 11 << "\n";
            continue;
        }
        vi res(n+1,0);
        ll div = n/3;
        if(div%2){
            res[div] = 1;
            res[2*div+1] = 1;
            if(3*div+2<=n) res[3*div+2] = 1;
        }else{
            res[div+1] = 1;
            res[2*div+1] = 1;
            if(3*div+2<=n) res[3*div+2] = 1;
        }
        
        for(ll i=1; i<=n; i++) cout << res[i];
        cout << "\n";
    }
}