#include<stdio.h>


void coleta_operandos(int qtd, int* num1, int* num2)
{
    printf("Digite o primeiro operando:");
    scanf("%d%*c", num1);

    if (qtd == 2)
    {
        printf("Digite o segundo operando:");
        scanf("%d%*c", num2);
    }
}

int soma(int num1, int num2)
{
    return num1 + num2;
}

int subtracao(int num1, int num2)
{
    return num1 - num2;
}

int multiplicacao(int num1, int num2)
{
    int res = 0;
    for(int i = 0; i < num1; i = soma(i, 1))
        res = soma(res, num2);

    return res;
}

int divisao(int num1, int num2)
{
    int aux = num1;
    int cont = 0;
    while(subtracao(aux, num2) >= 0)
    {
        aux = subtracao(aux, num2);
        cont = soma(cont, 1);
    }

    return cont;
}

int main(void)
{
    char op;
    int num1, num2, res, num_op;

    while(1)
    {
        printf("Digite a operacao desejada (+,  0):");
        scanf("%c%*c", &op);
        num_op = 2;

        switch (op)
        {
        case '+':
            coleta_operandos(num_op, &num1, &num2);
            res = soma(num1, num2);
            break;
        

        case '-':
            coleta_operandos(num_op, &num1, &num2);
            res = subtracao(num1, num2);
            break;
        
        case '*':
            coleta_operandos(num_op, &num1, &num2);
            res = multiplicacao(num1, num2);
            break;
        
        case '/':
            coleta_operandos(num_op, &num1, &num2);
            res = divisao(num1, num2);
            break;

         case '0':
            return 0;

        default:
            printf("Operacao nao suportada. Digita novamente");
        }

        if (num_op == 2)
            printf("%d %c %d = %d\n", num1, op, num2, res);
        else if (num_op == 1)
            printf("%c %d = %d\n", num1, op, res);
    }

    return 0;
}