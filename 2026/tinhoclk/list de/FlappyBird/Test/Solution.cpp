#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

// Cấu trúc đường thẳng: y = mx + c
struct Line {
    long long m, c;
};

// Hàm tìm giao điểm của 2 đường thẳng
// m1*x + c1 = m2*x + c2 => x = (c2 - c1) / (m1 - m2)
double intersect(Line l1, Line l2) {
    return (double)(l2.c - l1.c) / (l1.m - l2.m);
}

int main() {
    // Tối ưu I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }

    // --- BƯỚC 1: Dựng bao lồi (Convex Hull) ---
    // Đường thẳng thứ i có dạng: y = -(i)*x + val (với x là d)
    // Hệ số góc m = -i. Khi i tăng từ 0->n-1, m giảm dần (0, -1, -2...)

    // 1. Dựng Lower Hull cho U(d) = min(r_i - i*d)
    // Ta thêm đường thẳng theo thứ tự hệ số góc giảm dần -> Dùng Monotone Stack
    vector<Line> hullU;
    for (int i = 0; i < n; ++i) {
        Line curr = {-i, r[i]};
        while (hullU.size() >= 2) {
            Line l2 = hullU.back();
            Line l1 = hullU[hullU.size() - 2];
            // Nếu giao điểm của (l1, l2) nằm bên phải giao điểm (l2, curr)
            // thì l2 bị curr che khuất, loại bỏ l2.
            if (intersect(l1, l2) >= intersect(l2, curr)) {
                hullU.pop_back();
            } else {
                break;
            }
        }
        hullU.push_back(curr);
    }

    // 2. Dựng Upper Hull cho V(d) = max(l_i - i*d)
    // Để dùng logic tương tự, ta thêm đường thẳng theo thứ tự hệ số góc TĂNG dần
    // (từ n-1 về 0) để tìm bao trên.
    vector<Line> hullV;
    for (int i = n - 1; i >= 0; --i) {
        Line curr = {-i, l[i]};
        while (hullV.size() >= 2) {
            Line l2 = hullV.back();
            Line l1 = hullV[hullV.size() - 2];
            // Điều kiện loại bỏ tương tự vì ta đang xét bao trên với hệ số góc ngược lại
            if (intersect(l1, l2) >= intersect(l2, curr)) {
                hullV.pop_back();
            } else {
                break;
            }
        }
        hullV.push_back(curr);
    }

    // --- BƯỚC 2: Gom các điểm giao nhau để chia khoảng ---
    vector<double> points;
    // Thêm các giao điểm của Hull U
    for (size_t i = 0; i + 1 < hullU.size(); ++i) points.push_back(intersect(hullU[i], hullU[i+1]));
    // Thêm các giao điểm của Hull V
    for (size_t i = 0; i + 1 < hullV.size(); ++i) points.push_back(intersect(hullV[i], hullV[i+1]));
    
    // Thêm biên vô cực (đủ lớn để bao phủ nghiệm)
    points.push_back(-2e9 - 7);
    points.push_back(2e9 + 7);
    
    sort(points.begin(), points.end());

    // --- BƯỚC 3: Duyệt qua từng khoảng và tính tổng ---
    long long total_ans = 0;
    int ptrU = 0; // Con trỏ dòng đang active của Hull U
    int ptrV = 0; // Con trỏ dòng đang active của Hull V

    for (size_t i = 0; i + 1 < points.size(); ++i) {
        double x_start = points[i];
        double x_end = points[i+1];
        
        // Tìm khoảng số nguyên [L, R] nằm trong (x_start, x_end]
        long long L_range = floor(x_start) + 1;
        long long R_range = floor(x_end);
        
        if (L_range > R_range) continue;

        // Cập nhật con trỏ để tìm đường thẳng active tại khoảng này
        double mid = (x_start + x_end) / 2.0;
        while (ptrU + 1 < hullU.size() && intersect(hullU[ptrU], hullU[ptrU+1]) < mid) ptrU++;
        while (ptrV + 1 < hullV.size() && intersect(hullV[ptrV], hullV[ptrV+1]) < mid) ptrV++;

        Line lineU = hullU[ptrU];
        Line lineV = hullV[ptrV];

        // Hàm cần tính tổng: f(d) = U(d) - V(d) + 1
        // f(d) = (m_u - m_v)d + (c_u - c_v + 1) = Ad + B
        long long A = lineU.m - lineV.m;
        long long B = lineU.c - lineV.c + 1;

        // Ta cần tính tổng (Ad + B) với d thuộc [L_range, R_range] sao cho Ad + B > 0
        long long L = L_range, R = R_range;

        // Thu hẹp L, R dựa trên điều kiện Ad + B > 0
        if (A == 0) {
            if (B <= 0) continue; 
        } else if (A > 0) {
            // d > -B/A => d >= floor(-B/A) + 1 (công thức tổng quát cho số nguyên)
            long long min_d = floor((double)-B / A) + 1;
            L = max(L, min_d);
        } else { // A < 0
            // d < -B/A => d <= ceil(-B/A) - 1
            long long max_d = ceil((double)-B / A) - 1;
            R = min(R, max_d);
        }

        if (L <= R) {
            long long count = R - L + 1;
            long long start_val = A * L + B;
            long long end_val = A * R + B;
            // Tổng cấp số cộng: n * (đầu + cuối) / 2
            total_ans += count * (start_val + end_val) / 2;
        }
    }

    cout << total_ans << endl;

    return 0;
}