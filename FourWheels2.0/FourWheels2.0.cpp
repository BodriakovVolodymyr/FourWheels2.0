#include <limits>
#include <iostream>
#include "CarManager.h"

void clearScreen() {
#ifdef _WIN32
    system("cls"); 
#else
    system("clear"); 
#endif
}
void pause()
{
    std::cout << "\nPress ENTER to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int main()
{
    
    CarManager manager;
    int choice;

    do
    {
        //clearScreen();

        std::cout << "\n========== MENU ==========\n";
        std::cout << "1. Add Used Car\n";
        std::cout << "2. Add Sports Car\n";
        std::cout << "3. Add Special Vehicle\n";
        std::cout << "4. Show All Cars\n";
        std::cout << "5. Sort By Price\n";
        std::cout << "6. Sort By Year\n";
        std::cout << "7. Search By Brand\n";
        std::cout << "8. Remove Car\n";
        std::cout << "9. Edit Car\n";
        std::cout << "10. Save To File\n";
        std::cout << "11. Load From File\n";
        std::cout << "12. Show Car Count\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose: ";

        std::cin >> choice;
        if(std::cin.fail())
        {
            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "\nInvalid input!\n";

            pause();

            continue;
        }
        try
        {
            switch (choice)
            {
            case 1:
            {
                //clearScreen();
                std::string brand, equipment, country, saleDate, buyerName;
                std::string ownerName;
                int year;
                double price, condition, mileage;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Brand: ";
                getline(std::cin, brand);

                std::cout << "Year: ";
                std::cin >> year;

                std::cout << "Price: ";
                std::cin >> price;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Equipment: ";
                getline(std::cin, equipment);

                std::cout << "Country: ";
                getline(std::cin, country);

                std::cout << "Sale Date: ";
                getline(std::cin, saleDate);

                std::cout << "Buyer Name: ";
                getline(std::cin, buyerName);

                std::cout << "Condition: ";
                std::cin >> condition;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Owner Name: ";
                getline(std::cin, ownerName);

                std::cout << "Mileage: ";
                std::cin >> mileage;

                manager.addCar(
                    new UsedCar(
                        brand,
                        year,
                        price,
                        equipment,
                        country,
                        saleDate,
                        buyerName,
                        condition,
                        ownerName,
                        mileage
                    )
                );

                std::cout << "\nUsed car added successfully!\n";

                pause();
                break;
            }

            case 2:
            {
                //clearScreen();
                std::string brand, equipment, country, saleDate, buyerName;
                int year, horsepower;
                double price, acceleration, engineVolume;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Brand: ";
                getline(std::cin, brand);

                std::cout << "Year: ";
                std::cin >> year;

                std::cout << "Price: ";
                std::cin >> price;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Equipment: ";
                getline(std::cin, equipment);

                std::cout << "Country: ";
                getline(std::cin, country);

                std::cout << "Sale Date: ";
                getline(std::cin, saleDate);

                std::cout << "Buyer Name: ";
                getline(std::cin, buyerName);

                std::cout << "Acceleration: ";
                std::cin >> acceleration;

                std::cout << "Engine Volume: ";
                std::cin >> engineVolume;

                std::cout << "Horsepower: ";
                std::cin >> horsepower;

                manager.addCar(
                    new SportsCar(
                        brand,
                        year,
                        price,
                        equipment,
                        country,
                        saleDate,
                        buyerName,
                        acceleration,
                        engineVolume,
                        horsepower
                    )
                );

                std::cout << "\nSports car added successfully!\n";
                pause();
                break;
            }

            case 3:
            {
                //clearScreen();
                std::string brand, equipment, country, saleDate, buyerName;
                std::string vehicleType, dimensions;

                int year;

                double price, weight;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Brand: ";
                getline(std::cin, brand);

                std::cout << "Year: ";
                std::cin >> year;

                std::cout << "Price: ";
                std::cin >> price;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Equipment: ";
                getline(std::cin, equipment);

                std::cout << "Country: ";
                getline(std::cin, country);

                std::cout << "Sale Date: ";
                getline(std::cin, saleDate);

                std::cout << "Buyer Name: ";
                getline(std::cin, buyerName);

                std::cout << "Vehicle Type: ";
                getline(std::cin, vehicleType);

                std::cout << "Weight: ";
                std::cin >> weight;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Dimensions: ";
                getline(std::cin, dimensions);

                manager.addCar(
                    new SpecialVehicle(
                        brand,
                        year,
                        price,
                        equipment,
                        country,
                        saleDate,
                        buyerName,
                        vehicleType,
                        weight,
                        dimensions
                    )
                );

                std::cout << "\nSpecial vehicle added successfully!\n";
                pause();
                break;
            }

            case 4:
            {
                //clearScreen();
                manager.showAll();
                pause();
                break;
            }

            case 5:
            {
                //clearScreen();
                manager.sortByPrice();

                std::cout << "\nCars sorted by price!\n";
                pause();
                break;
            }

            case 6:
            {
                //clearScreen();
                manager.sortByYear();

                std::cout << "\nCars sorted by year!\n";
                pause();
                break;
            }

            case 7:
            {
                //clearScreen();
                std::string brand;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter brand: ";
                getline(std::cin, brand);

                manager.searchByBrand(brand);
                pause();
                break;
            }

            case 8:
            {
                //clearScreen();
                int index;

                std::cout << "Enter index: ";
                std::cin >> index;

                manager.removeCar(index);

                std::cout << "\nCar removed!\n";
                pause();
                break;
            }

            case 9:
            {
                //clearScreen();
                int index;

                std::cout << "Enter index: ";
                std::cin >> index;

                manager.editCar(index);
                pause();
                break;
            }

            case 10:
            {
                //clearScreen();
                manager.saveToFile("cars.txt");

                std::cout << "\nSaved successfully!\n";
                pause();
                break;
            }

            case 11:
            {
                //clearScreen();
                manager.loadFromFile("cars.txt");

                std::cout << "\nLoaded successfully!\n";
                pause();
                break;
            }

            case 12:
            {
                //clearScreen();
                std::cout << "\nTotal cars: "
                    << Car::getCarCount()
                    << std::endl;
                pause();
                break;
            }

            case 0:
            {
                //clearScreen();
                std::cout << "\nGoodbye!\n";
                pause();
                break;
            }

            default:
            {
                //clearScreen();
                std::cout << "\nInvalid choice!\n";
                pause();
            }
            }
        }
        catch (std::exception& ex)
        {
            //clearScreen();
            std::cout << "\nError: " << ex.what() << std::endl;
            pause();
        }

    } while (choice != 0);

	return 0;
}