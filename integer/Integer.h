//
// Created by sudha on 4/12/21.
//

#ifndef COMPETE__INTEGER_H_
#define COMPETE__INTEGER_H_

#include <cstdint>
#include <iostream>
using namespace std;

/**
 * Integer class to convert primitive int datatype to a class
 * that supports auto-casting and null i/o.
 */
class Integer {
 public:
  int val;
  Integer();
  Integer(int v);
  bool operator==(const Integer &other) const;
};

// Note that actual value cannot be INT32_MIN to avoid clash with null value.
const Integer null = INT32_MIN;

ostream &operator<<(ostream &output_stream, const Integer &integer);

#endif//COMPETE__INTEGER_H_
