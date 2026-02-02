 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */


struct FishStore
{
    // 5 properties:
    int numberOfTanks = 45;      //     1) number of tanks (int)
    int numberOfFilters = 90;    //     2) number of filters (int)
    int numberOfEmployees = 3;   //     3) number of employees on given day (int)
    int numberOfFishSold = 120;   //     4) fish sold per day (int)
    float amountOfWaterUsed = 200.f;     //     5) amount of RO water used per day (float)

    // this is the nested UDT:
    struct FishTank
    {
        // 5 member variables with relevant data types.
        int tankGallonSize = 20;
        int poundsOfGravel = 10;
        int numberOfFilters = 2;
        int numberOfHeaters = 1;
        std::string brand = "UNS tanks";

        // 3 member functions.
        void fillTankWithWater(float gallonsOfWaterToFill = 10.f);
        void drainTankOfWater(float gallonsOfWaterToDrain = 5.5f);
        void addFishToTank(std::string fishType = "Cory Catfish", int numberOfFishToAdd = 1);

    };

    // things it can do:
    void changeWater();                                 //     1) water change
    void sellFish(std::string fishType, int amount);     //     2) employee sells Fish to customer
    void sellFishTank(FishTank fishTank);               //     3) employee sells Tank to customer
    void cleanTanks();                                  //     4) clean tanks

    FishTank fishTankBeingUsed;                         // member variable whose type is a UDT.
    };

struct GuitarShop
{
    // 5 properties:
    int numberOfGibsonGuitars = 300;        //     1) number of Gibson guitars in stock (int)
    int numberOfFenderGuitars = 250;       //     2) number of Fender guitars in stock (int)
    int numberOfEmployees = 13;           //     3) number of employees on given day (int)
    int numberOfGuitarsSold = 15000;     //     4) number of guitars sold per year (double)
    int numberOfStrings = 1000;         //     5) amount of strings left in stock (int)


    // this is the nested UDT:
    struct Guitar
    {
        int numberOfStrings = 6;
        int numberOfFrets = 24;
        std::string guitarType = "Electric";
        std::string guitarBrand = "Gibson";
        std::string guitarModel = "Les Paul";

        void playGuitar();
        void tuneGuitar(std::string tuningType ="Drop D");   
        void changeStrings(std::string stringBrand = "Ernie Ball", std::string stringGauge = "10-46");
    };

    // 3 things it can do:
    void sellGuitar(Guitar guitar);    //     1) sell a guitar to a customer
    void changePrice(float originalPrice, float discountPercentage);     //     2) change pricing on a guitar
    float checkStatusOfGuitar(Guitar guitar);        // check status of guitar

    Guitar guitarBeingSold;      // member variable whose type is a UDT.

    };

struct GuitarRepairShop
{
    // 5 properties:
    int numberOfStrings = 1000;          //     1) amount of strings left in stock (int)
    int numberOfElectronics = 50;        //     2) amount of replacement electronics left in stock (int)
    int numberOfPickups = 20;            //     3) amount of replacement pickups left in stock (int)
    double numberOfPicksGivenOut = 10000;//     4) number of guitar picks given out per year (double)
    int numberOfGuitarsSetUp = 10;       //     5) number of guitars set up per day (int)

    // 3 things it can do:
    void fretRedressing();        //     1) fret redressing
    void changePickups();        //     2) change pickups
    void setUpGuitar();         //     3) set up a guitar

};

struct RecordingStudio
{
    // 5 properties:
    int numberOfMicrophones = 42;         //     1) number of microphones (int)
    int numberOfAmps = 12;                //     2) number of amps (int)
    int numberOfEngineers = 3;            //     3) number of engineers on given day (int)
    int numberOfTracksRecorded = 4;       //     4) number of tracks recorded per day (float)
    float lengthOfTimeRecorded = 6.5f;    //     5) length of time recorded per day (float)

    // 3 things it can do:
    void recordTrack();        //     1) record a track
    void mixTrack();           //     2) mix a track
    void masterTrack();        //     3) master a track

};

struct DisplayMonitor
{
    // 5 properties:
    int resolutionWidth = 1920;    //     1) resolution width in pixels (int)
    int resolutionHeight = 1080;    //     2) resolution height in pixels (int) 
    int numberOfHDMIPorts = 2;    //     3) HDMI ports (int)
    int refreshRate = 144;    //     4) refresh rate in Hz (int)
    int sizeInInches = 27;    //     5) diagnal size in inches (int)

    // 3 things it can do:
    void displayImage();    //     1) display an image
    void displayVideo();    //     2) display a video
    void displayGame();    //     3) display a game

};

struct Memory
{
    // 5 properties:
    int amountOfRAM = 16;                //     1) amount of RAM in GB (int)
    double speedOfRAM = 3200.0;          //     2) speed of RAM in Hz (double)
    std::string ramStandard = "DDR4";    //     3) RAM standard (std::string)
    float productVoltage = 1.2f;         //     4) product voltage (float)
    std::string ramTechnology = "DDR";    //     5) RAM technology (std::string) 

    // 3 things it can do:
    void runGame();       //     1) run game 
    void runProgram();    //     2) run program
    void storeData();     //     3) temporarily store data

};

struct CPU
{
    // 5 properties:
    float clockSpeed = 3.6f;           //     1) clock speed in GHz (float)
    int coreCount = 6;                 //     2) core count (int)
    float maxClockSpeed = 4.2f;        //     3) max clock speed in GHz (float)
    int maxTemperature = 100;        //     4) max temperature in C (int)
    std::string model = "Ryzen 5 3600";        //     5) model (std::string)

    // 3 things it can do:
    void processData();              //     1) process data
    void computeData();              //     2) compute dat
    void fetchInstructions();        //     3) fetch instructions from memory

};

struct Motherboard
{
    // 5 properties:
    int ramSlots = 4;        //     1) RAM slots (int)
    int pciSlots = 2;        //     2) PCI slots (int)
    std::string branch = "AM4";        //     3) branch (std::string)
    std::string formFactor = "ATX";        //     4) form factor (std::string)
    std::string chipset = "B450";        //     5) chipset (std::string)

    // 3 things it can do:
    void connectCPU();        //     1) connect to CPU
    void connectRAM();        //     2) connect RAM
    void connectGPU();        //     3) connect GPU
};

struct Storage
{
    // 5 properties:
    int numberOfHardDrives = 2;    //     1) number of hard drives (int)
    int numberOfSSDDrives = 1;        //     2) number of SSD drives (int)
    int totalStorage = 1024;    //     3) total storage in GB (int)
    int writeSpeed = 550;    //     4) write speed in MB/s (int)
    std::string brand = "Samsung";    //     5) brand (std::string)

    // 3 things it can do:
    void writeData();    //     1) write data
    void storeData();        //     2) store data
    void loadData();        //     3) load data
};

struct Computer
{
    // 5 properties: 
    DisplayMonitor displayMonitor;        //     1) Monitor
    Memory memory;        //     2) Memory
    CPU cpu;
    Motherboard motherboard;
    Storage storage;

    // 3 things it can do:
    void runProgram();
    void programProgram();
    void playGame();
};







int main()
{
    std::cout << "good to go!" << std::endl;
}
