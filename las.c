#include<stdio.h>

#define nmax 100

	typedef struct Ventas{

			char tlf[9];
			char cliente[40];
			int tipoContrato;

			}venta;


int cargar(venta A[][nmax]);


int main(){

 	int i, j;
	int operadora[3]={0,0,0};
	venta A[3][nmax];
	
	FILE *f=fopen("fi.txt", "r");

				
			if(f==NULL){
	
				return -1;			
			
				} else {				

				for(i=0;i<7;i++){
					
		
						fscanf(f,"%d", &operadora[i]);
				
				}
								

					for(i=0;i<7;i++){
						
						
		
						printf("valor de la operadora[%d]: %d \n",i, operadora[i]);
				

					}			

	fclose (f);
					


				}
}


		
		

		


		
		
