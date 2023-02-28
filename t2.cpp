// #pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define nline "\n"
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define mod 1000000007
#define MOD 998244353
#define INF 1000000000000000005
#define PI 3.141592653589793238462
#define sz(x) ((long long)(x).size())
#define all(x) (x).begin(), (x).end()
#define mkp make_pair
#define vll vector<ll>
#define pll pair<ll, ll>

#define fastio()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

/*
declaration
pbds A;

return iterator to the kth largest element starting from 0.
A.find_by_order(k);

returns number of items that are strictly smaller than k.
A.order_of_key(k);

returns iterator to first element greater than equal to k.
A.lower_bound(k);

returns first element greater than k.
A.upper_bound(k);

erases the element provided if element not present doesn't do anything.
A.erase(k);  // k is not an iterator

to make it sort in descending order use greater<int>
to make it a ordered multiset use less_equal<int>

*/

// uncomment to use pbds =>

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds;

/////////////////// Debug //////////////////////////////////////////////////////////

#ifndef ONLINE_JUDGE
#define debug(x)     \
  cerr << #x << " "; \
  _print(x);         \
  cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
  cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
  cerr << "{";
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
  cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
  cerr << "[ ";
  for (auto i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}

////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////// Functions //////////////////////////////////////////////

vector<ll> primes;
void sieve(ll n)
{
  bool checkPrime[n + 1] = {0};
  checkPrime[0] = 1;
  checkPrime[1] = 1;
  for (ll i = 2; i * i <= n; i++)
  {
    if (checkPrime[i] == 0)
    {
      for (ll j = i * i; j <= n; j += i)
      {
        checkPrime[j] = 1;
      }
    }
  }
  for (ll i = 0; i <= n; i++)
  {
    if (checkPrime[i] == 0)
      primes.pb(i);
  }
}
ll gcd(ll a, ll b)
{
  if (b == 0)
  {
    return a;
  }
  return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll expo(ll a, ll b)
{
  // fast expo
  // calculating (a^b)
  ll res = 1;
  while (b > 0)
  {
    if (b & 1)
    {
      res *= a;
    }
    a *= a;
    b = b >> 1;
  }
  return res;
}
ll mod_expo(ll a, ll b, ll m)
{
  // fast modulo expo
  // calculating (a^b)%m
  ll res = 1;
  while (b > 0)
  {
    if (b & 1)
    {
      res *= a;
      res %= m;
    }
    a *= a;
    a %= m;
    b = b >> 1;
  }
  return res;
}
ll inverse(ll a, ll m) { return mod_expo(a, m - 2, m); }
ll mod_add(ll a, ll b, ll m)
{
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
  a = a % m;
  b = b % m;
  return (mod_mul(a, inverse(b, m), m) + m) % m;
} // only for prime m
void google(ll t) { cout << "Case #" << t << ": "; }

///////////////////////////////////////////////////////////////////////////////////

bool digitCount(string num)
{

  int n = num.length();

  vector<int> vec(n);

  for (char ch : num)
  {
    int idx = ch - '0';
    vec[idx]++;
  }

  for (int i = 0; i < n; i++)
  {
    int val = num[i] - '0';
    if (val != vec[i])
      return false;
  }
  return true;
}

void solve()
{
  cout << digitCount("030");
}

int main()
{

  fastio();
  solve();

  return 0;
}