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
    if (cars.empty())
    {
        std::cout << "No cars available\n";
        return;
    }
    for (int i = 0; i< cars.size();i++)
    {
	
        std::cout << std::endl;
		cars[i]->displayInfo();
    }
}

void CarManager::showUsedCars() const
{
    if (cars.empty())
    {
        std::cout << "No cars available\n";
        return;
    }
	for (auto car : cars)
	{
		if (car->type() == "Used Car")
		{
			car->displayInfo();
		}
	}
}

void CarManager::showSportsCars() const
{
    if (cars.empty())
    {
        std::cout << "No cars available\n";
        return;
    }
	for (auto car : cars)
	{
		if (car->type() == "Sports Car")
		{
			car->displayInfo();
		}
	}
}

void CarManager::showSpecialVehicles() const
{
    if (cars.empty())
    {
        std::cout << "No cars available\n";
        return;
    }
	for (auto car : cars)
	{
		if (car->type() == "Special Vehicle")
		{
			car->displayInfo();
		}
	}
}

void CarManager::removeCar(int id)
{
    for (int i = 0; i < cars.size(); i++)
    {
        if (cars[i]->getId() == id)
        {
            delete cars[i];
            cars.erase(cars.begin() + i);
            return;
        }
    }

    throw std::out_of_range("Car not found");
}

void CarManager::editCar(int id)
{
    int index = -1;
    for (int i = 0; i < cars.size(); i++)
    {
        if (cars[i]->getId() == id)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
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
    if (cars.empty())
    {
        std::cout << "No cars available\n";
        return;
    }
    std::sort(cars.begin(), cars.end(),
        [](Car* a, Car* b)
        {
            return *a < *b;
        });
}

void CarManager::sortByYear()
{
    if (cars.empty())
    {
        std::cout << "No cars available\n";
        return;
    }
    std::sort(cars.begin(), cars.end(),
        [](Car* a, Car* b)
        {
            return a->getYear() < b->getYear();
        });
}

void CarManager::searchByBrand(const std::string& brand) const
{
    if (cars.empty())
    {
        std::cout << "No cars available\n";
        return;
    }
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

void CarManager::searchByIndex(int id) const
{
	int index = -1;
	for (int i = 0; i < cars.size(); i++)
	{
		if (cars[i]->getId() == id)
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{
		std::cout << "Invalid index\n";
		return;
	}
	cars[index]->displayInfo();
}

void CarManager::searchByPriceRange(double minPrice, double maxPrice) const
{
    if (cars.empty())
    {
        std::cout << "No cars available\n";
        return;
    }
    bool found = false;

    for (auto car : cars)
    {
        if (car->getPrice() >= minPrice && car->getPrice() <= maxPrice)
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

int CarManager::getCarsCount() const
{
    return cars.size();
}

void CarManager::clear()
{
    for (auto car : cars)
    {
        delete car;
    }
    cars.clear();
}
