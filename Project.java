import java.util.Scanner;
import java.util.*;
import java.util.HashMap;
class City{
    String Hotel[];
    String Restaurant[];
    String VisitingPlace[];
    public City(String Hotel[],String Restaurant[],String VisitingPlace[]){
        this.Hotel=Hotel;
        this.Restaurant=Restaurant;
        this.VisitingPlace=VisitingPlace;
    }
}
public class Project {
    private static void citiesInfo(HashMap<Integer,String> Cityname,HashMap<String,City> Cityinfo){
        String delhi_hotels[]={"1.Radisson blu Marina Hotel", 
                               "2.Hotel Hari Piorko",
                               "3.The Corus Hotel",
                               "4.Hotel Connaught Royale",
                               "5.Hotel Comrade"
                              };
        String delhi_Restaurant[]={"1.The GT Road",
                                   "2.Barbeque Nation",
                                   "3. Haldiram’s",
                                   "4.Sandoz",
                                   "5.Samyak marg"
                                  };
        String delhi_VisitingPlace[]={"1.Gurudwara Sri Bangla Sahib",
                                      "2.Jantar Mantar",
                                      "3.Museum of Illusions",
                                      "4.Ugrasen ki Baoli",
                                      "5.Sun set point"
                                    };
        String mumbai_hotels[]={"1.Marriott Executive Apartment",
                                "2.Vivanta Navi Mumbai Turbhe",
                                "3.FabHotel Starwood Residency",
                                "4.Collection O sairup",
                                "5.Jawhar e shaam"
                               };
        String mumbai_Restaurant[]={"1.Barbeque Nation",
                                    "2.Soy street",
                                    "3.Cafe Vihar",
                                    "4.Something Fishy",
                                    "5.Something unique"
                                   };
        String mumbai_VisitingPlace[]={"1.Gateway Of India",
                                       "2.Elephant Caves",
                                       "3.Chhatrapati Shivaji Maharaj Terminus",
                                       "4.Shree Siddhivinayak Temple",
                                       "5.Shiv temple"
                                      };
        String bangalore_hotels[]={"1.LoCul Central Church Street",
                                   "2.Galaxy comfort inn",
                                   "3.Octave Kings Suites",
                                   "4.Monarch Luxur Hotel"
                                  };
        String bangalore_Restaurant[]={"1.Hard Rock Café",
                                       "2.Gazebo Pool & Restaurant",
                                       "3.Empire Restaurant",
                                       "4.The Pub Residency Road"
                                      };
        String bangalore_VisitingPlace[]={"1.Cubbon Park",
                                          "2.Indiragandhi Musical fountain Park",
                                          "3.Shivoham Shiva Temple",
                                          "4.Tipu Sultan’s Summer Palace"
                                         };
        String kolkata_hotels[]={"1.The Oberoi Grand",
                                 "2.Hotel Angina",
                                 "3.Polo Floatel",
                                 "4.Hotel Minerva"
                                };
        String kolkata_Restaurant[]={"1.Hatari",
                                    "2.Mughal Garden",
                                    "3.Kafe Eden",
                                    "4.Chittoda’s Suruchee"};
        String kolkata_VisitingPlace[]={"1.Howrah Bridge",
                                        "2.Fort William", 
                                        "3.Indian Museum", 
                                        "4.Victoria Memorial"};       
        City kolkata=new City(kolkata_hotels, kolkata_Restaurant, kolkata_VisitingPlace);
        City delhi=new City(delhi_hotels, delhi_Restaurant, delhi_VisitingPlace);
        City mumbai=new City(mumbai_hotels, mumbai_Restaurant, mumbai_VisitingPlace);
        City bangalore=new City(bangalore_hotels, bangalore_Restaurant, bangalore_VisitingPlace);

        Cityinfo.put("Delhi(Cannaught place)", delhi);
        Cityinfo.put("Mumbai(Navi Mumbai)", mumbai);
        Cityinfo.put("Bangalore(Chinnaswamy Stadium)", bangalore);
        Cityinfo.put("Kolkata(Eden Garden)", kolkata);       
        Cityname.put(1, "Delhi(Cannaught place)");
        Cityname.put(2, "Mumbai(Navi Mumbai)");
        Cityname.put(3, "Bangalore(Chinnaswamy Stadium)");
        Cityname.put(4, "Kolkata(Eden Garden)"); 
    }
    public static void main(String args[]){
        HashMap<Integer,String> Cityname = new HashMap<>();
        HashMap<String,City> Cityinfo= new HashMap<>();
        citiesInfo(Cityname,Cityinfo);
        Scanner sc=new Scanner(System.in);
        while(true){
            System.out.println("----------------------------------------------------------------------------");
            System.out.println("---------------------------------New----------------------------------------");
            System.out.println("----------------------------------------------------------------------------");
            System.out.println("Welcome to the Track Your Journey App");
            System.out.println("Available cities:");

            Set<Integer> cities=Cityname.keySet();
            for (Integer s : cities) {
                System.out.println(s+") "+Cityname.get(s));
            }
            System.out.println("Enter the number of the city you want to explore (or type 'quit' to exit): ");
            String input = sc.nextLine();

            if(input.equals("quit")||input.equals("exit")){
                System.out.println("Thank You For Visiting Us!!");
                break;
            }

            try{
                int selectedCityNum = Integer.parseInt(input);
                String selectedcity=Cityname.get(selectedCityNum);
                if(selectedcity!=null){
                    City cityinformation=Cityinfo.get(selectedcity);
                    System.out.println("Selected City: "+ selectedcity);
                    System.out.println("What information would you like to know:- 1)Hotels 2)Restaurants 3)Visiting place");
                    String selectedoption=sc.nextLine();
                    if(selectedoption.equals("Hotels")){
                        System.out.println("Hotels");
                        for (String hotel : cityinformation.Hotel) {
                            System.out.println(hotel);
                        }
                    }
                    else if(selectedoption.equals("Restaurant")){
                        System.out.println("Restaurants");
                        for(String restrau : cityinformation.Restaurant){
                            System.out.println(restrau);
                        }
                    }
                    else if(selectedoption.equals("Visiting place")){
                        System.out.println("Visiting Place");
                        for(String vp : cityinformation.VisitingPlace){
                            System.out.println(vp);
                        }
                    }
                    else{
                        System.out.println("Invalid!!");
                    }
                }
                else{
                    System.out.println("Invalid entry!!");
                }
            }
            catch(NumberFormatException e) {
                System.out.println("Invalid input. Please enter a number or 'quit' to exit.");
            }
        }
    }
}
