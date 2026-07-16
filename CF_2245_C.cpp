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
        ll n,k; cin >> n >> k;
        ll val = n^k;
        // cout << val << "\n";
        vi res(n);
        if(val==0){
            res[n-1] = 0;
            for(ll i=0; i<n-1; i++) res[i] = i+1;
            cout << "YES" << "\n";
            for(auto a : res) cout << a << " ";
            cout << "\n";
            continue;
        }
        if(val<=n-1 && n>1){
            res[n-1] = val;
            res[n-2] = 0;
            ll ptr = 1;
            for(ll i=0; i<n-2; i++){
                if(ptr==val) ptr++;
                res[i] = ptr++;
            }
            cout << "YES" << "\n";
            for(auto a : res) cout << a << " ";
            cout << "\n";
            continue;
        }
        ll temp = 1;
        while(temp<=n-1) temp*=2;
        if(val>=temp){
            cout << "NO" << "\n";
            continue;
        }
        ll num1 = n-1;
        ll num2 = val^num1;
        if(n<3){
            cout << "NO" << "\n";
            continue;
        }
        res[n-1] = num1;
        res[n-2] = num2;
        res[n-3] = 0;
        ll ptr = 1;
        for(ll i=0; i<n-3; i++){
            while(ptr==num1 || ptr==num2) ptr++;
            res[i] = ptr++;
        }
        cout << "YES" << "\n";
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}