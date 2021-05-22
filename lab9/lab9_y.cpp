#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
int y(const vector<int>& arr ){
    int sum =0;
    for(const auto&i:arr){
        if(i<0)
            throw invalid_argument("All values must be non-negative!");
        sum+=i;
    }
    if(sum%arr.size())
        throw domain_error("Sum must be divisible by the element count!");
    return sum/arr.size();
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    try{
        cout << y(v)<<endl;
    }catch(const exception& e){
        cout << "An exception was thrown: "<< e.what() <<endl;
    }
    
    return 0;

}