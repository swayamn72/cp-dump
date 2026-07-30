#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    auto ask = [](ll r, ll c)->ll{
        cout << "? " << r << " " << c << endl;
        ll a; cin >> a;
        return a;
    };
    while(t--){
        ll n,m; cin >> n >> m;
        
        ll ans1 = ask(1,1);

        if(ans1==0){
            cout << "! 1 1" << endl;
            continue;  
        }
        ll idx = ans1+1;
        if(idx>m){
            ll dist = ask(idx,1);
            cout << "! " << idx << " " << 1+dist << endl;
            continue;
        }
        if(idx>n){
            ll dist = ask(1,idx);
            cout << "! " << 1+dist << " " << idx << endl;
            continue;
        }
        ll dist1 = ask(1,idx);
        ll dist2 = ask(idx,1);
        if(dist1<=dist2){
            cout << "! " << 1+dist1 << " " << idx << endl;
        }else{
            cout << "! " << idx << " " << 1+dist2 << endl;
        }
    }
}