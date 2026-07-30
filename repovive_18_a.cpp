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
        ll n; cin >> n;
        vi arr(n);
        for(auto &x : arr) cin >> x;
        if(n==1 || n==2){
            cout << "Yes" << "\n";
            continue;
        }
        vi v;
        for(auto a : arr){
            if(a==1 || a==n) continue;
            v.push_back(a);
        }
        if(is_sorted(v.begin(),v.end())){
            cout << "Yes" << "\n";
        }else{
            cout << "No" << "\n";
        }
    }
}