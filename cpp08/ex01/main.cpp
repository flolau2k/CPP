#include "Span.hpp"
#include <iostream>
#include <sstream>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Error: too few args!" << std::endl;
    return 1;
  }

  Span span(argc - 1);
  int val;

  for (int i = 1; i < argc; ++i) {
    std::istringstream iss(argv[i]);
    iss >> val;
    if (iss.fail()) {
      std::cerr << "Error" << std::endl;
      return 1;
    }
    span.addNumber(val);
  }

  try {
    std::cout << "Longest Span: " << span.longestSpan() << std::endl;
    std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }


  return 0;
}