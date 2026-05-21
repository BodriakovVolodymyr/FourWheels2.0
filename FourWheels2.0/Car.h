#pragma once
#include<string>
#include<iostream>
//#include<QDate>
#include <fstream>

class Car
{
protected:
	std::string brand;
	int year;
	double price;
	std::string equipment;
	std::string country;
	std::string saleDate;
	std::string buyerName;
	static int carCount;
public:
	Car();
	Car(const std::string& brand, int year, double price, const std::string& equipment, const std::string& country, const std::string saleDate, const std::string& buyerName);
	virtual ~Car() = default;

	void setBrand(std::string brand);
	void setYear(int year);
	void setPrice(double price);
	void setEquipment(std::string equipment);
	void setCountry(std::string country);
	void setSaleDate(std::string saleDate);
	void setBuyerName(std::string buyerName);

	std::string getBrand() const;
	int getYear() const;
	double getPrice() const;
	std::string getEquipment() const;
	std::string getCountry() const;
	std::string getSaleDate() const;
	std::string getBuyerName() const;
	static int getCarCount();

	virtual void displayInfo() const = 0;
	virtual void saveToFile(std::ofstream& file) const = 0;
	virtual void loadFromFile(std::ifstream& file) = 0;
	virtual std::string type()const = 0;


	bool operator<(const Car& other) const;
	bool operator>(const Car& other) const;
	bool operator==(const Car& other) const;
};

