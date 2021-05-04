#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    int size;
    cin >> size;
    vector<int> v(size);
    vector<int> positive;
    for(auto& e:v){
        cin>>e;
    }
    copy_if(v.begin(),v.end(),back_inserter(positive),[=](int a){return a>0;});
    auto vmin = min_element(positive.begin(),positive.end());
    auto vmax = max_element(positive.begin(),positive.end());
    cout<<"Min: "<< ((vmin == positive.end())?0:*vmin) <<endl;
    cout<<"Max: "<< ((vmax == positive.end())?0:*vmax) << endl;
    

}