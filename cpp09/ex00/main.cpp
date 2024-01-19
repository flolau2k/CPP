#include "My_CSV.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

int main(void) {
  My_CSV csv("data.csv");
  const std::map<std::string, double> data = csv.get_map();

  typedef std::map<std::string, double>::const_iterator iter;
  for (iter it = data.begin(); it != data.end(); ++it) {
    std::cout << "curr date: " << it->first << ", curr val: " << it->second
              << std::endl;
  }

  return 0;
}
