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
    cin >> t;
    auto ask = [&](vi &v){
        cout << "? " << v.size() << " ";
        for(auto a : v) cout << a << " ";
        cout << endl;
        ll ans; cin >> ans;
        return ans;
    };
    while(t--){
        ll n; cin >> n; n*=2;
        vi curr = {1};
        vi res(n+1,0);
        for(ll i=2; i<=n; i++){
            curr.push_back(i);
            ll ans = ask(curr);
            if(ans!=0){
                res[i] = ans;
                curr.pop_back();
            }
        }
        while(!curr.empty()) curr.pop_back();
        curr.push_back(n);
        for(ll i=n-1; i>=1; i--){
            curr.push_back(i);
            if(res[i]==0){
                ll ans = ask(curr);
                res[i] = ans;
                curr.pop_back();
            }
        }

        cout << "! ";
        for(ll i=1; i<=n; i++) cout << res[i] << " ";
        cout << endl;
    }
} 