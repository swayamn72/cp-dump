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
        string s; cin >> s;
        ll n = s.size();
        set<char> st = {'a','e','i','o','u'};
        vector<bool> isvowel(n,false);
        string c="", v=""; 
        for(ll i=0; i<n; i++){
            if(st.count(s[i])){
                isvowel[i] = true;
                v+=s[i];
            }else{
                c+=s[i];
            }
        }
        auto palindrome = [](string a)->bool{
            bool flag = true;
            ll ptr1 = 0, ptr2 = a.size()-1;
            while(ptr1<ptr2){
                if(a[ptr1]==a[ptr2]){
                    ptr1++; ptr2--;
                }else{
                    flag = false;
                    break;
                }
            }
            return flag;
        };
        bool flag1 = palindrome(c);
        bool flag2 = palindrome(v);
        if(!flag1 || !flag2 || (c.size()%2 && v.size()%2)){
            cout << "NO" << "\n";
            continue;
        }
        cout << "YES" << "\n";
    }
}