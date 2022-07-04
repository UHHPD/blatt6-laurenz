#ifndef KOERPER_HH
#define KOERPER_HH

#include "Vektor.hh"

class Koerper {
public:  
virtual Vektor punkt()=0;
std :: string virtual name () { return " Koerper ";}

private:
  double r_, l_;
};

#endif