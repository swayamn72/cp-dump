#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;
        if(a==b){
            cout << 0 << "\n";
            continue;
        }      
        ll res = 0;  
        bool flag = true;
        for(ll i=0; i<n-1; i++){
            if(a[i]==b[i]){
                continue;
            }else if(a[i]<b[i]){
                flag = false;
                break;
            }else{
                ll extra = a[i]-b[i];
                if(extra>1e15){
                    flag = false; break;
                }
                res += extra;
                a[i+1] += extra*2;
            }
        }
        if(a[n-1]!=b[n-1]) flag = false;

        cout << (flag ? res : -1) << "\n";
    }
}