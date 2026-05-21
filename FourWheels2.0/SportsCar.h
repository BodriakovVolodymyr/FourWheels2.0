#pragma once
#include "Car.h"
class SportsCar :
    public Car
{
    double acceleration;
    double engineVolume;
	int horsepower;
public:
	SportsCar();
	SportsCar(const std::string& brand, int year, double price, const std::string& equipment, const std::string& country, const std::string saleDate, const std::string& buyerName, double acceleration, double engineVolume, int horsepower);
	~SportsCar();

	void setAcceleration(double acceleration);
	void setEngineVolume(double engineVolume);
	void setHorsepower(int horsepower);

	double getAcceleration() const;
	double getEngineVolume() const;
	int getHorsepower() const;

	void displayInfo() const override;

	void saveToFile(std::ofstream& file) const override;
	void loadFromFile(std::ifstream& file) override;
	virtual std::string type()const override;
};

