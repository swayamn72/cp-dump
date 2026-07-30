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
        vi v;
        for(ll i=0; i<n; i++){
            ll x; cin >> x;
            if(x!=2) v.push_back(x-2);
        }        
        if(v.empty()){
            cout << "Yes" << "\n";
            continue;
        }
        if(v.size()==1){
            cout << "No" << "\n";
            continue;
        }
        sort(v.rbegin(),v.rend());
        if(v[1]!=1){
            cout << "No" << "\n";
            continue;
        }
        if(v[0]==v.size()-1){
            cout << "Yes" << "\n";
        }else{
            cout << "No" << "\n";
        }
    }
}