#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n; cin >> n; n++;
    ll res = 0;
    ll val = 2; // 8
    while(true){
        ll div = n/val; // 0
        ll rem = n%val; // 7

        res += div*(val/2);
        if(rem > val/2) res += (rem-val/2);
        val*=2;
        if(div==0) break;
    }
    cout << res;
    return 0;
}