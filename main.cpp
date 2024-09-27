#include "biblioteka.h"
#include "stud.h"

int main() {
    vector<Stud> Vec1;
    Stud Temp;
    int n;
    char pasirinkimas;

    cout << "Ar norite duomenis irasyti ranka ar nuskaityti is failo? (r/f): ";
    cin >> pasirinkimas;

    if (pasirinkimas == 'f' || pasirinkimas == 'F') {
        string failo_pavadinimas;
        cout << "Irasykite failo pavadinima ";
        cin >> failo_pavadinimas;

        if (!skaitytiIsFailo(failo_pavadinimas, Vec1)) {
            return 1;
        }
    } else {
        cout << "Kiek is viso studentu? ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Iveskite studento duomenis" << endl;
            ived(Temp);
            Vec1.push_back(Temp);
        }
    }

    cout << "Naudoti vidurki (v) ar mediana (m) galutinio balo skaiciavimui? (v/m): ";
    cin >> pasirinkimas;


    for (int i = 0; i < Vec1.size(); i++) {
        if (pasirinkimas == 'm' || pasirinkimas == 'M') {
            val(Vec1[i], true);
        } else {
            val(Vec1[i], false);
        }
    }

    // Antraštės
    cout << setw(15) << left << "Studento vardas: "
         << setw(10) << left << "Pavarde: "
         << setw(15) << right << "Galutinis ivertinimas: " << endl;


    for (int i = 0; i < Vec1.size(); i++)
        output(Vec1.at(i));

    return 0;
}

