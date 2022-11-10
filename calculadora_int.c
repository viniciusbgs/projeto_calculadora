#include<stdio.h>


void coleta_operandos(int qtd, float* num1, float* num2)
{
    printf("Digite o primeiro operando:");
    scanf("%f%*c", num1);

    if (qtd == 2)
    {
        printf("Digite o segundo operando:");
        scanf("%f%*c", num2);
    }
}

float soma(float num1, float num2)
{
    return num1 + num2;
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
        
        case '0':
            return 0;
        
        default:
            printf("Operacao nao suportada. Digita novamente");
        }

        if (num_op == 2)
            printf("%d %c %d = %d\n", num1, op, num2, res);


    return 0;
}