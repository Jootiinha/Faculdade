#include<iostream>
#include<string.h>
using namespace std;

char vetor[5];

char teste(char lol[])
{
    //Compara string
    char kkk;
    if(strcmp(lol,"A") == 0)
    {
        return kkk = 'J';
    }
    else
    {
        return kkk = 'S';
    }
}

int verificaVazio()
{
    for(int i = 0; i < 5; i++)
    {
        if(strlen(vetor[i]) <= 0)
        {
            return i;
        }
        else
        {
            return 0;
        }
    }

    //retorna posição vazia
}

int main()
{
    vetor[0] = 'a';
    vetor[1] = 'b';
    vetor[2] = 'c';
    vetor[3] = 'd';

    for(int i = 0; i < 5; i++)
    {
        if(verificaVazio() != 0)
        {
            cout<<"Esta vazio na posicao "<<i;
        }
        else
        {
            cout<<"Nao esta vazio\n";
        }
    }
}
