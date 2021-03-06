/*Patrícia Rocha - Crie as funções: pré-ordem e pós-ordem */
#include<iostream>
using namespace std;

struct No {

int chave;//conteudo que ele guarda
No *esq;
No *dir;
};

struct ArvoreBinaria{
No *raiz;
void Criar();
No * Inserir(No *noAtual, int valor);
bool Pesquisar(No *noAtual,int valor);
void Inserir_semretorno(int valor);
void Imprime_ordem(No *noAtual);
void Imprime_preOrdem(No *noAtual);
void Imprime_posOrdem(No *noAtual);
bool NoFolha(No *noAtual);
};

void ArvoreBinaria::Criar(){

raiz=NULL;

}
No * ArvoreBinaria::Inserir (No *noAtual, int valor){

if(noAtual==NULL){
    noAtual= new No;
    noAtual->dir=NULL;
    noAtual->esq=NULL;
    noAtual->chave=valor;
}

else if(valor<noAtual->chave){// verificar se vai pra esq ou dir
    noAtual->esq= Inserir(noAtual->esq, valor);
}
else {
        noAtual->dir= Inserir(noAtual->dir, valor);
}
return noAtual;

}


bool ArvoreBinaria::Pesquisar(No* noAtual, int valor){

if(noAtual==NULL){

return false;
}

else if(noAtual->chave== valor){
    return true;
}

else{
    if(valor<noAtual->chave){
        Pesquisar(noAtual->esq, valor);
    }
    else {
         Pesquisar(noAtual->dir, valor);
    }

}
}

void ArvoreBinaria::Inserir_semretorno(int valor){

raiz=Inserir(raiz, valor);
}

void ArvoreBinaria::Imprime_ordem(No*noAtual){

if(noAtual!=NULL){
    Imprime_ordem(noAtual->esq);
    cout<<"Elemento visitado foi o: "<<noAtual->chave<<endl;
    Imprime_ordem(noAtual->dir);

}
}

void ArvoreBinaria :: Imprime_preOrdem(No*noAtual){
    
if(noAtual!=NULL){
    cout<<"Elemento visitado foi o: "<<noAtual->chave<<endl;
    Imprime_preOrdem(noAtual->esq);
    Imprime_preOrdem(noAtual->dir);

}
}
void ArvoreBinaria :: Imprime_posOrdem(No* noAtual){
    
  if(noAtual!=NULL){
    Imprime_posOrdem(noAtual->esq);
    Imprime_posOrdem(noAtual->dir);
    cout<<"Elemento visitado foi o: "<<noAtual->chave<<endl;
}                                 
}

bool ArvoreBinaria :: NoFolha (No* noAtual){
    if (noAtual->dir==NULL && noAtual->esq==NULL){
            return true;
    } 
}

int main(){
ArvoreBinaria arv;
arv.Criar();
arv.Inserir_semretorno(50);
arv.Inserir_semretorno(10);
arv.Inserir_semretorno(27);
arv.Inserir_semretorno(33);
arv.Inserir_semretorno(12);
arv.Inserir_semretorno(13);


if(arv.Pesquisar(arv.raiz,27)){
    cout<<"Elemento foi encontrado"<<endl;
   }
   else{
    cout<<"Elemento não foi encontrado"<<endl;

}

cout<<"Elemento visitados Em Ordem!"<<endl;
arv.Imprime_ordem(arv.raiz);
cout<<endl;
cout<<"Elemento visitados na Pré-Ordem!"<<endl;
arv.Imprime_preOrdem(arv.raiz);
cout<<endl;
cout<<"Elemento visitados na Pós-Ordem!"<<endl;
arv.Imprime_posOrdem(arv.raiz);


if(arv.NoFolha(arv.raiz)){
    cout<<"Elemento é um nó folha"<<endl;
   }
   else{
    cout<<"Elemento não é nó folha"<<endl;
}

return 0;
}
