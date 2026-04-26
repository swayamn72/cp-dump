1\. Binary Exponentiation :



const ll mod = 1e9+7;

ll binexp(ll a, ll b){

&#x20;       ll res = 1;

&#x20;       a %= mod;

&#x20;       while(b>0){

&#x20;           if(1\&b) res = (res\*a)%mod;

&#x20;           a = (a\*a)%mod;

&#x20;           b >>= 1;

&#x20;       }

&#x20;       return res;

&#x20;   }



2\. Extended Euclidean Algorithm :



ll extGCD(ll a, ll b, ll \&x, ll \&y) {

&#x20;   if (b == 0) {

&#x20;       x = 1;

&#x20;       y = 0;

&#x20;       return a;

&#x20;   }

&#x20;   ll x1, y1;

&#x20;   ll d = extGCD(b, a % b, x1, y1);

&#x20;   x = y1;

&#x20;   y = x1 - y1 \* (a / b);

&#x20;   return d;

}



3\. Diophantine single solution :



bool find\_any\_solution(int a, int b, int c, int \&x0, int \&y0, int \&g) {

&#x20;   g = gcd(abs(a), abs(b), x0, y0);

&#x20;   if (c % g) {

&#x20;       return false;

&#x20;   }

&#x20;   x0 \*= c / g;

&#x20;   y0 \*= c / g;

&#x20;   if (a < 0) x0 = -x0;

&#x20;   if (b < 0) y0 = -y0;

&#x20;   return true;

}



4\. Matrix Exponentiation :



Matrix multuiply(Matrix A, Matrix B){

&#x20;   Matrix C;

&#x20;   C.a\[0]\[0] = (A.a\[0]\[0]\*B.a\[0]\[0] + A.a\[0]\[1]\*B.a\[1]\[0]) % MOD;

&#x20;   C.a\[0]\[1] = (A.a\[0]\[0]\*B.a\[0]\[1] + A.a\[0]\[1]\*B.a\[1]\[1]) % MOD;

&#x20;   C.a\[1]\[0] = (A.a\[1]\[0]\*B.a\[0]\[0] + A.a\[1]\[1]\*B.a\[1]\[0]) % MOD;

&#x20;   C.a\[1]\[1] = (A.a\[1]\[0]\*B.a\[0]\[1] + A.a\[1]\[1]\*B.a\[1]\[1]) % MOD;

&#x20;   return C;

}

Matrix power(Matrix base, ll n){

&#x20;   Matrix result = {{{1,0},{0,1}}};

&#x20;   while(n>0){

&#x20;       if(n\&1) result = multiply(result, base);

&#x20;       base = multiply(base, base);

&#x20;       n >>= 1;

&#x20;   }

&#x20;   return result;

}



5\. Sieve Of Eratosthenes



ll n;

vector<bool> isprime(n+1, true);

isprime\[0] = isprime\[1] = false;

for (ll i = 2; i\*i <= n; i++) {

&#x20;   if (isprime\[i]) {

&#x20;       for (int j = i\*i; j <= n; j+=i)

&#x20;           is prime\[j] = false;

&#x20;   }

}



6\. Miller Rabin Primality Test :



using int128 = \_\_int128\_t;



ll mulmod(ll a, ll b, ll m) {

&#x20;   return (ll)((int128)a \* b % m);

}



ll power(ll a, ll b, ll m) {

&#x20;   ll res = 1;

&#x20;   a %= m;

&#x20;   while (b > 0) {

&#x20;       if (b \& 1) res = mulmod(res, a, m);

&#x20;       a = mulmod(a, a, m);

&#x20;       b >>= 1;

&#x20;   }

&#x20;   return res;

}



bool check\_composite(ll n, ll a, ll d, int s) {

&#x20;   ll x = power(a, d, n);

&#x20;   if (x == 1 || x == n - 1) return false;

&#x20;   for (int r = 1; r < s; r++) {

&#x20;       x = mulmod(x, x, n);

&#x20;       if (x == n - 1) return false;

&#x20;   }

&#x20;   return true;

};



bool isPrime(ll n) {

&#x20;   if (n < 2) return false;

&#x20;   if (n == 2 || n == 3) return true;

&#x20;   if (n % 2 == 0 || n % 3 == 0) return false;



&#x20;   // Write n-1 as 2^s \* d

&#x20;   int s = 0;

&#x20;   ll d = n - 1;

&#x20;   while ((d \& 1) == 0) {

&#x20;       d >>= 1;

&#x20;       s++;

&#x20;   }



&#x20;   // Deterministic bases for 64-bit integers

&#x20;   for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {

&#x20;       if (n == a) return true;

&#x20;       if (check\_composite(n, a, d, s)) return false;

&#x20;   }

&#x20;   return true;

}



7\. Bipartite Graph Check : 



bool isbipartite = true;

&#x09;    vector<ll> color(n,-1);

&#x09;    queue<ll> q;

&#x09;    for(ll i=0; i<n; i++){

&#x09;        if(color\[i]==-1){

&#x09;            color\[i] = 0;

&#x09;            q.push(i);

&#x09;            while(!q.empty()){

&#x09;                ll u = q.front(); q.pop();

&#x09;                for(auto v : adj\[u]){

&#x09;                    if(color\[v]==-1){

&#x09;                        color\[v] = 1-color\[u];

&#x09;                        q.push(v);

&#x09;                    }else{

&#x09;                        if(color\[v]==color\[u]) isbipartite = false;

&#x09;                    }

&#x09;                }

&#x09;            }

&#x09;        }

&#x09;    }





