#include <iostream>
#include <vector>
#include <map>

using namespace std; 

class City {
public:
    vector<string> Hotel;
    vector<string> Restaurant;
    vector<string> VisitingPlace;

    City(const vector<string>& hotels, const vector<string>& restaurants, const vector<string>& visitingPlaces) :
        Hotel(hotels), Restaurant(restaurants), VisitingPlace(visitingPlaces) {}
};

void citiesInfo(map<int, string>& Cityname, map<string, City>& Cityinfo) {
    vector<string> delhi_hotels = {
        "1.Radisson blu Marina Hotel",
        "2.Hotel Hari Piorko",
        "3.The Corus Hotel",
        "4.Hotel Connaught Royale"
    };
    vector<string> delhi_Restaurant = {
        "1.The GT Road",
        "2.Barbeque Nation",
        "3. Haldiram’s",
        "4.Sandoz"
    };
    vector<string> delhi_VisitingPlace = {
        "1.Gurudwara Sri Bangla Sahib",
        "2.Jantar Mantar",
        "3.Museum of Illusions",
        "4.Ugrasen ki Baoli"
    };

    vector<string> mumbai_hotels = {
        "1.Marriott Executive Apartment",
        "2.Vivanta Navi Mumbai Turbhe",
        "3.FabHotel Starwood Residency",
        "4.Collection O sairup"
    };
    vector<string> mumbai_Restaurant = {
        "1.Barbeque Nation",
        "2.Soy street",
        "3.Cafe Vihar",
        "4.Something Fishy"
    };
    vector<string> mumbai_VisitingPlace = {
        "1.Gateway Of India",
        "2.Elephant Caves",
        "3.Chhatrapati Shivaji Maharaj Terminus",
        "4.Shree Siddhivinayak Temple"
    };

    vector<string> bangalore_hotels = {
        "1.LoCul Central Church Street",
        "2.Galaxy comfort inn",
        "3.Octave Kings Suites",
        "4.Monarch Luxur Hotel"
    };
    vector<string> bangalore_Restaurant = {
        "1.Hard Rock Café",
        "2.Gazebo Pool & Restaurant",
        "3.Empire Restaurant",
        "4.The Pub Residency Road"
    };
    vector<string> bangalore_VisitingPlace = {
        "1.Cubbon Park",
        "2.Indiragandhi Musical fountain Park",
        "3.Shivoham Shiva Temple",
        "4.Tipu Sultan’s Summer Palace"
    };

    vector<string> kolkata_hotels = {
        "1.The Oberoi Grand",
        "2.Hotel Angina",
        "3.Polo Floatel",
        "4.Hotel Minerva"
    };
    vector<string> kolkata_Restaurant = {
        "1.Hatari",
        "2.Mughal Garden",
        "3.Kafe Eden",
        "4.Chittoda’s Suruchee"
    };
    vector<string> kolkata_VisitingPlace = {
        "1.Howrah Bridge",
        "2.Fort William",
        "3.Indian Museum",
        "4.Victoria Memorial"
    };

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
    map<int, string> Cityname;
    map<string, City> Cityinfo;
    citiesInfo(Cityname, Cityinfo);

    while (true) {
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "---------------------------------New----------------------------------------" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "Welcome to the Track Your Journey App" << endl;
        cout << "Available cities:" << endl;
        for (const auto& entry : Cityname) {
            cout << entry.first << ") " << entry.second << endl;
        }
        cout << "Enter the number of the city you want to explore (or type 'quit' to exit): ";
        string input;
        cin >> input;
        if (input == "quit" || input == "exit") {
            cout << "Thank You For Visiting Us!!" << endl;
            break;
        }
        try {
            int selectedCityNum = stoi(input);
            string selectedcity = Cityname[selectedCityNum];
            if (!selectedcity.empty()) {
                City cityinformation = Cityinfo[selectedcity];
                cout << "Selected City: " << selectedcity << endl;
                cout << "What information would you like to know:- 1)Hotels 2)Restaurants 3)Visiting place" << endl;
                cin >> input;
                if (input == "Hotels") {
                    cout << "Hotels" << endl;
                    for (const string& hotel : cityinformation.Hotel) {
                        cout << hotel << endl;
                    }
                }
                else if (input == "Restaurants") {
                    cout << "Restaurants" << endl;
                    for (const string& restaurant : cityinformation.Restaurant) {
                        cout << restaurant << endl;
                    }
                }
                else if (input == "Visiting place") {
                    cout << "Visiting Place" << endl;
                    for (const string& place : cityinformation.VisitingPlace) {
                        cout << place << endl;
                    }
                }
                else {
                    cout << "Invalid!!" << endl;
                }
            }
            else {
                cout << "Invalid entry!!" << endl;
            }
        }
        catch (invalid_argument&) {
            cout << "Invalid input. Please enter a number or 'quit' to exit." << endl;
        }
    }

    return 0;
}
