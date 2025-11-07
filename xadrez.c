#include <stdio.h>

char upper(char letter);
int strLen(char *str);
int comparaDuasStringCaseInsensitive(char *string1, char *string2);

void moveTorre();
void moveBispo();
void moveRainha();

void moverCima();
void moverBaixo();
void moverEsquerda();
void moverDireita();
void moverDiagonalDireitaCima();

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int numMovimentacaoTorre = 5;
int numMovimentacaoBispo = 5;
int numMovimentacaoRainha = 8;

int main()
{
    // Nível Novato - Movimentação das Peças
    // Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.

    // Implementação de Movimentação do Bispo
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.

    // Implementação de Movimentação da Torre
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.

    // Implementação de Movimentação da Rainha
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.

    // Nível Aventureiro - Movimentação do Cavalo
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.

    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.

    // aqui ira simular a movimentação da torre (5 casos para a esquerda)

   inicia();
    
    return 0;
}

void inicia(){
     char inputUsuario[100];
    printf("Insira um valor para a peça para a qual deseja saber o tipo de movimentação\n");
    scanf("%s", inputUsuario); 

    if (comparaDuasStringCaseInsensitive(inputUsuario, "torre") == 1)
    {
        moveTorre();
        return;
    }

    if(comparaDuasStringCaseInsensitive(inputUsuario, "bispo") == 1) {
        moveBispo();
        return; 
    };

    if(comparaDuasStringCaseInsensitive(inputUsuario, "rainha") == 1){
        moveRainha();
        return; 
    }

    printf("Nenhuma das opções que você escolheu são disponíveis\n\n\n");
    inicia();
}

void moveTorre()
{

    for (int i = 0; i < numMovimentacaoTorre; i++)
    {
        moverEsquerda();
    }

}

void moveBispo()
{

    int acc = 0;
    while (acc < numMovimentacaoBispo)
    {
        moverDiagonalDireitaCima();
        acc++;
    }
}

void moveRainha()
{
    int accDoWhile = 0;

    do
    {
        moverEsquerda();
        accDoWhile++;

    } while (numMovimentacaoRainha > accDoWhile);
}

void moverCima()
{
    printf("Cima\n");
}

void moverBaixo()
{
    printf("Baixo\n");
}

void moverEsquerda()
{
    printf("Esquerda\n");
}

void moverDireita()
{
    printf("Direita\n");
}

void moverDiagonalDireitaCima()
{
    printf("Direita, Cima\n");
}

int comparaDuasStringCaseInsensitive(char *string1, char *string2)
{
    if (strLen(string1) != strLen(string2))
    {
        return 0;
    }

    for (int i = 0; i < strLen(string1); i++)
    {
        if (upper(string1[i]) != upper(string2[i]))
        {
            return 0;
        }
    }

    return 1;
}

int strLen(char *str)
{
    int pos = 0;
    while (str[pos] != '\0')
    {
        pos++;
    }
    return pos;
}

char upper(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
    {
        return letter;
    }

    else if (letter >= 'a' && letter <= 'z')
    {
        return letter - ('a' - 'A');
    }

    return letter;
}