//repaso matrices

#include<stdio.h>

#define nmax 3

//busca múltiplo en la matriz, en este caso de 7
int mul(int m[nmax][nmax]);
//suma los valores de la matriz y devuelve la media
int suma(int m[nmax][nmax]);
//muestra el valor máximo
int max(int m[nmax][nmax]);
//transpone los valores de la matriz
void transponer(int m[nmax][nmax],int mt[nmax][nmax]);

int main(){

	int i, j, res;
	int m[nmax][nmax], mt[nmax][nmax];
	
	printf("Introduce números enteros, la matriz es de: %d filas por %d columnas. \n", nmax, nmax);
	
	for(i=0;i<nmax;i++){
		
		for(j=0;j<nmax;j++){
		
			scanf("%d", &m[i][j]);
		}
	}
	
	res=mul(m);
	
	if(res == 1){
	
		printf("La matriz contiene múltiplos de 7. \n");
	
	} else {
	
		printf("La matriz no contiene múltiplos de 7. \n");
	
	}
	
	printf("\n");
	
	printf("Contenido de la matriz: \n");
	
	for(i=0;i<nmax;i++){
	
		printf("\n");
	
		for(j=0;j<nmax;j++){
		
			printf("%d", m[i][j]);
		
		}
	}
	
	printf("\n");

	res=suma(m);
	
	printf("La media de los valores de la matriz es: %d \n", res);
	
	res=max(m);
	
	printf("El valor máximo de la matriz es: %d \n", res);
	
	transponer(m,mt);
	
	printf("Contenido de la matriz transpuesta: \n");
	
	for(i=0;i<nmax;i++){
	
		printf("\n");
	
		for(j=0;j<nmax;j++){
		
			printf("%d", mt[i][j]);
		
		}
	}
	
	printf("\n");
}



int mul(int m[nmax][nmax]){

	int i, j;

	for(i=0;i<nmax;i++){
		
		for(j=0;j<nmax;j++){
			
			if(m[i][j] % 7 == 0){
			
				return 1;
			
			}
		
		}
	
	}

	return -1;

}

int suma(int m[nmax][nmax]){

	int i, j, suma=0;
	
		for(i=0;i<nmax;i++){
		
			for(j=0;j<nmax;j++){
			
				suma+=m[i][j];
			
			}
		}

		
		return suma/9;

}

int max(int m[nmax][nmax]){

	int i, j, max=m[0][0];	
	
	
		for(i=0;i<nmax;i++){
		
			for(j=0;j<nmax;j++){
			
				if(m[i][j] > max){
					
					max=m[i][j];
				
				}
			
			}
		}
	
	return max;

}

void transponer(int m[nmax][nmax], int mt[nmax][nmax]){


	int i, j;
	
		for(i=0;i<nmax;i++){
			for(j=0;j<nmax;j++){
			
				mt[i][j]=m[j][i];
				
			}
		}

}
