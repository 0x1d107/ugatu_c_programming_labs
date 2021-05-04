#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int a;
    vector<int>v;
    do{
        cin>>a;
        if(a>0) 
            v.push_back(a);
    }while(a!=0);
    cout<<v.size();

}