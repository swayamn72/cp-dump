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
    // cin >> t;
    while(t--){
        ll xs,ys; cin >> xs >> ys;
        ll xt,yt; cin >> xt >> yt;
        if(xs==xt){
            if(yt>ys) cout << "N";
            else cout << "S";
            continue;
        }else if(ys==yt){
            if(xt>xs) cout << "E";
            else cout << "W";
            continue;
        }
        bool east = false;
        bool north = false;
        if(yt>ys) north = true;
        if(xt>xs) east = true;
        if(abs(xt-xs)==abs(yt-ys)){
            string res = "";
            if(north) res += 'N';
            else res += 'S';
            if(east) res += 'E';
            else res += 'W';
            cout << res << "\n";
            continue;
        }
        if(abs(xt-xs)>abs(yt-ys)){
            if(east) cout << "E" << "\n";
            else cout << "W" << "\n";
        }else if(abs(yt-ys)>abs(xt-xs)){
            if(north) cout << "N" << "\n";
            else cout << "S" << "\n";
        }
        string res = "";
        if(north) res += 'N';
        else res += 'S';
        if(east) res += 'E';
        else res += 'W';
        cout << res << "\n";
    }
}