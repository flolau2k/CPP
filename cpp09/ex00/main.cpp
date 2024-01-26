#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

int main(void) {
  BitcoinExchange btc("data.csv");
  const std::map<std::string, double> data = btc.get_map();

  // typedef std::map<std::string, double>::const_iterator iter;
  // for (iter it = data.begin(); it != data.end(); ++it) {
  //   std::cout << "curr date: " << it->first << ", curr val: " << it->second
  //             << std::endl;
  // }

  return 0;
}
