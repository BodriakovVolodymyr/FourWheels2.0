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
    for (int i = 0; i< cars.size();i++)
    {
		std::cout << "~~~~~~~~~Car~~~~~~~~" << i + 1 << "~~~~~~~~~" << std::endl;
		cars[i]->displayInfo();
    }
}

void CarManager::removeCar(int index)
{
    if (index < 0 || index >= static_cast<int>(cars.size())) // tra to in
    {
        throw std::out_of_range("Invalid index");
    }

    delete cars[index];

    cars.erase(cars.begin() + index);
}

void CarManager::editCar(int index)
{
    if (index < 0 || index >= static_cast<int>(cars.size()))
    {
        throw std::out_of_range("Invalid index");
    }

    int choice;
    std::cout << "\n1. Edit brand";
    std::cout << "\n2. Edit year";
    std::cout << "\n3. Edit price";
    std::cout << "\n4. Edit buyer name";
    std::cout << "\nChoose: ";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
    {
        std::string brand;

        std::cout << "New brand: ";
        std::cin.ignore();
        getline(std::cin, brand);

        cars[index]->setBrand(brand);

        break;
    }

    case 2:
    {
        int year;

        std::cout << "New year: ";
        std::cin >> year;

        cars[index]->setYear(year);

        break;
    }

    case 3:
    {
        double price;

        std::cout << "New price: ";
        std::cin >> price;

        cars[index]->setPrice(price);

        break;
    }

    case 4:
    {
        std::string buyer;

        std::cout << "New buyer name: ";

        std::cin.ignore();
        getline(std::cin, buyer);

        cars[index]->setBuyerName(buyer);

        break;
    }

    default:
        std::cout << "Invalid choice\n";
    }
}

void CarManager::sortByPrice()
{
    std::sort(cars.begin(), cars.end(),
        [](Car* a, Car* b)
        {
            return *a < *b;
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
    clear();
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

void CarManager::clear()
{
    for (auto car : cars)
    {
        delete car;
    }
    cars.clear();
}
