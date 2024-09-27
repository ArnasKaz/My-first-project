#include "biblioteka.h"
#include "stud.h"


int main()
{
    vector<Stud> Vec1;
    Stud Temp;
    cout<<"How many students You have? ";
    int n;
    cin>>n;
    for(int i=0; i < n ; i++){
    cout<< "Please input user data:"<<endl;
    ived(Temp);
    Vec1.push_back(Temp);
    val(Temp);
    }
    cout << setw(15) << left << "Student Name: "
    << setw(10) << left << "Surname: " << setw(3)
    << right << "Egzam point : " << endl;
    for (int i=0; i < n ; i++)
        output(Vec1.at(i));

    system("pause");

    return 0;
}
