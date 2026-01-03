#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>
#include <cstdlib>

using namespace std;

// --- CẤU HÌNH SỐ LƯỢNG TEST ---
const int NUM_TEST_SUB1 = 15;
const int NUM_TEST_SUB2 = 15;
const int NUM_TEST_SUB3 = 20;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long r) {
    if (l > r) return l;
    return uniform_int_distribution<long long>(l, r)(rng);
}

void generate_data(int n, int subtask, ofstream &out) {
    long long max_coord;
    if (subtask == 1) max_coord = 100;
    else if (subtask == 2) max_coord = 100000; 
    else max_coord = 1000000000; 

    out << n << "\n";

    // BƯỚC 1: CHỌN ĐƯỜNG THẲNG TRỤC (BASE LINE) y = A*x + B an toàn
    long long A = 0, B = 0;
    
    // Để tạo ra nhiều nghiệm, đường thẳng trục nên nằm giữa bản đồ
    // Tránh nằm sát biên 1 hoặc max_coord quá
    long long safe_margin = max_coord / 10; 
    if (safe_margin == 0) safe_margin = 1;

    if (n >= max_coord) {
        A = 0;
        B = Rand(safe_margin, max_coord - safe_margin); 
    } 
    else {
        long long max_A_possible = (max_coord - 2 * safe_margin) / n;
        if (max_A_possible < 0) max_A_possible = 0;
        
        // Random A
        if (Rand(0, 10) < 4) A = 0; 
        else A = Rand(-max_A_possible, max_A_possible);

        long long current_min = min(A * 1, A * n);
        long long current_max = max(A * 1, A * n);
        
        // Chọn B sao cho đường thẳng nằm trong vùng an toàn (cách biên safe_margin)
        long long min_B = safe_margin - current_min;
        long long max_B = (max_coord - safe_margin) - current_max;
        
        if (min_B > max_B) { // Fallback nếu tính toán quá chặt
            A = 0; 
            B = max_coord / 2;
        } else {
            B = Rand(min_B, max_B);
        }
    }

    // BƯỚC 2: SINH KHE HỞ [L, R] VỚI "MARGIN" BẮT BUỘC
    for (int i = 1; i <= n; ++i) {
        long long exact_y = A * i + B;
        
        // Đảm bảo exact_y nằm trong giới hạn (fix lỗi làm tròn nếu có)
        exact_y = max(1LL, min(exact_y, max_coord));

        // Margin: Khoảng cách tối thiểu từ exact_y đến biên L và R
        // Đây chính là yếu tố giúp Output > 1
        long long margin; 
        long long max_deviation; // Độ lệch tối đa

        if (subtask == 1) {
            margin = Rand(1, 3); // Lề ít nhất 1-3 đơn vị -> cho phép dịch chuyển y +- 1,2,3
            max_deviation = 10;
        } else {
            // Với subtask lớn, margin càng lớn thì output càng khủng
            margin = Rand(50, 500); 
            max_deviation = max_coord / 4; 
        }

        // Sinh L trong khoảng [exact_y - max_deviation, exact_y - margin]
        // Sinh R trong khoảng [exact_y + margin, exact_y + max_deviation]
        
        long long l_target = exact_y - Rand(margin, max_deviation);
        long long r_target = exact_y + Rand(margin, max_deviation);

        // Kẹp vào giới hạn bản đồ
        long long l = max(1LL, l_target);
        long long r = min(max_coord, r_target);

        // Chốt chặn cuối cùng: Đảm bảo đường thẳng trục luôn đi lọt
        if (l > exact_y) l = exact_y;
        if (r < exact_y) r = exact_y;

        out << l << " " << r << "\n";
    }
}

void create_test_file(int id, int subtask) {
    string id_str = (id < 10 ? "0" : "") + to_string(id);
    string inp_path = "Input\\test" + id_str + ".inp";
    string out_path = "Output\\test" + id_str + ".out";
    
    ofstream out(inp_path);
    
    int n;
    if (subtask == 1) n = Rand(10, 100);
    else if (subtask == 2) n = Rand(1000, 200000); 
    else n = Rand(1000, 200000);

    generate_data(n, subtask, out);
    out.close();

    string command = "Solution.exe < " + inp_path + " > " + out_path;
    system(command.c_str());

    cout << "Generated Test " << id_str << " (Sub " << subtask << ") | N=" << n << endl;
}

int main() {
    int current_test = 1;
    
    system("mkdir Input 2>nul");
    system("mkdir Output 2>nul");

    // Subtask 1
    for (int i = 0; i < NUM_TEST_SUB1; ++i) create_test_file(current_test++, 1);

    // Subtask 2
    for (int i = 0; i < NUM_TEST_SUB2; ++i) create_test_file(current_test++, 2);

    // Subtask 3
    for (int i = 0; i < NUM_TEST_SUB3; ++i) create_test_file(current_test++, 3);

    cout << "DONE! Check Output folder." << endl;
    return 0;
}