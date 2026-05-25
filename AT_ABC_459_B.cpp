#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    vector<string> arr(n); for(auto &x : arr) cin >> x;
    string res = "";
    for(auto a : arr){
        char ch = a[0];
        if(ch=='a'||ch=='b'||ch=='c') res += '2';
        else if(ch=='d'||ch=='e'||ch=='f') res += '3';
        else if(ch=='g'||ch=='h'||ch=='i') res += '4';
        else if(ch=='j'||ch=='k'||ch=='l') res += '5';
        else if(ch=='m'||ch=='n'||ch=='o') res += '6';
        else if(ch=='p'||ch=='q'||ch=='r'||ch=='s') res += '7';
        else if(ch=='t'||ch=='u'||ch=='v') res += '8';
        else res += '9';
    }
    cout << res;
}