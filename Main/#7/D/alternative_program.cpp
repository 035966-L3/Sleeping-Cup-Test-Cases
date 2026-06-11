#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int nxt[MAXN], jmp[MAXN], stp[MAXN]; int tag[MAXN];
int blk[MAXN], bl[MAXN], br[MAXN];
void rebuild(int x) {
	for (int i = br[x]; i >= bl[x]; i--) {
		if (nxt[i] < i || nxt[i] > br[x]) jmp[i] = nxt[i], stp[i] = 1;
		else jmp[i] = jmp[nxt[i]], stp[i] = stp[nxt[i]] + 1;
	}
}
void pushdown(int x) {
	if (tag[x] != -1) {
		for (int i = bl[x]; i <= br[x]; i++) nxt[i] = tag[x];
		tag[x] = -1; rebuild(x);
	}
}
int a[MAXN], lat[MAXN], buc[MAXN];
namespace sgt {
	int f[MAXN << 2];
	void build(int rt, int l, int r) {
		f[rt] = -1; if (l == r) return; int mid = (l + r) >> 1;
		build(rt << 1, l, mid); build(rt << 1 | 1, mid + 1, r);
	}
	void modify(int rt, int l, int r, int x, int y, int w) {
		if (x > y) return; if (x <= l && r <= y) return f[rt] = max(f[rt], w), void();
		int mid = (l + r) >> 1;
		if (x <= mid) modify(rt << 1, l, mid, x, y, w);
		if (y > mid) modify(rt << 1 | 1, mid + 1, r, x, y, w);
	}
	void push(int rt, int l, int r) {
		if (l == r) return nxt[l] = f[rt], void(); int mid = (l + r) >> 1;
		f[rt << 1] = max(f[rt << 1], f[rt]);
		f[rt << 1 | 1] = max(f[rt << 1 | 1], f[rt]);
		push(rt << 1, l, mid); push(rt << 1 | 1, mid + 1, r);
	}
}
int main() {
	freopen("translation.in", "r", stdin); freopen("translation.out", "w", stdout);
	int t; scanf("%d", &t); while (t--) {
		int n; scanf("%d", &n);
		int b = sqrt(n);
		int nb = (n + b - 1) / b;
		for (int i = 1; i <= n; i++) tag[i] = -1;
		for (int i = 1; i <= nb; i++) {
			bl[i] = b * (i - 1) + 1; br[i] = min(b * i, n);
			for (int _ = bl[i]; _ <= br[i]; _++) blk[_] = i;
			rebuild(i);
		}
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), buc[a[i]] = i;
		for (int i = 1; i <= n; i++) lat[i] = buc[a[i]], buc[a[i]] = i;

		sgt::build(1, 1, n);
		for (int i = 2; i <= n; i++) {
			int p = lat[i] >= i ? n : lat[i];
			p = p % n + 1;
			sgt::modify(1, 1, n, p, i - 1, i);
		}
		sgt::push(1, 1, n);
		for (int i = 1; i <= nb; i++) rebuild(i);

		for (int i = 1; i <= n; i++) {
			int tmp = tag[blk[i]] != -1 ? tag[blk[i]] : nxt[i];
			int j = lat[i]; j = j % n + 1;
			if (j < i) {
				int bi = blk[i], bj = blk[j];
				if (bi == bj) {
					pushdown(bi); for (int _ = j; _ < i; _++) nxt[_] = i;
					nxt[i] = -1; rebuild(bi);
				}
				else {
					pushdown(bi); pushdown(bj);
					for (int _ = j; _ <= br[bj]; _++) nxt[_] = i;
					for (int _ = bj + 1; _ < bi; _++) tag[_] = i;
					for (int _ = bl[bi]; _ < i; _++) nxt[_] = i;
					nxt[i] = -1; rebuild(bi); rebuild(bj);
				}
			}
			else {
				int bi = blk[i], bj = blk[j];
				if (bi == bj) {
					pushdown(bi);
					for (int _ = j; _ <= br[bj]; _++) nxt[_] = i;
					for (int _ = bj + 1; _ <= nb; _++) tag[_] = i;
					for (int _ = 1; _ < bi; _++) tag[_] = i;
					for (int _ = bl[bi]; _ < i; _++) nxt[_] = i;
					nxt[i] = -1; rebuild(bi);
				}
				else {
					pushdown(bi); pushdown(bj);
					for (int _ = j; _ <= br[bj]; _++) nxt[_] = i;
					for (int _ = bj + 1; _ <= nb; _++) tag[_] = i;
					for (int _ = 1; _ < bi; _++) tag[_] = i;
					for (int _ = bl[bi]; _ < i; _++) nxt[_] = i;
					nxt[i] = -1; rebuild(bi); rebuild(bj);
				}
			}
			int step = 0;
			while (tmp != -1) {
				if (tag[blk[tmp]] != -1) step++, tmp = tag[blk[tmp]];
				else step += stp[tmp], tmp = jmp[tmp];
			}
			printf("%d%c", step, " \n"[i == n]);
		}
	}
}
