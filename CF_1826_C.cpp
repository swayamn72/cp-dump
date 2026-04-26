#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll checkprime(ll n){
    for(ll i=2; i*i<=n; i++){
        if(n%i==0){
            return i;
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        if(n==1){
            cout << "YES" << "\n";
        }else if(m>=n){
            cout << "NO" << "\n";
        }else if(m==1){
            cout << "YES" << "\n";
        }else{
            if(checkprime(n)==-1 || checkprime(n)>m){
                cout << "YES" << "\n";
            }else{
                cout << "NO" << "\n";
            }
        }
    }
}