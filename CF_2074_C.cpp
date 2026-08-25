#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll x; cin >> x;
        ll rep = log2(x)+1;
        ll bits = __builtin_popcount(x);
        if(bits==rep || bits==1){
            cout << -1 << "\n";
            continue;
        }       
        ll res = 0;
        bool flag1 = false, flag2 = false;
        ll temp = 1;
        while(x>0){
            if(x%2 && !flag1){
                flag1 = true;
                res += temp;
            }
            if(x%2==0 && !flag2){
                flag2 = true;
                res += temp;
            }
            temp*=2;
            x>>=1;
        }
        cout << res << "\n";
    }
} 