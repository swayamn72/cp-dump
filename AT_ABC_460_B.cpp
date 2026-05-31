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
        ll x1,y1,r1,x2,y2,r2; cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        ll dist = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
        ll radiussum = (r1+r2);
        ll diff = abs(r1-r2);
        if(dist>=diff*diff && dist<=radiussum*radiussum){
            cout << "Yes" << "\n";
        }else{
            cout << "No" << "\n";
        }
    }
}