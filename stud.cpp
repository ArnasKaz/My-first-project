#include "stud.h"
#include <algorithm>
#include <random>

void ived(Stud &Lok) {
    cout << "Iveskite studento varda: ";
    cin >> Lok.vardas;

    cout << "Iveskite studento pavarde: ";
    cin >> Lok.pavarde;

    string pasirinkimas;
    cout << "Ar generuoti studento ivertinimus atsitiktinai? (taip/ne): ";
    cin >> pasirinkimas;

    Lok.ND.clear();
    double grade;
    double sum = 0;
    int count = 0;

    if (pasirinkimas == "taip") {

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dist(1, 10);
        std::uniform_int_distribution<> nd_count_dist(3, 10);
        int m = nd_count_dist(gen);
        for (int i = 0; i < m; i++) {
            grade = dist(gen);
            Lok.ND.push_back(grade);
            sum += grade;
            count++;
        }


        Lok.vid = sum / count;


        Lok.egz = dist(gen);
        cout << "Sugeneruota " << m << " Namu darbu ivertinimai ir egzamino ivertinimas" << endl;

    } else if (pasirinkimas == "ne") {
        string input;


        while (true) {
            cout << "Irasykite namu darbu ivertinimu, kol baigsite, tuomet rasykite 'baigti' kad baigtumete: ";
            cin >> input;

            if (input == "baigti") {
                break;
            }

            try {
                grade = std::stod(input);
                Lok.ND.push_back(grade);
                sum += grade;
                count++;
            } catch (const std::invalid_argument&) {
                cout << "Netinkamas simbolis, rasykite tik skaicius arba 'baigti' " << endl;
            }
        }


        if (count > 0) {
            Lok.vid = sum / count;
        } else {
            Lok.vid = 0;
        }

        cout << "Irasykite egzamino ivertinima: ";
        cin >> Lok.egz;
    } else {
        cout << "Netinkamas pasirinkimas. Iveskite 'taip' arba 'ne'." << endl;
    }
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
