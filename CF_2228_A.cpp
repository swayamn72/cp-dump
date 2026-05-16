#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll res = 0;
        ll twos = 0, ones = 0, zeros = 0;
        for(auto a : arr){
            if(a==0) zeros++;
            else if(a==1) ones++;
            else twos++;
        }        
        ll minv = min(twos,ones);
        res += minv; 
        twos -= minv; ones -= minv;
        res += (ones/3);
        res += zeros;
        res += (twos/3);
        cout << res << "\n";
    }
}