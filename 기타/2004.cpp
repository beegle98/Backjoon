#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

ll a[10], b[10];
ll min(ll a, ll b) {
    return  a < b ? a : b;
}
ll count(ll n, ll k) {
    ll sum = 0;
    for (ll i = k; i <= n; i *= k) {
        sum += (n / i);
    }
    return sum;
}
int main() {
    ll n, m, a5, a2;
    scanf("%lld %lld", &n, &m);
    if (m == 0) {
        printf("0");
        return 0;
    }
    a5 = count(n, 5) - count(n - m, 5) - count(m, 5);
    a2 = count(n, 2) - count(n - m, 2) - count(m, 2);
    //printf("%d %d\n",a5,a2);
    printf("%lld", min(a5, a2));
    return 0;
}