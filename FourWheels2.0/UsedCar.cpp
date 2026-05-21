#include "UsedCar.h"

UsedCar::UsedCar()
    :Car()
{
	double condition = 0.0;
	std::string ownerName = "No info";
	double mileage = 0.0;
}

UsedCar::UsedCar(const std::string& brand, int year, double price, const std::string& equipment, const std::string& country, const std::string saleDate, const std::string& buyerName, double condition, const std::string& ownerName, double mileage)
    :Car(brand, year, price, equipment, country, saleDate, buyerName)
{
    this->condition = condition;
    this->ownerName = ownerName;
    this->mileage = mileage;
}

UsedCar::~UsedCar()
{
}

void UsedCar::setCondition(double condition)
{
	this->condition = condition;
}

void UsedCar::setOwnerName(std::string ownerName)
{
    this->ownerName = ownerName;
}

void UsedCar::setMileage(double mileage)
{
    this->mileage = mileage;
}

double UsedCar::getCondition() const
{
    return condition;
}

std::string UsedCar::getOwnerName() const
{
    return ownerName;
}

double UsedCar::getMileage() const
{
    return mileage;
}

void UsedCar::displayInfo() const
{
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Year: " << year << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Equipment: " << equipment << std::endl;
	std::cout << "Country: " << country << std::endl;
	std::cout << "Sale Date: " << saleDate << std::endl;
	std::cout << "Buyer Name: " << buyerName << std::endl;
    std::cout << "Condition: " << condition << std::endl;
    std::cout << "Owner Name: " << ownerName << std::endl;
    std::cout << "Mileage: " << mileage << std::endl;
}

void UsedCar::saveToFile(std::ofstream& file) const
{
    file << type() << '\n';
	file << brand << '\n';
	file << year << '\n';
	file << price << '\n';
	file << equipment << '\n';
	file << country << '\n';
	file << saleDate << '\n';
	file << buyerName << '\n';
	file << condition << '\n';
	file << ownerName << '\n';
	file << mileage << '\n';
}

void UsedCar::loadFromFile(std::ifstream& file)
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

    file >> condition;
    file.ignore();

    getline(file, ownerName);

    file >> mileage;
    file.ignore();
}

std::string UsedCar::type() const
{
    return "Used Car";
}
