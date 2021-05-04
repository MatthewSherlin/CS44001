// sorting oranges
// converting vectors to multimaps
// Mikhail Nesterenko modified by Matthew Sherlin
// 2/17/2020

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::string; using std::multimap; using std::make_pair;
using std::vector;

enum class Variety {orange, pear, apple};
vector<string> colors = {"red", "green", "yellow"};

int main(){
   srand(time(nullptr));
   multimap<Variety, string> orangeMap;
   int size= rand()%100+1;


   for(int i=0; i<size; ++i){
    orangeMap.emplace(static_cast<Variety>(rand()%3), colors[rand()%3]);
   }
 
   cout << "Colors of the oranges: \n";
   for(auto it=orangeMap.lower_bound(Variety::orange); it != orangeMap.upper_bound(Variety::orange); ++it)
      cout << it->second << endl;
}
