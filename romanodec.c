/*
# UC: 21048 - Física Geral 
# Ano 2022/23 - EFOLIO Global 
# - Conversor RomToDec 
# - UAb
# - Aluno: 2100927 - Ivo Baptista 
# 
#
# Programa em C que converte um número romano em decimal.
*/

#include <stdio.h>
#include <string.h>

//Função que converte um número romano para decimal.
int romToDec(char *rom)
{
    int dec = 0;
    int length = strlen(rom);

    // Ciclo por cada caractere do número romano.
    for (int i = 0; i < length; i++)
    {
        switch (rom[i])
        {
            // Verifica os caracteres e altera sumando e subtraindo os 
            //valor do decimal e avança para o caracter seguinte e volata a verificar.
            case 'I':
                if (rom[i+1] == 'V')
                {
                    dec += 4;
                    i++;
                }
                else if (rom[i+1] == 'X')
                {
                    dec += 9;
                    i++;
                }
                else
                {
                    dec+= 1;
                }
                break;

            case 'V':
                dec += 5;
                break;

            case 'X':
                if (rom[i+1] == 'L')
                {
                    dec += 40;
                    i++;
                }
                else if (rom[i+1] == 'C')
                {
                    dec += 90;
                    i++;
                }
                else
                {
                    dec += 10;
                }
                break;

            case 'L':
                dec += 50;
                break;

            case 'C':
                if (rom[i+1] == 'D')
                {
                    dec += 400;
                    i++;
                }
                else if (rom[i+1] == 'M')
                {
                    dec+= 900;
                    i++;
                }
                else
                {
                    dec += 100;
                }
                break;

            case 'D':
                dec += 500;
                break;

            case 'M':
                dec += 1000;
                break;

            default:
                printf("Erro este símbolo não é permitido: %c\n", rom[i]);
                return -1;
        }
    }

    return dec;
}
//função main
int main()
{
    //Declaraçâo de Variaveis
    char rom[100];
    int dec;
    //Introduzir o valor em Romano
    printf("Digite um número romano, este será convertido em decimal: ");
    scanf("%s", rom);

    //Atribui o valor da função a variavel dec
    dec = romToDec(rom);

    if (dec != -1)
    {
        //Mostra o valor em Decimal
        printf("O número decimal convertido é: %d\n", dec);
    }

    return 0;
}
