#include "biblioteka.h"
#include "stud.h"

int main()
{
    vector<Stud> Vec1;
    Stud Temp;
    int n;
    char pasirinkimas;

    cout << "How many students do you have? ";
    cin >> n;


    cout << "Would you like to use average (a) or median (m) for the final grade calculation? (a/m): ";
    cin >> pasirinkimas;

    for (int i = 0; i < n; i++) {
        cout << "Please input student data:" << endl;
        ived(Temp);


        if (pasirinkimas == 'm' || pasirinkimas == 'M') {
            val(Temp, true);
        } else {
            val(Temp, false);
        }

        Vec1.push_back(Temp);
    }


    cout << setw(15) << left << "Student Name: "
         << setw(10) << left << "Surname: "
         << setw(15) << right << "Final Grade: " << endl;


    for (int i = 0; i < n; i++)
        output(Vec1.at(i));

    return 0;
}
