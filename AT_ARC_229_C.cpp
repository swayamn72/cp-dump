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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll odd = -1;
        ll res = 0;
        for(auto a : arr){
            if(a%2==0){
                res += (a/2);
            }else{
                if(odd==-1){
                    odd = a;
                }else{
                    res += (odd+a)/2;
                    odd = -1;
                }
            }
        }
        if(odd!=-1){
            res += odd/2;
        }
        cout << res << "\n";
    }
} 