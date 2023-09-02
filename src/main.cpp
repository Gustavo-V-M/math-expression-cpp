#include "../include/CheckOrder.hpp"
#include "../include/Variable.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  string expression = "";
  if (!isCorrectOrder(expression)) {
    cout << "Invalid Expression (Order of terms is incorrect)" << endl;
    return 0;
  }

  return 0;
}
