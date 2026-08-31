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
    auto ask = [](ll u, ll v, ll d)->bool{
        cout << "? " << u << " " << v << " " << d << endl;
        ll a; cin >> a;
        return a;
    };
    while(t--){
        ll n; cin >> n;
        ll maxd = 0;
        ll u = 1;
        for(ll i=2; i<=n; i++){
            while(ask(1,i,maxd+1)){
                maxd++;
                u=i;
            }
        }
        ll v = 1;
        for(ll i=1; i<=n; i++){
            if(i==u) continue;
            while(ask(u,i,maxd+1)){
                maxd++;
                v=i;
            }
        }
        cout << "! " << u << " " << v << " " << maxd << endl;
    }
} 