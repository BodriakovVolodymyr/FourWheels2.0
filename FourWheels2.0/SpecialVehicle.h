#pragma once
#include "Car.h"
class SpecialVehicle :
    public Car
{
	std::string vehicleType;
	double weight;
	std::string dimensions;
public:
	SpecialVehicle();
	SpecialVehicle(const std::string& brand, int year, double price, const std::string& equipment, const std::string& country, const std::string saleDate, const std::string& buyerName, const std::string& vehicleType, double weight, const std::string& dimensions);
	~SpecialVehicle();

	void setVehicleType(const std::string& vehicleType);
	void setWeight(double weight);
	void setDimensions(const std::string& dimensions);

	std::string getVehicleType() const;
	double getWeight() const;
	std::string getDimensions() const;

	void displayInfo() const override;

	void saveToFile(std::ofstream& file) const override;
	void loadFromFile(std::ifstream& file) override;
	virtual std::string type()const override;
};

