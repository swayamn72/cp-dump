#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

// phi of n in root n
int phi(ll &n){
    ll res = n;
    for(ll i=2; i*i<=n; i++){
        if(n%i==0){
            while(n%i==0) n/=i;
            res -= (res/i);
        }
    }
    if(n>1) res -= (res/n);
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    while(cin>>n){
        if(n==0) break;
        cout << phi(n) << "\n";
    }
}