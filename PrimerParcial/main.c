#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 4

typedef struct{
	int id;
	char procesador[20];
	char marca[20];
	float precio;
}eNotebook;

float aplicarDescuento(float precio);
int contarCaracteres(char cadena[], char caracter);
void ordenarPorMarcayPrecio(eNotebook notebooks[], int tamNote);

int main() {

	float precio = 400;
	float resultado;
	char nombre[20];
	int cantidadCaracter;
	eNotebook listaN[TAM] =
	{
        {1000, "Intel", "Core i5", 20000},
        {1001, "AMD", "Sempron", 35000},
        {1002, "AMD", "Athlon 64", 40000},
        {1003, "Intel", "Core i3", 50000}
    };

    //1
	resultado = aplicarDescuento(precio);

    //2
	strcpy(nombre, "Franco");

	cantidadCaracter = contarCaracteres(nombre, 'o');

    //3
	ordenarPorMarcayPrecio(listaN, TAM);


	//1
	printf("%.2f\n\n", resultado);

	//2
	printf("Cantidad caracter %d\n\n", cantidadCaracter);

	//3
	printf("ID       Procesador        Marca      Precio\n\n");
	for(int i = 0; i <TAM; i++)
	{
		printf("%d    %10s    %10s   $ %.2f\n", listaN[i].id, listaN[i].procesador, listaN[i].marca, listaN[i].precio);
	}

	return 0;
}

float aplicarDescuento(float precio)
{
	float resultado;

	resultado = precio - (precio * 5 / (float)100);

	return resultado;
}

int contarCaracteres(char cadena[], char caracter)
{
	int contador = 0;

	for(int i = 0; cadena[i] != '\0'; i++)
	{
		if(cadena[i] == caracter)
		{
			contador++;
		}
	}
	return contador;
}

void ordenarPorMarcayPrecio(eNotebook notebooks[], int tamNote)
{
	eNotebook auxNotebook;
	for(int i = 0; i < tamNote-1; i++)
	{
		for(int j = i + 1; j < tamNote; j++)
		{
			if(strcmp(notebooks[i].marca, notebooks[j].marca) > 0)
			{

				auxNotebook = notebooks[i];
				notebooks[i] = notebooks[j];
				notebooks[j] = auxNotebook;
			}
			else if(strcmp(notebooks[i].marca, notebooks[j].marca) == 0 && notebooks[i].precio < notebooks[j].precio)
			{
				auxNotebook = notebooks[i];
				notebooks[i] = notebooks[j];
				notebooks[j] = auxNotebook;
			}

		}
	}
}
