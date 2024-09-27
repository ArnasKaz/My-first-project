#include "biblioteka.h"
#include "stud.h"

int main()
{
    vector<Stud> Vec1;
    Stud Temp;
    int n;
    char pasirinkimas;

    cout << "Kiek is viso studentu? ";
    cin >> n;


    cout << "Naudoti vidurki (v) ar mediana (m) galutinio balo skaiciavimui? (v/m): ";
    cin >> pasirinkimas;

    for (int i = 0; i < n; i++) {
        cout << "Iveskite studento duomenis" << endl;
        ived(Temp);


        if (pasirinkimas == 'm' || pasirinkimas == 'M') {
            val(Temp, true);
        } else {
            val(Temp, false);
        }

        Vec1.push_back(Temp);
    }


    cout << setw(15) << left << "Studento vardas: "
         << setw(10) << left << "Pavarde: "
         << setw(15) << right << "Galutinis ivertinimas: " << endl;


    for (int i = 0; i < n; i++)
        output(Vec1.at(i));

    return 0;
}
