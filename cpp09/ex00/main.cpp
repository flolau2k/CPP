#include "BitcoinExchange.hpp"
#include "Date.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

int main(void) {
  BitcoinExchange btc("data.csv");
  const std::map<Date, double> data = btc.get_map();

  // typedef std::map<Date, double>::const_iterator iter;
  // for (iter it = data.begin(); it != data.end(); ++it) {
  //   std::cout << "curr date: " << it->first << ", curr val: " << it->second
  //             << std::endl;
  // }

  return 0;
}
