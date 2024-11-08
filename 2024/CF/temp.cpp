#include<iostream>
using namespace std;
#include<vector>

long long Min(long long a, long long b){
    return a<b?a:b;
}

void swap(vector<long long>& a, long long i, long long j){
    a[i] = a[i] + a[j];
    a[j] = a[i] - a[j];
    a[i] = a[i] - a[j];
}

void check_up(vector<long long>& a, long long i){
    while(i != 0){
        if(a[i] < a[(i-1)/2]){
            swap(a,i,(i-1)/2);
            i = (i-1)/2;
        }
        else return;
    }
}

void check_down(vector<long long>& a, long long i){
    while( 2*i + 1 <= a.size()-1){ // node a[i] still has children
        if(2*i+1 == a.size() - 1){ // it has 1 child
            if(a[i] > a[2*i+1]){
                swap(a,i,2*i+1);
                i = 2*i+1;
            }
            else return;
        }
        else if(a[i] > Min(a[2*i+1],a[2*i+2])){
            if(a[2*i+1] == Min(a[2*i+1],a[2*i+2])){
                swap(a,i,2*i+1);
                i = 2*i+1;
            }
            else {
                swap(a,i,2*i+2);
                i = 2*i+2;
        }

    }
        else return;
}
}
long long getMin(vector<long long>& a){
    if(a.size() != 0) return a[0];
}

void extract_min(vector<long long>& a){
    if( a.size() != 0){
        swap(a,0,a.size()-1);
        a.pop_back();
        check_down(a,0);
    }
}
vector<long long> sortedArray(vector<long long>& a){
    long long n = a.size();
    vector<long long> result;
    vector<long long> temp;
    for(long long i = 0; i < n; i++){
        temp.push_back(a[i]);
        check_up(temp,i);
    }
    for(long long i = 0; i < n; i++){
        result.push_back(getMin(temp));
        extract_min(temp);
    }
    return result;
}
int main(){
    long long n;
    cin>>n;
    vector<long long> vec;
    for(long long i = 0; i<n;i++){
        long long t;
        cin>>t;
        vec.push_back(t);
    }
    long long number = 1;
    vector<long long> result = sortedArray(vec);

    for(long long i = 1; i < result.size();i++){
        if(result[i] != result[i-1]){number++;}
    }
    cout<<number<<endl;
    return 0;
}