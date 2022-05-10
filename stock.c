/*

1.-Una tenda de roba té les dades dels seus productes en l’arxiu STOCK.TXT. Els camps que conté aquest fitxer són:  Codi, Descripció, Quantitat i Preu.
 
    a) Crea  un tipus de dades (typedef) amb l’estructura adequada per a aquest exercici. El typedef s’anomenarà STOCK.
	Nota: El camp Codi serà alfanumèric (utilitzarem una cadena per guardar-ho)
 
	Genera manualment un fitxer amb les dades de tots els camps amb almenys 5 registres.

    b) Realitza una funció que carregui els registres del fitxer en un vector d’estructures de tipus STOCK.

    c) Realitza una funció que llisti per pantalla tots els productes amb un preu superior a 15 euros

    d) Realitza una funció que busqui  un producte donat un codi i mostri per pantalla,  en cas que el producte es trobi, tots els camps del producte

    e) Realitza una funció que guardi els productes que tinguin un stock inferior a 5 en un altre fitxer anomenat  STOCK5.TXT

    f) Realitza una funció que guardi els productes el preu dels quals sigui superior a 10 euros  i el seu stock superior a 100, en un fitxer anomenat Productes.txt

    g) Afegeix a l'arxiu stock.txt un article més. Demana a l'usuari que introdueixi les dades i afegeix-les al final del fitxer.


	FILE:

	00000000 50 10 camiseta
	00000001 35 50 sudadera
	00000002 20 101 botas
	00000003 2 16 gorra		
	00000004 100 11 gafas
	00000005 102 11 zapatillas
	00000006 2 2 tela	 

*/


/*25 mayo = posible fecha de exámen;

crear vecttos num con 3 posiciones inicializado a 0, es el um de registros q tengo en la fila de la matriz. 
ir al fichero y leemos la posición.

scanf 1 leer operador
scanf 2
a[ope[num[ope]]]
num[ope]++;
función mostrar=también por filas

V A[3][NMAX] = DEFINIR MATRIZ

*/



#include <stdio.h>
#include<string.h>

#define nmax 15


	typedef struct STOCK {

		char codi[30];
		int quantitat;
		int preu;
		char descripcio[15];

	} stck;

int cargar(stck A[], int *num, char nombre_fichero[]);

void mostrar(stck A[], int num);

void buscar(stck A[], int num, char codiBuscar[]);

void guardar(stck A[]);

int main(){

	int n=1, num, opcio, j; 

	stck A[nmax];

	char nombre_fichero[12], codiBuscar[30];

	FILE *f;

	while(n!=0){

		printf("-----------------------------------------------------------\n");	
		printf("\n");
		printf("   Selecciona una opción.");
		printf("\n\n");
	
		printf("   1.-Importar registros desde un fichero. \n");
	
		printf("   2.-Mostrar productos con precio superior a 15€. \n");

		printf("   3.-Buscar producto por código y mostrar por pantalla. \n"); //usar strcmp;
		
		printf("   4.-Guardar productos con stock < 5 en fichero. \n"); //file=STOCK5.TXT
		
		printf("   5.-Guardar productos precio > 10€ && stock > 100. \n"); //file=Productes.txt;

		printf("   6.-Añadir producto al stock. \n"); 
		//Afegeix a l'arxiu stock.txt un article més. Demana a l'usuari que introdueixi les dades i afegeix-les al final del fitxer.

		printf("   0.-Salir. \n");
		
		printf("\n");
		printf("-----------------------------------------------------------\n");	
	
		scanf("%d", &n);

		printf("\n");
	
	switch(n){
	
		case 0: printf("Bye!! \n");
		
		break;
	
		case 1: printf("Introducir los datos desde un fichero. \n");
				
			printf("Indica el nombre del fichero incluyendo la extensión. \n");
				
				scanf("%s", nombre_fichero);

				

			cargar(A, &num, nombre_fichero);

			printf("\n");	
			
			break;

		case 2: mostrar(A, num);

			printf("\n");
			break;

		case 3: printf("¿Qué código quieres buscar? \n");
			scanf("%s", codiBuscar); 


			buscar(A, num, codiBuscar);
				

			printf("\n");
			
			break;
			
		case 4: guardar(A);
			
			printf("\n");
			
			break;
			
		case 5: 
			
		
			printf("\n");
			
			break;
			
		case 6: 
			
		
		
			printf("\n");
			
		
			break;

		


		default: printf("Opción incorrecta. \n");
	
	
		}
	
	}

}



int cargar(stck A[], int *num, char nombre_fichero[]){

		int i;
		
		FILE *f;

		f=fopen(nombre_fichero, "r");

		
			if(f==NULL){
	
			return -1;			
			
			} else {
		
			for(i=0;feof(f)==0;i++){

			fscanf (f, "%s  %d  %d %s", A[i].codi, &A[i].quantitat, &A[i].preu, A[i].descripcio);
						
			}	

			
		*num=i-1;

		fclose (f);
				
			
		}

				
}

void mostrar(stck A[], int num){

	int i;
		printf("------------------------------------ \n");
		printf("Productos con precio inferior a 15€: \n");
		printf("------------------------------------ \n");		

			for(i=0;i<num;i++){

				if(A[i].preu > 15){

				printf("Código: %s, Cantidad: %d, Precio: %d, Descripción: %s. \n", A[i].codi, A[i].quantitat, A[i].preu, A[i].descripcio);		
		
				}

			}

}

void buscar(stck A[], int num, char codiBuscar[]){


	int i=0, res;

		while(strcmp(A[i].codi, codiBuscar)!=0){
		
			
				i++;


				if(i==num){
			
				res = -1;
				
				} else {
			
				res = i;
			
				}
				
				

				if (res == i) {

					printf("Código: %s, Cantidad: %d, Precio: %d, Descripción: %s. \n", A[i].codi, A[i].quantitat, A[i].preu, A[i].descripcio);
						
		
				} else {

					printf("El código introducino no corresponde a ningún producto. \n ");
				}
				
				
		}

}



void guardar(stck A[]){

	
		int i, num;
	
		FILE *f;

		f=fopen("STOCK5.TXT", "w");
		
			
			for(i=0;feof(f)==0;i++){

				if(A[i].quantitat < 5){


					fprintf(f, "Código: %s, Cantidad: %d, Precio: %d, Descripción: %s. \n", A[i].codi, A[i].quantitat, A[i].preu, A[i].descripcio);
					

			}

			num=i-1;

			fclose (f);

			}


}
