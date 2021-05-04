// needed for lab
// Mikhail Nesterenko modified by Matthew Michael Sherlin
// 3/26/2021

#include <iostream>
#include <vector>
#include <cstdlib>
#include "CarFactory.hpp"

using std::vector;
using std::cout; using std::endl;

class CarLot{
public:
   CarLot();

   Car *buyCar(){ 
      Car* buy = &car4sale_[nextCars];
      car4sale_[nextCars] = 
        *(factories_[rand()%factories_.size()]->requestCar());
      return buy;
   }
    
   Car *nextCar(){
      if(++nextCars ==10){
      nextCars = 0;
      }
      Car* next1= &car4sale_[nextCars];
      return next1;
   }
   
   int lotSize(){ 
     return size_; 
   } 
   
private:
  const static int size_=10;
  Car car4sale_[size_]; // single car for sale at the lot
  vector<CarFactory *> factories_;
  static int nextCars;
};

CarLot::CarLot(){
   // creates 2 Ford factories and 2 Toyota factories 
   factories_.push_back(new FordFactory());   
   factories_.push_back(new ToyotaFactory());
   factories_.push_back(new FordFactory());
   factories_.push_back(new ToyotaFactory());

   // gets the first car for sale
   for(int i=0; i < size_; ++i){
   car4sale_[i] = *(factories_[rand() % factories_.size()] -> requestCar());
  }
}

CarLot *carLotPtr = nullptr; // global pointer instantiation
int CarLot::nextCars=0; // static members initialization

// test-drives a car
// buys it if Toyota
void toyotaLover(int id){
   if (carLotPtr == nullptr)
      carLotPtr = new CarLot();

   for(int i = 0; i < carLotPtr->lotSize(); ++i){
   Car *toBuy = carLotPtr -> nextCar(); 
   cout << "Buyer " << id << endl;
   cout << "test driving " 
	<< toBuy->getMake() << " "
	<< toBuy->getModel();

   if (toBuy->getMake() == "Toyota"){
      cout << " love it! buying it!" << endl;
      carLotPtr -> buyCar();
      break;
   } else
      cout << " did not like it!" << endl;
  }
  cout << "\n=========================================\n";
}

// test-drives a car
// buys it if Ford
void fordLover(int id){
   if (carLotPtr == nullptr)
      carLotPtr = new CarLot();
      
   for(int i = 0; i < carLotPtr->lotSize(); ++i){
   Car *toBuy = carLotPtr -> nextCar();
   
   cout << "Buyer " << id << endl;
   cout << "test driving "
	<< toBuy->getMake() << " "
        << toBuy->getModel();
   
   if (toBuy->getMake() == "Ford"){
      cout << " love it! buying it!" << endl;
      carLotPtr -> buyCar();
      break;
   } else
      cout << " did not like it!" << endl;
  }
  cout << "\n=========================================\n";
}



int main() {
   srand(time(nullptr));

   const int numBuyers=10;
   for(int i=0; i < numBuyers; ++i)
      if(rand()% 2 == 0)
	 toyotaLover(i);
      else
	 fordLover(i);

  
}