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
        while(pos<=n){
            if((n-pos)%d==0){
                flag = true;
                break;
            }
            pos*=2;
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
}