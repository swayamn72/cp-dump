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
        if(n%2){
            cout << "NO" << "\n";
            continue;
        }        
        ll c1 = 0, c2 = 0;
        for(auto a : arr){
            if(a==1) c1++;
            else c2++;
        }
        if((c2%2)==((n/2)%2)){
            cout << "YES" << "\n";
            continue;
        }
        cout << "NO" << "\n";
    }
}