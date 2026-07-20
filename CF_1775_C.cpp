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
        ll n,x; cin >> n >> x;
        if((n&x)!=x){
            cout << -1 << "\n";
            continue;
        }
        if(n==x){
            cout << x << "\n";
            continue;
        }
        bool flag = true;
        bool found = false;
        ll idx = -1;
        ll i = 0;
        while(true){
            ll val = 1LL<<i;
            if(val>n || val>(LLONG_MAX/2)) break;
            ll val1 = n&val, val2 = x&val;
            if(val1!=0 && val2==0) idx = i;
            i++;
        }
        // cout << idx << "\n";

        ll m = ((n>>(idx+1))<<(idx+1)) + (1LL<<(idx+1));

        ll diff = n^m;
        ll p = 0;
        while((1LL<<p)<=diff) p++;
        ll res = (n>>p)<<p;
        if(res==x) cout << m << "\n";
        else cout << -1 << "\n";
    }
}