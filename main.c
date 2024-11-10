#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cpf.h"

void CriarCpf(){
    printf("Digite os primeiro 9 digitos do cpf\n> ");
    char input[10];
    scanf("%9s", input);

    PrintCpf(GetCpf(input));
}

void validarCpf(){
    printf("Digite o cpf\n>");
    char input[12];
    scanf("%11s", input);

    int r = CpfValid(input);

    printf((r == 0) ? "verdadeiro" : "falso");
}

void GenerateCpf(){
    char* rCpf = malloc(10);
    rCpf[9] = '\0';
    srand(time(NULL));
    for(int i = 0; i < 9; i++){
        rCpf[i] = (rand() % 10) + '0';
    }

    PrintCpf(GetCpf(rCpf));

    free(rCpf);
}

int main()
{
    int op = 0;

    printf("1 - Criar cpf; 2 - validar cpf; 3 - cpf aleatorio ; 4 - sair\n> ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        CriarCpf();
        break;
    case 2:
        validarCpf();
        break;
    case 3:
        GenerateCpf();
        break;
    case 4:
        return EXIT_SUCCESS;

    default:
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}