#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        if(n==1){
            cout << 2 << "\n";
            continue;
        }        
        ll res = 0;
        for(int x1=0; x1<=1; x1++){
            vi x(n);
            x[0] = x1;
            bool flag = true;
            for(int i=0; i<n-1; i++){
                ll val = arr[i+1]-arr[i]+1-x[i];
                if(val<0 || val>1){
                    flag = false; break;
                }
                x[i+1] = val;
            }
            if(!flag) continue;
            ll sum = accumulate(x.begin(),x.end(),0LL);
            if(arr[0]==n+x[0]-sum) res++;
        }
        cout << res << "\n";
    }
}