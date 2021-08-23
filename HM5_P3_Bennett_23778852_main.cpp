/*
NAME: Talike Bennett
EMPLID: 23778852
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Computer { //Base class

    public:

        virtual void Print() = 0; //Print function (virtual)

        //Setters
        void SetCPU(string CPU) { this->CPU = CPU; }
        void SetClockSpeed(double clockSpeed) { this->clockSpeed = clockSpeed; }
        void SetRAM(int RAM) { this->RAM = RAM; }
        void SetStorage(int storage) { this->storage = storage; }
        void SetPrice(double price) { this->price = price; }

        //Getters
        string GetCPU() const { return this->CPU; }
        double GetClockSpeed() const { return this->clockSpeed; }
        int GetRAM() const { return this->RAM; }
        int GetStorage() const { return this->storage; }
        double GetPrice() const {return this->price; }

    private:

        //Private data member(s)
        string CPU = "unknown";
        double clockSpeed = 0.0;
        int RAM = 0;
        int storage = 0;
        double price = 0.0;

};

class Desktop : public Computer { //Derived from Computer class.

    public:

        void Print() override { //Print function (overridden)

            cout << "CPU: " << this->GetCPU() << endl;
            cout << "Clock Speed: " << this->GetClockSpeed() << " GHz" << endl;
            cout << "RAM: " << this->GetRAM() << " GB" << endl;
            cout << "Storage: " << this->GetStorage() << " GB" << endl;
            cout << "Price: $" << this->GetPrice() << endl;
            cout << "Tower Size (W x D x H): " << this->GetTowerSize()[0] << " in. x "
                 << this->GetTowerSize()[1] << " in. x "
                 << this->GetTowerSize()[2] << " in." << endl;
            cout << "Warranty: " << warranty << " year(s)" << endl;
            cout << "PSU Wattage: " << PSU_Wattage << " W" << endl;

        }

        //Setters
        void SetTowerSize(double width, double depth, double height) {

            this->towerSize[0] = width;
            this->towerSize[1] = depth;
            this->towerSize[2] = height;

        }
        void SetWarranty(int warranty) { this->warranty = warranty; }
        void SetPSUWattage(int PSU_Wattage) { this->PSU_Wattage = PSU_Wattage; }

        //Getters
        double* GetTowerSize() { return this->towerSize; }
        int GetWarranty() const { return this->warranty; }
        int GetPSUWattage() const { return this->PSU_Wattage; }

    private:

        //Private data member(s)
        double towerSize[3] = {0.0, 0.0, 0.0};
        int warranty = 0;
        int PSU_Wattage = 0;

};

class Dell : public Desktop { //Derived from Desktop class.

    public:

        void Print() override { //Print function (overridden)

            this->Desktop::Print(); //Calls the print function from its parent class.
            cout << "Model Type: " << modelType << endl;

        }

        void SetModelType(string modelType) { this->modelType = modelType; } //Setter
        string GetModelType() const { return this->modelType; } //Getter

    private:

        //Private data member(s)
        string modelType = "unknown";

};

class HP : public Desktop { //Derived from Desktop class.

    public:

        void Print() override { //Print function (overridden)

            this->Desktop::Print(); //Calls the print function from its parent class.
            cout << "Model Type: " << modelType << endl;

        }

        void SetModelType(string modelType) { this->modelType = modelType; } //Setter
        string GetModelType() const { return this->modelType; } //Getter

    private:

        //Private data member(s)
        string modelType = "unknown";

};

class Laptop : public Computer { //Defined from Computer class.

    public:

        void Print() override { //Print function (overridden)

            cout << "CPU: " << this->GetCPU() << endl;
            cout << "Clock Speed: " << this->GetClockSpeed() << " GHz" << endl;
            cout << "RAM: " << this->GetRAM() << " GB" << endl;
            cout << "Storage: " << this->GetStorage() << " GB" << endl;
            cout << "Price: $" << this->GetPrice() << endl;
            cout << "Screen Size (diagonal): " << screenSize << " in." << endl;
            cout << "Weight: " << weight << " pounds" << endl;
            cout << "Battery Life: " << batteryLife << " hours" << endl;

        }

        //Setters
        void SetScreenSize(double screenSize) { this->screenSize = screenSize; }
        void SetWeight(double weight) { this->weight = weight; }
        void SetBatteryLife(int batteryLife) { this->batteryLife = batteryLife; }

        //Getters
        double GetScreenSize() const { return this->screenSize; }
        double GetWeight() const { return this->weight; }
        int GetBatteryLife() const { return this->batteryLife; }

    private:

        //Private data member(s)
        double screenSize = 0.0;
        double weight = 0.0;
        int batteryLife = 0;

};

class Apple : public Laptop { //Derived from Laptop class.

    public:

        void Print() override { //Print function (overridden)

            this->Laptop::Print(); //Calls the print function from its parent class.
            cout << "Make-Type: " << makeType << endl;

        }

        void SetMakeType(string makeType) { this->makeType = makeType; } //Setter
        string GetMakeType() const { return this->makeType; } //Getter

    private:

        //Private data member(s)
        string makeType = "unknown";

};

class Lenovo : public Laptop { //Derived from Laptop class.

    public:

        void Print() override { //Print function (overridden)

            this->Laptop::Print(); //Calls the print function from its parent class.
            cout << "Make-Type: " << makeType << endl;

        }

        void SetMakeType(string makeType) { this->makeType = makeType; } //Setter
        string GetMakeType() const { return this->makeType; } //Getter

    private:

        //Private data member(s)
        string makeType = "unknown";

};

int main(){

    Dell computer1;
    HP computer2;
    Apple computer3;
    Lenovo computer4;

    cout << fixed << setprecision(2);

    /* DELL */
    //Specs derived from https://deals.dell.com/en-us/productdetail/8r0c
    computer1.SetCPU("Intel Core i5");
    computer1.SetClockSpeed(2.9);
    computer1.SetRAM(8);
    computer1.SetStorage(512);
    computer1.SetPrice(929.99);
    computer1.SetTowerSize(6.65, 12.13, 14.45);
    computer1.SetWarranty(5);
    computer1.SetPSUWattage(360);
    computer1.SetModelType("Dell G5 Gaming Desktop");

    /* HP */
    //Specs derived from https://www.hp.com/us-en/shop/pdp/hp-pavilion-desktop-tp01-2255t-bundle-pc
    computer2.SetCPU("Intel Core i7");
    computer2.SetClockSpeed(2.5);
    computer2.SetRAM(16);
    computer2.SetStorage(256);
    computer2.SetPrice(949.99);
    computer2.SetTowerSize(6.12, 11.97, 13.28);
    computer2.SetWarranty(1);
    computer2.SetPSUWattage(310);
    computer2.SetModelType("HP Pavilion Desktop");

    /* APPLE */
    //Specs derived from https://www.apple.com/macbook-pro-16/specs/
    computer3.SetCPU("Intel Core i9");
    computer3.SetClockSpeed(2.3);
    computer3.SetRAM(16);
    computer3.SetStorage(512);
    computer3.SetPrice(2799);
    computer3.SetScreenSize(16);
    computer3.SetWeight(4.3);
    computer3.SetBatteryLife(11);
    computer3.SetMakeType("MacBook Pro 16\"");

    /* LENOVO */
    //Specs derived from https://www.lenovo.com/us/en/laptops/ideapad/ideapad-500-series/IdeaPad-5i-15IIL05/p/88IPS501391
    computer4.SetCPU("Intel Core i7");
    computer4.SetClockSpeed(2.8);
    computer4.SetRAM(16);
    computer4.SetStorage(512);
    computer4.SetPrice(979.99);
    computer4.SetScreenSize(15.6);
    computer4.SetWeight(3.66);
    computer4.SetBatteryLife(11);
    computer4.SetMakeType("IdeaPad 5");

    cout << "DELL COMPUTER INFO" << endl;
    computer1.Print();
    cout << endl;

    cout << "HP COMPUTER INFO" << endl;
    computer2.Print();
    cout << endl;

    cout << "APPLE COMPUTER INFO" << endl;
    computer3.Print();
    cout << endl;

    cout << "LENOVO COMPUTER INFO" << endl;
    computer4.Print();

    return 0;
}
