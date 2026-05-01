#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,d; cin >> n >> d;
        ll pos = 1;
        bool flag = false;
        ll res = LLONG_MAX;
        ll moves = 0;
        while(pos<=n){
            if((n-pos)%d==0){
                flag = true;
                res = min(res, moves+(n-pos)/d);
            }
            pos*=2;
            moves++;
        }
        if(flag){
            cout << "YES " << res << "\n"; 
        }else{
            cout << "NO" << "\n";
        }
    }
}