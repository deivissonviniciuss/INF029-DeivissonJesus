// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Deivisson Vinicus França de Jesus
//  email: deivissonvinici@gmail.com
//  Matrícula: 20232160028
//  Semestre: 2024.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "deivissonJesus20232160028.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>

DataQuebrada quebraData(char data[]);
int verificarBissexto(int ano);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

int verificarBissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

int q1(char data[]){
    int datavalida;
    //quebra a string data em strings sDia, sMes, sAno
    DataQuebrada dataQuebrada = quebraData(data);

    if (dataQuebrada.valido == 0) {
        return 0;
    } else if((dataQuebrada.iMes == 2) 
                && (dataQuebrada.iDia == 29) 
                && !(dataQuebrada.iAno % 4 == 0 
                    || dataQuebrada.iAno % 400 == 0) 
                && (dataQuebrada.iAno % 100 != 0)) {
                    return 0;
    } else if ((dataQuebrada.iMes == 1
                ||dataQuebrada.iMes == 3
                ||dataQuebrada.iMes == 5
                ||dataQuebrada.iMes == 7
                ||dataQuebrada.iMes == 8
                ||dataQuebrada.iMes == 10
                ||dataQuebrada.iMes == 12) 
            && (dataQuebrada.iDia < 1 || dataQuebrada.iDia > 31) ){
                return 0;
    } else if((dataQuebrada.iMes == 4
                ||dataQuebrada.iMes == 6 
                ||dataQuebrada.iMes == 9
                ||dataQuebrada.iMes == 11) 
            && (dataQuebrada.iDia < 1 || dataQuebrada.iDia > 30)){
            return 0;
    } 

    if(dataQuebrada.iMes < 1 || dataQuebrada.iMes > 12 ){
        return 0;
    }
  return 1;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{

        //datainicial
        int i;
        char diaInicial[3], mesInicial[3], anoInicial[5];
        for(i = 0; datainicial[i] != '/'; i++){
            diaInicial[i] = datainicial[i];
        }
        diaInicial[i] = '\0';

        int j = 0;
        for(i = i + 1; datainicial[i] != '/'; i++){
            mesInicial[j] = datainicial[i];
            j++;
        }
        mesInicial[j] = '\0';

        j = 0;
        for(i = i + 1; datainicial[i] != '\0'; i++){
            anoInicial[j] = datainicial[i];
            j++;
        }
        anoInicial[j] = '\0';

        //dataFinal 
        i = 0;
        char diaFinal[3], mesFinal[3], anoFinal[5];
        for(i = 0; datafinal[i] != '/'; i++){
            diaFinal[i] = datafinal[i];
        }
        diaFinal[i] = '\0';

        j = 0;
        for(i = i + 1; datafinal[i] != '/'; i++){
            mesFinal[j] = datafinal[i];
            j++;
        }
        mesFinal[j] = '\0';

        j = 0;
        for(i = i + 1; datafinal[i] != '\0'; i++){
            anoFinal[j] = datafinal[i];
            j++;
        }
        anoFinal[j] = '\0';   

        //converter para inteiro
        int diai = 0;
        for(int k = 0; diaInicial[k] != '\0'; k++)
            diai = diai * 10 + (diaInicial[k] - 48);
        int mesi = 0;
        for(int k = 0; mesInicial[k] != '\0'; k++)
            mesi = mesi * 10 + (mesInicial[k] - 48);
        int anoi = 0;
        for(int k = 0; anoInicial[k] != '\0'; k++)
            anoi = anoi * 10 + (anoInicial[k] - 48);

        int diaf = 0;
        for(int k = 0; diaFinal[k] != '\0'; k++)
            diaf = diaf * 10 + (diaFinal[k] - 48);
        int mesf = 0;
        for(int k = 0; mesFinal[k] != '\0'; k++)
            mesf = mesf * 10 + (mesFinal[k] - 48);
        int anof = 0;
        for(int k = 0; anoFinal[k] != '\0'; k++)
            anof = anof * 10 + (anoFinal[k] - 48);

        if(anof < anoi){
            dma.retorno = 4;
            return dma;
        } else if(anof == anoi && mesi > mesf){
            dma.retorno = 4;
            return dma;
        } else if(anof == anoi && mesf == mesi && diai > diaf){
            dma.retorno = 4;
            return dma;
        }

      //calcule a distancia entre as datas

        if(diaf > diai){
            dma.qtdDias = diaf - diai;
        } else if(diaf < diai) {
            if(verificarBissexto(anoi) && mesi == 2)
                dma.qtdDias = 28 - diai + diaf;
            else if(mesi == 2)
                dma.qtdDias = 29 - diai + diaf;
            else if(mesf == 1 || mesf == 3 || mesf == 5 || mesf == 7|| mesf == 10 || mesf == 12)
                dma.qtdDias = 30 - diai + diaf;
            else if(mesf == 2 || mesf == 4 || mesf == 6 || mesf == 8 || mesf == 9 || mesf == 11)
                dma.qtdDias = 31 - diai + diaf;
        } else {
            dma.qtdDias = 0;
        }

        int subtrair = 0;
        if(mesf > mesi && diaf >= diai){
            dma.qtdMeses = mesf - mesi;  
        } else if(mesf > mesi && diaf < diai){
            dma.qtdMeses = mesf - mesi - 1;
        } else if(mesf < mesi && diaf >= diai){
            dma.qtdMeses = 12 - mesi + mesf;
        } else if(mesf < mesi && diaf < diai){
            dma.qtdMeses = 12 - mesi + mesf + 1;
        } else if(mesf == mesi && diaf < diai){
            dma.qtdMeses = 11;
            subtrair++;
        } else {
            dma.qtdMeses = 0;
        }

        if(anof > anoi && mesf >= mesi){
            dma.qtdAnos = anof - anoi - subtrair;
        } else if (anof > anoi && mesf < mesi){
            dma.qtdAnos = anof - anoi - 1;
        } else {
            dma.qtdAnos = 0;
        }

      //se tudo der certo
      dma.retorno = 1;
      return dma;

    }

}



/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;

    if(isCaseSensitive){
        for(int i = 0; texto[i] != '\0'; i++)
            if(texto[i] == c)
                qtdOcorrencias++;
    } else{
        if(c >= 'A' && c <= 'Z')
            c += 'a' - 'A';
        
        for(int i = 0; texto[i] != '\0'; i++){
        char textoTemp = texto[i];
            if(texto[i] >= 'A' && texto[i] <= 'Z')
                textoTemp += 'a' - 'A';    
            if(c == textoTemp)
                qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;

    int tam = 0;
    for(int i = 0; strBusca[i] != '\0'; i++)
        tam++;

    int cont;
    int posicao = 0;
    for(int j = 0; strTexto[j] != '\0'; j++){
        int inicio = j + 1;
        int x = 0;
        cont = 0;
        for(int k = j; strTexto[k] != '\0'; k++){
            if(strTexto[k] == strBusca[x]){
                cont++;
                x++;
                    if(cont == tam){
                        int finall = k + 1;
                        posicoes[posicao] = inicio;
                        posicoes[posicao + 1] = finall;
                        posicao += 2;
                        qtdOcorrencias++;
                        j = k;
                        break;
                    }
            } else {
                cont = 0;
                break;
            }
        }
    }
    
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){
    int invertido = 0;
    int aux = 0;

    while(num != 0){
        invertido = (aux * 10) + num%10;
        aux = invertido;
        num = num/10;
    }
    
    return invertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias = 0;
    int tambusca = 0;
    int buscaTemp = numerobusca;
    
    while(buscaTemp > 0){
        tambusca++;
        buscaTemp /= 10;
    }

    int pot = 1;
    for(int i = 0; i < tambusca; i++){
        pot *= 10;
    }

    while(numerobase >= numerobusca){
        int aux = numerobase % pot;
        if(aux == numerobusca){
            qtdOcorrencias++;
            numerobase /= pot;
        } else {
            numerobase /= 10;
        }
    }
    
    return qtdOcorrencias;
}




DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
    char sMes[3];
    char sAno[5];
    int i; 

    for (i = 0; data[i] != '/'; i++){
        sDia[i] = data[i];	
    }
    if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
        sDia[i] = '\0';  // coloca o barra zero no final
    }else {
        dq.valido = 0;
    return dq;
  }  


    int j = i + 1; //anda 1 cada para pular a barra
    i = 0;

    for (; data[j] != '/'; j++){
        sMes[i] = data[j];
        i++;
    }

    if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
        sMes[i] = '\0';  // coloca o barra zero no final
    }else {
        dq.valido = 0;
    return dq;
  }


    j = j + 1; //anda 1 cada para pular a barra
    i = 0;

    for(; data[j] != '\0'; j++){
        sAno[i] = data[j];
        i++;
    }

    if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
        sAno[i] = '\0';  // coloca o barra zero no final
    }else {
        dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

    dq.valido = 1;

  return dq;
}
