#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
template<typename T> ostream& operator<<(ostream&out, vector<T>& v){
    for(auto& e:v){
        out<<e<<endl;
    }
    return out;
}
int main(){
    int n;
    cin>>n;
    srand(time(NULL));
    vector<int> v(n);
    for_each(v.begin(),v.end(),[n](int& i){i=rand()%(n/5+1);});
    cout<<v;
    cout<<"=============="<<endl;
    auto mean = accumulate(v.begin(),v.end(),0.0)/n;
    cout<<"Mean: "<<mean<<endl;
    sort(v.begin(),v.end());
    cout<<"Median: "<<v[n/2]<<endl;
    vector<int> cnt;
    cnt.reserve(n);
    transform(v.begin(),v.end(),back_inserter(cnt),[&v](int value){return count(v.begin(),v.end(),value);});
    auto low_mode_cnt_iter = max_element(cnt.begin(),cnt.end());
    auto mode = (v[low_mode_cnt_iter-cnt.begin()]);
    cout<<"Mode: "<<mode<<endl;
}