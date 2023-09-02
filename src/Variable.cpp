#include "../include/Variable.hpp"

Variable::Variable(char letter, float value) {
  Variable::_letter = letter;
  Variable::_value = value;
}

float Variable::getValue() { return Variable::_value; };
char Variable::getLetter() { return Variable::_letter; };

void Variable::setValue(float value) { Variable::_value = value; };
