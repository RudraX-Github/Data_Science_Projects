#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle {
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;
    static int totalVehicles;

public:
    Vehicle(int id, string manu, string mod, int yr) : vehicleID(id), manufacturer(manu), model(mod), year(yr) {
        totalVehicles++;
    }

    virtual ~Vehicle() {
        totalVehicles--;
    }

    static int getTotalVehicles() {
        return totalVehicles;
    }

    int getVehicleID() const { return vehicleID; }
    string getManufacturer() const { return manufacturer; }
    string getModel() const { return model; }
    int getYear() const { return year; }

    void setVehicleID(int id) { vehicleID = id; }
    void setManufacturer(string manu) { manufacturer = manu; }
    void setModel(string mod) { model = mod; }
    void setYear(int yr) { year = yr; }

    virtual void display() const {
        cout << "Vehicle ID: " << vehicleID << "\nManufacturer: " << manufacturer << "\nModel: " << model << "\nYear: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle {
protected:
    string fuelType;

public:
    Car(int id, string manu, string mod, int yr, string fuel) : Vehicle(id, manu, mod, yr), fuelType(fuel) {}

    string getFuelType() const { return fuelType; }
    void setFuelType(string fuel) { fuelType = fuel; }

    void display() const override {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car {
protected:
    int batteryCapacity;

public:
    ElectricCar(int id, string manu, string mod, int yr, string fuel, int battery) : Car(id, manu, mod, yr, fuel), batteryCapacity(battery) {}

    int getBatteryCapacity() const { return batteryCapacity; }
    void setBatteryCapacity(int battery) { batteryCapacity = battery; }

    void display() const override {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

class Aircraft {
protected:
    int flightRange;

public:
    Aircraft(int range) : flightRange(range) {}

    int getFlightRange() const { return flightRange; }
    void setFlightRange(int range) { flightRange = range; }

    virtual void display() const {
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar(int id, string manu, string mod, int yr, string fuel, int range) : Car(id, manu, mod, yr, fuel), Aircraft(range) {}

    void display() const override {
        Car::display();
        Aircraft::display();
    }
};

class SportsCar : public ElectricCar {
protected:
    int topSpeed;

public:
    SportsCar(int id, string manu, string mod, int yr, string fuel, int battery, int speed) : ElectricCar(id, manu, mod, yr, fuel, battery), topSpeed(speed) {}

    int getTopSpeed() const { return topSpeed; }
    void setTopSpeed(int speed) { topSpeed = speed; }

    void display() const override {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};

class Sedan : public Car {
public:
    Sedan(int id, string manu, string mod, int yr, string fuel) : Car(id, manu, mod, yr, fuel) {}

    void display() const override {
        Car::display();
    }
};

class SUV : public Car {
public:
    SUV(int id, string manu, string mod, int yr, string fuel) : Car(id, manu, mod, yr, fuel) {}

    void display() const override {
        Car::display();
    }
};

class VehicleRegistry {
private:
    vector<Vehicle*> vehicles;

public:
    void addVehicle(Vehicle* v) {
        vehicles.push_back(v);
    }

    void displayAll() const {
        for (const auto& v : vehicles) {
            v->display();
            cout << "-------------------" << endl;
        }
    }

    Vehicle* searchById(int id) const {
        for (const auto& v : vehicles) {
            if (v->getVehicleID() == id) {
                return v;
            }
        }
        return nullptr;
    }

    ~VehicleRegistry() {
        for (auto& v : vehicles) {
            delete v;
        }
    }
};

int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "1. Add Vehicle\n2. View All Vehicles\n3. Search by ID\n4. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int type, id, year, battery, range, speed;
            string manu, model, fuel;

            cout << "Enter Vehicle Type (1: Car, 2: ElectricCar, 3: FlyingCar, 4: SportsCar, 5: Sedan, 6: SUV): ";
            cin >> type;
            cout << "Enter Vehicle ID: ";
            cin >> id;
            cout << "Enter Manufacturer: ";
            cin >> manu;
            cout << "Enter Model: ";
            cin >> model;
            cout << "Enter Year: ";
            cin >> year;

            if (type == 1) {
                cout << "Enter Fuel Type: ";
                cin >> fuel;
                registry.addVehicle(new Car(id, manu, model, year, fuel));
            } else if (type == 2) {
                cout << "Enter Fuel Type: ";
                cin >> fuel;
                cout << "Enter Battery Capacity: ";
                cin >> battery;
                registry.addVehicle(new ElectricCar(id, manu, model, year, fuel, battery));
            } else if (type == 3) {
                cout << "Enter Fuel Type: ";
                cin >> fuel;
                cout << "Enter Flight Range: ";
                cin >> range;
                registry.addVehicle(new FlyingCar(id, manu, model, year, fuel, range));
            } else if (type == 4) {
                cout << "Enter Fuel Type: ";
                cin >> fuel;
                cout << "Enter Battery Capacity: ";
                cin >> battery;
                cout << "Enter Top Speed: ";
                cin >> speed;
                registry.addVehicle(new SportsCar(id, manu, model, year, fuel, battery, speed));
            } else if (type == 5) {
                cout << "Enter Fuel Type: ";
                cin >> fuel;
                registry.addVehicle(new Sedan(id, manu, model, year, fuel));
            } else if (type == 6) {
                cout << "Enter Fuel Type: ";
                cin >> fuel;
                registry.addVehicle(new SUV(id, manu, model, year, fuel));
            }
        } else if (choice == 2) {
            registry.displayAll();
        } else if (choice == 3) {
            int id;
            cout << "Enter Vehicle ID: ";
            cin >> id;
            Vehicle* v = registry.searchById(id);
            if (v) {
                v->display();
            } else {
                cout << "Vehicle not found!" << endl;
            }
        }
    } while (choice != 4);

    return 0;
}
