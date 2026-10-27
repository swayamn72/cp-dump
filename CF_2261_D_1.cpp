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
        ll n,m; cin >> n >> m;
        if(n==1){
            cout << 0 << "\n";
            continue;
        }else if(n==2){
            cout << 1 << "\n";
            cout << 1 << " " << 1 << "\n";
            continue;
        }else if(n==3){
            cout << 2 << "\n";
            cout << 1 << " " << 1 << "\n";
            cout << 2 << " " << 2 << "\n";
            continue;
        }
        // if(n<=6){
        //     cout << n-2 << "\n";
        //     for(ll i=1; i<=n-2; i++){
        //         cout << i << " " << i+1 << "\n";
        //     }
        //     continue;
        // }
        cout << (n+1)/2 << "\n";
        for(ll i=1; i<=(n+1)/2; i++){
            cout << i << " " << i+((n+1)/2)-1 << "\n";
        }
    }
}