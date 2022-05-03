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

*/

#include <stdio.h>
#include<string.h>

//#define nmax 10

	typedef struct STOCK {

		char codi[30];
		char descripcio[15];
		int quantitat;
		int preu;

	} stck;




int main(){

	int n=1;

	while(n!=0){

		printf("-----------------------------------------------------------\n");	
		printf("\n");
		printf("   Selecciona una opción.");
		printf("\n\n");
	
		printf("   1.-Importar registros desde un fichero. \n");
	
		printf("   2.-Mostrar productos con precio > 15€. \n");

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
	
		case 1: 
			
			printf("\n");
			break;

		case 2: 
s
			printf("\n");
			break;

		case 3: 
				

			printf("\n");
			
			break;
			
		case 4: 
			
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
