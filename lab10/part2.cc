#include <iostream>
#include<fstream>
using namespace std;

struct information
{
        int dob;
        int ssn;
        string firstname;
        string lastname;
        string state;
        int zipcode;
};

void search(information info[], int size)
{
        cout<<"Please enter name: ";
        string searchname;
        cin>>searchname;

        for (int i=0; i<size;i++)
        {
                if ((searchname==info[i].firstname)||(searchname==info[i].lastname))
                {
                        cout<<info[i].dob<<" "<<info[i].ssn<<" "<<info[i].firstname<<" "<<info[i].lastname
                        <<" "<<info[i].state<<" "<<info[i].zipcode<<endl;
                }

                info[i].firstname[0] += (32);
                info[i].lastname[0] += (32);
                if ((searchname==info[i].firstname)||(searchname==info[i].lastname))
                {
                        info[i].firstname[0] -= (32);
                        info[i].lastname[0] -= (32);
                        cout<<info[i].dob<<" "<<info[i].ssn<<" "<<info[i].firstname<<" "<<info[i].lastname
                        <<" "<<info[i].state<<" "<<info[i].zipcode<<endl;
                }
        }
}


void readfile(information info[], int const size)
{
        ifstream fin("/home/www/class/een118/labs/162/database1.txt");
        if(fin.fail())
        {
                cout << "can't open input file" << endl;
        }
        int i=0;
        while(!fin.eof())
        {

                int dob, ssn, zipcode;
                string firstname, lastname, state;
                fin >>info[i].dob>>info[i].ssn>>info[i].firstname>>info[i].lastname>>
                        info[i].state>>info[i].zipcode;
                i++;
        }
        fin.close();
}

void main()
{
        int const size = 1000;
        information info[size];

        readfile(info, size);

		search(info,size);
}

