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
        ll n,m; cin >> n >> m;
        cout << n*m << "\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << ((i<<8) | j) << " ";
            }
            cout << "\n";
        }        
    }
}