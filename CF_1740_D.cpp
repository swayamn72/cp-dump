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
        ll n,m,k; cin >> n >> m >> k;
        vi arr(k); for(auto &x : arr) cin >> x;
        bool flag = true;
        ll ptr = k;
        ll buffer = n*m-3;
        set<ll> s;
        for(ll i=0; i<k; i++){
            s.insert(arr[i]);
            while(ptr>0 && s.count(ptr)){
                s.erase(ptr);
                ptr--;
            }
            if(s.size()>=buffer){
                flag = false;
                break;
            }
        }        
        cout << (flag ? "YA" : "TIDAK") << "\n"; 
    }
}