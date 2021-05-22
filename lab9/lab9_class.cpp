#include <iostream>
#include "LivingSpace.h"
int main()
{
    LivingSpace space(26,74);
    LivingSpace k;
    std::cout<<"roomCount " <<space.getRoomCount()<<std::endl;
    space.setArea(3434);
    space.getArea();
    space.setRoomCount(228);
    space.print();
    Flat f(12,51,43);
    Flat g;
    f.setFloor(1337);
    f.setFloor(232);
    f.setArea(457654);
    f.getArea();
    f.getRoomCount();
    std::cout<<"Total "<<f.totalPrice(2)<<std::endl;
    try{
    f.writeToFile("flat.txt");
    }catch(const file_exception& e){
        std::cerr<< "Caught file_exception: "<<e.what()<<std::endl;
    }
    return 0;
}
