#include "CarManager.h"

CarManager::~CarManager()
{
    for (auto car : cars)
    {
        delete car;
    }

    cars.clear();
}

void CarManager::addCar(Car* car)
{
    cars.push_back(car);
}

void CarManager::showAll() const
{
    for (auto car : cars)
    {
        car->displayInfo();
    }
}

void CarManager::removeCar(int index)
{
    if (index < 0 || index >= cars.size())
    {
        throw std::out_of_range("Invalid index");
    }

    delete cars[index];

    cars.erase(cars.begin() + index);
}

void CarManager::sortByPrice()
{
    std::sort(cars.begin(), cars.end(),
        [](Car* a, Car* b)
        {
            return a->getPrice() < b->getPrice();
        });
}

void CarManager::sortByYear()
{
    std::sort(cars.begin(), cars.end(),
        [](Car* a, Car* b)
        {
            return a->getYear() < b->getYear();
        });
}

void CarManager::searchByBrand(const std::string& brand) const
{
    bool found = false;

    for (auto car : cars)
    {
        if (car->getBrand() == brand)
        {
            car->displayInfo();
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "Cars not found\n";
    }
}

void CarManager::saveToFile(const std::string& filename) const
{
    std::ofstream file(filename);

    if (!file)
    {
        throw std::runtime_error("File error");
    }

    for (auto car : cars)
    {
        car->saveToFile(file);
    }
}

void CarManager::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file)
    {
        throw std::runtime_error("File error");
    }

    std::string type;

    while (getline(file, type))
    {
        if (type.empty())
        {
            continue;
        }
        Car* car = nullptr;

        if (type == "Used Car")
        {
            car = new UsedCar();
        }
        else if (type == "Sports Car")
        {
            car = new SportsCar();
        }
        else if (type == "Special Vehicle")
        {
            car = new SpecialVehicle();
        }

        if (car != nullptr)
        {
            car->loadFromFile(file);
            cars.push_back(car);
        }
    }
}
