#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll a,b,c; cin >> a >> b >> c;
        ll sum = a + b + c;
        if(sum%2){
            cout << "No" << "\n";
            continue;
        }
        ll a1,a2,a3,b1,b2,b3,c1,c2,c3;
        bool flag = false;
        
        if(a%2){
            flag = true;
            a1 = a/2;
            a2 = a/2+1;
        }else{
            a1 = a/2;
            a2 = a/2;
        }
        if(b%2){
            if(!flag){
                flag = true;
                b1 = b/2;
                b2 = b/2+1;
            }else{
                b1 = b/2+1;
                b2 = b/2;
            }
        }else{
            b1 = b/2;
            b2 = b/2;
        }
        if(c%2){
            c1 = c/2+1;
            c2 = c/2;
        }else{
            c1 = c/2;
            c2 = c/2;
        }
        cout << "Yes" << "\n";
        cout << a1 << " " << b1 << " " << c1 << " " << a2 << " " << b2 << " " << c2 << "\n";
    }
}