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
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        // 5 5 0
        // 4 3 3
        ll res = 0;
        ll buffer = 0;
        bool flag = true;        
        for(ll i=0; i<n; i++){
            if(a[i]==b[i]){
                continue;
            }else if(a[i]<b[i]){
                ll diff = b[i]-a[i];
                if(buffer<diff){
                    flag = false;
                    break;
                }
                buffer -= diff;
                a[i]+=diff;
            }else{
                res += a[i]-b[i];
                buffer += a[i]-b[i];
            }
        }
        if(buffer) flag = false;
        cout << (flag ? res : -1) << "\n";
    }
}