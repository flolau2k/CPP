#include "Span.hpp"
#include <iostream>

int main(void) {
  Span span(10);
  span.addNumber(0);
  span.addNumber(1);
  span.addNumber(2);
  span.addNumber(3);
  span.addNumber(4);
  span.addNumber(5);
  span.addNumber(6);
  span.addNumber(7);
  span.addNumber(8);
  span.addNumber(9);

  std::cout << "longest Span: " << span.longestSpan() << std::endl;
  std::cout << "shortest Span: " << span.shortestSpan() << std::endl;
  return 0;
}