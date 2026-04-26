#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,a,b,c; cin >> n >> a >> b >> c;
    ll res = 0;
    ll tempa = a, tempb = b, tempc = c, tempn = n;
    ll ans = 0;
    while(tempn>0){
        while(tempn>0 && tempn%a==0){
            ans += tempn/a;
            tempn -= 
        }
        while(tempn>0 && tempn%b==0){
            tempn-=b;
            ans++;
        }
        if(tempn==0) res = max(res, ans);
    }
    tempa = a, tempb = b, tempc = c, tempn = n;
    while(tempn>0){
        while(tempn>0 && tempn%a==0){
            tempn/=a;
            ans++;
        }
        while(tempn>0 && tempn%c==0){
            tempn/=c;
            ans++;
        }
        if(tempn==0) res = max(res, ans);
    }
    while(tempn>0){
        while(tempn>0 && tempn%b==0){
            tempn/=b;
            ans++;
        }
        while(tempn>0 && tempn%c==0){
            tempn/=c;
            ans++;
        }
        if(tempn==0) res = max(res, ans);
    }
    cout << res << "\n";
}