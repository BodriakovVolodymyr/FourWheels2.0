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
        clearScreen();

        std::cout << "\n========== MENU ==========\n";
        std::cout << "1. Add Car\n";
        std::cout << "2. Show Cars\n";
		std::cout << "3. Sorting Cars List\n";
		std::cout << "4. Search Car By Brand\n";
        std::cout << "5. Remove Car\n";
        std::cout << "6. Edit Car\n";
        std::cout << "7. Save To File\n";
        std::cout << "8. Load From File\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose: ";

        std::cin >> choice;
        if(std::cin.fail())
        {
            clearScreen();
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
                clearScreen();
                int choise;
                std::cout << "Witch car you want to add(enter 1-3): " << std::endl;
                std::cout << "1. Used Car" << std::endl;
                std::cout << "2. Sports Car" << std::endl;
                std::cout << "3. Special Vehicle" << std::endl;
                std::cin >> choise;
                if (choise == 1)
                {

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

                    std::cout << "Condition (0/100% saved): ";
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
                else if (choise == 2)
                {

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
                else if (choise == 3)
                {

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
                else
                {
                    std::cout << "\nInvalid car type!\n";
                    pause();
                    break;
                }
                break;
            }
            case 2:
            {
                clearScreen();
                int showSelector;
				std::cout << "Show (1.Used Cars, 2.Sports Cars, 3.Special Vehicles, 4.All): ";
				std::cin >> showSelector;
				if (showSelector == 1)
				{
					manager.showUsedCars();
					pause();
					break;
				}
				else if (showSelector == 2)
				{
					manager.showSportsCars();
					pause();
					break;
				}
				else if (showSelector == 3)
				{
					manager.showSpecialVehicles();
					pause();
					break;
				}
				else if (showSelector == 4)
				{
					manager.showAll();
					pause();
					break;
				}
				else
				{
					std::cout << "\nInvalid show type!\n";
					pause();
					break;
				}
                
            }

            case 3:
            {
                clearScreen();
                int enterSortType;
                std::cout << "Enter sort type(1.Price, 2.Year): ";
                std::cin >> enterSortType;
                if (enterSortType == 1)
                {
                    manager.sortByPrice();

                    std::cout << "\nCars sorted by price!\n";
                    pause();
                    break;
                }
                else if (enterSortType == 2)
                {
                    manager.sortByYear();
                    std::cout << "\nCars sorted by year!\n";
                    pause();
                    break;
                }
                else
                {
                    std::cout << "\nInvalid sort type!\n";
                    pause();
                    break;
                }
                break;
            }

            case 4:
            {
                clearScreen();
                int searchType;
                std::cout << "Search by (1.Brand, 2.Index, 3.PriceRange): ";
                std::cin >> searchType;
                if (searchType == 1)
                {
                    std::string brand;

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    std::cout << "Enter brand: ";
                    getline(std::cin, brand);

                    manager.searchByBrand(brand);
                    pause();
                    break;
                }
                else if (searchType == 2)
                {
                    int index;
                    std::cout << "Enter index: ";
                    std::cin >> index;
                    manager.searchByIndex(index);
                    pause();
                    break;
                }
                else if (searchType == 3)
                {
                    double minPrice, maxPrice;
                    std::cout << "Enter minimum price: ";
                    std::cin >> minPrice;
                    std::cout << "Enter maximum price: ";
                    std::cin >> maxPrice;
                    manager.searchByPriceRange(minPrice, maxPrice);
                    pause();
                    break;
                }
                else
                {
                    std::cout << "\nInvalid search type!\n";
                    pause();
                    break;
                }
                break;
            }

            case 5:
            {
                clearScreen();
                int index;

                std::cout << "Enter id: ";
                std::cin >> index;

                manager.removeCar(index);

                std::cout << "\nCar removed!\n";
                pause();
                break;
            }

            case 6:
            {
                clearScreen();
                int index;

                std::cout << "Enter index: ";
                std::cin >> index;

                manager.editCar(index);
                pause();
                break;
            }


            case 7:
            {
                clearScreen();
                manager.saveToFile("cars.txt");

                std::cout << "\nSaved successfully!\n";
                pause();
                break;
            }

            case 8:
            {
                clearScreen();
                manager.loadFromFile("cars.txt");

                std::cout << "\nLoaded successfully!\n";
                pause();
                break;
            }

            case 0:
            {
                clearScreen();
                std::cout << "\nGoodbye!\n";
                pause();
                break;
            }

            default:
            {
                clearScreen();
                std::cout << "\nInvalid choice!\n";
                pause();
            }
            }
        }
        catch (std::exception& ex)
        {
            clearScreen();
            std::cout << "\nError: " << ex.what() << std::endl;
            pause();
        }

    } while (choice != 0);

	return 0;
}