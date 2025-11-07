#include <stdio.h>

char upper(char letter);
int strLen(char *str);
int comparaDuasStringCaseInsensitive(char *string1, char *string2);

void moveTorre();
void moveBispo();
void moveRainha();
void moveCavalo();

void moverCima();
void moverBaixo();
void moverEsquerda();
void moverDireita();
void moverDiagonalDireitaCima();

void inicia();

int numMovimentacaoTorre = 5;
int numMovimentacaoBispo = 5;
int numMovimentacaoRainha = 8;

int numMovimentoCavaloVertical = 2;
int numMovimentoCavaloHorizontal = 1;

int main()
{
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

    if(comparaDuasStringCaseInsensitive(inputUsuario, "cavalo") == 1){
        moveCavalo();
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

void moveCavalo()
{
    printf("\n");

    for (int i = 0; i < numMovimentoCavaloVertical; i++)
    {
        moverBaixo();

        if (i == numMovimentoCavaloVertical - 1)
        {
            int j = 0;
            while (j < numMovimentoCavaloHorizontal)
            {
                moverEsquerda();
                j++;
            }
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