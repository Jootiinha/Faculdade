#include<iostream>
#include<string.h>
using namespace std;

bool existe(string nome)
{
    if(nome == "Joao")
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    string nome = "Joao";
    cout<<"TESTE DA NEGA��O\n";

    if(!existe(nome))
    {
        cout<<"Existe\n";
    }
    else
    {
        cout<<"N�o existe\n";
    }
}
