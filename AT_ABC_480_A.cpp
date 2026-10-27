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
    // cin >> t;
    while(t--){
        char a,b,c,d; cin >> a >> b >> c >> d;
        bool flag = true;
        if((a=='A' && d=='D') || (a=='D' && d=='A')) flag = false;
        if((b=='A' && c=='D') || (b=='D' && c=='A')) flag = false;
        cout << (flag ? "Yes" : "No");        
    }
}