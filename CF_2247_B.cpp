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
        ll n,k,m; cin >> n >> k >> m;
        if(k>m){
            cout << "NO" << "\n";
            continue;
        }        
        cout << "YES" << "\n";
        vi res(n);
        ll ptr = 0;
        while(ptr<n){
            if(ptr%k==k-1){
                res[ptr] = m-k+1;
            }else{
                res[ptr] = 1;
            }
            ptr++;
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}