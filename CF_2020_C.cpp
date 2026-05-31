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
        ll a,b,c; cin >> a >> b >> c;
        ll val = 1;
        ll res = 0;
        bool flag = true;
        while(val<=a || val<=b || val<=c){
            bool p = a&val, q = b&val, r = c&val;
            if(p==0 && q==0){
                if(r==1) res += val;
            }else if(p==0 && q==1){
                if(r==1){
                    flag = false;
                    break;
                }
            }else if(p==1 && q==0){
                if(r==0){
                    flag = false;
                    break;
                }
            }else if(p==1 && q==1){
                if(r==0) res += val;
            }
            val *= 2;
        }        
        if(!flag){
            cout << -1 << "\n";
            continue;
        }
        cout << res << "\n";
    }
}

// 0 0 0 : 0     1 -> 1
// 0 0 1 : 1     0 -> 0
// 0 1 0 : 0/1   
// 0 1 1 : NO    0 -> 0 / 1 -> 0   
// 1 0 0 : NO    0 -> 1 / 1 -> 1
// 1 0 1 : 0/1
// 1 1 0 : 1     0 -> 1 
// 1 1 1 : 

// 0 0 :  0 -> 0   1 -> 1
// 0 1 :  0 -> 0   1 -> 0
// 1 0 :  0 -> 1   1 -> 1
// 1 1 :  0 -> 1   1 -> 0

