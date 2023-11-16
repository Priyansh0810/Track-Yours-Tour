#include <iostream>
#include <unordered_map>
#include <vector>

class City {
public:
    std::vector<std::string> Hotel;
    std::vector<std::string> Restaurant;
    std::vector<std::string> VisitingPlace;

    City(std::vector<std::string> Hotel, std::vector<std::string> Restaurant, std::vector<std::string> VisitingPlace) {
        this->Hotel = Hotel;
        this->Restaurant = Restaurant;
        this->VisitingPlace = VisitingPlace;
    }
};

void citiesInfo(std::unordered_map<int, std::string>& Cityname, std::unordered_map<std::string, City>& Cityinfo) {
    std::vector<std::string> delhi_hotels = {"1.Radisson blu Marina Hotel",
                                              "2.Hotel Hari Piorko",
                                              "3.The Corus Hotel",
                                              "4.Hotel Connaught Royale"};
    std::vector<std::string> delhi_Restaurant = {"1.The GT Road",
                                                  "2.Barbeque Nation",
                                                  "3. Haldiram’s",
                                                  "4.Sandoz"};
    std::vector<std::string> delhi_VisitingPlace = {"1.Gurudwara Sri Bangla Sahib",
                                                     "2.Jantar Mantar",
                                                     "3.Museum of Illusions",
                                                     "4.Ugrasen ki Baoli"};
    std::vector<std::string> mumbai_hotels = {"1.Marriott Executive Apartment",
                                               "2.Vivanta Navi Mumbai Turbhe",
                                               "3.FabHotel Starwood Residency",
                                               "4.Collection O sairup"};
    std::vector<std::string> mumbai_Restaurant = {"1.Barbeque Nation",
                                                   "2.Soy street",
                                                   "3.Cafe Vihar",
                                                   "4.Something Fishy"};
    std::vector<std::string> mumbai_VisitingPlace = {"1.Gateway Of India",
                                                      "2.Elephant Caves",
                                                      "3.Chhatrapati Shivaji Maharaj Terminus",
                                                      "4.Shree Siddhivinayak Temple"};
    std::vector<std::string> bangalore_hotels = {"1.LoCul Central Church Street",
                                                  "2.Galaxy comfort inn",
                                                  "3.Octave Kings Suites",
                                                  "4.Monarch Luxur Hotel"};
    std::vector<std::string> bangalore_Restaurant = {"1.Hard Rock Café",
                                                      "2.Gazebo Pool & Restaurant",
                                                      "3.Empire Restaurant",
                                                      "4.The Pub Residency Road"};
    std::vector<std::string> bangalore_VisitingPlace = {"1.Cubbon Park",
                                                         "2.Indiragandhi Musical fountain Park",
                                                         "3.Shivoham Shiva Temple",
                                                         "4.Tipu Sultan’s Summer Palace"};
    std::vector<std::string> kolkata_hotels = {"1.The Oberoi Grand",
                                                "2.Hotel Angina",
                                                "3.Polo Floatel",
                                                "4.Hotel Minerva"};
    std::vector<std::string> kolkata_Restaurant = {"1.Hatari",
                                                    "2.Mughal Garden",
                                                    "3.Kafe Eden",
                                                    "4.Chittoda’s Suruchee"};
    std::vector<std::string> kolkata_VisitingPlace = {"1.Howrah Bridge",
                                                       "2.Fort William",
                                                       "3.Indian Museum",
                                                       "4.Victoria Memorial"};

    City kolkata(kolkata_hotels, kolkata_Restaurant, kolkata_VisitingPlace);
    City delhi(delhi_hotels, delhi_Restaurant, delhi_VisitingPlace);
    City mumbai(mumbai_hotels, mumbai_Restaurant, mumbai_VisitingPlace);
    City bangalore(bangalore_hotels, bangalore_Restaurant, bangalore_VisitingPlace);

    Cityinfo["Delhi(Cannaught place)"] = delhi;
    Cityinfo["Mumbai(Navi Mumbai)"] = mumbai;
    Cityinfo["Bangalore(Chinnaswamy Stadium)"] = bangalore;
    Cityinfo["Kolkata(Eden Garden)"] = kolkata;

    Cityname[1] = "Delhi(Cannaught place)";
    Cityname[2] = "Mumbai(Navi Mumbai)";
    Cityname[3] = "Bangalore(Chinnaswamy Stadium)";
    Cityname[4] = "Kolkata(Eden Garden)";
}

int main() {
    std::unordered_map<int, std::string> Cityname;
    std::unordered_map<std::string, City> Cityinfo;
    citiesInfo(Cityname, Cityinfo);

    while (true) {
        std::cout << "----------------------------------------------------------------------------" << std::endl;
        std::cout << "---------------------------------New----------------------------------------" << std::endl;
        std::cout << "----------------------------------------------------------------------------" << std::endl;
        std::cout << "Welcome to the Track Your Journey App" << std::endl;
        std::cout << "Available cities:" << std::endl;

        for (const auto& city : Cityname) {
            std::cout << city.first << ") " << city.second << std::endl;
        }

        std::cout << "Enter the number of the city you want to explore (or type 'quit' to exit): " << std::endl;
        std::string input;
        std::getline(std::cin, input);

        if (input == "quit" || input == "exit") {
            std::cout << "Thank You For Visiting Us!!" << std::endl;
            break;
        }

        try {
            int selectedCityNum = std::stoi(input);
            std::string selectedcity = Cityname[selectedCityNum];

            if (!selectedcity.empty()) {
                City cityinformation = Cityinfo[selectedcity];
                std::cout << "Selected City: " << selectedcity << std::endl;
                std::cout << "What information would you like to know:- 1)Hotels 2)Restaurants 3)Visiting place" << std::endl;
                std::getline(std::cin, input);

                if (input == "Hotels") {
                    std::cout << "Hotels" << std::endl;
                    for (const auto& hotel : cityinformation.Hotel) {
                        std::cout << hotel << std::endl;
                    }
                } else if (input == "Restaurants") {
                    std::cout << "Restaurants" << std::endl;
                    for (const auto& restaurant : cityinformation.Restaurant) {
                        std::cout << restaurant << std::endl;
                    }
                } else if (input == "Visiting place") {
                    std::cout << "Visiting Place" << std::endl;
                    for (const auto& visitingPlace : cityinformation.VisitingPlace) {
                        std::cout << visitingPlace << std::endl;
                    }
                } else {
                    std::cout << "Invalid!!" << std::endl;
                }
            } else {
                std::cout << "Invalid entry!!" << std::endl;
            }
        } catch (std::invalid_argument& e) {
            std::cout << "Invalid input. Please enter a number or 'quit' to exit." << std::endl;
        }
    }

    return 0;
}


