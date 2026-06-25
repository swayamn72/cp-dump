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
        ll n,b,c; cin >> n >> b >> c;
        // if(b==0 && c==0){
        //     cout << -1 << "\n";
        //     continue;
        // }
        if(b==0){
            if(c==n-2 || c==n-1){
                cout << n-1 << "\n";
            }else if(c<n){
                cout << -1 << "\n";
            }else{
                cout << n << "\n";
            }
            continue;
        }
        if(c>=n){
            cout << n << "\n";
            continue;
        }
        ll ready = (n-1-c)/b + 1;
        cout << n-ready << "\n";
        // cout << "LOL" << "\n";
    }
}