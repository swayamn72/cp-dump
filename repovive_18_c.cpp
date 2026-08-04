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
        vi arr(n);for(auto &x : arr) cin >> x;
        vi v;
        for(auto a : arr) if(a-2>0) v.push_back(a-2);
        if(v.size()==0){
            cout << "Yes" << "\n";
            continue;
        }        
        ll sum = accumulate(v.begin(),v.end(),0LL);
        if(sum%2 || sum>((v.size()-1)*2)){
            cout << "No" << "\n";
            continue;
        }
        cout << "Yes" << "\n";
    }
}