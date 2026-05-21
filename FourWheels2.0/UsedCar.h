#pragma once
#include "Car.h"
class UsedCar :
    public Car
{
    double condition;
    std::string ownerName;
    double mileage;
public:
	UsedCar();
	UsedCar(const std::string& brand, int year, double price, const std::string& equipment, const std::string& country, const std::string saleDate, const std::string& buyerName, double condition, const std::string& ownerName, double mileage);
	~UsedCar();

	void setCondition(double condition);
	void setOwnerName(std::string ownerName);
	void setMileage(double mileage);

	double getCondition() const;
	std::string getOwnerName() const;
	double getMileage() const;

	void displayInfo() const override;

	void saveToFile( std::ofstream& file) const override;
	void loadFromFile( std::ifstream& file) override;
	virtual std::string type()const override;
};

