#include "arrayUtilits.h"

int CpfDigit(int multplicationSumResult)
{
    int r = multplicationSumResult % 11;
    return (r > 9) ? 0 : r;
}

char *CpfRegion(int nineDigit)
{
    switch (nineDigit)
    {
    case 1:
        return "Distrito Federal, Goias, Mato Grosso, Mato Grosso do Sul e Tocantins";
    case 2:
        return "Amazonas, Para, Roraima, Amapa, Acre e Rondonia";
    case 3:
        return "Ceara, Maranhao e Piaui";
    case 4:
        return "Paraiba, Pernambuco, Alagoas e Rio Grande do Norte";
    case 5:
        return "Bahia e Sergipe";
    case 6:
        return "Minas Gerais";
    case 7:
        return "Rio de Janeiro e Espirito Santo";
    case 8:
        return "Sao Paulo";
    case 9:
        return "Parana e Santa Catarina";
    default:
        return "Rio Grande do Sul";
    }
}

int* GetCpf(char input[]) {
    int i;
    int* fullCpf = malloc(11 * sizeof(int));

    for (i = 0; i < 9; i++) {
        fullCpf[i] = input[i] - '0';
    }

    int* multplicationArray = malloc(9 * sizeof(int));
    for (i = 0; i < 9; i++) {
        multplicationArray[i] = i + 1;
    }

    int* multiplicationResult = MultTwoPointersArray(fullCpf, multplicationArray, 9);

    int sum = SumPointerArray(multiplicationResult, 9);
    fullCpf[9] = CpfDigit(sum);

    free(multplicationArray);
    free(multiplicationResult);

    multplicationArray = malloc(10 * sizeof(int));

    for (i = 0; i < 10; i++) {
        multplicationArray[i] = 0 + i;
    }

    multiplicationResult = MultTwoPointersArray(fullCpf, multplicationArray, 10);
    
    sum = SumPointerArray(multiplicationResult, 10);
    fullCpf[10] = CpfDigit(sum);  

    free(multplicationArray);
    free(multiplicationResult);

    return fullCpf;
}

int CpfValid(char input[]){
    int* inputCpf = malloc(11 * sizeof(int));
    int i = 0;
    
    for (i = 0; i < 11; i++) {
        inputCpf[i] = input[i] - '0';
    }

    int* realCpf = GetCpf(input);

    for (i = 0; i < 11; i++)
    {
        if(inputCpf[i] != realCpf[i])
        {
            free(realCpf);
            free(inputCpf);
            return 1;
        }
    }

    return 0;
}