#include <bits/stdc++.h>

#define cin(v) for (auto& i : v) cin >> i
#define cout(v) for (auto& i : v) cout << i << ' '; cout << "\n"

using namespace std;


template <typename T = int> struct SegmentTree {
    struct Node {
        T sum = T();
    };

    void build(int now, int s, int e, vector<Node>& seg_tree, vector<T>& v) {
        if (s == e - 1) {
            seg_tree[now].sum = v[s];
            return;
        }

        int mid = s + (e - s) / 2;
        build(now << 1, s, mid, seg_tree, v);
        build(now << 1 | 1, mid, e, seg_tree, v);

        seg_tree[now].sum = seg_tree[now << 1].sum + seg_tree[now << 1 | 1].sum;
    }

    void update(int now, int s, int e, int idx, T value, vector<Node>& seg_tree) {
        if (s == e - 1) {
            seg_tree[now].sum = value;
            return;
        }

        int mid = s + (e - s) / 2;
        if (idx < mid) {
            update(now << 1, s, mid, idx, value, seg_tree);
        } else {
            update(now << 1 | 1, mid, e, idx, value, seg_tree);
        }

        seg_tree[now].sum = seg_tree[now << 1].sum + seg_tree[now << 1 | 1].sum;
    }

    T query(int now, int s, int e, int l, int r, const vector<Node>& seg_tree) {
        if (r <= s || e <= l) return T();
        if (s >= l && e <= r) return seg_tree[now].sum;

        int mid = s + (e - s) / 2;
        T x = query(now << 1, s, mid, l, r, seg_tree);
        T y = query(now << 1 | 1, mid, e, l, r, seg_tree);

        return x + y;
    }
};



int main() {
    int n;
    cin >> n;
    vector <int> v(n);
    cin(v);
    
    SegmentTree sg;
    vector<SegmentTree<int>::Node> seg_tree(4 * n); 

    sg.build(1, 0, n, seg_tree, v);

    //------- THE REST OF THE CODE  ----------//

    return 0;
}