#include<stdio.h>
#include<stdlib.h>

#define tam 50

//Prototipo de las funciones utilizadas
int menu(), cargarViajes(char tipoVehiculo[], float recorridoVehiculo[], float precioVehiculo[]);
void mostrarViajes(char tipoVehiculo[], float recorridoVehiculo[], float precioVehiculo[], int finCarga);
void kmxVehiculo(char tipoVehiculo[], float recorridoVehiculo[], int finCarga);
void kmTotales(char tipoVehiculo[], float recorridoVehiculo[], int finCarga);
void precioxVehiculo(char tipoVehiculo[], float recorridoVehiculo[], float precioVehiculo[], int finCarga);
void totalGeneral(char tipoVehiculo[], float recorridoVehiculo[], float precioVehiculo[], int finCarga);

//Programa propiamente dicho
int main()
{
	char tipoVehiculo[tam];
	float recorridoVehiculo[tam], precioVehiculo[tam];
	int opcion, finCarga=0;
	
	do
	{
		opcion = menu();
		
		switch(opcion)
		{
			case 1:
				finCarga = cargarViajes(tipoVehiculo, recorridoVehiculo, precioVehiculo);
				break;
			case 2:
				mostrarViajes(tipoVehiculo, recorridoVehiculo, precioVehiculo, finCarga);
				break;
			case 3:
				kmxVehiculo(tipoVehiculo, recorridoVehiculo, finCarga);
				break;
			case 4:
				kmTotales(tipoVehiculo, recorridoVehiculo, finCarga);
				break;
			case 5:
				precioxVehiculo(tipoVehiculo, recorridoVehiculo, precioVehiculo, finCarga);
				break;
			case 6:
				totalGeneral(tipoVehiculo, recorridoVehiculo, precioVehiculo, finCarga);
				break;
			case 7:
				printf("\n\nGracias por elejir nuestro sistema de control de viajes!!!\n\n");
				system("pause");
				break;
			default:
				printf("\n\nOPCION INGRESADA ERRONEA\n");
				system("pause");
				break;
		}
	}while(opcion != 7); 
}

//Implementacion de las funciones
int menu()
{
	int opcion;
	
	system("cls");
	printf("TRABAJO PRACTICO: INT. A LA PROGRAMACION\n\n\n");
	printf("1- Cargar viajes del dia");
	printf("\n2- Mostrar viajes del dia");
	printf("\n3- Mostrar kilometros recorridos en el dia por un vehiculo");
	printf("\n4- Mostrar el total de kilometros recorridos por cada vehiculo en el dia");
	printf("\n5- Mostrar total de ingresos por vehiculo en el día");
	printf("\n6- Mostrar total general de ingresos");
	printf("\n7- Salir del sistema");
	printf("\n\nOpcion seleccionada: ");
	scanf("%d", &opcion);
	return opcion;
}

int cargarViajes(char tipoVehiculo[], float recorridoVehiculo[], float precioVehiculo[])
{
	int i=0;
	
	do
	{
		printf("\nIngrese el tipo de vehiculo(A-C-M-T-V o S para salir): ");
		fflush(stdin);
		scanf("%c", &tipoVehiculo[i]);
		switch(tipoVehiculo[i])
		{
			case 'A':
			case 'a':
			case 'C':
			case 'c':
			case 'M':
			case 'm':
			case 'T':
			case 't':
			case 'V':
			case 'v':
				printf("\nIngrese la cantidad de kilometros recorridos: ");
				fflush(stdin);
				scanf("%f", &recorridoVehiculo[i]);
				printf("\nIngrese el precio por kilometro: ");
				scanf("%f", &precioVehiculo[i]);
				i++;
				break;
			case 's':
			case 'S':
				tipoVehiculo[i] = ' ';
				break;
			default:
				printf("\nEL vehiculo ingresado es erroneo\n");
				system("pause");
				break;
		}
	}while(tipoVehiculo[i]!=' ');
	return i;
}

void mostrarViajes(char tipoVehiculo[], float recorridoVehiculo[], float precioVehiculo[], int finCarga)
{
	int i;
	
	printf("\n\nTipoVehiculo\tkmRecorridos\tPrecioTotal\n");
	for(i=0 ; i<finCarga; i++)
	{
		printf("%c\t\t%.1f\t\t%.1f\n", tipoVehiculo[i], recorridoVehiculo[i], recorridoVehiculo[i]*precioVehiculo[i]);
	}
	system("pause");
}

void kmxVehiculo(char tipoVehiculo[], float recorridoVehiculo[], int finCarga)
{
	int i, flag=0;
	float kmTotal=0;
	char tipoV;
	
	printf("\n\nIngrese un tipo de vehiculo: ");
	fflush(stdin);
	scanf("%c", &tipoV);
	printf("\nTipoVehiculo\t\tRecorrido\n");
	for(i=0 ; i<finCarga ; i++)
	{
		if(tipoV == tipoVehiculo[i])
		{
			flag=1;
			printf("%c\t\t\t%.1f\n", tipoVehiculo[i], recorridoVehiculo[i]);
			kmTotal = kmTotal + recorridoVehiculo[i];
		}
	}
	if(flag==1)
	{
		printf("\nKilometros totales\t%.1f\n", kmTotal);
		system("pause");
	}
	else
	{
		printf("\n\nEl tipo de vehiculo es erroneo o no realizo viajes, los tipos son A-C-M-T-V\n");
		system("pause");
	}
}

void kmTotales(char tipoVehiculo[], float recorridoVehiculo[], int finCarga)
{
	int i, flag=0;
	float recorridoTotal=0;
	
	printf("\n\nTipoVehiculo\tRecorrido\n");
	for(i=0 ; i<finCarga ; i++)
	{
		if(tipoVehiculo[i]=='a'||tipoVehiculo[i]=='A')
		{
			flag=1;
			printf("%c\t\t%.1f\n", tipoVehiculo[i], recorridoVehiculo[i]);
			recorridoTotal = recorridoTotal + recorridoVehiculo[i];
		}
	}
	if(flag==1)
	{
		printf("Total\t\t%.1f\n\n", recorridoTotal);
		recorridoTotal = 0;
		flag = 0;
	}
	for(i=0 ; i<finCarga ; i++)
	{
		if(tipoVehiculo[i]=='c'||tipoVehiculo[i]=='C')
		{
			flag=1;
			printf("%c\t\t%.1f\n", tipoVehiculo[i], recorridoVehiculo[i]);
			recorridoTotal = recorridoTotal + recorridoVehiculo[i];
		}
	}
	if(flag==1)
	{
		printf("Total\t\t%.1f\n\n", recorridoTotal);
		recorridoTotal = 0;
		flag = 0;
	}
	for(i=0 ; i<finCarga ; i++)
	{
		if(tipoVehiculo[i]=='m'||tipoVehiculo[i]=='M')
		{
			flag=1;
			printf("%c\t\t%.1f\n", tipoVehiculo[i], recorridoVehiculo[i]);
			recorridoTotal = recorridoTotal + recorridoVehiculo[i];
		}
	}
	if(flag==1)
	{
		printf("Total\t\t%.1f\n\n", recorridoTotal);
		recorridoTotal = 0;
		flag = 0;
	}
	for(i=0 ; i<finCarga ; i++)
	{
		if(tipoVehiculo[i]=='t'||tipoVehiculo[i]=='T')
		{
			flag=1;
			printf("%c\t\t%.1f\n", tipoVehiculo[i], recorridoVehiculo[i]);
			recorridoTotal = recorridoTotal + recorridoVehiculo[i];
		}
	}
	if(flag==1)
	{
		printf("Total\t\t%.1f\n\n", recorridoTotal);
		recorridoTotal = 0;
		flag = 0;
	}
	for(i=0 ; i<finCarga ; i++)
	{
		if(tipoVehiculo[i]=='v'||tipoVehiculo[i]=='V')
		{
			flag=1;
			printf("%c\t\t%.1f\n", tipoVehiculo[i], recorridoVehiculo[i]);
			recorridoTotal = recorridoTotal + recorridoVehiculo[i];
		}
	}
	if(flag==1)
	{
		printf("Total\t\t%.1f\n\n", recorridoTotal);
		recorridoTotal = 0;
		flag = 0;
	}
	system("pause");
}

void precioxVehiculo(char tipoVehiculo[], float recorridoVehiculo[], float precioVehiculo[], int finCarga)
{
	int i, flag=0;
	float precio, precioTotal=0;
	char tipoV;
	
	printf("\n\nIngrese un tipo de vehiculo: ");
	fflush(stdin);
	scanf("%c", &tipoV);
	printf("\nTipoVehiculo\t\tPrecioTotal\n");
	for(i=0 ; i<finCarga ; i++)
	{
		if(tipoV == tipoVehiculo[i])
		{
			flag = 1;
			precio = recorridoVehiculo[i]*precioVehiculo[i];
			printf("%c\t\t\t%.1f\n", tipoVehiculo[i], precio);
			precioTotal = precioTotal + precio;
		}
	}
	if(flag == 1)
	{
		printf("\nTotal\t\t\t%.1f\n", precioTotal);
		system("pause");
	}
	else
	{
		printf("\n\nEl tipo de vehiculo es erroneo o no realizo viajes, los tipos son A-C-M-T-V\n");
		system("pause");
	}
}

void totalGeneral(char tipoVehiculo[], float recorridoVehiculo[], float precioVehiculo[], int finCarga)
{
	int i;
	float kmTotal=0,precioTotal=0; 
	
	printf("\n\nTipoVehiculo\tRecorrido\tPrecioTotal\n");
	for(i=0 ; i<finCarga ; i++)
	{
		printf("%c\t\t%.1f\t\t%.1f\n", tipoVehiculo[i], recorridoVehiculo[i], precioVehiculo[i]*recorridoVehiculo[i]);
		kmTotal = kmTotal + recorridoVehiculo[i];
		precioTotal = precioTotal + (precioVehiculo[i]*recorridoVehiculo[i]);	
	}
	printf("TotalGeneral\t%.1f\t\t%.1f\n", kmTotal, precioTotal);
	system("pause");
}
