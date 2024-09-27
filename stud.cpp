#include "stud.h"

void ived(Stud &Lok, int m) {
    cout << "Enter student first name: ";
    cin >> Lok.vardas;

    cout << "Enter student last name: ";
    cin >> Lok.pavarde;

    Lok.ND.resize(m);
    double sum = 0;

    for (int i = 0; i < m; i++) {
        cout << "Enter grade for homework " << i + 1 << ": ";
        cin >> Lok.ND[i];
        sum += Lok.ND[i];
    }

    Lok.vid = sum / m;

    cout << "Enter exam grade: ";
    cin >> Lok.egz;
}


void val(Stud &Lok) {
    Lok.rez = 0.4 * Lok.vid + 0.6 * Lok.egz;
}


void output(const Stud &Lok) {
    cout << setw(15) << left << Lok.vardas
         << setw(10) << left << Lok.pavarde
         << setw(15) << right << fixed << setprecision(2) << Lok.rez << endl;
}
