#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//primeiro é criado as matrizes nas funçoes inicializaTabuleiro, inicializaTabuleiroPC com dimensao 10x10.

void inicializaTabuleiro(int tabuleiro[][10])
{
    int linha, coluna;
        for(linha=0 ; linha < 10 ; linha++ )
            for(coluna=0 ; coluna < 10 ; coluna++ )
                tabuleiro[linha][coluna]=-1;
}
void inicializaTabuleiroPC(int tabuleiroPC[][10])
{
    int linha1, coluna1;
        for(linha1=0 ; linha1 < 10 ; linha1++ )
            for(coluna1=0 ; coluna1 < 10 ; coluna1++ )
                tabuleiroPC[linha1][coluna1]=-1;
}

// nas funçoes mostraTabuleiro,mostraTabuleiroPC imprime os numeros das linhas e coluna
//junto com os caracteres para esconder os navios e as ações do jogo.
// 'o' = tiro na agua
//'-' = sem açao
//'X' = acertou o tiro no navio.
void mostraTabuleiro(int tabuleiro[][10])
{

    int linha, coluna;

        printf("\t1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9 \t10");
        printf("\n");

        for(linha=0 ; linha < 10 ; linha++ ){
            printf("%d",linha+1);
            for(coluna=0 ; coluna < 10 ; coluna++ ){
                if(tabuleiro[linha][coluna]==-1){
                    printf("\t-");
                }else if(tabuleiro[linha][coluna]==0){
                    printf("\to");
                }else if(tabuleiro[linha][coluna]==1){
                    printf("\tX");
                }

            }
            printf("\n");
        }

    }
    void mostraTabuleiroPC(int tabuleiroPC[][10])
    {


        int linha1, coluna1;

            printf("\t1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9 \t10");
            printf("\n");

            for(linha1=0 ; linha1 < 10 ; linha1++ ){
                printf("%d",linha1+1);
                for(coluna1=0 ; coluna1 < 10 ; coluna1++ ){
                    if(tabuleiroPC[linha1][coluna1]==-1){
                        printf("\t-");
                    }else if(tabuleiroPC[linha1][coluna1]==0){
                        printf("\to");
                    }else if(tabuleiroPC[linha1][coluna1]==1){
                        printf("\tX");
                    }

                }
                printf("\n");
            }

        }

//iniciaNavios e iniciaNaviosPC sao posicionados os nvios de forma aleatoria nas matrizes.
void iniciaNavios(int navios[][2]){
        srand(time(NULL));
        int navio, anterior, x;

        for(navio=0 ; navio < 10 ; navio++){
            navios[navio][0]= rand()%10;
            navios[navio][1]= rand()%10;



            //agora vamos checar se esse par não foi sorteado
            //se foi, so sai do do...while enquanto sortear um diferente
            for(anterior=0 ; anterior < navio ; anterior++){
                if( (navios[navio][0] == navios[anterior][0])&&(navios[navio][1] == navios[anterior][1]) )
                    do{
                        navios[navio][0]= rand()%10;
                        navios[navio][1]= rand()%10;
                    }while( (navios[navio][0] == navios[anterior][0])&&(navios[navio][1] == navios[anterior][1]) );
            }
        }

      }



void iniciaNaviosPC(int naviosPC[][2]){
            srand(time(NULL));
            int navio1, anterior1 ;

            for(navio1=0 ; navio1 < 10 ; navio1++){
                naviosPC[navio1][0]= rand()%10;
                naviosPC[navio1][1]= rand()%10;

                //agora vamos checar se esse par não foi sorteado
                //se foi, so sai do do...while enquanto sortear um diferente
                for(anterior1=0 ; anterior1 < navio1 ; anterior1++){
                    if( (naviosPC[navio1][0] == naviosPC[anterior1][0])&&(naviosPC[navio1][1] == naviosPC[anterior1][1]) )
                        do{
                            naviosPC[navio1][0]= rand()%10;
                            naviosPC[navio1][1]= rand()%10;
                        }while( (naviosPC[navio1][0] == naviosPC[anterior1][0])&&(naviosPC[navio1][1] == naviosPC[anterior1][1]) );
                }

            }
        }


//darTiro e darTiroPC sao funcoes utilizadas para realizar os tiros sendo que na funcao darTiro a escolha é feita pelo jogador.
// darTiroPC a escolha é feita de forma aleatoria usando srand(time(NULL)), rand()%10.
void darTiro(int tiro[2])
{

        printf("Linha: ");
        scanf("%d",&tiro[0]);
        tiro[0]--;

        printf("Coluna: ");
        scanf("%d",&tiro[1]);
        tiro[1]--;

}
void darTiroPC(int tiroPC[2])
{
  int x,y;
      srand(time(NULL));
      x = rand()%10;
      y = rand()%10;

      tiroPC[0] = x;
      tiroPC[0]--;

      tiroPC[1] = y;
      tiroPC[1]--;
      printf("ataque do inimigo linha: %d\n",x );
      printf("ataque do inimigo coluna: %d\n",y );

}
// as funcoes acertou e acertouPC vao verificar o tiro com o navio.
int acertou(int tiro[2], int navios[][2])
{
    int navio, pontosJ;

        for(navio=0 ; navio < 10 ; navio++){
            if( tiro[0]==navios[navio][0] && tiro[1]==navios[navio][1]){
                printf("Você acertou o tiro (%d,%d)\n",tiro[0]+1,tiro[1]+1);
                pontosJ = pontosJ + 10;
                return 1;
            }
        }
        return 0;
    }
int acertouPC(int tiroPC[2], int naviosPC[][2])
    {
        int navio1, pontosINI;

            for(navio1=0 ; navio1 < 10 ; navio1++){
                if( tiroPC[0]==naviosPC[navio1][0] && tiroPC[1]==naviosPC[navio1][1]){
                    printf("Você acertou o tiro (%d,%d)\n",tiroPC[0]+1,tiroPC[1]+1);
                    pontosINI = pontosINI + 10;
                    return 1;
                }
            }
            return 0;
        }

//caso as funçoes acertou e acertosPC, acusem o tiro certo ou nao no tabuleiro é trocado o caractere por 'X'e 'o' respectivamente.
void alteraTabuleiro(int tiro[2], int navios[][2], int tabuleiro[][10]){
    int pontosJ;
        if(acertou(tiro,navios)){
            tabuleiro[tiro[0]][tiro[1]]=1;
            pontosJ = pontosJ + 10;
        }


        else{
            tabuleiro[tiro[0]][tiro[1]]=0;
        }
    }
void alteraTabuleiroPC(int tiroPC[2], int naviosPC[][2], int tabuleiroPC[][10]){
      int pontosINI;
            if(acertou(tiroPC,naviosPC)){
                tabuleiroPC[tiroPC[0]][tiroPC[1]]=1;
                pontosINI = pontosINI + 10;
            }

            else
                tabuleiroPC[tiroPC[0]][tiroPC[1]]=0;
        }

int main() {
        int tabuleiro[10][10];
        int tabuleiroPC[10][10];
        int navios[10][2];
        int navios1[3][2];
        int naviosPC[10][2];
        int tiro[2];
        int tiroPC[2];
        int tentativas=0,
            acertos=0;
        int acertosPC = 0, pontosJ = 0, pontosINI = 0;
        char nome[50];




        inicializaTabuleiro(tabuleiro);


        iniciaNavios(navios);

        inicializaTabuleiroPC(tabuleiroPC);

        iniciaNaviosPC(naviosPC);
        printf("\t\t\t\t         ____        __        ____             _   __                  __\n");
        printf("\t\t\t\t        / __ )____ _/ /_____ _/ / /_  ____ _   / | / /___ __   ______ _/ /\n");
        printf("\t\t\t\t       / __  / __ `/ __/ __ `/ / __ \\/ __ `/  /  |/ / __ `/ | / / __ `/ / \n");
        printf("\t\t\t\t      / /_/ / /_/ / /_/ /_/ / / / / / /_/ /  / /|  / /_/ /| |/ / /_/ / /  \n");
        printf("\t\t\t\t     /_____/\\__,_/\\__/\\__,_/_/_/ /_/\\__,_/  /_/ |_/\\__,_/ |___/\\__,_/_/   \n");

        printf("\n");
        printf("..............A  B A T A L H A   N A V A L:...............\n" );
        printf("COMO É SEU NOME CAPITAO?\n");
        scanf("%s", nome );
        printf("..........................................................\n" );
        printf("Capitao %s voce tem uma missao muito importante, nesse exato momento tem tropas inimigas querendo dominar o nosso pais.\n", nome);
        printf("Por isso estou te eniviando uma tropa PARA NOS DEFENDER, mas temos um problema os inimigos danificaram os nossos RADARES.\n");
        printf("Entao vc tem usar toda sua experiencia para derrotar os navios inimigos.\n" );
        printf("...........................................................\n");
        printf("boa sorte na missao, CAPITAO\n" );
        printf("LEMBRANDO MISSAO DADA EH MISSAO COMPRIDA\n" );
        printf("...........................................................\n");
        printf("regra do jogo \n");
        printf("tiro na agua = 'o'\n");
        printf("acertou no navio = 'X'\n");
        while((pontosJ<70)&&(pontosINI <70)){
            printf("..............A  B A T A L H A   N A V A L:............\n");
            printf("tabuleiro do inimigo\n" );
            printf("pontos do inimigo = %d\n", pontosINI );
            mostraTabuleiro(tabuleiro);
            printf("\n");
            printf("tabuleiro do jogador\n" );
            printf("CAPITAO %s\n",nome );
            printf("pontos do jogador = %d\n",pontosJ );
            mostraTabuleiro(tabuleiroPC);


            darTiro(tiro);
            darTiroPC(tiroPC);
            alteraTabuleiro(tiro,navios,tabuleiro);
            alteraTabuleiroPC(tiroPC,naviosPC,tabuleiroPC);

            tentativas++;

            if(acertou(tiro,navios)){
                printf("acertou um navio\n" );
                pontosJ = pontosJ + 10;
                acertos++;
            }if(acertouPC(tiroPC,naviosPC)){
                printf("olha o inimigo chegando\n" );
                pontosINI = pontosINI + 10;
            }






        }

        if (pontosJ>=70){
        printf("\n\n\nJogo terminado. Você acertou os 3 navios em %d tentativas\n", tentativas);
        printf("\n");
        mostraTabuleiro(tabuleiro);
        }
        if( pontosINI>=70){
        printf("\n\n\nJogo terminado. Você perdeu e o nosso pais foi tomado, PESSIMO RESULTADO CAPITAO  %d   tentativas\n", tentativas);
        printf("\n" );
        mostraTabuleiroPC(tabuleiroPC);
        }
}
