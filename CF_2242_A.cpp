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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        bool flag = false;
        ll count = 0;
        for(auto a : arr){
            if(a>2){
                flag = true;
                break;
            }
            if(a>1)count++;
        } 
                
        if(count>1) flag = true;
        cout << (flag ? "YES" : "NO") << "\n";
    }
}