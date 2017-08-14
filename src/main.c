#include <stdio.h>

int main(){

  char c;
  int numeroPalavras = 0;
  char anteriorLetra = 0;
  char anteriorNumero = 0;
  char anteriorFlutuante = 0;
  char anteriorSeparador = 0;
  char atualLetra = 0;
  char atualNumero = 0;
  char atualFlutuante = 0;
  char atualSeparador = 0;
  char numeroPontos = 0;
  char reticencia = 0;

  do{
    scanf("%c", &c);

    //Analise do caractere para fazer a verificação do final de palavra
    //Conta o número de pontos para verificar reticencias
    if(c=='.'){
      if(reticencia==0){
        numeroPontos++;
      }
      else{
        reticencia = 0;
      }
    }
    else{
      if(reticencia==1){
        numeroPalavras++;
      }
      numeroPontos = 0;
      reticencia = 0;
    }
    //Verifica se o caractere é uma letra
    if(((c>=65)&&(c<=90))||((c>=97)&&(c<=122))){
      atualLetra = 1;
      atualNumero = 0;
      atualFlutuante = 0;
      atualSeparador = 0;
    }
    //Verifica se o caractere é um número
    if((c>=48)&&(c<=57)){
      //Faz a distinção entre número isolado e número flutuante
      if(anteriorFlutuante==0){
        atualLetra = 0;
        atualNumero = 1;
        atualFlutuante = 0;
        atualSeparador = 0;
      }
      else{
        atualLetra = 0;
        atualNumero = 0;
        atualFlutuante = 1;
        atualSeparador = 0;
      }
    }
    //Verifica se o caractere é um separador/simbolo
    if(((c>=32)&&(c<=47))||((c>=58)&&(c<=64))||((c>=91)&&(c<=96))||((c>=123)&&(c<=126))||(c=='\n')){
      atualLetra = 0;
      atualNumero = 0;
      atualFlutuante = 0;
      atualSeparador = 1;
    }
    //Verifica se o caractere pode compor um número de ponto flutuante
    if((anteriorNumero==1)&&((c=='.')||(c==','))){
      atualLetra = 0;
      atualNumero = 0;
      atualFlutuante = 0;
      atualFlutuante = 1;
      atualSeparador = 0;
    }

    //Verificação do final de palavra
    //Se antes era uma letra e agora é um divisor, então é uma palavra
    if((anteriorLetra==1)&&(atualSeparador==1)){
      numeroPalavras++;
    }
    //Se antes era um número e agora é um divisor, então é uma palavra
    if((anteriorNumero==1)&&(atualSeparador==1)){
      numeroPalavras++;
    }
    //Se antes era um número de ponto flutuante e agora é um divisor, então é uma palavra
    if((anteriorFlutuante==1)&&((atualSeparador==1)||(atualLetra==1))){
      numeroPalavras++;
    }
    //Se tem 3 pontos seguidos, é uma reticencia
    if(numeroPontos==3){
      reticencia = 1;
    }

    //Transfere a analise atual para a anterior para a proxima analise
    anteriorLetra = atualLetra;
    anteriorNumero = atualNumero;
    anteriorSeparador = atualSeparador;
    anteriorFlutuante = atualFlutuante;
  }while(c!='\n');

  printf("%d\n",numeroPalavras);
  return 0;
}
