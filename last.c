/*25 mayo = posible fecha de exámen;
crear vector num con 3 posiciones inicializado a 0, es el num de registros q tengo en la fila de la matriz. 
ir al fichero y leemos la posición.

	scanf 1 leer operador
	scanf 2

	a[ope[num[ope]]]

	num[ope]++;

	función mostrar=también por filas

	V A[3][NMAX] = DEFINIR MATRIZ

	cada fila de m[][] pertenece a un operador.

*/

#include<stdio.h>

#define nmax 100

	typedef struct Ventas{

			char tlf[9];
			char cliente[40];
			int tipoContrato;

			}venta;


void cargar(venta A[][nmax]);



int main(){

 	int n=1, i, j;
	int operadora[3]={0,0,0};
	venta A[3][nmax];
 
	FILE*f;
	
	
	
 	while(n!=0){
 	
 		printf("-----------------------------------------------------------\n");	
		printf("\n");
		printf("   Selecciona una opción del menú.");
		printf("\n\n");
 	
 		printf("1 - Carga ventas desde fichero. \n");
 		
 		printf("2 - Introduce venta. \n");
 		
 		printf("3 - Muestra información de un cliente. \n"); //buscar por telf con strcmp; pedir operadora y pasar como parámetro.
 		
 		printf("4 - Muestra información de todos los clientes. \n");
 		
 		printf("5 - Dar de baja a un cliente. \n");
 		
 		printf("6 - ****. \n");
 		
 		printf("7 - Salir del programa con confirmación. \n");
 		
 		printf("\n");
		printf("-----------------------------------------------------------\n");
 		
 		
 		scanf("%d", &n);
 		printf("\n");
 	
 	
 	
 	}
 	
 	switch(n){
 	
 		case 0: printf("BYE! \n");
 		
 			break;
 		
 		case 1: //printf("Indica el nombre de la compañía. \n");

			cargar(A);


			printf("\n");

			break;
		
		case 2:

			

			printf("\n");

			break;



 		
 		default: printf("Opción incorrecta. \n");
 	
 	
 	
 	}


}

/*int cargar(venta A[][nmax]){


		int i, j;
		int operadora[3]={0,0,0};
		
		FILE *f=fopen("fichero.txt", "r");

				if(f==NULL){
	
					return -1;			
			
					} else {				

					for(i=0;i<3;i++){
						
						for(j=0;j<1;i++){
		
						fscanf(f,"%d", &operadora[i]);
				
						}
					}

					}	
		
					for(i=0;i<3;i++){

						for(j=0;feof(f)==0;j++){

						
							fscanf (f, "%s  %s  %d", A[i][j].tlf, A[i][j].cliente, &A[i][j].tipoContrato);
					
						}
					
					}

			for(i=0;i<3;i++){

				for(j=0;j<5;j++){

					fprintf(f,"Teléfono: %s, Cliente: %s, Tipo de contrato: %d. \n", A[i][j].tlf, A[i][j].cliente, A[i][j].tipoContrato);	

			
			}

			}
	

					
			

		fclose (f);
				
			
}*/

void cargar(venta A[][nmax]){



	int i, j;
	int operadora[3]={0,0,0};
	
	FILE *f=fopen("fi.txt", "r");

				
			/*if(f==NULL){
	
				return -1;			
			
				} else {*/				

				for(i=0;i<7;i++){
					
		
						fscanf(f,"%d", &operadora[i]);
							
				}

				printf("Fichero cargado \n");

								
					//mostrar para probar!
					for(i=0;i<7;i++){
						
						
						printf("valor de la operadora[%d]: %d \n",i, operadora[i]);
				

					}			

	fclose (f);
					


}
				

		


		
		
