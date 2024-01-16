#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

int main(int argc, char **argv) {
  if (argc < 2) return 1;
  std::string s = argv[1];
  std::ios_base::fmtflags ff;
  ff = std::cout.flags();
  // s = s.substr(0, s.length() - 1);
  std::istringstream iss(s);
  double f;
  iss >> f;
  if (fmod(f, 1.0) == 0) 
    std::cout << std::fixed << std::setprecision(1);
  else
    std::cout << std::resetiosflags(ff);
  std::cout << "double is: " << f << std::endl;
}