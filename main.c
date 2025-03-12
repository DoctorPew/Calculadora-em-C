#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DIM 10 


typedef struct {
    int linhas;
    int colunas;
    double elementos[MAX_DIM][MAX_DIM];
} Matriz;

void limparBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}


Matriz lerMatriz() {
    Matriz matriz;
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &matriz.linhas);
    limparBuffer();

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &matriz.colunas);
    limparBuffer();

    printf("Digite os elementos da matriz (separe os elementos por espaço ou enter):\n");
    for (int i = 0; i < matriz.linhas; i++) {
        for (int j = 0; j < matriz.colunas; j++) {
            scanf("%lf", &matriz.elementos[i][j]);
        }
    }
    limparBuffer();

    return matriz;
}


void exibirMatriz(Matriz matriz) {
    printf("Matriz (%d x %d):\n", matriz.linhas, matriz.colunas);
    for (int i = 0; i < matriz.linhas; i++) {
        for (int j = 0; j < matriz.colunas; j++) {
            printf("%.2lf ", matriz.elementos[i][j]);
        }
        printf("\n");
    }
}


Matriz somarMatrizes(Matriz matrizA, Matriz matrizB) {
    Matriz resultado;
    if (matrizA.linhas == matrizB.linhas && matrizA.colunas == matrizB.colunas) {
        resultado.linhas = matrizA.linhas;
        resultado.colunas = matrizA.colunas;
        for (int i = 0; i < matrizA.linhas; i++) {
            for (int j = 0; j < matrizA.colunas; j++) {
                resultado.elementos[i][j] = matrizA.elementos[i][j] + matrizB.elementos[i][j];
            }
        }
    } else {
        printf("Erro: As matrizes devem ter o mesmo tamanho para adição.\n");
        resultado.linhas = 0;
        resultado.colunas = 0;
    }
    return resultado;
}


Matriz subtrairMatrizes(Matriz matrizA, Matriz matrizB) {
    Matriz resultado;
    if (matrizA.linhas == matrizB.linhas && matrizA.colunas == matrizB.colunas) {
        resultado.linhas = matrizA.linhas;
        resultado.colunas = matrizA.colunas;
        for (int i = 0; i < matrizA.linhas; i++) {
            for (int j = 0; j < matrizA.colunas; j++) {
                resultado.elementos[i][j] = matrizA.elementos[i][j] - matrizB.elementos[i][j];
            }
        }
    } else {
        printf("Erro: As matrizes devem ter o mesmo tamanho para subtração.\n");
        resultado.linhas = 0;
        resultado.colunas = 0;
    }
    return resultado;
}


Matriz multiplicarPorEscalar(Matriz matriz, double escalar) {
    Matriz resultado;
    resultado.linhas = matriz.linhas;
    resultado.colunas = matriz.colunas;
    for (int i = 0; i < matriz.linhas; i++) {
        for (int j = 0; j < matriz.colunas; j++) {
            resultado.elementos[i][j] = matriz.elementos[i][j] * escalar;
        }
    }
    return resultado;
}


Matriz multiplicarMatrizes(Matriz matrizA, Matriz matrizB) {
    Matriz resultado;
    if (matrizA.colunas == matrizB.linhas) {
        resultado.linhas = matrizA.linhas;
        resultado.colunas = matrizB.colunas;
        for (int i = 0; i < matrizA.linhas; i++) {
            for (int j = 0; j < matrizB.colunas; j++) {
                resultado.elementos[i][j] = 0;
                for (int k = 0; k < matrizA.colunas; k++) {
                    resultado.elementos[i][j] += matrizA.elementos[i][k] * matrizB.elementos[k][j];
                }
            }
        }
    } else {
        printf("Erro: O número de colunas da matriz A deve ser igual ao número de linhas da matriz B para multiplicação.\n");
        resultado.linhas = 0;
        resultado.colunas = 0;
    }
    return resultado;
}


int main() {
    int menu1; 

    while (1) { 
        printf("\n----- Menu Principal -----\n");
        printf("1. Calculadora Completa\n");
        printf("2. Questões Matemáticas\n");
        printf("3. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &menu1);
        limparBuffer();

        switch (menu1) {
            case 1: { 
                int escolha;
                Matriz matrizA, matrizB, resultado;

                printf("\n----- Calculadora de Matrizes -----\n");
                printf("1. Adição de Matrizes\n");
                printf("2. Subtração de Matrizes\n");
                printf("3. Multiplicação por Escalar\n");
                printf("4. Multiplicação de Matrizes\n");
                printf("Digite sua escolha: ");
                scanf("%d", &escolha);
                limparBuffer();

                switch (escolha) {
                    case 1: 
                        printf("Digite a primeira matriz:\n");
                        matrizA = lerMatriz();
                        printf("Digite a segunda matriz:\n");
                        matrizB = lerMatriz();
                        resultado = somarMatrizes(matrizA, matrizB);
                        if (resultado.linhas > 0 && resultado.colunas > 0) {
                            printf("\nResultado da adição das matrizes:\n");
                            exibirMatriz(resultado);
                        }
                        break;
                    case 2: 
                        printf("Digite a primeira matriz:\n");
                        matrizA = lerMatriz();
                        printf("Digite a segunda matriz:\n");
                        matrizB = lerMatriz();
                        resultado = subtrairMatrizes(matrizA, matrizB);
                        if (resultado.linhas > 0 && resultado.colunas > 0) {
                            printf("\nResultado da subtração das matrizes:\n");
                            exibirMatriz(resultado);
                        }
                        break;
                    case 3: 
                        printf("Digite a matriz:\n");
                        matrizA = lerMatriz();
                        double escalar;
                        printf("Digite o escalar:\n");
                        scanf("%lf", &escalar);
                        resultado = multiplicarPorEscalar(matrizA, escalar);
                        printf("\nResultado da multiplicação da matriz por %.2lf:\n", escalar);
                        exibirMatriz(resultado);
                        break;
                    case 4: 
                        printf("Digite a primeira matriz:\n");
                        matrizA = lerMatriz();
                        printf("Digite a segunda matriz:\n");
                        matrizB = lerMatriz();
                        resultado = multiplicarMatrizes(matrizA, matrizB);
                        if (resultado.linhas > 0 && resultado.colunas > 0) {
                            printf("\nResultado da multiplicação das matrizes:\n");
                            exibirMatriz(resultado);
                        }
                        break;
                    default:
                        printf("Opção inválida.\n");
                        break;
                }
                break; 
            }
        }
    }
}
