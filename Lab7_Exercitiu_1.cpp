#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<sstream>

using namespace std;

class Data{
public:
    int zi;
    int luna;
    int an;
};

class Zbor{
public:
    Data dataZbor;
    string orasPlecare;
    string orasSosire;
    string numarZbor;
};

class Operator{
public:

    void login(){
        string username;
        string password;

        string x;

        cout<<"Introduceti username-ul: "<<endl;
        cin>>username;
        cout<<"Introduceti parola: "<<endl;
        cin>>password;

        ifstream file("utilizatori.txt");

        while(file){
            try{
                getline(file, x);
                if(x == username + " " + password){
                    cout<<"Sunteti autentificat!"<<endl;
                    break;
                }
                if(file.eof()){
                    throw "\nCont inexistent";
                }
            }
            catch(const char* msg){
                cout << msg << endl;
            }   
        }

    }

    int formatDataGresita(Data data){
        if(data.luna == 2){
            if(data.zi > 29){
                return 0;
            }
        }
        else if(data.zi > 31){
            return 0;
        }
        return 1;
    }

    int dataInTrecut(Data data){
        if(data.an < 2021){
            return 0;
        }
        else if(data.an == 2021 && data.luna < 12){
            return 0;
        }
        else if(data.an == 2021 && data.luna == 12 && data.zi < 12){
            return 0;
        }
        return 1;
    }
    int caractereInexistente(string a){
        for(int i = 0; i < a.length(); i++){
            if(a[i] < 65 || (a[i] > 90 && a[i] < 97) || a[i] > 122){
                return 0;
            }
        }
        return 1;
    }

    void adaugareZbor(){
        Zbor zbor;
        char c1, c2;

        cout<<"== Sa incepem adaugarea unui nou zbor =="<<endl;
        cout<<"Introduceti numarul zborului: ";
        cin>>zbor.numarZbor;
        cout<<endl<<"Oras plecare: ";
        cin>>zbor.orasPlecare;
        cout<<endl<<"Oras sosire: ";
        cin>>zbor.orasSosire;
        cout<<endl<<"Data zborului: (DD/MM/YY): ";
        cin>>zbor.dataZbor.zi;
        cin>>c1;
        cin>>zbor.dataZbor.luna;
        cin>>c2;
        cin>>zbor.dataZbor.an;

      
        try{
            if(formatDataGresita(zbor.dataZbor) == 0){
                throw "\nFormatul datei este gresit!";
            }
        }
        catch(const char* msg){
                cout << msg << endl;
        }
        
        
        try{
            if(dataInTrecut(zbor.dataZbor) == 0){
                throw "\nData introdusa este in trecut!";
            }
        }
        catch(const char* msg){
            cout << msg << endl;
        }
        
        try{
            if(caractereInexistente(zbor.orasPlecare) == 0 || caractereInexistente(zbor.orasSosire) == 0){
                throw "\nCaractere inexistente in numele oraselor!";
            }
        }
        catch(const char* msg){
            cout << msg << endl;
        }
        if(formatDataGresita(zbor.dataZbor) == 1 && dataInTrecut(zbor.dataZbor) == 1 && caractereInexistente(zbor.orasPlecare) == 1 && caractereInexistente(zbor.orasSosire) == 1){
            cout<<"Zborul cu numarul " << zbor.numarZbor << " a fost adaugat."<<endl;
            ofstream output("zboruri.txt", ios::app);
            output<<zbor.numarZbor << " " << zbor.orasPlecare << " " << zbor.orasSosire << " " << zbor.dataZbor.zi << "/" << zbor.dataZbor.luna << "/" << zbor.dataZbor.an << endl;
        }
    }

    void StergereZbor(){
        Zbor zbor;
        string x;
        char c1, c2;
        string ss1, ss2, ss3;

        cout<<"Introduceti numarul de zbor pe care vreti sa il stergeti: ";
        cin>>zbor.numarZbor;
        cout<<"Orasul de plecare: ";
        cin>>zbor.orasPlecare;
        cout<<"Oras sosire: ";
        cin>>zbor.orasSosire;
        cout<<endl<<"Data zborului: (DD/MM/YY): ";
        cin>>zbor.dataZbor.zi;
        cin>>c1;
        cin>>zbor.dataZbor.luna;
        cin>>c2;
        cin>>zbor.dataZbor.an;

        stringstream s1;
        stringstream s2;
        stringstream s3;

        s1 << zbor.dataZbor.zi;
        s2 << zbor.dataZbor.luna;
        s3 << zbor.dataZbor.an;

        s1 >> ss1;
        s2 >> ss2;
        s3 >> ss3;

        ofstream temp("temp.txt");
        ifstream file("zboruri.txt");

        while(getline(file, x)){
            if (x != zbor.numarZbor + " " + zbor.orasPlecare + " " + zbor.orasSosire + " " + ss1 + "/" + ss2 + "/" + ss3){
                temp << x << endl;
            }
            else if(file.eof()){
                cout << "Zbor inexistent" << endl;
            }
            if (x == zbor.numarZbor + " " + zbor.orasPlecare + " " + zbor.orasSosire + " " + ss1 + "/" + ss2 + "/" + ss3){
                cout<<"Zborul cu numarul "<<zbor.numarZbor<<" a fost sters."<<endl;
            }
        }
        temp.close();
        file.close();
        remove("zboruri.txt");
        rename("temp.txt", "zboruri.txt");
    }
};

class Utilizator{
public:
        string username;
        string password;
        string repetPassword;
        string email;
        string phoneNumber;

    int x, y, n, t, i, flag;
    long int e[50], d[50], temp[50], j;
    char en[50], m[50];
    string msg;

    int prime(long int pr){
        int i;
        j = sqrt(pr);
        for(i = 2; i <= j; i++)
        {
            if(pr % i == 0)
                return 0;
        }
        return 1;
    }

    void encryption_key(){
        int k;
        k = 0;
        for(i = 2; i < t; i++)
        {
            if(t % i == 0)
                continue;
            flag = prime(i);
            if(flag == 1 && i != x && i != y)
            {
                e[k] = i;
                flag = cd(e[k]);
                if(flag > 0)
                {
                    d[k] = flag;
                    k++;
                }
                if(k == 99)
                    break;
            }
        }
    }

    long int cd(long int a){
        long int k = 1;
        while(1)
        {
            k = k + t;
            if(k % a == 0)
                return(k/a);
        }
    }

    void encrypt(){
        long int pt, ct, key = e[0], k, len;
        i = 0;
        len = msg.length();

        while(i != len)
        {
            pt = m[i];
            pt = pt - 96;
            k = 1;
            for(j = 0; j < key; j++)
            {
                k = k * pt;
                k = k % n;
            }
            temp[i] = k;
            ct= k + 96;
            en[i] = ct;
            i++;
        }
        en[i] = -1;
        cout<<endl;
        cout << "Parola criptata este: "<<endl;
        for(i=0; en[i] != -1; i++){
            cout << en[i];
        }
        cout<<endl;
    }

    void decrypt(){
        long int pt, ct, key = d[0], k;
        i = 0;
        while(en[i] != -1)
        {
            ct = temp[i];
            k = 1;
            for(j = 0; j < key; j++)
            {
                k = k * ct;
                k = k % n;
            }
            pt = k + 96;
            m[i] = pt;
            i++;
        }
        m[i] = -1;
        cout << endl;
    }

    int weakPassword(){
        if(password.length() < 8){
            return 0;
        }
        else{

        int n = password.length();

        bool hasLower = false;
        bool hasUpper = false;
        bool hasDigit = false;

        for (int i = 0; i < n; i++) {
            if (islower(password[i]))
                hasLower = true;
            if (isupper(password[i]))
                hasUpper = true;
            if (isdigit(password[i]))
                hasDigit = true;
        }
        cout << "Parola aleasa este: ";
        if (hasLower && hasUpper && hasDigit)
            cout << "Puternica" << endl;
        else if ((hasLower || hasUpper) )
            cout << "Moderata" << endl;
        else
            cout << "Slaba" << endl;
        }
    }

    int verificareParola(string a, string b){

        if(a != b){
            return 0;
        }
        else{
            return 1;
        }

    }
    bool isChar(char c)
    {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }

    int incorrectEmailFormat(){
        if (!isChar(email[0])) {
        return 0;
    }

    int At = -1, Dot = -1;

    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@') {

            At = i;
        }
        else if (email[i] == '.') {

            Dot = i;
        }
    }
    if (At == -1 || Dot == -1){
        return 0;
    }
    else if (At > Dot){
        return 0;
    }
    else{
        return 1;
    }

}

    string autentificare(){
        string a;

        cout<<"Introduceti username-ul: "<<endl;
        cin>>username;
        cout<<"Introduceti parola: "<<endl;
        cin>>password;

        ifstream file("utilizatori.txt");

        while(file){
            getline(file, a);
            if(a == username + " " + password){
                cout<<"Sunteti autentificat!"<<endl;
                return username;
                break;
            }
            try{
                if(file.eof()){
                    throw "\nCont inexistent";
                }
            }
            catch(const char* msg){
                cout << msg << endl;
            }   
        }
    }

    void creareCont(){

        cout<<"Username: ";
        cin>>username;
        cout<<"Parola: ";
        cin>>password;
        cout<<"Repetare parola: ";
        cin>>repetPassword;
        cout<<"Date de contact"<<endl;
        cout<<"Email: ";
        cin>>email;
        cout<<"Nr. de telefon: ";
        cin>>phoneNumber;

        x = 11;
        y = 13;

        msg = password;

        for(i = 0; msg[i] != 0; i++){
            m[i] = msg[i];
        }
        n = x * y;
        t = (x - 1) * (y - 1);

        encryption_key();

        encrypt();
        decrypt();

        try{
            if(verificareParola(password, repetPassword) == 0){
                throw "Creare cont esuata! Parolele nu corespund";
            }
        }
        catch(const char* msg){
            cout << msg << endl;
        }
        try{
            if(incorrectEmailFormat() == 0){
                cout<<"Creare cont esuata! Format email incorect!"<<endl;
            }
        }
        catch(const char* msg){
            cout << msg << endl;
        }
        try{
            if(weakPassword() == 0){
                throw "Creare cont esuata! Parola prea slaba!";
            }
        }
        catch(const char* msg){
            cout << msg << endl;
        }
        if(verificareParola(password, repetPassword) == 1 && incorrectEmailFormat() == 1){
            ofstream output("utilizatori.txt", ios::app);
            output<< username <<" "<< password <<endl;
        }
    }

    string cautareZbor(){
        Zbor zbor;
        string x;
        char c1,c2;

        stringstream s1;
        stringstream s2;
        stringstream s3;

        string ss1,ss2,ss3;

        cout<<"Introduceti numarul zborului: ";
        cin>>zbor.numarZbor;
        cout<<"Orasul de plecare: ";
        cin>>zbor.orasPlecare; 
        cout<<"Orasul de sosire: ";
        cin>>zbor.orasSosire;
        cout<<"Data zborului: (DD/MM/YY): ";
        cin>>zbor.dataZbor.zi;
        cin>>c1;
        cin>>zbor.dataZbor.luna;
        cin>>c2;
        cin>>zbor.dataZbor.an;

        s1 << zbor.dataZbor.zi;
        s2 << zbor.dataZbor.luna;
        s3 << zbor.dataZbor.an;

        s1 >> ss1;
        s2 >> ss2;
        s3 >> ss3;
        
        ifstream file("zboruri.txt");

        while(file){
            getline(file, x);
            if(x == zbor.numarZbor + " " + zbor.orasPlecare + " " + zbor.orasSosire + " " + ss1 + "/" + ss2 + "/" + ss3){
                cout<<"Zbor gasit!"<<endl;
                return zbor.numarZbor;
                break;
            }
            try{
                if(file.eof()){
                    throw "\nZbor inexistent";
                }
            }
            catch(const char* msg){
                cout << msg << endl;
                return "";
            }
        }
    }

    void rezervareBilete(){
        Zbor zbor;
        int numarBilete;

        ifstream file("zboruri.txt");

        cout<<"Va rugam sa va autentificati din nou: "<<endl;
        string a = autentificare();
        cout<<"Cate bilete doriti sa rezervati?"<<endl;
        cin >> numarBilete;

        string b;
        b = cautareZbor();
 
        if(b.length() > 0){
            cout<< a <<" a rezervat "<< numarBilete <<" bilete la zborul " << b << "." << endl;
        }
        try{
            if(b == "")
                throw "\nRezervare bilete esuata!";
        }
        catch(const char* msg){
            cout << msg << endl;
        }
    }
};



int main(){
    int x = 1;
    int y = 1;

    while(x != 0){
        x = 1;
        y = 1;

        cout<<"------------------------"<<endl;
        cout<<"1 - Operator"<<endl;
        cout<<"2 - Utilizator"<<endl;
        cout<<"0 - Iesire"<<endl;
        cout<<"------------------------"<<endl;
        cin >> x;

        if(x == 1){
            while( y != 0){
                cout<<"------------------------"<<endl;
                cout<<"1 - Login"<<endl;
                cout<<"2 - Adaugare zbor"<<endl;
                cout<<"3 - Stergere zbor"<<endl;
                cout<<"0 - Iesire"<<endl;
                cout<<"------------------------"<<endl;
                cin >> y;

                if(y == 1){
                    Operator eu;
                    eu.login();
                } 
                else if(y == 2){
                    Operator eu;
                    eu.adaugareZbor();
                }
                else if(y == 3){
                    Operator eu;
                    eu.StergereZbor();
                }
                else if(y != 0){
                    cout<<"Va rog sa introduceti o optiune valida!"<<endl;
                }
            }
      
        }
        if(x == 2){
            while(y != 0){
                cout<<"------------------------"<<endl;
                cout<<"1 - Creare cont"<<endl;
                cout<<"2 - Autentificare"<<endl;
                cout<<"3 - Cautare zbor"<<endl;
                cout<<"4 - Rezervare bilete"<<endl;
                cout<<"0 - Iesire"<<endl;
                cout<<"------------------------"<<endl;
                cin >> y;
                cout<<endl;

                if(y == 1){
                    Utilizator tu;
                    tu.creareCont();
                }
                else if(y == 2){
                    Utilizator tu;
                    tu.autentificare();
                }
                else if(y == 3){
                    Utilizator tu;
                    tu.cautareZbor();
                }
                else if(y == 4){
                    Utilizator tu;
                    tu.rezervareBilete();
                }
                else if(y != 0){
                    cout<<"Va rog sa introduceti o optiune valida!"<<endl;
                }
            }

        }

    }
}