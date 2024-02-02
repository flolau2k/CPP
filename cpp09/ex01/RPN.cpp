#include "RPN.hpp"
#include <string>
#include <stack>
#include <sstream>

RPN::RPN(){}

RPN::~RPN(){}

RPN::token_t RPN::get_type(std::string &tok) {
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
  int val = 0;
  iss >> val;
  if (iss.fail())
    throw std::exception();
  _stack.push(val);
}

void RPN::_plus() {
  if (_stack.size() < 2)
    throw std::exception();
  double val = _stack.top();
  _stack.pop();
  val += _stack.top();
  _stack.pop();
  _stack.push(val);
}

void RPN::_minus() {
  if (_stack.size() < 2)
    throw std::exception();
  double val1 = _stack.top();
  _stack.pop();
  double val2 = _stack.top();
  _stack.pop();
  _stack.push(val2 - val1);
}

void RPN::_multiply() {
  if (_stack.size() < 2)
    throw std::exception();
  double val = _stack.top();
  _stack.pop();
  val *= _stack.top();
  _stack.pop();
  _stack.push(val);
}

void RPN::_divide() {
  if (_stack.size() < 2)
    throw std::exception();
  double val1 = _stack.top();
  _stack.pop();
  double val2 = _stack.top();
  _stack.pop();
  _stack.push(val2 / val1);
}

double RPN::calculate(const std::string &arg) {
  RPN rpn;
  std::string token;
  std::istringstream iss(arg);
  token_t type;

  while (std::getline(iss, token, ' ')) {
    type = get_type(token);
    switch (type) {
      case ARG:
        rpn.push_val(token);
        break;
      case PLUS:
        rpn._plus();
        break;
      case MINUS:
        rpn._minus();
        break;
      case MULT:
        rpn._multiply();
        break;
      case DIV:
        rpn._divide();
        break;
      case ERROR:
        throw std::exception();
    }
  }
  if (rpn._stack.size() != 1)
    throw std::exception();
  return rpn._stack.top();
}
