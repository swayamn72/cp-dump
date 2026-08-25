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
        ll a,b,c,x; cin >> a >> b >> c >> x;
        if(x<=a){
            cout << 1;
            continue;
        }
        if(x<=b){
            cout << (double)c/(double)(b-a);
            continue;
        }
        cout << 0;
    }
} 