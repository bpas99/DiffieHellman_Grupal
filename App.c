#include <stdio.h> 

int main(void) {
    //Primero llamamos a esta funcion para reiniciar el calculo de numeros aleatorios
    srand (time(NULL));
    // Creamos un numero x aleatorio
    int x = rand();
    int y;
    int k = 0;

	printf("Send the number X: %d to your partner.\n",x);
    printf("Enter the Y number that your partner has sent you:");
    scanf(" %d",&y);
	printf("The shared secret key is:: %d.\n",k);

	return(0); 
}

int mod_exp(int b, int e, int p)
{
    int i, x, power;
    x = 1;
    power = b % p;
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