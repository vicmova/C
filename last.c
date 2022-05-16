/*25 mayo = posible fecha de exámen;
crear vector num con 3 posiciones inicializado a 0, es el num de registros q tengo en la fila de la matriz. 
ir al fichero y leemos la posición.

	scanf 1 leer operador
	scanf 2

	a[ope[num[ope]]]

	num[ope]++;

	función mostrar=también por filas

	V A[3][NMAX] = DEFINIR MATRIZ

	file:

	1 971464501 os b 1
	0 971221114 lv l 1
	2 601086396 k d 0
	2 667010942 r h 0
	0 615949821 t f 0
	1 971286248 a ma 0


*/

#include<stdio.h>

#define nmax 100

	typedef struct Ventas{

		char tlf[9];

		char cliente[40];

		int tipoContrato;

		}venta;


int cargarFichero(venta A[], char nombre_empresa[]);


int main(){

 	int n=1, i, num;
	char nombre_empresa[12];
	venta A[3][nmax];
 
	FILE*f;
	
	
	
	
 
 	while(n!=0){
 	
 		printf("-----------------------------------------------------------\n");	
		printf("\n");
		printf("   Selecciona una opción del menú.");
		printf("\n\n");
 	
 		printf("1 - Carga ventas desde fichero. \n");
 		
 		printf("2 - Introduce venta. \n");
 		
 		printf("3 - Muestra información de un cliente. \n"); //buscar por telf strcmp;
 		
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
 		
 		case 1: printf("Indica el nombre de la compañía. \n");

			cargarFichero(A, nombre_empresa);

			for(i=0;i<num;i++){

				printf("Teléfono: %s, Cliente: %s, Tipo de contrato: %d. \n", A[i].tlf, A[i].cliente, A[i].tipoContrato);		
		
			}

			printf("\n");

			break;


 		
 		default: printf("Opción incorrecta. \n");
 	
 	
 	
 	}


}

int cargarFichero(venta A[], char nombre_empresa){


		int i;
		
		FILE *f=fopen("fichero.txt", "r");
					
	
				if(f==NULL){
	
				return -1;			
			
				} else {
		
				for(i=0;feof(f)==0;i++){

	
					fscanf (f, "%s  %s  %d", A[i].tlf, A[i].cliente, &A[i].tipoContrato);
				
				}	

			}
			
		//*num=i-1;

		fclose (f);
				
			
		}

				
}
