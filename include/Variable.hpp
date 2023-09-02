#ifndef VARIABLE_H
#define VARIABLE_H

class Variable {
public:
  Variable(char letter, float value);
  float getValue();
  char getLetter();
  void setValue(float value);

private:
  char _letter;
  float _value;
};
#endif // VARIABLE_H
