#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,l; cin >> n >> l;
        vi arr(n); for(auto &x : arr) cin >> x;
        if(n==1){
            cout << "Yes";
            continue;
        }
        ll twos = 0;
        for(auto a : arr) if(a==2) twos++;
        bool flag = true;
        ll i=1;
        for(auto a : arr){
            if(i+1>l && a==2){
                flag = false;
                break;
            } 
            if(a==2){
                i+=3;
            }else{
                i+=2;
            }
        }
        cout << (flag ? "Yes" : "No");
    }
} 