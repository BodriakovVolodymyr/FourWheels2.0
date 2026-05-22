#include "SpecialVehicle.h"

SpecialVehicle::SpecialVehicle()
    :Car()
{
	vehicleType = "No info";
	weight = 0.0;
	dimensions = "No info";
}

SpecialVehicle::SpecialVehicle(const std::string& brand, int year, double price, const std::string& equipment, const std::string& country, const std::string saleDate, const std::string& buyerName, const std::string& vehicleType, double weight, const std::string& dimensions)
	:Car(brand, year, price, equipment, country, saleDate, buyerName)
{
	this->vehicleType = vehicleType;
	this->weight = weight;
	this->dimensions = dimensions;
}

SpecialVehicle::~SpecialVehicle()
{
}

void SpecialVehicle::setVehicleType(const std::string& vehicleType)
{
	this->vehicleType = vehicleType;
}

void SpecialVehicle::setWeight(double weight)
{
	this->weight = weight;
}

void SpecialVehicle::setDimensions(const std::string& dimensions)
{
	this->dimensions = dimensions;
}

std::string SpecialVehicle::getVehicleType() const
{
    return vehicleType;
}

double SpecialVehicle::getWeight() const
{
    return weight;
}

std::string SpecialVehicle::getDimensions() const
{
    return dimensions;
}

void SpecialVehicle::displayInfo() const
{
	Car::displayInfo();
	std::cout << "Vehicle Type: " << vehicleType << std::endl;
	std::cout << "Weight: " << weight << " kg" << std::endl;
	std::cout << "Dimensions: " << dimensions << std::endl;
}

void SpecialVehicle::saveToFile(std::ofstream& file) const
{
	file << type() << '\n';
	file << brand << '\n';
	file << year << '\n';
	file << price << '\n';
	file << equipment << '\n';
	file << country << '\n';
	file << saleDate << '\n';
	file << buyerName << '\n';
	file << vehicleType << '\n';
	file << weight << '\n';
	file << dimensions << '\n';
}

void SpecialVehicle::loadFromFile(std::ifstream& file)
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
	getline(file, vehicleType);
	file >> weight;
	file.ignore();
	getline(file, dimensions);
}

std::string SpecialVehicle::type() const
{
    return "Special Vehicle";
}
