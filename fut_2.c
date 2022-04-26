#include <stdio.h>
#include <string.h>

typedef struct Pichichi {

	char nombre[20];
	char apellido[20];
	char equipo[15];
	int goles;
	int minutos_jugados;
	double altura;
	
} Fut;


int imprimirMaxMinutos(Fut fb[]);

void ordena_por_altura(Fut fb[]);

int suma_goles(Fut fb[]);

void goleadores_por_equipo(Fut fb[]);

//función práctica ficheros;
void copiar_goles_f(Fut fb[], char nombre[]);


int main(){

	int res, i;
	int n = 1;

	char nombre[20];

		Fut fb[5] = {
	
			"Lionel", "Messi", "FC Barcelona", 29, 2157, 1.70,
			"Luís", "Suárez", "FC Barcelona", 18, 2287, 1.82,
			"Ben", "Yedder", "Sevilla FC", 16, 1923, 1.70,
			"Christian", "Stuani", "Girona FC", 16, 2101, 1.86,
			"Mata", "aaa", "Getafe CF", 13, 1688, 1.85,
	
			};


		while(n!=0){

		printf("-----------------------------------------------------------\n");	
		printf("\n");
		printf("   Selecciona una opción.");
		printf("\n\n");
	
		printf("   1.-¿Qué jugador ha jugado más minutos?\n");
	
		printf("   2.-Mostrar los jugadores por altura, ordenados de menor a mayor. \n");

		printf("   3.-Suma los goles de los cinco primeros clasificados. \n");
		
		printf("   4.-Goleadores ordenados por club. \n");

		printf("   5.-Crear fichero goleadores. \n");

		printf("   0.-Salir del programa. \n");
		
		printf("\n");
		printf("-----------------------------------------------------------\n");	
	
		scanf("%d", &n);

		printf("\n");
	
	switch(n){
	
		case 0: printf("B y e. \n");
		break;
	
		case 1: res=imprimirMaxMinutos(fb);	
	
			printf("El máximo tiempo jugado es: %d minutos. Han sido jugados por: %s %s. \n", res, fb[i].nombre, fb[i].apellido);
			
			printf("\n");
			break;

		case 2: ordena_por_altura(fb);
		
			printf("Jugadores ordenados por altura, de menor a mayor: \n");
			printf("\n");
		
			for (int i=0;i<5;i++){
	
				printf("Nombre: %s\n", fb[i].nombre);
				printf("Apellido: %s\n", fb[i].apellido);
				printf("Altura %.2f\n\n", fb[i].altura);
		
			}

		

			printf("\n");
			break;

		case 3: res=suma_goles(fb);
			
			printf("El resultado de sumar los goles es: %d.\n", res);
		
			printf("\n");
			
			break;
			
		case 4: goleadores_por_equipo(fb);
		
			printf("Goleadores ordenados por equipo: \n");
			printf("\n");
		
			for (int i=0;i<5;i++){
		
				printf("Nombre: %s\n", fb[i].nombre);
				printf("Apellido: %s\n", fb[i].apellido);
				printf("Equipo: %s\n", fb[i].equipo);
				printf("Goles: %d\n\n", fb[i].goles);
			
		
			}
			
			printf("\n");
			
			break;

		case 5: printf("¿Qué nombre quieres darle al fichero? \n"); 
			scanf("%s", nombre);			

			copiar_goles_f(fb, nombre);

			printf("\n");
			
			break;
			

		default: printf("Opción incorrecta. \n");
	
		}
	
	}
		

}


int imprimirMaxMinutos(Fut fb[]) {

		
	int i;
	int max=0;
	int minutos_jugados;		
	
		for(i=0;i<5;i++){

			minutos_jugados = fb[i].minutos_jugados;

		
				if(fb[i].minutos_jugados > max){
	
					max = fb[i].minutos_jugados;
					

				}
				
		
		}


		return max;
	
}


void ordena_por_altura(Fut fb[]){

	int i, j;
	
	Fut aux;
	
		for(i=0;i<5;i++){
			
			for(j=0;j<5;j++){
			
				if(fb[i].altura <fb[j].altura){

					aux = fb[i];
					fb[i] = fb[j];
					fb[j] = aux;
				}
			
			}		
		}

}


int suma_goles(Fut fb[]){

	int i;
	int suma=0;
	
	
		for(i=0;i<5;i++){
		
			
			suma += fb[i].goles;
			
		
		}
		
		return suma;

}


void goleadores_por_equipo(Fut fb[]){

int i, j;
	
	Fut aux;
	
		for(i=0;i<5;i++){
			
			for(j=0;j<5;j++){
			
				if(fb[i].goles > fb[j].goles){
				
					if(strcmp(fb[j].equipo, fb[j+1].equipo)>0){

					aux = fb[i];
					fb[i] = fb[j];
					fb[j] = aux;
				
					}
				
				}
			
			}		
		}

}

void copiar_goles_f(Fut fb[], char nombre[]){

/*
genera fichero(nombre-file pasado como parámetro x user), en el mismo directorio que se ejecuta este fichero;
para usar otra ruta indicar con barra doble(//) cuidado con los return y fclose!
*/

	int i;
	
	FILE *f;

		f=fopen(nombre, "w");
		
		for(i=0;i<5;i++){

			fprintf(f, "Nombre: %s. Goles: %d. \n", fb[i].nombre, fb[i].goles);

		}


		fclose(f);


}

