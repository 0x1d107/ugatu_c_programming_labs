// lab8_io.cpp
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <iosfwd>
#include <algorithm>

using namespace std;
struct Vec2d {
    double x;
    double y;
    double z;
};
struct Record {
    double time;
    int point;
    double temp;
    double displacementX;
    Vec2d coords;
};

ostream& operator<<(ostream& out,const Record& r){
    out << r.time <<'\t' << r.point << '\t' << r.temp <<'\t'<<r.displacementX << '\t' 
    << r.coords.x << '\t' << r.coords.y << '\t' << r.coords.z;
    return out;
}

void readRecords(vector<Record>& v,ifstream&bd,ifstream&bd_coords) {

    vector<Vec2d> lookup;
    char c=0;
    while(c!='\n')bd.get(c);
    c=0;
    while(c!='\n')bd_coords.get(c);
    while (!bd_coords.eof()) {
        Vec2d vec;
        int id;
        bd_coords >> id >> vec.x >> vec.y >> vec.z;
        lookup.push_back(vec);
    }
    while (!bd.eof()) {
        Record r;
        bd >> r.time >> r.point >> r.temp >> r.displacementX;
        r.coords = lookup[r.point - 1];
        v.push_back(r);
    }
}
void writeOut(const vector<Record>& v,ofstream& out) {
    out << "Time\tPoint ID\tTemperature\tDisplacement X\tX\tY\tZ"<<endl;
    for(const auto&r:v)
        out<<r<<endl;
}
void filteredOut(const vector<Record>& v,ofstream& out){
    cout<< "Coordinates of a point for filter: ";
    Vec2d p;
    cin >> p.x >> p.y >> p.z;
    out<< "X = "<<p.x<<"; Y = " <<p.y<<"; Z = "<<p.z<<endl;
    out << "Time\tDisplacement X\tTemperature"<<endl;
    for(const Record& r:v){
        if(r.coords.x == p.x && r.coords.y ==p.y&&r.coords.z == p.z){
            
            out <<fixed<<setprecision(3)<< r.time <<'\t'<< scientific<<setprecision(2)<<r.displacementX <<'\t'<<fixed<<setprecision(2)<< r.temp <<endl;
        }
    }


}
int main()
{
    ifstream bd("BD.txt");
    ifstream bd_coords("BD_Coords.txt");
    ofstream nd("ND.txt");
    ofstream nf("NF.txt");
    vector<Record> v; 
    if (!bd.is_open()||!bd_coords.is_open()||!nd.is_open()||!nf.is_open()) {
        cout << "Can't open the files!" << endl;
        return 1;
    }
    readRecords(v, bd, bd_coords);
    double x, y, z, t;
    cout<< "Coordinates and time: ";
    cin >> x >> y >> z >> t;
    auto lb_t = lower_bound(v.begin(), v.end(), t, [](const Record& a, const double b) {return a.time < b; });
    auto ub_t = upper_bound(v.begin(), v.end(), t, [](const double b,const Record& a ) {return  b< a.time; });
    for(auto it = lb_t;it!=ub_t;it++){
        if((*it).coords.x == x &&(*it).coords.y == y &&(*it).coords.z == z){
            cout<< *it <<endl;
            break;
        }
    }
    writeOut(v,nd);
    filteredOut(v,nf);

}

