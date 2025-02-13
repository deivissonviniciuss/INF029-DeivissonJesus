#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

typedef struct estrutura {
    int *vetorAux;
    int tamanho;
    int qtd;
} estruturaPrincipal;

estruturaPrincipal vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    // se posição é um valor válido {entre 1 e 10}
    if(posicao < 1	|| posicao >	TAM ){
        return POSICAO_INVALIDA;
        //retorno = POSICAO_INVALIDA;
    }
    if(tamanho < 1){ // o tamanho nao pode ser menor que 1
        //retorno = TAMANHO_INVALIDO;
        return TAMANHO_INVALIDO;
    }
    if(	vetorPrincipal[posicao-1].vetorAux !=	NULL){
        return JA_TEM_ESTRUTURA_AUXILIAR;
        // a posicao pode já existir estrutura auxiliar
        //retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    }
    vetorPrincipal[posicao-1].vetorAux = malloc (tamanho * sizeof(int));
    vetorPrincipal[posicao-1].tamanho = tamanho;
    if (!vetorPrincipal[posicao	-1].vetorAux){
        // o tamanho ser muito grande
        return SEM_ESPACO_DE_MEMORIA;
        //retorno = SEM_ESPACO_DE_MEMORIA;	
    }
    // deu tudo certo, crie
    return SUCESSO;// isso aqui recebe o tamanho? pois essa variável não é ponteiro, porém o vetor de struct é um ponteiro.
    //retorno = SUCESSO;
}
/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
    
    if (posicao < 1 || posicao > 10)
        retorno	= POSICAO_INVALIDA;
    else {
        if (vetorPrincipal[posicao-1].vetorAux	!= NULL){
            if (vetorPrincipal[posicao-1].tamanho > vetorPrincipal[posicao-1].qtd){
                vetorPrincipal[posicao-1].vetorAux[vetorPrincipal[posicao-1].qtd] = valor;
                vetorPrincipal[posicao-1].qtd++;
    
                retorno = SUCESSO;
            }
            else {
                retorno = SEM_ESPACO;
            }
        }
        else {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao) {
    if(!verificarPosicaoValida(posicao))
        return POSICAO_INVALIDA;
    
    if(!verificarEstruturaAuxiliar(posicao))
        return SEM_ESTRUTURA_AUXILIAR;
    
    if(vetorPrincipal[posicao-1].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    vetorPrincipal[posicao-1].qtd--;
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor){
    int existeValor = verficarValor(posicao, valor);
    
    if(!verificarPosicaoValida(posicao))
        return POSICAO_INVALIDA;
    
    if(!verificarEstruturaAuxiliar(posicao))
        return SEM_ESTRUTURA_AUXILIAR;
    
    if(vetorPrincipal[posicao-1].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;
    
    if(existeValor < 0)
        return NUMERO_INEXISTENTE;	

    for(int i = 0; i < vetorPrincipal[posicao-1].qtd; i++) { 
        if(vetorPrincipal[posicao-1].vetorAux[i] == valor){
            for(int j = i; j < vetorPrincipal[posicao-1].qtd-1; j++){
                vetorPrincipal[posicao-1].vetorAux[j] = vetorPrincipal[posicao-1].vetorAux[j+1];
            }
            i--;
            vetorPrincipal[posicao-1].qtd--;
        }
    }
    return SUCESSO;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){		
    if(!verificarPosicaoValida(posicao))
        return POSICAO_INVALIDA;

    if(!verificarEstruturaAuxiliar(posicao))
        return SEM_ESTRUTURA_AUXILIAR;

    int j = 0;
    for(int i = 0; i < vetorPrincipal[posicao-1].qtd; i++){
        vetorAux[j] = vetorPrincipal[posicao-1].vetorAux[i];
        j++;
    }	
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    if(!verificarPosicaoValida(posicao))
        return POSICAO_INVALIDA;
    if(!verificarEstruturaAuxiliar(posicao))
        return SEM_ESTRUTURA_AUXILIAR;

    int temp, cont = 0;
    int j = 0; 
    for(int i = 0; i < vetorPrincipal[posicao-1].qtd; i++){
        vetorAux[j] = vetorPrincipal[posicao-1].vetorAux[i];
        j++;
        cont++;
    }

    for(int i = 0; i < cont-1; i++) { 
        for(int j = 0; j < cont-1; j++){
            if(vetorAux[j] > vetorAux[j+1]){
                temp = vetorAux[j]; 
                vetorAux[j] = vetorAux[j+1]; 
                vetorAux[j+1] = temp;
            }
        }
    }
    return SUCESSO;		
}
/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int k = 0;
    int todasEstuturasVazias = 1; 

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].vetorAux != NULL && vetorPrincipal[i].qtd > 0) {
            todasEstuturasVazias = 0; 
            for (int j = 0; j < vetorPrincipal[i].qtd; j++) {
                vetorAux[k] = vetorPrincipal[i].vetorAux[j];
                k++;
            }
        }
    }
    if (todasEstuturasVazias) {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    } else {
        return SUCESSO;
    }
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int i, j, k = 0, temp;
    int todasEstuturasVazias = 1;

    for(int i = 0; i < TAM; i++) {
        if(vetorPrincipal[i].vetorAux != NULL && vetorPrincipal[i].qtd > 0) {
            todasEstuturasVazias = 0;
            for(int j = 0; j < vetorPrincipal[i].qtd; j++) {
                vetorAux[k] = vetorPrincipal[i].vetorAux[j];
                k++;
            }
        }
    }

    if (todasEstuturasVazias)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    for(i = 0; i < k-1; i++) {
        for(j = 0; j < k-1; j++){
            if(vetorAux[j+1]<vetorAux[j]){
                temp = vetorAux[j];
                vetorAux[j] = vetorAux[j+1];
                vetorAux[j+1] = temp;
            }
        }
    }
    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){

    if (!verificarPosicaoValida(posicao))
        return POSICAO_INVALIDA;
    if (!verificarEstruturaAuxiliar(posicao))
        return SEM_ESTRUTURA_AUXILIAR;

    int tamanhoAtual = vetorPrincipal[posicao-1].tamanho;
    int tamanhoAlterado = tamanhoAtual + novoTamanho;


    if (tamanhoAlterado <= 0)
        return NOVO_TAMANHO_INVALIDO;

    int *novoVetor = realloc(vetorPrincipal[posicao-1].vetorAux, tamanhoAlterado * sizeof(int)); 
    if (novoVetor == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    vetorPrincipal[posicao-1].vetorAux = novoVetor;
    vetorPrincipal[posicao-1].tamanho = tamanhoAlterado;

    if (tamanhoAlterado < vetorPrincipal[posicao-1].qtd) {
        vetorPrincipal[posicao-1].qtd = tamanhoAlterado;
    }

    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){
        if(!verificarPosicaoValida(posicao))
            return POSICAO_INVALIDA;
        if(!verificarEstruturaAuxiliar(posicao))
            return SEM_ESTRUTURA_AUXILIAR;

        return vetorPrincipal[posicao-1].qtd;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote(){
    int tam = 0;
    for(int i = 0; i < TAM; i++) {
        tam += vetorPrincipal[i].qtd;
    }
    int vetorAux2[tam];
    getDadosDeTodasEstruturasAuxiliares(vetorAux2);

    No *inicio = (No *) malloc(sizeof(No));

    inicio->prox = NULL;
    No *atual = inicio;

    for(int i = 0; i < TAM; i++) {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = vetorAux2[i];
        novo->prox = NULL;
        atual->prox = novo;
        atual = novo;
    }

    return inicio;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]){
    No *atual = inicio->prox;
    int i = 0;
    while (atual != NULL) {
        vetorAux[i] = atual->conteudo;
        atual = atual->prox;
        i++;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio){
    No* atual = *inicio;

    while(atual->prox != NULL){
        No* tmp = (No*)malloc (sizeof(No));
        tmp = atual->prox;
        free(atual);
        atual = tmp;
    }

    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

/*void inicializar(){ 
    for(int i = 0; i < TAM; i++) 
        vetorPrincipal[i].vetorAux = NULL;
}*/

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

/*void finalizar(){
    free(vetorPrincipal -> vetorAux);
}*/

int verificarEstruturaAuxiliar(int posicao){
    if(vetorPrincipal[posicao-1].vetorAux != NULL)
        return 1;
    else 
        return 0;
}

int verificarPosicaoValida(int posicao){
    if(posicao < 1 || posicao > TAM)
        return 0;
    else
        return 1;
}

int verificarEspaco(int posicao){
    int diferenca = vetorPrincipal[posicao-1].tamanho - vetorPrincipal[posicao-1].qtd;
    if(diferenca > 0)
        return diferenca;
    else
        return 0;
}

int verficarValor(int posicao, int valor) {
    for (int i = 0; i < vetorPrincipal[posicao-1].tamanho; i++)
        if(vetorPrincipal[posicao-1].vetorAux[i] == valor)
            return i;	
    return -1;
}

void inicializar() { 
    for(int i = 0; i < TAM; i++) 
        vetorPrincipal[i].vetorAux = NULL;
    
    FILE *arquivo = fopen("estruturas.txt", "w+"); 
    for (int i = 0; i < TAM; i++) {
        vetorPrincipal[i].vetorAux = NULL;
        vetorPrincipal[i].qtd = 0;
        vetorPrincipal[i].tamanho = 0;
    }

    if (arquivo) {
        for (int i = 0; i < TAM; i++) {
            fscanf(arquivo, "%d", &vetorPrincipal[i].tamanho);  
            fscanf(arquivo, "%d", &vetorPrincipal[i].qtd); 

            if (vetorPrincipal[i].tamanho > 0 && vetorPrincipal[i].qtd > 0) {
                vetorPrincipal[i].vetorAux = malloc(vetorPrincipal[i].tamanho * sizeof(int));
                for (int j = 0; j < vetorPrincipal[i].qtd; j++) {
                    fscanf(arquivo, "%d", &vetorPrincipal[i].vetorAux[j]); 
                }
            }
        }
        fclose(arquivo);  
    } else {
        printf("Arquivo não encontrado!\n");
    }
}

void finalizar() {
    FILE *arquivo = fopen("estruturas.txt", "w+");  
    if (arquivo) {
        for (int i = 0; i < TAM; i++) {
            fprintf(arquivo, "%d ", vetorPrincipal[i].tamanho); 
            fprintf(arquivo, "%d ", vetorPrincipal[i].qtd);  

            
            if (vetorPrincipal[i].vetorAux != NULL) {
                for (int j = 0; j < vetorPrincipal[i].qtd; j++) {
                    fprintf(arquivo, "%d ", vetorPrincipal[i].vetorAux[j]);  
                }
                free(vetorPrincipal[i].vetorAux);  
                vetorPrincipal[i].vetorAux = NULL;
            }
            if(i < TAM-1)
            fprintf(arquivo, "\n");  
        }
        fclose(arquivo); 
    } else {
        printf("Erro ao abrir o arquivo para salvar.\n");
    }
    
    free(vetorPrincipal -> vetorAux);
}
