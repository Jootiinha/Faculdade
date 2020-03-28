#include<iostream>
#include<string.h>
using namespace std;

char trata(char tel[])
{
    char ntratado[20];
    for(int i = 0; i < strlen(tel); i++)
    {
        ntratado[i] = tel[i];
        if(tel[i] == '+' || tel[i] == '(' || tel[i] == ')' || tel[i] == ' ')
        {
            ntratado[i] = ' ';
        }
    }

    for(int i = 0; i < strlen(ntratado); i++)
    {
        cout<<ntratado[i];
    }
    cout<<"\n";
}

int main()
{
    char telefone[20];
    cout<<"Digite o telefone\n";
    cin>>telefone;
    trata(telefone);
}
