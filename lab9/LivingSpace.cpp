#include "LivingSpace.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
file_exception::file_exception(const std::string& filename){
	file_name = filename;
	msg+= "Can't open file ";
	msg+= filename;
	
}
const char * file_exception::what() const noexcept{
	
	return msg.c_str();
}
LivingSpace::LivingSpace() {
	this->area=25;
	this->room_count = 1;
	std::cout<<"LS"<<std::endl;
}
LivingSpace::LivingSpace(unsigned int area, unsigned int room_count) {
	if( area < 25u )
		throw std::invalid_argument("area must be at least 25! got:"+std::to_string(area));
	if(room_count < 1)
		throw std::invalid_argument("count must not be less than 1! got:"+std::to_string(room_count));
	this->area = area;
	this->room_count = room_count;
	std::cout<<"LS"<<std::endl;
}
LivingSpace::~LivingSpace() {
}
unsigned int LivingSpace::getArea() {
	return this->area;
}
void LivingSpace::setArea(unsigned area) {
	if( area < 25u )
		throw std::invalid_argument("area must be at least 25! got:"+std::to_string(area));
	
	this->area = area;
}
unsigned int LivingSpace::getRoomCount() {
	return this->room_count;
}
void LivingSpace::setRoomCount(unsigned count) {
	if(count < 1)
		throw std::invalid_argument("count must not be less than 1! got:"+std::to_string(count));
	this->room_count = count;
}
void LivingSpace::print( std::ostream& out) {
	out <<"==LivingSpace=="<<std::endl<< "Area: " << this->area << std::endl << "Room count: " << this->room_count << std::endl;
}
double LivingSpace::totalPrice(double m2p) {
	return this->area * m2p;
}
void LivingSpace::writeToFile(const std::string& filename){
	std::ofstream file(filename);
	if(!file.is_open()){
		throw file_exception(filename);
	}
	print(file);
	file.close();
}
Flat::Flat() {
	this->setArea(25);
	this->setRoomCount(1);
	this->floor = 1;
	std::cout<<"FLT"<< std::endl;
}
unsigned Flat::getFloor() {
	return this->floor;
}
Flat::Flat(unsigned int floor, unsigned int area, unsigned int room_count) {
	this->setArea(area);
	this->setRoomCount(room_count);
	if(floor < 1)
		throw std::invalid_argument("floor must not be less than 1! got:"+std::to_string(floor));
	this->floor = floor;
	std::cout<<"FLT"<< std::endl;
}
void Flat::setFloor(unsigned floor) {
	if(floor < 1)
		throw std::invalid_argument("count must not be less than 1! got:"+std::to_string(floor));
	this->floor = floor;
}
void Flat::print( std::ostream& out ) {
	out<<"==Flat=="<<std::endl << "Area: " << this->getArea() << std::endl << "Room count: " << this->getRoomCount() << std::endl<<"Floor: "<<this->floor<<std::endl;
}
