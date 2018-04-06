#include <iostream>
#include<fstream>
using namespace std;
#include <time.h>
#include <sys/resource.h>

double get_cpu_time()
{
        struct rusage ruse;
        getrusage(RUSAGE_SELF, &ruse);
        return ruse.ru_utime.tv_sec+ruse.ru_utime.tv_usec/1000000.0 +
                ruse.ru_stime.tv_sec+ruse.ru_stime.tv_usec/1000000.0;
}


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

void findtheoldest(information info[], int size)
{
        int min = 0;
        for(int i=0;i<size;i++)
        {
                if (info[i].dob==0)
                {
                        break;
                }
                if (info[i].dob < info[min].dob)
                {
                        min= i;
                }
        }
        cout<< info[min].dob<< " "<<info[min].ssn<<" "<<info[min].firstname<<" "<<
        info[min].lastname <<" "<<info[min].state<<" "<<info[min].zipcode<<endl;
}

void promotetheyoungest(information info[], int size)
{
        int k;
        information temp[1];
        for (int i = 0; i < size; i++)
        {
                for(k=i;k<size;k++)
                {
                        if (info[i].dob < info[k].dob)
                        {
                                temp[0]=info[i];
                                info[i]=info[k];
                                info[k]=temp[0];
                         }
                }

        }

        for(int j=0; j<size; j++)
        {
                cout<<info[j].dob<<" "<<info[j].ssn<<" "<<info[j].firstname<<" "<<info[j].lastname
                      <<" "<<info[j].state<<" "<<info[j].zipcode<<endl;
        }

}

void makenewfile(information info[], int size)
{
        ofstream fout("person_info.txt");
        if(!fout)
        {
                cout<<"can't open output file!"<<endl;
        }
        else
        {
                 for(int j=0; j<size; j++)
                        {
                                fout<<info[j].dob<<" "<<info[j].ssn<<" "<<
                                        info[j].firstname<<" "<<info[j].lastname
                                        <<" "<<info[j].state<<" "<<info[j].zipcode
                                        <<endl;
                        }
                cout<<"work finished"<<endl;
                fout.close();
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
        double initialtime = get_cpu_time();

        int const size = 1000;
        information info[size];

        readfile(info, size);

//      search(info,size);
//      findtheoldest(info,size);

        promotetheyoungest(info,size);
        makenewfile(info,size);

        double finaltime = get_cpu_time();
        double totaltime= finaltime - initialtime;
        cout<<"How fast was it? " <<  totaltime << " seconds"<<endl;
}

