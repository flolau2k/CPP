#include "RPN.hpp"
#include <string>
#include <stack>
#include <sstream>

RPN::RPN(){}

RPN::~RPN(){}

RPN::token_t RPN::get_type(std::string &tok) const {
  if (tok == "+")
    return RPN::PLUS;
  if (tok == "-")
    return RPN::MINUS;
  if (tok == "*")
    return RPN::MULT;
  if (tok == "/")
    return RPN::DIV;
  int val;
  std::istringstream iss(tok);
  iss >> val;
  if (iss.fail())
    return RPN::ERROR;
  return RPN::ARG;
}

void RPN::push_val(std::string &tok) {
  std::istringstream iss(tok);
  int val;
  if (!iss >> val)
    throw std::exception();
  _stack.push(val);
}

void RPN::_plus() {
  if (_stack.size() != 2)
    throw std::exception();
  
}

int RPN::calculate(std::string &arg) const {
  RPN rpn;
  std::string token;
  std::istringstream iss(arg);
  token_t type;

  while (std::getline(iss, token, ' ')) {
    type = get_type(token);
    switch (type) {
      case ARG:
        rpn.push_val(token);
      case PLUS:
        rpn._plus();
      case MINUS:
        rpn._minus();
      case MULT:
        rpn._multiply();
      case DIV:
        rpn._divide();
      case ERROR:
        throw std::exception();
    }
  }
  return _stack.top();
}
