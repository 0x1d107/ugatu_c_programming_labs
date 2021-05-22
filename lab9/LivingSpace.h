#pragma once
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <string>
class LivingSpace {
private:
	unsigned int area;
	unsigned int room_count;
public:	
	LivingSpace();
	LivingSpace(unsigned int area, unsigned int room_count);
	~LivingSpace();
	unsigned int getArea();
	void setArea(unsigned int area);
	unsigned int getRoomCount();
	void setRoomCount(unsigned int count);
	virtual void print( std::ostream& out = std::cout);
	double totalPrice(double m2price);
	void writeToFile(const std::string& filename);
	
};
class Flat:public LivingSpace {
private:
	unsigned int floor;
public:
	Flat();
	Flat(unsigned int floor, unsigned int area, unsigned int room_count);
	unsigned getFloor();
	void setFloor(unsigned floor);
	void print( std::ostream& out = std::cout) override;
};
class file_exception:public std::exception{
	private:
	std::string file_name;
	std::string msg;
	public:
	file_exception(const std::string& file_name);
	const char* what() const noexcept override;
};