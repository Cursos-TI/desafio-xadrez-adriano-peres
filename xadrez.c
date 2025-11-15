#include <stdio.h>

char upper(char letter);
int strLen(char *str);
int comparaDuasStringCaseInsensitive(char *string1, char *string2);

void moveTorre();
void moveBispo();
void moveRainha();
void moveCavalo();

void moveTorreRecursivo(int casasRestantes);
void moveRainhaRecursivo(int casasRestantes);
void moveBispoRecursivo(int casasRestantes);
void moveBispoComLoopsAninhados();

void moverCima();
void moverBaixo();
void moverEsquerda();
void moverDireita();

void inicia();

int numMovimentacaoTorre = 5;
int numMovimentacaoBispo = 5;
int numMovimentacaoRainha = 8;

int numMovimentoCavaloVertical = 2;
int numMovimentoCavaloHorizontal = 1;

int main()
{
   inicia();

   int unsigned ad;
   printf("sizeof is %d", &ad);
    
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

    if(comparaDuasStringCaseInsensitive(inputUsuario, "cavalo") == 1){
        moveCavalo();
        return;
    }

    printf("Nenhuma das opções que você escolheu são disponíveis\n\n\n");
    inicia();
}

void moveTorreRecursivo(int casasRestantes)
{
    if (casasRestantes <= 0)
    {
        return;
    }
    moverEsquerda();
    moveTorreRecursivo(casasRestantes - 1);
}

void moveTorre()
{
    printf("\nMovimento da Torre (Recursivo):\n");
    moveTorreRecursivo(numMovimentacaoTorre);
}

void moveBispoRecursivo(int casasRestantes)
{
    if (casasRestantes <= 0)
    {
        return;
    }
    moverCima();
    moverDireita();
    moveBispoRecursivo(casasRestantes - 1);
}

void moveBispoComLoopsAninhados()
{
    int i, j;
    for (i = 0; i < numMovimentacaoBispo; i++)
    {
        moverCima();
        for (j = 0; j < 1; j++)
        {
             moverDireita();
        }
    }
}

void moveBispo()
{
    printf("\nMovimento do Bispo (Recursivo):\n");
    moveBispoRecursivo(numMovimentacaoBispo);

    printf("\nMovimento do Bispo (Loops Aninhados):\n");
    moveBispoComLoopsAninhados();
}

void moveRainhaRecursivo(int casasRestantes)
{
    if (casasRestantes <= 0)
    {
        return;
    }
    moverEsquerda();
    moveRainhaRecursivo(casasRestantes - 1);
}

void moveRainha()
{
    printf("\nMovimento da Rainha (Recursivo):\n");
    moveRainhaRecursivo(numMovimentacaoRainha);
}

void moveCavalo()
{
    printf("\nMovimento do Cavalo (Loops Complexos):\n");
    int vertical, horizontal;

    for (vertical = 0; vertical < numMovimentoCavaloVertical; vertical++)
    {
        if (vertical < numMovimentoCavaloVertical - 1)
        {
            moverCima();
            continue;
        }

        moverCima();

        for (horizontal = 0; horizontal < numMovimentoCavaloHorizontal; horizontal++)
        {
            moverDireita();
            break;
        }
    }
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