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

    void removeCar(int index);

    void editCar(int index);

    void sortByPrice();

    void sortByYear();

    void searchByBrand(const std::string& brand) const;

    void saveToFile(const std::string& filename) const;

    void loadFromFile(const std::string& filename);

    void clear();
};

