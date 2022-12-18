#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Variables dadas en el ejercicio
    int p = 761;
    int r = 6;
    // Primero llamamos a esta funcion para reiniciar el calculo de numeros aleatorios
    srand(time(NULL));
    // Creamos un numero x aleatorio
    int e = (rand() % 5000 + 1);
    int y = 0;

    int x = mod_exp(r, e, p);

    printf("Send the number X: %d to your partner.\n", x);
    printf("Enter the Y number that your partner has sent you:");
    scanf(" %d", &y);
    int k = mod_exp(y, e, p);
    printf("The shared secret key is:: %d.\n", k);

    return (0);
}

int mod_exp(int r, int e, int p)
{
    int i, x, power;
    x = 1;
    power = r % p;
    for (i = 0; i < 8 * sizeof(int); i++)
    {
        if (e & 1)
        {
            x = (x * power) % p;
        }
        e >>= 1;
        power = (power * power) % p;
    }

    return x;
}