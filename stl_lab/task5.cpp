#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
bool isThreatening(int ax,int ay,int bx,int by){
    return ax == bx|| ay==by||(ax-bx)*(ax-bx) ==(ay-by)*(ay-by);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    srand(time(NULL));
    random_shuffle(v.begin(),v.end());
    for(auto i:v)
        cout<< i <<' ';
    cout<<endl;
    bool result = true;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            result&=!isThreatening(i+1,v[i],j+1,v[j]);
        }
    cout<<(result?"true":"false")<<endl;
}
