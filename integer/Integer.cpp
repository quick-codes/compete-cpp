//
// Created by sudha on 4/12/21.
//

#include "Integer.h"
#include <ostream>
using namespace std;

Integer::Integer() : Integer(0) {}

Integer::Integer(int v) : val(v) {}

bool Integer::operator==(const Integer &other) const {
  return val == other.val;
}

ostream &operator<<(ostream &output_stream, const Integer &integer) {
  if (integer == null) return output_stream << "null";
  return output_stream << integer.val;
}
