#include<iostream>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<utility>
#include<string>


using namespace std;
bool manjiod(double cijena)
{
    if(cijena<500)
        return true;
    else
        return false;
}
int main()
{
    int izbor,brojac=0;
    int brartkl=0;
    string *naziv=new string[2000];
    double *cijena=new double[2000];
    unsigned long long int *brkd=new unsigned long long int[2000];
    while(1)
{
    cout<<"1.Unos novog artikla: "<<endl;
    cout<<"2.Ispis svih podataka: "<<endl;
    cout<<"3.Inventura: "<<endl;
    cout<<"4.Pretraga prema nazivu artikla: "<<endl;
    cout<<"5.Brisanje artikla: "<<endl;
    cout<<"6.Izmjena podataka artikla: "<<endl;
    cout<<"7.Izlaz iz programa:"<<endl;
    cout<<"Odaberite opciju:"<<endl;
    cin>>izbor;
    if(izbor==1)
    {
        unsigned long long unos;
        while(1)
        {
            try
        {
                cout<<"Unesite barkod: "<<endl;
                cin>>unos;
                if(unos<100000||unos>999999)
                    throw"Barkod mora imati 6 znamenki.";
                break;
            }
          catch (const char* msg)
            {
                  cout <<msg<< endl;
            }

        }
        brkd[brartkl]=unos;
        cout<<"Unesite naziv artikla: "<<endl;
        cin.ignore();
        getline(cin, naziv[brartkl]);
        cout<<"Unesite broj artikla:"<<endl;
        cin>>cijena[brartkl];
        brartkl++;

    }
    else if(izbor==2)
    {
        for(int i=0;i<brartkl;i++)
            cout<<brkd[i]<<", "<<naziv[i]<<", "<<cijena[i]<<endl;
    }
    else if(izbor==3)
    {
        cout<<"Podatci za inventuru: "<<endl;
        cout<<"Suma svih cjena artikala: "<<accumulate(cijena, cijena+brartkl, 0.0)<<endl;
        int min_index=min_element(cijena,cijena+brartkl)-cijena;
        double min_cijena=cijena[min_index];
        cout<<"Artikal s najmanjom cjenom: "<<naziv[min_index]<<endl;
        for(int i=0;i<brartkl;i++)
        {
            if(cijena[i]==min_cijena)
                brojac++;
        }
        cout<<"Broj artikla s najmanjom cjenom: "<<brojac<<endl;
        cout<<"Broj artikala s cjenom manjom od 500 kn"<<count_if(cijena,cijena+brartkl,manjiod)<<endl;

    }

}

    return 0;
}
