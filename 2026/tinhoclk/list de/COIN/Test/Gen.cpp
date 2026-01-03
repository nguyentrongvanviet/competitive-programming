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
const int NUM_TEST_SUB1 = 10;
const int NUM_TEST_SUB2 = 10;
const int NUM_TEST_SUB3 = 10;
const int NUM_TEST_SUB4 = 20;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long r) {
    if (l > r) return l;
    return uniform_int_distribution<long long>(l, r)(rng);
}

void generate_data(int n, int q, int subtask, ofstream &out) {
    out << n << " " << q << "\n";

    // Sinh mảng A
    // Chiến thuật sinh: Để đáp án lớn, ta cần nhiều số 1, rồi các số nhỏ tăng dần
    // Sub 3: Giá trị <= 20
    long long max_val = 1000000000;
    if (subtask == 3) max_val = 20;

    for (int i = 0; i < n; ++i) {
        long long val;
        int type = Rand(1, 100);
        
        if (subtask == 3) {
            val = Rand(1, 20);
        } else {
            // Với Sub 1, 2, 4: Cần trộn lẫn các chiến thuật
            if (type <= 40) val = 1; // 40% cơ hội ra số 1
            else if (type <= 70) val = Rand(2, 100); // 30% ra số nhỏ
            else if (type <= 90) val = Rand(100, 10000); // 20% ra số trung bình
            else val = Rand(10000, max_val); // 10% ra số lớn
        }
        out << val << (i == n - 1 ? "" : " ");
    }
    out << "\n";

    // Sinh truy vấn
    for (int i = 0; i < q; ++i) {
        int l = Rand(1, n);
        int r = Rand(l, n); // Đảm bảo l <= r
        out << l << " " << r << "\n";
    }
}

void create_test_file(int id, int subtask) {
    string id_str = (id < 10 ? "0" : "") + to_string(id);
    string inp_path = "Input\\test" + id_str + ".inp";
    string out_path = "Output\\test" + id_str + ".out";
    
    ofstream out(inp_path);
    
    int n, q;
    // Cấu hình kích thước theo Subtask
    if (subtask == 1) { // N, Q <= 10
        n = Rand(1, 10);
        q = Rand(1, 10);
    } else if (subtask == 2) { // N, Q <= 1000
        n = Rand(100, 1000);
        q = Rand(100, 1000);
    } else if (subtask == 3) { // N, Q <= 2e5, Val <= 20
        n = Rand(10000, 100000);
        q = Rand(10000, 100000);
    } else { // Full
        n = Rand(100000, 200000);
        q = Rand(100000, 200000);
    }

    generate_data(n, q, subtask, out);
    out.close();

    string command = "Solution.exe < " + inp_path + " > " + out_path;
    system(command.c_str());

    cout << "Generated Test " << id_str << " (Sub " << subtask << ") | N=" << n << " Q=" << q << endl;
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
    // Subtask 4
    for (int i = 0; i < NUM_TEST_SUB4; ++i) create_test_file(current_test++, 4);

    cout << "DONE! Check Output folder." << endl;
    return 0;
}