#pragma once
#include <math.h>
struct Sample { float value; float aux; bool valid; };
inline bool isAlert(const Sample &s) {
  if (!s.valid || !isfinite(s.value) || !isfinite(s.aux)) return false;
  if (s.value < 0.0f || s.value > 4095.0f) return false;
  return s.value > 2500.0f || s.aux > 0.5f;
}
