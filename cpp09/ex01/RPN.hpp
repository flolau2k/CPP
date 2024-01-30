#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

class RPN {
public:
  int calculate(std::string &arg) const;

private:
  RPN();
  RPN(const RPN &cpy);
  RPN &operator=(const RPN &other);
  ~RPN();

  enum token_t {PLUS, MINUS, MULT, DIV, ARG, ERROR};

  void push_val(std::string &tok);
  void _plus();
  void _minus();
  void _multiply();
  void _divide();
  token_t get_type(std::string &tok) const;

  std::stack<int> _stack;

};

#endif // RPN_HPP