#include <bits/stdc++.h>
using namespace std;
#define DEBUG false
#define endl '\n'

class Bitset{
    public:
    std::vector<uint64_t> bits;
    int size;

    Bitset(int n) : size(n), bits((n + 63) / 64, 0) {}

    void flipRange(int l, int r) {
        int leftBlock = l / 64, leftOffset = l % 64;
        int rightBlock = r / 64, rightOffset = r % 64;

        if (leftBlock == rightBlock) {
            bits[leftBlock] ^= ((1ULL << (rightOffset - leftOffset + 1)) - 1) << leftOffset;
        } else {
            bits[leftBlock] ^= ~((1ULL << leftOffset) - 1);
            for (int i = leftBlock + 1; i < rightBlock; ++i) {
                bits[i] ^= ~0ULL;
            }
            bits[rightBlock] ^= (1ULL << (rightOffset + 1)) - 1;
        }
    }
    bool getBit(int index) {
        return (bits[index / 64] >> (index % 64)) & 1;
    }
};

void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}

int N, M, Q;
const int mod = 1e9+7;
vector<bool> pfx;
//vector<int> precalculate;
int main() {
    if (DEBUG) {
        setIO("test");
    } else {
        setIO();
    }
    cin >> N >> M >> Q;
    Bitset bs(1e9+1);
    /*
    precalculate.assign(N+1, 0);
    precalculate[0] = 1;
    for(int i = 1; i<N+1; i++){
        precalculate[i] = precalculate[i-1] * 2;
        precalculate[i] %= mod;
    }*/
    for(int i = 0; i<M; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        bs.flipRange(a, b);
    }
    for(int i = 0; i < Q; i++){
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        int ans = 0;
        int size = 0;
        for(int i = l; i < r-(k - size); i++){
            if(bs.getBit(i) && size < k){
                ans += (1 << k-size-1);
                ans %= mod;
                size++;
            }
        }
        for(int i = r - (k - size); i < r; i++){
            if(bs.getBit(i) == 1){
                ans += (1 << k-size-1);
                ans %= mod;
            }
            size++;
        }
        cout << ans << endl;
    }
    /*
    pfx.assign(N+1, 0);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b; 
        a--, b--;
        pfx[a] = pfx[a] ^ 1;
        if (b + 1 < N) pfx[b + 1]  = pfx[b+1] ^ 1;
    }
    for (int i = 1; i < N; i++) {
        pfx[i] = pfx[i] ^ pfx[i-1];
    }
    for (int i = 0; i < Q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        l--; 
        long long ans = 0;
        int size = 0;
        for(int i = l; i < r-(k - size); i++){
            if(pfx[i] && size < k){
                ans += precalculate[k-size-1];
                ans %= mod;
                size++;
            }
        }
        for(int i = r - (k - size); i < r; i++){
            ans += (pfx[i] ?  precalculate[k - size-1]: 0);
            ans %= mod;
            size++;
        }
        cout << ans << endl;
    }*/
}
