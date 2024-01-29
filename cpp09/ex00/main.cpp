#include "BitcoinExchange.hpp"
#include "Date.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

int main(int argc, char **argv) {
  const std::string data_file = "test.csv";

  if (argc != 2) {
    std::cerr << "Wrong number of args; no input file given!" << std::endl;
    return 1;
  }

  BitcoinExchange btc;

  try {
    btc.read_data(data_file);
  } catch (std::exception &e) {
    std::cerr << data_file << ": " << e.what() << std::endl;
    return 1;
  }
  try {
    btc.read_input(argv[1]);
  } catch (std::exception &e) {
    std::cerr << argv[1] << ": " << e.what() << std::endl;
  }


  // typedef std::map<Date, double>::const_iterator iter;
  // for (iter it = data.begin(); it != data.end(); ++it) {
  //   std::cout << "curr date: " << it->first << ", curr val: " << it->second
  //             << std::endl;
  // }

  return 0;
}
