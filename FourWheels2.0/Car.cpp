#include "Car.h"

Car::Car()
{
	brand = "No info";
	year = 0;
	price = 0.0;
	equipment = "No info";
	country = "No info";
	saleDate = "No info";
	buyerName = "No info";
}

Car::Car(const std::string& brand, int year, double price, const std::string& equipment, const std::string& country, const std::string saleDate, const std::string& buyerName)
{
	this->brand = brand;
	setYear(year);
	setPrice(price);
	this->equipment = equipment;
	this->country = country;
	this->saleDate = saleDate;
	this->buyerName = buyerName;
}

Car::~Car()
{
}

void Car::setBrand(std::string brand)
{
	this->brand = brand;
}

void Car::setYear(int year)
{
	if (year < 1900 || year > 2026)
	{
		throw std::invalid_argument("Invalid year");
	}

	this->year = year;
}

void Car::setPrice(double price)
{
	if (price < 0)
	{
		throw std::invalid_argument("Price cannot be negative");
	}

	this->price = price;
}

void Car::setEquipment(std::string equipment)
{
	this->equipment = equipment;
}

void Car::setCountry(std::string country)
{
	this->country = country;
}

void Car::setSaleDate(std::string saleDate)
{
	this->saleDate = saleDate;
}

void Car::setBuyerName(std::string buyerName)
{
	this->buyerName = buyerName;
}

std::string Car::getBrand() const
{
    return brand;
}

int Car::getYear() const
{
    return year;
}

double Car::getPrice() const
{
    return price;
}

std::string Car::getEquipment() const
{
    return equipment;
}

std::string Car::getCountry() const
{
    return country;
}

std::string Car::getSaleDate() const
{
    return saleDate;
}

std::string Car::getBuyerName() const
{
    return buyerName;
}

int Car::getCarCount()
{
	return 0;
}

bool Car::operator<(const Car& other) const
{
	return price < other.price;
}

bool Car::operator>(const Car& other) const
{
	return price > other.price;
}

bool Car::operator==(const Car& other) const
{
	return brand == other.brand
		&& year == other.year
		&& price == other.price;
}

