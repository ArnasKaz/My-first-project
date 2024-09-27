#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "biblioteka.h"

struct Stud{
std::string vardas, pavarde;
std::vector<double>ND;
double vid, med, egz, rez;
};

void ived(Stud &Lok);
void output(Stud Lok);
void val(Stud &Lok);

#endif // STUD_H_INCLUDED
