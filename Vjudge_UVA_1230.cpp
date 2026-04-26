#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
ll binexp(ll a, ll b, ll n){
    ll res = 1;
    ll temp = a;
    while(b>0){
        if(b&1) res *= temp; res %= n;
        b >>= 1;
        temp *= temp; temp %= n;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    while(cin>>t){
        ll x,y,n; x=t; cin >> y >> n;
        cout << binexp(x,y,n) << "\n";
    }
}