#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    ll n = s.size();
    vi lps(n,0);
    ll len = 0, i = 1;
    while(i<n){
        if(s[i]==s[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len!=0){
                len = lps[len-1];
            }else{
                i++;
            }
        }
    }
    ll longest = lps[n-1];
    if(n<3 || longest==0){
        cout << "Just a legend";
        return 0;
    }
    bool flag = false;
    for(ll i=1; i<n-1; i++){
        if(lps[i]==longest){
            flag = true;
            break;
        }
    }
    
    if(flag){
        cout << s.substr(0,longest);
        return 0;
    } 
    longest = lps[longest-1];
    if(longest>0){
        cout << s.substr(0,longest);
        return 0;
    }
    cout << "Just a legend";
}