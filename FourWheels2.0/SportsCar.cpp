#include "SportsCar.h"

SportsCar::SportsCar()
    :Car()
{
	acceleration = 0.0;
	engineVolume = 0.0;
	horsepower = 0;
}

SportsCar::SportsCar(const std::string& brand, int year, double price, const std::string& equipment, const std::string& country, const std::string saleDate, const std::string& buyerName, double acceleration, double engineVolume, int horsepower)
	:Car(brand, year, price, equipment, country, saleDate, buyerName)
{
	this->acceleration = acceleration;
	this->engineVolume = engineVolume;
	this->horsepower = horsepower;
}

SportsCar::~SportsCar()
{
}

void SportsCar::setAcceleration(double acceleration)
{
	this->acceleration = acceleration;
}

void SportsCar::setEngineVolume(double engineVolume)
{
	this->engineVolume = engineVolume;
}

void SportsCar::setHorsepower(int horsepower)
{
	this->horsepower = horsepower;
}

double SportsCar::getAcceleration() const
{
    return acceleration;
}

double SportsCar::getEngineVolume() const
{
    return engineVolume;
}

int SportsCar::getHorsepower() const
{
    return horsepower;
}

void SportsCar::displayInfo() const
{
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Year: " << year << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Equipment: " << equipment << std::endl;
	std::cout << "Country: " << country << std::endl;
	std::cout << "Sale Date: " << saleDate << std::endl;
	std::cout << "Buyer Name: " << buyerName << std::endl;
	std::cout << "Acceleration: " << acceleration << " m/s^2" << std::endl;
	std::cout << "Engine Volume: " << engineVolume << " L" << std::endl;
	std::cout << "Horsepower: " << horsepower << " HP" << std::endl;
}

void SportsCar::saveToFile(std::ofstream& file) const
{
	file << type() << '\n';
	file << brand << '\n';
	file << year << '\n';
	file << price << '\n';
	file << equipment << '\n';
	file << country << '\n';
	file << saleDate << '\n';
	file << buyerName << '\n';
	file << acceleration << '\n';
	file << engineVolume << '\n';
	file << horsepower << '\n';
}

void SportsCar::loadFromFile(std::ifstream& file)
{
	
	getline(file, brand);

	file >> year;
	file.ignore();

	file >> price;
	file.ignore();

	getline(file, equipment);
	getline(file, country);
	getline(file, saleDate);
	getline(file, buyerName);
	file >> acceleration;
	file.ignore();
	file >> engineVolume;
	file.ignore();
	file >> horsepower;
}

std::string SportsCar::type() const
{
	return "Sports Car";
}
