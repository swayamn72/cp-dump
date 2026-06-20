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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll ones = 0, twos = 0;
        for(auto a : arr){
            if(a==1) ones++;
            else twos++;
        }        
        if(ones%2 || (twos%2 && ones==0)){
            cout << "NO" << "\n";
        }else{
            cout << "YES" << "\n"; 
        }
    }
}