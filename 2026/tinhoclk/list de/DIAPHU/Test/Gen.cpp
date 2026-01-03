#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <numeric>
#include <cstdlib>
#include <string>
#include<iomanip>
using namespace std;

// --- CẤU HÌNH ---
const int NUM_TEST_SUB1 = 10;
const int NUM_TEST_SUB2 = 15;
const int NUM_TEST_SUB3 = 25;

const int MAX_N_SMALL = 500;
const int MAX_N_LARGE = 200000;
const int MAX_VAL_A   = 200000; // Theo đề bài: Ai <= 2e5

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long r) {
    if (l > r) return l;
    return uniform_int_distribution<long long>(l, r)(rng);
}

// Sinh cây ngẫu nhiên
vector<pair<int, int>> generate_random_tree(int n) {
    vector<pair<int, int>> edges;
    for (int i = 2; i <= n; ++i) edges.push_back({(int)Rand(1, i - 1), i});
    vector<int> p(n + 1); iota(p.begin(), p.end(), 0);
    shuffle(p.begin() + 1, p.end(), rng);
    vector<pair<int, int>> res;
    for (auto e : edges) res.push_back({p[e.first], p[e.second]});
    return res;
}

// Sinh cây đường thẳng (cho Subtask 2)
vector<pair<int, int>> generate_line_graph(int n) {
    vector<int> p(n + 1); iota(p.begin(), p.end(), 0);
    shuffle(p.begin() + 1, p.end(), rng);
    vector<pair<int, int>> res;
    for (int i = 1; i < n; ++i) res.push_back({p[i], p[i+1]});
    return res;
}

void create_test(int id, int subtask, int min_n, int max_n) {
    string id_str = (id < 10 ? "0" : "") + to_string(id);
    string inp_path = "Input\\test" + id_str + ".inp";
    string out_path = "Output\\test" + id_str + ".out";
    
    ofstream out(inp_path);
    
    // 1. Sinh N, Q
    int n = Rand(min_n, max_n);
    int q = Rand(min_n, max_n);
    
    // 2. Sinh mảng A
    out << n << " " << q << "\n";
    for(int i=0; i<n; ++i) out << Rand(0, MAX_VAL_A) << (i==n-1?"":" ");
    out << "\n";

    // 3. Sinh cạnh (Subtask 2 là đường thẳng, còn lại là cây)
    vector<pair<int, int>> edges;
    if (subtask == 2) edges = generate_line_graph(n);
    else edges = generate_random_tree(n);

    shuffle(edges.begin(), edges.end(), rng);
    for(auto e : edges) out << e.first << " " << e.second << "\n";
    
    // 4. Sinh truy vấn: x y w
    // w cũng nằm trong khoảng [1, 2e5]
    for(int i=0; i<q; ++i) {
        int x = Rand(1, n);
        int y = Rand(1, n);
        int w = Rand(1, MAX_VAL_A); 
        // Đôi khi sinh w nhỏ để test độ khó, đôi khi w lớn
        if (Rand(0, 10) < 3) w = Rand(1, 100); 

        out << x << " " << y << " " << w << "\n";
    }
    
    out.close();

    // --- ĐO THỜI GIAN CHẠY SOLUTION ---
    string command = "Solution.exe < " + inp_path + " > " + out_path;
    
    // Bắt đầu bấm giờ
    auto start = chrono::high_resolution_clock::now();
    
    system(command.c_str()); // Chạy file Solution
    
    // Dừng bấm giờ
    auto end = chrono::high_resolution_clock::now();
    
    // Tính khoảng thời gian (theo giây)
    chrono::duration<double> elapsed = end - start;
    
    // In ra màn hình console
    cout << "Test " << id_str << " | N=" << n << " | Time: " 
         << fixed << setprecision(3) << elapsed.count() << "s";
         
    if (elapsed.count() > 1.0) cout << " [SLOW!]"; // Cảnh báo nếu chạy quá 1s
    cout << endl;
}

int main() {
    int current_test = 1;
    
    // Subtask 1: N, Q <= 500
    for(int i=0; i<NUM_TEST_SUB1; ++i) 
        create_test(current_test++, 1, 10, MAX_N_SMALL);

    // Subtask 2: Line Graph, N lớn
    int s2_limit = 4;
    for(int i=0; i<NUM_TEST_SUB2; ++i)
        create_test(current_test++, 2, (i<s2_limit ? 501 : 150000), (i<s2_limit ? 149999 : MAX_N_LARGE));

    // Subtask 3: Tree, N lớn
    int s3_limit = 7;
    for(int i=0; i<NUM_TEST_SUB3; ++i)
        create_test(current_test++, 3, (i<s3_limit ? 501 : 150000), (i<s3_limit ? 149999 : MAX_N_LARGE));

    cout << "Done! Generated 50 tests." << endl;
    return 0;
}