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
        vi arr(n+1); for(ll i=1; i<=n; i++) cin >> arr[i];
        vector<bool> vis(n+1,false);
        for(ll i=1; i<=n; i++){
            if(vis[i]) continue;
            if(i-arr[i]>=1 && !vis[i-arr[i]] && arr[i-arr[i]]==arr[i]){
                vis[i-arr[i]] = true;
                vis[i] = true;
            }else if(i+arr[i]<=n && !vis[i+arr[i]] && arr[i+arr[i]]==arr[i]){
                vis[i+arr[i]] = true;
                vis[i] = true;
            }
        }
        bool flag = true;
        for(ll i=1; i<=n; i++){
            if(!vis[i]){
                flag = false;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << "\n";
    }
}