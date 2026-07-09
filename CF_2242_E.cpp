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
        ll l,r,n; cin >> l >> r >> n;
        ll val = 1;
        
        while(val*2<=r) val*=2;

        if(val>l && val<=r){
            ll val2 = max(l, val/2);

            string a = "";
            while(val>0){
                if(val&1) a += '1';
                else a += '0';
                val/=2;
            }
            string b = "";
            while(val2>0){
                if(val2&1) b+='1';
                else b+='0';
                val2/=2;
            }
            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end());
            ll ptr = 0, ptr2 = 0; 
            ll n1 = a.size(), n2 = b.size();
            string res = "";
            for(ll i=0; i<n; i++){
                if(a[ptr]==b[ptr2] && a[ptr]=='1'){
                    res += '1';
                }else{
                    res += '0';
                }
                ptr++; ptr%=n1;
                ptr2++; ptr2%=n2;
            }
            cout << res << "\n";
            continue;
        }
        val = l;
        ll val2 = r;
        string a = "";
        while(val>0){
            if(val&1) a += '1';
            else a += '0';
            val/=2;
        }
        string b = "";
        while(val2>0){
            if(val2&1) b+='1';
            else b+='0';
            val2/=2;
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string s1 = "", s2 = "";
        ll ptr = 0, m = a.size();
        while(ptr<m && a[ptr]==b[ptr]){
            s1 += a[ptr]; 
            s2 += b[ptr];
            ptr++;
        }
        if(ptr!=m){
            s1 += '0';
            s2 += '1';
            ptr++;
        }
        
        for(ll i=ptr; i<m; i++){
            s1 += '1';
            s2 += '0';
        }
        ptr = 0;
        string res = "";
        for(ll i=0; i<n; i++){
            if(s1[ptr]==s2[ptr] && s1[ptr]=='1'){
                res += '1';
            }else{
                res += '0';
            }
            ptr++; ptr%=m;
        }
        cout << res << "\n";
    }
}