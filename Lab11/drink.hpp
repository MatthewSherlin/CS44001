// drink class to be used in Coffee Shack lab
// Mikhail Nesterenko modified by Matthew Sherlin
// 11/15/2016

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <string>

using std::string;
using std::vector;

enum DrinkType {small, medium, large};

class Drink{
public:
   Drink(DrinkType type = small, double price=0): type_(type), price_(price){}
   virtual double getPrice() const = 0;
   virtual string getName()  const = 0;
   virtual string getSize()  const = 0;
protected: 
    std::string name_;
    double price_;
    DrinkType type_;

};

class Coffee : public Drink {
public:
	Coffee(): 
	Drink(){}

	double getPrice() const override;
	string getName() const override;
	string getSize() const override;
	string getLevel() const;

	void printToppings() const;
	void orderCoffee();
	bool operator==(const Coffee&);

private:
	vector<char> toppings_;
	string level_;
};