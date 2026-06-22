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
        ll r1,c1,r2,c2,r3,c3; cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
        ll x,y; cin >> x >> y;
        ll odd = 0, even = 0;
        if((r1+c1)%2) odd++; else even++;
        if((r2+c2)%2) odd++; else even++;
        if((r3+c3)%2) odd++; else even++;
        ll a,b;
        if(even==1){
            if((r1+c1)%2==0){a=r1; b=c1;}
            else if((r2+c2)%2==0){a=r2; b=c2;}
            else {a=r3;  b=c3;}
        }else{
            if((r1+c1)%2){a=r1;b=c1;}
            else if((r2+c2)%2){a=r2; b=c2;}
            else {a=r3; b=c3;}
        }
        if((a==1||a==n)&&(b==n||b==1)){
            if(x==a || y==b){
                cout << "YES" << "\n";
            }else{
                cout << "NO" << "\n";
            }
            continue;
        }else{
            if((x-a)%2 && (y-b)%2) cout << "NO" << "\n";
            else cout << "YES" << "\n";
        }
    }
}