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
        
        auto ask = [&](ll l, ll r)->ll{
            cout << "? " << l << " " << r << endl;
            ll ans; cin >> ans;
            return ans;
        };
        ll num = ask(1,n);
        if(num==n || num==0){
            cout << "! NO" << endl;
            continue;
        }
        ll num2 = ask(1,num);
        if(num2==num){
            cout << "! NO" << endl;
        }else{
            cout << "! YES" << endl;
        }
    }
}