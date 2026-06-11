#include <bits/stdc++.h>
using namespace std;

inline unsigned int step(unsigned int &s){
    s ^= s << 7;
    s ^= s >> 23;
    s ^= s << 12;
    return s;
}

static uint32_t cntHigh[1u << 16]; // 65536 * 4B = 256 KB
static uint32_t cntLow [1u << 16]; // 256 KB  (total well below limit)

int main(){
    freopen("median.in","r",stdin);
    freopen("median.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int n, x;
    if(!(cin >> n >> x)) return 0;
    unsigned int seed0 = x;

    const unsigned HIGH_BITS = 16;
    const unsigned LOW_BITS  = 16;
    const unsigned LOW_MASK  = (1u << LOW_BITS) - 1u;

    unsigned long long k = (n - 1ull) / 2ull; // median rank (0-based)

    // First pass: count high 16-bit prefixes
    for (unsigned int i = 0; i < n; ++i){
        unsigned int v = step(x);
        ++cntHigh[v >> LOW_BITS];
    }

    // Find bucket containing median
    unsigned long long acc = 0;
    unsigned int bucket = 0;
    for (; bucket < (1u << HIGH_BITS); ++bucket){
        unsigned long long nxt = acc + cntHigh[bucket];
        if (nxt > k) break;
        acc = nxt;
    }

    // Second pass: regenerate sequence, count low bits inside chosen bucket
    unsigned int y = seed0;
    for (unsigned int i = 0; i < n; ++i){
        y = step(y);
        if ((y >> LOW_BITS) == bucket)
            ++cntLow[y & LOW_MASK];
    }

    unsigned long long need = k - acc;
    unsigned long long cur = 0;
    unsigned int lowPart = 0;
    for (; lowPart < (1u << LOW_BITS); ++lowPart){
        unsigned long long nxt = cur + cntLow[lowPart];
        if (nxt > need) break;
        cur = nxt;
    }

    unsigned int answer = (bucket << LOW_BITS) | lowPart;
    cout << answer << '\n';
    return 0;
}
