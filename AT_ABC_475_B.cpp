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
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll one = 0, ten = 0, hun = 0;
        for(auto a : arr){
            ll digit = a%10;
            one += (digit!=0 ? (10-digit) : 0);

            digit = a%100;
            if(digit%10==0){
                ten += ((10 - (digit/10)))%10;
            }else{
                ten += ((9 - (digit/10)))%10;
            }

            digit = a%1000;
            if(digit%100==0){
                hun += (10 - (digit/100))%10;
            }else{
                hun += (9 - (digit/100))%10;
            }
        }        
        cout << one << " " << ten << " " << hun;
    }
} 