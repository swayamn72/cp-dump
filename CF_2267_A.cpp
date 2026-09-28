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
        ll n; char ch; cin >> n >> ch;
        string s; cin >> s;
        ll ptr1 = 0, ptr2 = n-1;
        ll res = 0;
        while(ptr1<ptr2){
            if(s[ptr1]==s[ptr2]){
                ptr1++;
                ptr2--;
                continue;
            }else if(s[ptr1]==ch || s[ptr2]==ch){
                ptr1++;
                ptr2--;
                res++;
                continue;
            }else{
                res += 2;
                ptr1++;
                ptr2--;
            }
        }     
        cout << res << "\n";   
    }
}