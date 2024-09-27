#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "biblioteka.h"

struct Stud{
    std::string vardas, pavarde;
    std::vector<double> ND;
    double vid, med, egz, rez;
};


void ived(Stud &Lok);
void output(const Stud &Lok);
void val(Stud &Lok, bool naudotiMediana);
double skaiciuotiMediana(std::vector<double> &ND);


bool skaitytiIsFailo(const std::string& failo_pavadinimas, std::vector<Stud>& studentai);

#endif // STUD_H_INCLUDED
