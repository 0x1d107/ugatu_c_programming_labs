#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
bool isThreatening(int ax,int ay,int bx,int by){
    return ax == bx|| ay==by||(ax-bx)*(ax-bx) ==(ay-by)*(ay-by);
}
bool notHasThreatening(vector<int>& v){
    bool result = true;
    int n = v.size();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            result&=!isThreatening(i+1,v[i],j+1,v[j]);
        }
    return result;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    bool res = false;
    do{
        if(notHasThreatening(v)){
            for(auto l:v)
                cout<<l<<' ';
            cout<<endl;
            res=true;
        }
    }while(next_permutation(v.begin(),v.end()));
    if(!res)
        cout<<"false"<<endl;
}