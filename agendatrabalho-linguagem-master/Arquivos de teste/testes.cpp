#include<iostream>
#include<string.h>
using namespace std;
bool verNome(char infos[]);
void exiber();

struct Contato{
    char nome[15];
    char idade[15];
};

Contato infos;
Contato vetor[4];

//Esta funcionando
int verificaVazio()
{
    for(int i = 0; i < 4; i++)
    {
        if(strlen(vetor[i].nome) <= 1)
        {
            return i;
            break;
        }
    }
}
int main()
{

    cout<<"Cadastrando\n";
    for(int i = 0; i < 2; i++)
    {
        cout<<"Nome: ";cin>>infos.nome;
        cout<<"Idade: ";cin>>infos.idade;cout<<"\n";
        vetor[i] = infos;
    }
    char n[15];
    int aux = 0;
    cout<<"\nExibindo informacoes\n";
    exiber();
    cout<<"Buscar por nome:\n";
    cin>>n;
    cout<<"Posicao vazia "<<verificaVazio()<<"\n";
    cout<<"\n\n";
    int posicao = 0;
    verNome(n);
    cout<<"Posicao do contato: "<<posicao<<"\n\n";


    return main();
}
void exiber()
{
    for(int i = 0; i < 3; i++)
    {
        cout<<"Nome: "<<vetor[i].nome;cout<<" - Idade: "<<vetor[i].idade<<"\n";
    }
}

//Funcionando -->Preciso obter o valor de I
bool verNome(char ift[])
{
    for(int i = 0; i < 4; i++)
    {
        if(strcmp(vetor[i].nome, ift) == 0)
        {
            cout<<"\nCadastrado\n";
            return true;
            break;
        }
        else
        {
            cout<<"Procurando...\n";
            continue;
        }
    }
}



