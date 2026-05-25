#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        s = " "+s;
        vi a(n+1); for(ll i=1; i<=n; i++) cin >> a[i];
        vi c(n+1); for(ll i=1; i<=n; i++) cin >> c[i];
        vi b(n+1,0);
        vector<bool> locked(n+1,false);
        c[0] = -2e18;
        locked[0] = true;
        bool flag = true;

        for(ll i=1; i<=n; i++){
            if(c[i]!=c[i-1]){
                if(c[i]<c[i-1]){
                    flag = false;
                    break;
                }
                b[i] = c[i];
                locked[i] = true;
                for(ll j=i; j>=1; j--){
                    if(s[j]=='1'){
                        if(locked[j-1] && b[j-1]+a[j] != b[j]){
                            flag = false;
                            break;
                        }
                        locked[j-1] = true;
                        b[j-1] = b[j] - a[j];
                    }else{
                        break;
                    }
                }
            }
        }
        if(!flag){
            cout << "No" << "\n";
            continue;
        }
        for(ll i=1; i<=n; i++){
            if(s[i]=='1'){
                b[i] = b[i-1] + a[i];
                locked[i] = true;
            }
            if(!locked[i]){
                b[i] = -1e16;
            }
            a[i] = b[i] - b[i-1];
            if(max(c[i-1],b[i])!=c[i]){
                flag = false;
                break;
            } 
        }
        if(!flag){
            cout << "No" << "\n";
            continue;
        }
        cout << "Yes" << "\n";
        for(ll i=1; i<=n; i++) cout << a[i] << " ";
        cout << "\n";
    }
}