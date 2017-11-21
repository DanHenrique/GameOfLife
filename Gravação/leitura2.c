#include <stdio.h>

#define TAMANHO_MAX 10

void AbrirArquivoGeracao(int matriz1[TAMANHO_MAX][TAMANHO_MAX], int matriz2[TAMANHO_MAX][TAMANHO_MAX], int tam){

    printf("Lendo arquivo...\n\n");

    int linha, coluna;
    FILE *arq;
    char url[] = "recSuperElisa.txt";
    
    arq = fopen(url, "r");
    if(arq == NULL)
            printf("Erro, nao foi possivel abrir o arquivo\n");
    else
        if((fscanf(arq,"Tamanho: %d\n", &tam)) != EOF){
            printf("Tamanho: %d\n", tam);
        }        

        while( (fscanf(arq,"%d - %d\n", &linha, &coluna)) != EOF){
            matriz1[linha][coluna] = matriz2[linha][coluna] = 1;
            printf("Alguem vivo na possicao -> Linha: %d Coluna: %d\n", linha, coluna);
        }    
    fclose(arq);
}

void SalvarArquivo(int matriz1[TAMANHO_MAX][TAMANHO_MAX], int matriz2[TAMANHO_MAX][TAMANHO_MAX], int tam){

    int i, j;

    // Variaveis para auxiliar na criação e gravação do arquivo
    char rec[100];  
    FILE *arq;
    int result, contador = 0;
    char url[] = "recSuperElisa.txt";  
    
    arq = fopen(url, "wt");

    if(arq == NULL){
        printf("Problemas na criacao do arquivo\n");
    }

    printf("\n\nSalvando arquivo...\n");

    sprintf(rec, "Tamanho: %d\n", tam);
    printf("Tamanho: %d\n", tam);
    result = fputs(rec, arq);

    for(i=0; i < tam;i++){
        for(j=0; j< tam; j++){;
            if(matriz2[i][j]==1){                
                sprintf(rec, "%d - %d\n", i,j);
                printf("[%d][%d]\n", i,j );
                result = fputs(rec,arq);
                contador++;
            }
        }       
    }
    fclose(arq);
    printf("Gravacao concluida com sucesso\nSeres Vivos gravados: %d\n", contador); 
}



int main(void)
{   
    int tamanho = TAMANHO_MAX;


    int m2[tamanho][tamanho], m1[tamanho][tamanho], i, j;

    printf("Qual tamanho deseja que seja o mundo? ");
    scanf("%d", &tamanho);
    //tamanho = 6;

    int linha, coluna;

    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            m2[i][j] = m1[i][j] = 0;
        }
    }

    // m1[0][0] = 1;
    // m1[0][1] = 1;
    // m1[0][2] = 1;

    printf("\n\n");
    printf("Esse programa e so para teste, sera solicitado para adicionar 3 seres vivos\n");
    printf("Recomendamos a linha 1 e as colunas 1, 2 ,3...");
    printf("\n\n");

    for(i = 0; i < 3; i++){
        printf("Digite a linha(de 1 ate %d): ", tamanho);
        scanf("%d", &linha);
        printf("Digite a coluna(de 1 ate %d): ", tamanho);
        scanf("%d", &coluna);

        m1[linha-1][coluna-1] = 1;
    }

    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            m2[i][j] = m1[i][j];
        }
    }


    SalvarArquivo(m1, m2, tamanho);

    printf("\n\n");
    printf("Caso queira testar se o arquivo esta realmente carregando tente mudar o arquivo que foi criado, não alterando a estrutura dele claro\n");
    

    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            m2[i][j] = m1[i][j] = 0;
        }
    }

    AbrirArquivoGeracao(m1, m2, tamanho);

    printf("\n\n");

    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    return 0;
}
