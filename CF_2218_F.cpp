#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll even,odd; cin >> even >> odd;
        ll total = even+odd;
        if(even>odd){
            cout << "NO" << "\n";
            continue;
        }else if(even==0){
            if(odd%2==1){
                cout << "YES" << "\n";
                for(ll i=2; i<=odd; i++){
                    cout << 1 << " " << i << "\n";
                }
            }else{
                cout << "NO" << "\n";
            }
            continue;
        }
        ll rem = odd-even;
        cout << "YES" << "\n";
        for(ll i=2; i<=2*even; i++){
            cout << i-1 << " " << i << "\n";
        }
        ll num = 2*even;
        if(rem%2==0) num--;
        ll val = 2*even+1;
        for(ll i=0; i<rem; i++){
            cout << num << " " << val++ << "\n";
        }
    }
}