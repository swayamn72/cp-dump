#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,x,y; cin >> n >> x >> y;
    ll res = min(x,y);
    n--;
    if(n==0){
        cout << res;
        return 0;
    }
    ll l=1,r=max(x,y)*n;
    res = r;
    while(l<=r){
        ll m = l + (r-l)/2;
        if((m/x + m/y)>=n){
            res = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }
    cout << res + min(x,y) << endl;
}