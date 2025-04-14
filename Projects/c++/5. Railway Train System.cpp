#include <iostream>
#include <cstring>
using namespace std;
class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
    static int trainCount;
    

public:
    Train() //Default Constructure
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }
    // paramiterised constructor
    Train(int number, const char* name, const char* src, const char* desti, const char* time)
        
    {
        trainNumber = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, desti);
        strcpy(trainTime, time);
        trainCount++;
    }
    // Deconstructor
    ~Train()
    {
        trainCount--;
    }

    // Getters and Setters
    int getTrainNumber() const //"const" function does not modify any non-static data members of the class
    {
        return trainNumber;
    }
    const char* getTrainName() const
    {
        return trainName;
    }
    //"char*"function returns a pointer to a constant character
    const char* getSource() const
    {
        return source;
    }
    const char* getDestination() const
    {
        return destination;
    }

    const char* getTrainTime() const
    {
        return trainTime;
    }
    static int getTrainCount()
    {
        return trainCount;
    }

    // Input and Output methods
    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();  // To clear the input buffer
        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);
        cout << "Enter Source: ";
        cin.getline(source, 50);
        cout << "Enter Destination: ";
        cin.getline(destination, 50);
        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    void displayTrainDetails() const
    {
        cout << "Train Number               : " << trainNumber << endl;
        cout << "Train Name                 : " << trainName << endl;
        cout << "Source (Origin Station)    : " << source << endl;
        cout << "Destination (Last Station) : " << destination << endl;
        cout << "Train Time                 : " << trainTime << endl;
    }
};

// Static member initialization
int Train::trainCount = 0;

class RailwaySystem
{
private:
    Train trains[5];
    int totalTrains;

public:
    RailwaySystem()
    {
        totalTrains = 0;
    }
    // Add new train Details
    
    void addTrain()
    {
        if (totalTrains < 5)
        {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
            cout << "Train record added successfully." << endl;
        }
        else
        {
            cout << "Cannot add more trains. Kindly Increase Storage capacity" << endl;
        }
    }

    void displayAllTrains() const
    {
        if (totalTrains == 0)
        {
            cout << "No trains to display." << endl;
            return;
        }
        for (int i = 0; i < totalTrains; ++i)
        {
            cout << "Train " << (i + 1) << " details:" << endl;
            trains[i].displayTrainDetails();
            cout << endl;
        }
    }
    // Match Train detalis by train number
    void searchTrainByNumber(int number) const
    {
        bool found = false;
        for (int i = 0; i < totalTrains; ++i)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "Train found! Details:" << endl;
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
            else
            {
                cout<<"Kindly check your credentials "<< endl;
            }
        }
        if (!found)
        {
            cout << "Train with number " << number << " not found!" << endl;
        }
    }
    

};

int main()
{
    RailwaySystem railwaySystem;
    int choice;
    int searchNumber;

    do {
        cout << "--- Welcome to R&W Railways ---" << endl;
        cout << "--- Reservation System Menu ---" << endl;
        cout << "1. Add New Train Record" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "4. Book your Ticket" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                railwaySystem.addTrain();
                break;
            case 2:
                railwaySystem.displayAllTrains();
                break;
            case 3:
                cout << "Enter Train Number to search: ";
                cin >> searchNumber;
                railwaySystem.searchTrainByNumber(searchNumber);
                break;
            case 5:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != 4);

    return 0;
}