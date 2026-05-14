#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll k; cin >> k;
        if(k==0){
            cout << 0 << "\n";
            continue;
        }
        vector<pair<ll,ll>> v;
        ll x=0, y=0;   

        while(k>0) {
            ll sum = 0; 
            ll curr = 0;
            while(sum+curr+1 <= k){
                sum += (curr+1); 
                curr++;
            } 
            for(ll i=0; i<=curr; i++){
                v.push_back({x, y+i});
            }
            k-=sum;  
            x++;             
            y+=10000;   
        }

        cout << v.size() << "\n";
        for(auto [a1,b1] : v) {
            cout << a1 << " " << b1 << "\n";
        }
    }
    return 0;
}