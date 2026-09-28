#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll a,b,m; cin >> a >> b >> m;
        a++;
        ll val = (b-a+1)/m;
        ll res = val * (m*(m-1))/2;
        ll rem = (b-a+1)%m;
        if(!rem){
            cout << res <<  "\n";
            continue;
        }
        ll curr = a%m, next = curr+rem-1;
        next%=m;

        if(curr<=next){
            res += ((next*(next+1))/2 - (curr*(curr-1))/2);
            cout << res << "\n";
            continue;
        }
        // next ..... curr
        ll total = ((m-1)*m)/2;
        total -= ((curr-1)*curr)/2;
        total += (next*(next+1))/2;
        res += total;
        cout << res << "\n";   
    }
}