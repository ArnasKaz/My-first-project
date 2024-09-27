#include "stud.h"
#include <algorithm>


void ived(Stud &Lok) {
    cout << "Enter student first name: ";
    cin >> Lok.vardas;

    cout << "Enter student last name: ";
    cin >> Lok.pavarde;

    Lok.ND.clear();
    double grade;
    string input;
    double sum = 0;
    int count = 0;


    while (true) {
        cout << "Enter homework grade or type 'fin' to finish: ";
        cin >> input;

        if (input == "fin") {
            break;
        }

        try {
            grade = std::stod(input);
            Lok.ND.push_back(grade);
            sum += grade;
            count++;
        } catch (const std::invalid_argument&) {
            cout << "Invalid input. Please enter a valid grade or 'fin'." << endl;
        }
    }


    if (count > 0) {
        Lok.vid = sum / count;
    } else {
        Lok.vid = 0;
    }

    cout << "Enter exam grade: ";
    cin >> Lok.egz;
}


void val(Stud &Lok, bool naudotiMediana) {
    if (naudotiMediana) {
        Lok.med = skaiciuotiMediana(Lok.ND);
        Lok.rez = 0.4 * Lok.med + 0.6 * Lok.egz;
    } else {
        Lok.rez = 0.4 * Lok.vid + 0.6 * Lok.egz;
    }
}


double skaiciuotiMediana(std::vector<double> &ND) {
    std::sort(ND.begin(), ND.end());

    size_t size = ND.size();
    if (size % 2 == 0) {
        return (ND[size / 2 - 1] + ND[size / 2]) / 2.0;
    } else {
        return ND[size / 2];
    }
}


void output(const Stud &Lok) {
    cout << setw(15) << left << Lok.vardas
         << setw(10) << left << Lok.pavarde
         << setw(15) << right << fixed << setprecision(2) << Lok.rez << endl;
}
