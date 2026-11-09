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
        ll k; cin >> k;
        ll temp = 1;
        ll res = 0;
        while(k>=0){
            ll low = 1;
            for(ll i=0; i<temp-1; i++) low*=10;
            ll high = low*10-1;
            ll sum = (high*(high+1)/2) - (low-1*(low))/2;
            ll num = temp*(high-low+1);
            if(num>=k){
                k-=num;
                res += sum;
            }else{
                ll div = num/temp;
                ll nextnum = num+div-1;
                res += (nextnum*(nextnum+1)/2)-()
            }
        }       
        cout << res << "\n"; 
    }
}