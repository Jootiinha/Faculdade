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
    cout<<"TESTE DA NEGAÇÃO\n";

    if(!existe(nome))
    {
        cout<<"Existe\n";
    }
    else
    {
        cout<<"Não existe\n";
    }
}
