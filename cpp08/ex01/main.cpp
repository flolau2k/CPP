#include "Span.hpp"
#include <iostream>
#include <sstream>

int main(int argc, char **argv) {
  // Span span(10);
  // span.addNumber(0);
  // span.addNumber(1);
  // span.addNumber(2);
  // span.addNumber(3);
  // span.addNumber(4);
  // span.addNumber(5);
  // span.addNumber(6);
  // span.addNumber(7);
  // span.addNumber(8);
  // span.addNumber(9);

  // Span sp2(10);
  // int arr[] = {100, 11};
  // std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
  // sp2.addRange(vec.begin(), vec.end());

  // std::cout << "longest Span: " << span.longestSpan() << std::endl;
  // std::cout << "shortest Span: " << span.shortestSpan() << std::endl;
  // std::cout << "longest Span 2: " << sp2.longestSpan() << std::endl;
  // std::cout << "shortest Span 2: " << sp2.shortestSpan() << std::endl;

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