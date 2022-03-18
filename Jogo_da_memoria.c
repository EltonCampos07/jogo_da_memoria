#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void mostrar_vetor (int x[10]){
    int cont;
    for (cont=0; cont<10; cont++){
        printf ("%d ", x[cont]);
    }
}

int Sorteio (int x[10]){
    int cont;
    for (cont=0; cont<10; cont++){
        x[cont] = 1 + rand () %10;
    }
    return x[10];
}

int main (void){
    int i, cont, x;
    int A[10], B[10];

    setbuf(stdout, NULL);
    srand(time(0));

    cont = 0;

    //Cria os números aleatorios
    Sorteio(A);

    printf ("Tenta memorizar os numeros sorteados!\n\n");

    //mostra os números sorteados
    mostrar_vetor (A);

    //Os valores sorteados serao mostrados na tela e, apos 3 segundos, os valores somem
    Sleep(3000);
    system ("cls");

    printf ("Agora eh sua vez! Informe a sequencia dos numeros sorteados.\n");

    //Nessa etapa, o programa solicita 10 numeros e eh feito um teste para validar os numeros informados pelo jogador

    for (i=0; i<10; i++){
        do{
            scanf ("%d", &x);
            if (x<=0||x>10){
                printf ("Valor invalido!! O valor digitado deve ser  entre 1 e 10\n");
            }
        } while (x<=0 || x>10);
        B[i] = x;
    }

    //Nessa etapa, o programa compara com os valores do vetor A e B e determina a pontuacao do jogador

    for (i = 0; i < 10; i++){
        if (A[i] == B [i]){
            cont++;
        }
    }

    //mostra os valores sorteados, os numeros digitados e a  portuacao final do jogador
    printf ("Os valores sorteados:\n");
    mostrar_vetor (A);

    printf ("\nOs valores digitados:\n");
    mostrar_vetor (B);

    printf ("\nA pontuacao do jogador: %d ponto(s)\n", cont);
    if (cont == 10){
        printf ("Parabens, voce acertou todos numeros sorteados!\nVoce eh bom nisso!!\n");
    }
    
    return EXIT_SUCCESS;
}

