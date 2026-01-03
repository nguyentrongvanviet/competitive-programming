#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MAX_VAL = 1e9 + 7;

// Node của Persistent Segment Tree
struct Node {
    long long sum;
    int left, right;
    Node() : sum(0), left(0), right(0) {}
};

const int MAXN = 200005;
const int NODES = MAXN * 40; // LogN * N

Node tree[NODES];
int roots[MAXN]; // Lưu chỉ số root của từng version
int node_cnt = 0;

// Hàm xây dựng cây rỗng ban đầu
int build(int l, int r) {
    int id = ++node_cnt;
    if (l == r) return id;
    int mid = l + (r - l) / 2;
    tree[id].left = build(l, mid);
    tree[id].right = build(mid + 1, r);
    return id;
}

// Hàm cập nhật (tạo phiên bản mới)
// prev_id: id của version trước
// l, r: phạm vi quản lý của node
// val_pos: vị trí giá trị cần update (sau khi nén hoặc dùng trực tiếp giá trị)
// add_val: giá trị cần cộng thêm
int update(int prev_id, int l, int r, int val_pos, int add_val) {
    int id = ++node_cnt;
    tree[id] = tree[prev_id]; // Copy dữ liệu từ node cũ
    tree[id].sum += add_val;

    if (l == r) return id;

    int mid = l + (r - l) / 2;
    if (val_pos <= mid)
        tree[id].left = update(tree[prev_id].left, l, mid, val_pos, add_val);
    else
        tree[id].right = update(tree[prev_id].right, mid + 1, r, val_pos, add_val);
    
    return id;
}

// Hàm truy vấn tổng các số trong phạm vi [1, k] (tức là giá trị <= k)
// Thực hiện trên 2 version để lấy hiệu (r_ver - l_ver)
long long query(int id_l, int id_r, int l, int r, int k) {
    if (l > k) return 0; // Phạm vi node nằm hoàn toàn bên phải k -> không lấy
    if (r <= k) return tree[id_r].sum - tree[id_l].sum; // Phạm vi node nằm hoàn toàn trong [1, k]

    int mid = l + (r - l) / 2;
    return query(tree[id_l].left, tree[id_r].left, l, mid, k) +
           query(tree[id_l].right, tree[id_r].right, mid + 1, r, k);
}

// Dùng nén số (Coordinate Compression) vì giá trị x_i lên tới 10^9
// Tuy nhiên để đơn giản và hiệu quả, ta có thể build Segment Tree trên mảng giá trị đã nén
// Ánh xạ: Giá trị thực -> Index nén
vector<int> vals;
int get_idx(int v) {
    return lower_bound(vals.begin(), vals.end(), v) - vals.begin() + 1;
}
// Ánh xạ ngược để tìm index giới hạn cho query
int get_upper_idx(long long v) {
    return upper_bound(vals.begin(), vals.end(), v) - vals.begin();
}

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    vector<int> a(n + 1);
    vals.clear();
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        vals.push_back(a[i]);
    }

    // Nén số
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = vals.size(); // Kích thước mảng giá trị

    // Build cây rỗng
    node_cnt = 0;
    roots[0] = build(1, m);

    // Xây dựng các phiên bản cây
    for (int i = 1; i <= n; ++i) {
        int idx = get_idx(a[i]);
        roots[i] = update(roots[i - 1], 1, m, idx, a[i]);
    }

    // Xử lý truy vấn
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        
        long long current_miss = 1;
        while (true) {
            // Tìm tổng tất cả các số trong đoạn [l, r] mà có giá trị <= current_miss
            int idx_limit = get_upper_idx(current_miss);
            
            // Nếu không có số nào <= current_miss thì idx_limit = 0 -> sum = 0
            long long sum_smaller = 0;
            if (idx_limit > 0) {
                sum_smaller = query(roots[l - 1], roots[r], 1, m, idx_limit);
            }

            // Logic chính:
            // Nếu tổng các số (<= current_miss) vẫn < current_miss
            // Nghĩa là ta không thể với tới current_miss được.
            // (Thực ra logic chặt chẽ là: ta đang có thể tạo max là current_miss - 1.
            // Ta cần thêm coin để mở rộng. Ta lấy tất cả coin <= current_miss.
            // Nếu tổng chúng nó tạo ra là S_new.
            // Nếu S_new < current_miss thì vô lý vì ít nhất nó phải bằng tổng cũ.
            // Nếu S_new == current_miss - 1 (tức là không tăng thêm) -> Dừng).
            
            if (sum_smaller < current_miss) {
                cout << current_miss << "\n";
                break;
            } else {
                // Mở rộng giới hạn: Ta có thể tạo được tất cả tổng từ 1 đến sum_smaller
                // Vậy số tiếp theo cần kiểm tra là sum_smaller + 1
                current_miss = sum_smaller + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}