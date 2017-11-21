#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_PADRAO 50
#define TAMANHO_MAX 100

#define GERACOES 4

#define TRUE 1
#define FALSE 0

// Funções
void GerarAleatorio(int matriz1[TAMANHO_MAX][TAMANHO_MAX], int matriz2[TAMANHO_MAX][TAMANHO_MAX], int tam);
void ExibirMatriz (int matriz[TAMANHO_MAX][TAMANHO_MAX], int tam);
void RodarGeracoes(int matriz1[TAMANHO_MAX][TAMANHO_MAX], int matriz2[TAMANHO_MAX][TAMANHO_MAX], int nvezes, int tam);
void RodarGeracoesImprimir(int matriz1[TAMANHO_MAX][TAMANHO_MAX], int matriz2[TAMANHO_MAX][TAMANHO_MAX], int nvezes, int tam);
void SalvarArquivo(int matriz1[TAMANHO_MAX][TAMANHO_MAX], int matriz2[TAMANHO_MAX][TAMANHO_MAX], int tam);
void LimparCampos(int matriz1[TAMANHO_MAX][TAMANHO_MAX], int matriz2[TAMANHO_MAX][TAMANHO_MAX], int matriz3[TAMANHO_MAX][TAMANHO_MAX], int matriz4[TAMANHO_MAX][TAMANHO_MAX], int tam);

int main()
{
    char opcaomenu, opcao, opcaorec;
    int i, j, t = 0, x=0, k, fim = FALSE;
    int tamanho = TAMANHO_MAX, validar = 0;
    int m1[TAMANHO_MAX][TAMANHO_MAX], m2[TAMANHO_MAX][TAMANHO_MAX], m3[TAMANHO_MAX][TAMANHO_MAX], m4[TAMANHO_MAX][TAMANHO_MAX];
    int n_geracoes=GERACOES;
    int nsalvar, auxsalvar = 0;
    
    LimparCampos(m1, m2, m3, m4, tamanho);

    GerarAleatorio(m1, m3, tamanho);
    
    

    do{
        fflush(stdin);
        printf("\n(C)onfig\n(J)ogar\n(S)air\n\nForneca a opcao: ");
        scanf("%c", &opcaomenu);

        switch(opcaomenu){
            case 'C':
            case 'c':
                LimparCampos(m1, m2, m3, m4, tamanho);
                do{

                    if(validar  == TRUE){
                        printf("Digite um tamanho valido... Min: 50 - Max: 100");
                        printf("\n");
                    }

                    fflush(stdin);
                    printf("Digite o tamanho: ");
                    scanf("%d",&tamanho);

                    validar = TRUE;
                }while(tamanho < TAMANHO_PADRAO || tamanho > TAMANHO_MAX);
            
                validar = FALSE;
            
                do{
                    if(validar  == TRUE){
                        printf("Digite uma quantidade valida... Min: 1");
                        printf("\n");
                    }

                    fflush(stdin);
                    printf("Digite a quantidade de geracoes a partir da primeira: ");
                    scanf("%d",&n_geracoes);

                    validar = TRUE;

                }while(n_geracoes< 1);
            
            
                /* para atribuir os valores que o usuario deseja que tenha vida*/
                while (!fim){

                    printf("Digite i: "); /*linhas*/
                    scanf("%d", &i);

                    printf("Digite j: "); /*colunas*/
                    scanf("%d", &j);

                    m1[i][j]=1;
                    x++;
                    

                    printf("Deseja continuar (S/N)?");
                    opcao = getch();
                    printf("\nSeres vivos: %d", x);
                    printf("\n");
                    if(opcao == 'N'  || opcao == 'n')
                    fim=TRUE;
                }

                printf("\n");
            
                break;
    
            case 'J':
            case 'j':


                // Salvando a matriz inicial na matriz 3
                for(i=0;i<tamanho;i++){
                    for(j=0;j<tamanho;j++){

                        m3[i][j] = m1[i][j];
                    }
                }


                ExibirMatriz (m1, tamanho);

                RodarGeracoes(m1, m2, n_geracoes, tamanho);
                
                printf("Deseja salvar antes de limpar? (S/N)");
                opcaorec = getch();
                printf("\n");
                if(opcaorec == 'S'  || opcaorec == 's'){    
                    
                    do{
                        if(auxsalvar > 0){
                            printf("Digite uma geracao valida...");
                        }
                        printf("Qual geracao deseja salvar?");
                        scanf("%d", &nsalvar);

                        auxsalvar++;
                    }while (nsalvar > n_geracoes);

                    RodarGeracoesImprimir(m3, m4, nsalvar, tamanho);
                    SalvarArquivo(m3, m4, tamanho);
                    printf("A geracao salva foi:");
                    ExibirMatriz (m4, tamanho);

                }
    
    
                printf("\nDeseja limpar? (S/N)");
                opcao = getch();
                printf("\n");
                if(opcao == 'S'  || opcao == 's'){
                    LimparCampos(m1, m2, m3, m4, tamanho);
                }
        
            break;
        }
    } while (opcaomenu != 'S' && opcaomenu != 's');
}

void GerarAleatorio(int matriz1[TAMANHO_MAX][TAMANHO_MAX], int matriz2[TAMANHO_MAX][TAMANHO_MAX], int tam){

    matriz1[0][0] = matriz2[0][0] = 1;
    matriz1[0][1] = matriz2[0][0] = 1;
    matriz1[0][2] = matriz2[0][0] = 1;
}

void ExibirMatriz (int matriz[TAMANHO_MAX][TAMANHO_MAX], int tam){

    int i, j;

    /* Exibindo a matriz*/
    printf("\n\n");

    for(i = 0;i < tam; i++){
        for(j = 0;j < tam; j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void RodarGeracoes(int matriz1[TAMANHO_MAX][TAMANHO_MAX], int matriz2[TAMANHO_MAX][TAMANHO_MAX], int nvezes, int tam){

    int i, k, j;
    int t;

    for(k = 1; k <= nvezes; k++){ /* Numero de gerações a serem exibidas*/
        for(i=0;i<tam;i++){
            for (j=0;j<tam;j++){

                t=0;

                /* Série de testes sobre os 6 vizinhos possivéis*/
                if (matriz1[(i-1+tam)%tam][(j-1+tam)%tam]==1)
                    t++;
                if (matriz1[(i-1+tam)%tam][j]==1)
                    t++;
                if (matriz1[(i-1+tam)%tam][(j+1)%tam]==1)
                    t++;
                if (matriz1[i][(j-1+tam)%tam]==1)
                    t++;
                if (matriz1[i][(j+1)%tam]==1)
                    t++;
                if (matriz1[(i+1)%tam][(j-1+tam)%tam]==1)
                    t++;
                if (matriz1[(i+1)%tam][j]==1)
                    t++;
                if (matriz1[(i+1)%tam][(j+1)%tam]==1)
                    t++;

                /* Atribuir o valores atualizadoos*/
                    if ((t==0)||(t==1)||(t>=4)){
                        matriz2[i][j]=0;
                    }
                    else {
                        if (t==3){
                            matriz2[i][j]=1;
                        }
                        else {
                            matriz2[i][j]=matriz1[i][j];
                        }
                    }
            }
        }
        /* Atribuindo a matriz real(matriz2) na matriz de teste(matriz1)*/
        for(i=0;i<tam;i++){
            for(j=0;j<tam;j++){
                matriz1[i][j] = matriz2[i][j];
            }
        }
        /* Exibindo a matriz*/
        printf("\n\n");

                   
        ExibirMatriz(matriz2, tam);

        printf("\n\n");
    }    
}

void RodarGeracoesImprimir(int matriz1[TAMANHO_MAX][TAMANHO_MAX], int matriz2[TAMANHO_MAX][TAMANHO_MAX], int nvezes, int tam){

    int i, k, j;
    int t;

    for(k = 1; k <= nvezes; k++){ /* Numero de gerações a serem exibidas*/
        for(i=0;i<tam;i++){
            for (j=0;j<tam;j++){

                t=0;

                /* Série de testes sobre os 6 vizinhos possivéis*/
                if (matriz1[(i-1+tam)%tam][(j-1+tam)%tam]==1)
                    t++;
                if (matriz1[(i-1+tam)%tam][j]==1)
                    t++;
                if (matriz1[(i-1+tam)%tam][(j+1)%tam]==1)
                    t++;
                if (matriz1[i][(j-1+tam)%tam]==1)
                    t++;
                if (matriz1[i][(j+1)%tam]==1)
                    t++;
                if (matriz1[(i+1)%tam][(j-1+tam)%tam]==1)
                    t++;
                if (matriz1[(i+1)%tam][j]==1)
                    t++;
                if (matriz1[(i+1)%tam][(j+1)%tam]==1)
                    t++;

                /* Atribuir o valores atualizadoos*/
                    if ((t==0)||(t==1)||(t>=4)){
                        matriz2[i][j]=0;
                    }
                    else {
                        if (t==3){
                            matriz2[i][j]=1;
                        }
                        else {
                            matriz2[i][j]=matriz1[i][j];
                        }
                    }
            }
        }
        /* Atribuindo a matriz real(matriz2) na matriz de teste(matriz1)*/
        for(i=0;i<tam;i++){
            for(j=0;j<tam;j++){
                matriz1[i][j] = matriz2[i][j];
            }
        }
        /* Exibindo a matriz*/
        //printf("\n\n");                   
        //ExibirMatriz(matriz2, tam);

        printf("\n\n");
    }    
}




void SalvarArquivo(int matriz1[TAMANHO_MAX][TAMANHO_MAX], int matriz2[TAMANHO_MAX][TAMANHO_MAX], int tam){

    int i, j;

    // Variaveis para auxiliar na criação e gravação do arquivo
    char rec[100];  
    FILE *arq;
    int result;
    
    
    arq = fopen("recSuperElisa.txt", "wt");
    
    if(arq == NULL){
        printf("Problemas na criacao do arquivo\n");
    }

    printf("\n\nSalvando arquivo...\n");
    for(i=0; i < tam;i++){
        for(j=0; j< tam; j++){
            if(matriz2[i][j]==1){                
                sprintf(rec, "Linha %d -  Coluna %d \n", i,j);
                printf("[%d][%d]\n", i,j );
                result = fputs(rec,arq); 
            }
        }       
    }
    fclose(arq);
    printf("Gravacao concluida com sucesso\nSeres Vivos gravados:\n"); 
}

void LimparCampos(int matriz1[TAMANHO_MAX][TAMANHO_MAX], int matriz2[TAMANHO_MAX][TAMANHO_MAX], int matriz3[TAMANHO_MAX][TAMANHO_MAX], int matriz4[TAMANHO_MAX][TAMANHO_MAX], int tam){
    int i, j;
    for (i=0;i<tam;i++){
        for (j=0;j<tam;j++){
            matriz1[i][j] = matriz2[i][j] = matriz3[i][j] = matriz4[i][j] = 0;
        }
    }
}
