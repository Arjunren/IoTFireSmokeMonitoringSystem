#include <cassert>
#include <limits>
#include "logic.h"
int main() {
  assert(isAlert(Sample{3000.0f,0.0f,true})==true);
  assert(!isAlert(Sample{1000.0f,0.0f,true}));
  assert(!isAlert(Sample{3000.0f,0.0f,false}));
  assert(!isAlert(Sample{-1.0f,0,true}));
  assert(!isAlert(Sample{4096.0f,0,true}));
  assert(!isAlert(Sample{std::numeric_limits<float>::quiet_NaN(),0,true}));
}
