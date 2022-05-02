/*
para esta práctica es necesario crear un fichero para cargar con la función cargar: nombre_fichero.txt
	
	Nombre: L_V_Li. Teléfono: 97888888. Edad: 46
	Nombre: L_Vgow. Teléfono: 97888888. Edad: 36  
	Nombre: L_V_L. Teléfono: 97888888. Edad: 26  

*/

#include <stdio.h>
#include <string.h>

#define nmax 10

	typedef struct AGENDA {

		char nom[30];
		//este dato es char pq no se modifica; como un DNI... no varia;		
		char telefon[15];
		int edad;

	}amigos;

//prototipo de las funciones;

void introducir(amigos A[], int num);

void imprimir (amigos A[], int num);

int buscar(amigos A[], int num, int opcio, char cadena_buscar[]);

int ordenar(amigos A[], int num, int opcio);

void insertar(amigos A[], int *num, int opcio, amigos B);

int eliminar(amigos A[], int *num, int opcio, char cadena_eliminar[]);

void guardar(amigos A[], int num, char nombre_fichero[]);

int cargar(amigos A[], int *num, char nombre_fichero[]);


int main(){

	int num, i, res;
	int n=1;
	int opcio;
	char cadena_buscar[nmax];
	char contacto[nmax];
	char nombre_fichero[12];

	FILE *f;

	amigos A[nmax], B;
	

	
			printf("10 contactos. ¿Cuántos contactos quieres incluir en la agenda? \n");
			scanf("%d", &num);
			
			if(num > 1){
			
			printf("Vas a agregar %d contactos. \n\n", num);
			printf("Te queda espacio para %d contactos \n", nmax-num);

			} else {
			
			printf("Vas a agregar un contacto. \n");
			printf("Te queda espacio para %d contactos \n", nmax-num);
			
			}
	


		while(n!=0){

		printf("-----------------------------------------------------------\n");	
		printf("\n");
		printf("   Selecciona una opción.");
		printf("\n\n");
	
		printf("   1.-Crear contactos. \n");
	
		printf("   2.-Mostrar contactos. \n");

		printf("   3.-Buscar contactos. \n");
		
		printf("   4.-Ordenar contactos. \n");
		
		printf("   5.-Agregar un contacto. \n");

		printf("   6.-Eliminar un contacto. \n");

		printf("   7.-Guardar contactos en fichero. \n");

		printf("   8.-Cargar. \n");
		
		printf("   0.-Salir de la agenda. \n");
		
		printf("\n");
		printf("-----------------------------------------------------------\n");	
	
		scanf("%d", &n);

		printf("\n");
	
	switch(n){
	
		case 0: printf("B y e. \n");
		break;
	
		case 1: introducir(A, num);
			
			printf("\n");
			break;

		case 2: imprimir(A, num);

			printf("\n");
			break;

		case 3: printf("-------------------------\n");
			printf("--  Elige una opción  ---\n");
			printf("-------------------------\n");
			printf("\n");
			printf("  1. Buscar por nombre.\n");
			printf("  2. Buscar por teléfono.\n");
			
			scanf("%d", &opcio);
			
			
			if(opcio==1){
			
			printf("Indica el nombre del contacto. \n");
			
			} else {
			
			printf("Indica el teléfono del contacto. \n");
			
			
			}
			
			scanf("%s", contacto);
			
			res = buscar(A, num, opcio, contacto);
		
			
			if(res==-1){
					printf("El contacto no existe.\n");
				}
				
				else {
					
					printf("El contacto aparece en la posición %d de la agenda.\n",res+1);
				}	

			printf("\n");
			
			break;
			
		case 4: printf("-------------------------\n");
			printf("--  Elige una opción  ---\n");
			printf("-------------------------\n");
			printf("\n");
			printf("  1. Ordenar por nombre.\n");
			printf("  2. Ordenar por edad.\n");
			
			scanf("%d", &opcio);
			
			ordenar(A,num,opcio);
			imprimir(A,num);
			
			printf("\n");
			
			break;
			
		case 5: printf("Agenda ordenada por nombre(1) o desordenada(2)?\n");
			scanf("%d", &opcio);
		
		
			printf("Dime el nombre del contacto. \n");
			scanf("%s", B.nom);
			
			printf("Dime el teléfono de %s. \n", B.nom);
			scanf("%s", B.telefon);
			
			printf("Dime la edad de %s. \n", B.nom);
			scanf("%d", &B.edad);
			
			
			insertar(A, &num, opcio, B);
			
		
			printf("\n");
			
			break;
			
		case 6: printf("Buscar por nombre, pulsa 1.\n");
			printf("Buscar por teléfono, pulsa 2.\n");
			
			scanf("%d", &opcio);
			
			if(opcio==1){
			
			printf("Indica el nombre del contacto.\n");
			
			scanf("%s",contacto);
			
			
			} else {
			
			printf("Indica el teléfono del contacto.\n");
			
			scanf("%s",contacto);
			
			}
			
			
			
			res=eliminar(A, &num, opcio, contacto);
			
			if(res==-1){
			
				printf("El contacto: no aparece en la agenda.\n");
			}
			
			else {
				printf("Ha eliminado el contacto: que aparecían en la entrada:  %d.\n", res+1);
			}
			
			break;
		
			printf("\n");
			
		
			break;

		case 7: printf("Indica el nombre del fichero para guardar los datos. \n");

			scanf("%s", nombre_fichero);

			printf("¿Cúantos contactos vas a guardar? \n");
			
			scanf("%d", &num);			
			
			guardar(A, num, nombre_fichero);

			printf("\n");

			
			
			break;

		case 8: printf("Selecciona una opción: \n\n");
			printf("1. Introducir los datos mediante el teclado. \n");
			printf("2. Introducir los datos desde un fichero. \n");
				
			scanf("%d", &opcio);

			if(opcio==1){
					

					while (fscanf (f, "%s, %s, %d", A[i].nom, A[i].telefon, &A[i].edad) > 0){

				
						fprintf(f,"Nombre: %s. Teléfono: %s. Edad: %d. \n", A[i].nom, A[i].telefon, A[i].edad);			
			
					}

				

			} else {

				printf("Indica el nombre del fichero. \n");
				scanf("%s", nombre_fichero);



			}

			cargar(A, &num, nombre_fichero);

			printf("\n");
			
			break;


		default: printf("Opción incorrecta. \n");
	
		}
	
	}

	
}

void introducir(amigos A[], int num) {

	int i;


		for(i=0;i<num;i++){

			printf("Dime el nombre del contacto número %d \n", i+1);
			scanf("%s", A[i].nom);
			
			printf("Dime el teléfono de %s. \n", A[i].nom);
			scanf("%s", A[i].telefon);
			
			printf("Dime la edad de %s. \n", A[i].nom);
			scanf("%d", &A[i].edad);		
			//while(getchar()!='\n');
		
		}

}

//Declaración de las funciones;

void imprimir (amigos A[], int num){

	int i;
		
		printf("Los datos de tus contacto son: \n");
		printf("------------------------------ \n");		

			for(i=0;i<num;i++){

			printf("Nombre: %s, Teléfon: %s, Edad: %d. \n", A[i].nom, A[i].telefon, A[i].edad);		
		
			}
	

}


int buscar(amigos A[], int num, int opcio, char cadena_buscar[]){	
	
	
	int i=0;
	
		if(opcio==1){
	
			while(i<num && strcmp(A[i].nom, cadena_buscar)!=0){
			

				i++;
			}
			
				if(i==num){
			
				return -1;
				}
			
				else {
			
				return i;
			
				}
			
			} else {
		
		
			while(i<num && strcmp(A[i].telefon, cadena_buscar)!=0){
			
			i++;
			
			}
		
		if(i==num){
		
		return -1;
		}
		
		else {
			
		return i;
		
		}
	}
}

int ordenar(amigos A[], int num, int opcio){

	int i=0, j, canvi=1;
	amigos aux;
	
	if(opcio==1){
		while(canvi==1){
			canvi=0;
			for(j=0;j<num-i-1;j++){
				if(strcmp(A[j].nom,A[j+1].nom)>0){
					aux=A[j];
					A[j]=A[j+1];
					A[j+1]=aux;
					canvi=1;
				}
			}
			i++;
		}
	}
	else{
		while(canvi==1){
			canvi=0;
			for(j=0;j<num-i-1;j++){
				if(A[j].edad>A[j+1].edad){
					aux=A[j];
					A[j]=A[j+1];
					A[j+1]=aux;
					canvi=1;
				}
			}
			i++;
		}
	}

}

void insertar(amigos A[], int *num, int opcio, amigos B){

	int i,j;
		
	if(opcio==1){
		
		i=0;
		
		while(i<*num && strcmp(B.nom, A[i].nom)>0){
			i++;
		}
		
		for(j=*num;j>i;j--){
		
			A[j]=A[j-1];
		}
		
		A[i]=B;
		
		(*num)++;
	}
	
	else {
		i=*num;

		A[i]=B;
		
		(*num)++;
	}
}


int eliminar(amigos A[], int *num, int opcio, char cadena_eliminar[]){

	int i,j;
	
	i=buscar(A,*num, opcio, cadena_eliminar);
	
	if(i!=-1){
		for(j=i;j<*num;j++){
		
			A[j]=A[j+1];
		}
		
		(*num)--;
	}
	
	return i;

}

void guardar(amigos A[], int num, char nombre_fichero[]){

	
		int i;
	
		FILE *f;

		f=fopen(nombre_fichero, "w");
		
			
			for(i=0;i<num;i++){

				fprintf(f, "Nombre: %s. Teléfono: %s. \n", A[i].nom, A[i].telefon);

			}


		fclose(f);


}


int cargar(amigos A[], int *num, char nombre_fichero[]){

		int i;
		
		FILE *f;

		f=fopen(nombre_fichero, "r");

		
			if(f==NULL){

				printf("Error!!! \n");		
				return -1;			
			
			} else {
		
				for(i=0;feof(f)==0;i++){

					fscanf (f, "%s, %s, %d", A[i].nom, A[i].telefon, &A[i].edad);
				
			
				}	

			
		*num=i;

		fclose (f);
				
			
		}

		
}

