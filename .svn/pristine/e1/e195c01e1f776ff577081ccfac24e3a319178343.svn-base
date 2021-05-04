// sorting apples
// non STL-algorithm code to be replaced by algorthms
// Mikhail Nesterenko modified by Matthew Sherlin
// 10/03/2018


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector; using std::deque;

struct Apples{
   double weight; // oz
   string color;  // red or green
   void print() const { cout << color << ", " <<  weight << endl; }
};

int main(){
   srand(time(nullptr));
   const double minWeight = 3.;
   const double maxWeight = 8.;

   cout << "Input crate size: ";
   int size;
   cin >> size;

   vector <Apples> crate(size);

   std::generate(crate.begin(), crate.end(), [=](){Apples apple1; apple1.weight=minWeight + static_cast<double>(rand())/RAND_MAX*(maxWeight - minWeight); apple1.color = rand() % 2 == 1 ? "green" : "red"; return apple1;});

   cout << "Enter weight to find: ";
   double toFind;
   cin >> toFind;

  int cnt=std::count_if(crate.begin(), crate.end(), [=](Apples apple1){ return apple1.weight > toFind;});

   cout << "There are " << cnt << " apples heavier than " 
	<< toFind << " oz" <<  endl;

   // find_if()
   cout << "at positions ";
   
   auto it=crate.begin();
   do{
   it=std::find_if(++it, crate.end(), [=](Apples apple1){return apple1.weight > toFind;});
   if(it == crate.end()) break;
   cout << it - crate.begin() << " ";
   }while(it != crate.end());
   cout << endl;
   
   

   // max_element()
  double heaviest = crate[0].weight; 
  auto it2 = crate.begin();
  it2 = std::max_element(crate.begin(), crate.end(), [](Apples apple1, Apples apple2){return apple1.weight < apple2.weight;});
  cout << "The heaviest apple is " << it2->weight << " oz.\n";
  


   // for_each() or accumulate()
   double sum = 0;
   auto total = std::accumulate(crate.begin(), crate.end(), sum, [=](double a, Apples apple) {return a + apple.weight;});
   cout << "Total apple weight is: " << total << " oz" << endl;


   // transform();
   cout << "How much should they grow: ";
   double toGrow;
   cin >> toGrow;

  std::transform(crate.begin(), crate.end(), crate.begin(), [=](Apples apple){Apples apple1; apple1.weight= apple.weight+toGrow; apple1.color = apple.color; return apple1;});

   // remove_if()
   cout << "Input minimum acceptable weight: ";
   double minAccept;
   cin >> minAccept;
   
   crate.erase(std::remove_if(crate.begin(), crate.end(), [=](Apples &apple){return apple.weight < minAccept;}), crate.end());
   cout << "removed " << size - crate.size() << " elements" << endl;

   // bubble sort, replace with sort()
  
  std::sort(crate.begin(), crate.end(), [=](Apples apple, Apples apple2){return apple.weight < apple2.weight;});

   // moving all red apples from crate to peck
   // remove_copy_if() with back_inserter()/front_inserter() or equivalents
  deque<Apples> peck(size);

  std::remove_copy_if(crate.begin(), crate.end(), peck.begin(), [=](Apples apple){return apple.color != "red";});
  crate.erase(std::remove_if(crate.begin(), crate.end(), [=](Apples apple){return apple.color == "red";}), crate.end());

   // for_each() possibly
  cout << "apples in the crate"<< endl;
  std::for_each(crate.begin(), crate.end(), [=](Apples apple){if(apple.color != "")apple.print();});
  cout << endl;

   // for_each() possibly
  cout << "apples in the peck"<< endl;
  std::for_each(peck.begin(), peck.end(), [=](Apples apple){if(apple.color != "")apple.print();});

   // prints every "space" apple in the peck
   // 
   const int space=3; 
   cout << "\nevery " << space << "\'d apple in the peck"<< endl;

   // replace with advance()/next()/distance()
   // no iterator arithmetic
    int i = 1;
    auto itr = peck.begin();
    while(itr != peck.end()){
      if(itr->color != "" && i%3 == 0) itr->print();
      std::advance(itr, 1);
      ++i;
   }
     cout << endl;

  // putting all small green apples in a jam
  // use a binder to create a functor with configurable max weight
  // accumulate() or count_if() then remove_if()
   class jam{
     public:
       jam(){};
       void operator()(vector<Apples> apples, double max_weight){
         for(auto &e : apples){
  	       if(e.weight < max_weight) jamWeight += e.weight;
          }
       };
       
       double getJamWeight(){return jamWeight;};
     private:
       double jamWeight = 0;   
     };

   const double weightToJam = 10.0;
   jam jammy;

   auto f1 = std::bind(jammy, crate, std::placeholders::_1);
   f1(weightToJam);

   cout << "Weight of jam is: " << jammy.getJamWeight() << endl;

}
