#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        bool flag = true;
        for(ll i=1; i<n-1; i++){
            if(s[i]=='?' && s[i+1]==s[i-1] && s[i+1]!='?'){
                flag = false;
                break;
            }
            if(s[i]==s[i+1] && s[i]==s[i-1] && s[i]!='?'){
                flag = false;
                break;
            }
        }
        if(!flag){
            cout << 0 << "\n";
            continue;
        }
        if(n==2 && s=="??"){
            cout << 4 << "\n";
            continue;
        }
        
        // start with 00
        bool flag1 = true;
        ll count = 0;
        bool temp = false;
        for(ll i=0; i<n; i++){
            count++;
            if(!temp && s[i]=='1'){
                flag1 = false;
                break;
            }else if(temp && s[i]=='0'){
                flag1 = false;
                break;
            }
            if(count==2){
                count = 0;
                temp = !temp;
            }
        }

        // start with 11
        bool flag2 = true;
        count = 0;
        temp = true;
        for(ll i=0; i<n; i++){
            count++;
            if(!temp && s[i]=='1'){
                flag2 = false;
                break;
            }else if(temp && s[i]=='0'){
                flag2 = false;
                break;
            }
            if(count==2){
                count = 0;
                temp = !temp;
            }
        }

        // start with 1
        bool flag3 = true;
        count = 1;
        temp = false;
        for(ll i=0; i<n; i++){
            count++;
            if(!temp && s[i]=='1'){
                flag3 = false;
                break;
            }else if(temp && s[i]=='0'){
                flag3 = false;
                break;
            }
            if(count==2){
                count = 0;
                temp = !temp;
            }
        }
        // start with 0
        bool flag4 = true;
        count = 1;
        temp = true;
        for(ll i=0; i<n; i++){
            count++;
            if(!temp && s[i]=='1'){
                flag4 = false;
                break;
            }else if(temp && s[i]=='0'){
                flag4 = false;
                break;
            }
            if(count==2){
                count = 0;
                temp = !temp;
            }
        }
        ll res = 0;
        if(flag1) res++;
        if(flag2) res++;
        if(flag3) res++;
        if(flag4) res++;
        cout << res << "\n";
    }
}