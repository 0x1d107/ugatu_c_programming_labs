#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

void rnd(int& i){
    i = rand()%201-100;
}
template<typename T> void print(T element){
    cout<<element<<endl;
}
void read(int& i){
    cin>>i;
}
int main(){
    srand(time(NULL));
    vector<int> v(10);
    for_each(v.begin(),v.end(),read);
    for_each(v.begin(),find_if(v.begin(),v.end(),[](const int& a) {return (a%5 == 0 && a%4 !=0) ;}),print<int>);
    print("===================");
    for_each(v.begin(),find(v.begin(),v.end(),v.back()),print<int>);
}