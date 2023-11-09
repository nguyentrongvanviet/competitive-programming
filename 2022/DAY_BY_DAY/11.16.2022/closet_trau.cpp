#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define TASK "closet"
struct Point{
    ll x, y;
    int id;
    
    bool operator < (const Point& other) {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

struct cmp{
    bool operator () (const Point& a, const Point& b) const {
        if (a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    }
};

int n;
vector<Point> points; // Vector chứa tất cả các điểm
set<Point, cmp> T;

ll squared_dist(Point a, Point b) { // Nhận vào hai điểm, trả vể 
                                     // bình phương khoảng cách giữa hai điểm
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0) ; 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".ANS","w",stdout); 
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        points.push_back({x, y, i});
    }
    
    ll squared_d = squared_dist(points[0], points[1]); // Lưu bình phương của d
    int res_id1 = 0, res_id2 = 1;
    
    sort(points.begin(), points.end()); // Sắp xếp các điểm theo hoành độ
    
    for (auto p : points) {
        ll x = p.x, y = p.y;
        int id = p.id;
        
        ll d = sqrt(squared_d);
        Point cur = {-1000001, y - d, id};
        
        while (1) { // Tìm tất cả các điểm có tung độ trong khoảng [y - d, y + d]
            auto it = T.upper_bound(cur);
            
            if (it == T.end()) break;
            
            cur = *it;
            if (cur.y > y + d) break; // Dừng lại nếu điểm có tung độ lớn hơn y + d
            
            if (cur.x < x - d) {
                T.erase(it);
                continue;
            } // Xóa điểm nếu điểm này có hoành độ bé hơn x - d
            
            
            if (squared_dist(p, cur) < squared_d) {
                squared_d = squared_dist(p, cur);
                res_id1 = id; res_id2 = cur.id;
            } // Gán đáp án mới nếu tìm được d nhỏ hơn
        }
        
        T.insert(p); // Thêm điểm hiện tại vào T
    }
    
    if (res_id1 > res_id2) swap(res_id1, res_id2);
    cout << res_id1 << " " << res_id2 << " ";
    cout << fixed << setprecision(6) << sqrt(squared_d);
}