#pragma once
#include <vector>
#include <algorithm>
#include "Car.h"
#include "UsedCar.h"
#include "SportsCar.h"
#include "SpecialVehicle.h"

class CarManager
{
private:
	std::vector<Car*> cars;
public:
    ~CarManager();

    void addCar(Car* car);

    void showAll() const;
    void showUsedCars() const;
    void showSportsCars() const;
    void showSpecialVehicles() const;

    void removeCar(int index);

    void editCar(int index);

    void sortByPrice();

    void sortByYear();

    void searchByBrand(const std::string& brand) const;
    void searchByIndex(int index) const;
    void searchByPriceRange(double minPrice, double maxPrice) const;

    void saveToFile(const std::string& filename) const;

    void loadFromFile(const std::string& filename);

    void clear();
};

