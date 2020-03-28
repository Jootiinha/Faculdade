#include<iostream>
#include<cstdlib>
#include<string.h>
#include<windows.h>
//#include<cstdlib>
#include<locale.h>

using namespace std;

/*Variaveis globais:
            ->Agenda*/
//--------------------

struct Contato{
    char nome[50];
    char telefone[20];
    char email[50];
};
Contato dados;
Contato vetor[100];

bool verificaContato(char infos[]);
void criarLinha(int tamanho);
void menuInicio(int menu);
bool buscaContato(char info[], int *posicao);//Funcionando no ambiente de teste
void cadastrarContato();
int verificaVazio();
bool buscaContato(char info[]);
bool removerContato(char criterio[]);
void inicializaVetor();

int main(){

    setlocale(LC_ALL, "Portuguese");
    /***Variaveis de opção e a serem passadas para as funçoes***/
    int opcao;
    int opcaoCadContato, aux = 1;
    int posicao = 0; // Serve para receber a posição do contato caso existe. Utilizo na função BuscaContato
    /***==***/
    inicializaVetor();

    while(aux != 0)
    {
        menuInicio(1);// para abrir o menu inicio;
        cin>>opcao;
        system("cls");

        /***Menu Cadastrar Contato***/
        if(opcao == 1)
        {
            cadastrarContato();
        }
        else if(opcao == 2)
        {
            char criterio[50];
            cout<<"=============== Buscar contato ===============\n";
            cout<<"Criterio: ";
            cin>>criterio;
            buscaContato(criterio);
        }
        else if(opcao == 3)
        {
            char criterio[50];
            cout<<"=============== Remover contato ===============\n";
            cout<<"Digite alguma informacao: ";
            cin>>criterio;
            removerContato(criterio);
        }
        else if(opcao == 4)
        {
            for(int i = 0; i<100; i++)
            {
                cout<<"Nome: "<<vetor[i].nome<<"\n";
                cout<<"Telefone: "<<vetor[i].telefone<<"\n";
                cout<<"Email: "<<vetor[i].email<<"\n";
                cout<<i<<"\n";
                cout<<"===========================\n";
            }
        }
        else if(opcao == 0)
        {
            cout<<"Programa finalizado\n";
            return 0;
        }

        cout<<"\nDeseja voltar ao menu?(Para sair - 0 || Para voltar - qualquer tecla)\n";
        cin>>aux;
        system("cls");
    }
}


void criarLinha(int tamanho){
    for(int i = 0; i < tamanho; i++)
    {
        cout<<"=";
    }
    cout<<"\n";
}
void menuInicio(int menu){

    if(menu == 1)
    {
        criarLinha(40);
        cout<<"Cadastrar contato -------------------- 1\n";
        cout<<"Buscar contato    -------------------- 2\n";
        cout<<"Remover contato   -------------------- 3\n";
        cout<<"Exibir contatos cadastrados ---------- 4\n";
        cout<<"Sair              -------------------- x\n";
        criarLinha(40);
        cout<<"Digite sua opcao: ";
    }
}
bool buscaContato(char info[], int *posicao){

    for(int i = 0; i < 100; i++)
    {
        if(strcmp(vetor[i].nome, info) == 0 || strcmp(vetor[i].telefone, info) == 0 || strcmp(vetor[i].email, info) == 0)
        {
            //cout<<"\nContato existente na agenda.\n";
            *posicao = i;
            return true;
            break;
        }
        else
        {
            cout<<"Procurando...\n";
            *posicao = -1;
            continue;
        }
    }
}
void cadastrarContato(){

    setlocale(LC_ALL, "Portuguese");

    int posicao = verificaVazio();

    cout<<"=========== Cadastro de contato ===========\n";
    cout<<"Por favor, preencha todas as informacoes solicitadas.\n\n";
    cout<<"Nome: ";cin>>dados.nome;cout<<"\n";
    cout<<"Telefone: ";cin>>dados.telefone;cout<<"\n";
    cout<<"Email: ";cin>>dados.email;cout<<"\n";
    vetor[posicao] = dados;

}
int verificaVazio(){
    /***Retorna a primeira posição vazia***/
    for(int i = 0; i<100; i++)
    {
        if(strlen(vetor[i].nome) <= 1)
        {
            return i;
        }
    }
}
//Função BuscaContato --> Sobrecarga
bool buscaContato(char info[]){

    setlocale(LC_ALL, "Portuguese");

    for(int i = 0; i < 100; i++)
    {
        if(strcmp(vetor[i].nome, info) == 0 || strcmp(vetor[i].telefone, info) == 0 || strcmp(vetor[i].email, info) == 0)
        {
            cout<<"\nO contato existente na agenda.\n";
            cout<<"Nome: "<<vetor[i].nome<<"\n";
            cout<<"Telefone: "<<vetor[i].telefone<<"\n";
            cout<<"Email: "<<vetor[i].email<<"\n";
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
bool removerContato(char criterio[])
{
    int decisao = 0;
    for(int i = 0; i < 100; i++)
    {
        if(strcmp(vetor[i].nome, criterio) == 0 || strcmp(vetor[i].telefone, criterio) == 0 || strcmp(vetor[i].email, criterio) == 0)
        {
            cout<<"\nDeseja remover o seguinte contato?(0 = Nao || 1 = Sim)\n";
            cout<<vetor[i].nome<<"\n"<<vetor[i].telefone<<"\n"<<vetor[i].email;
            cout<<"\nDecisao: ";
            cin>>decisao;
            if(decisao == 1)
            {
                strcpy(vetor[i].nome,"0");
                strcpy(vetor[i].telefone,"0");
                strcpy(vetor[i].email,"0");
                cout<<"Contato removido com sucesso!\n";
                return true;
                break;
            }
        }
        else
        {
            break;
        }
    }
}
void inicializaVetor()
{
    for(int i = 0; i < 100; i++)
    {
        strcpy(dados.nome,"0");
        strcpy(dados.telefone,"0");
        strcpy(dados.email,"0");
        vetor[i] = dados;
    }
}
