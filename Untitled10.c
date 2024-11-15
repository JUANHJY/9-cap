 #include <stdio.h>

/* Alumnos.
El programa pregunta al usuario el numero de registro que desea
modificar, obtiene el nuevo promedio del alumno y modifica tanto el
registro como el archivo correspondiente. */

typedef struct          /* Declaracion de la estructura alumno. */
{
  int matricula;
  char nombre[20];
  int carrera;
  float promedio;
} alumno;

void modifica(FILE *);       /* Prototipo de funcion. */

void main(void)
{
FILE *ar;
if ((ar = fopen ("ad1.dat", "r+")) != NULL)
   modifica(ar);
else
   printf("\nEl archivo no se puede abrir");
fclose(ar);
}
void modifica(FILE *ap)
/* Esta funcion se utiliza para modificar el promedio de un alumno. */
{
int d;
alumno alu;
printf("\nIngrese el numero de registro que desea modificar: ");
/* Observa que el lenguaje C almacena el primer registro en la
posicion cero. Por lo tanto, si desea modificar el registro n,
debe buscarlo en la posici�n n-1. */
scanf("%d", &d);

fseek(ap, (d-1)*sizeof(alumno), 0);
/* Observa que la instrucci�n fseek tiene tres argumentos. El primero
indica que el apuntador se debe posicionar al inicio del FILE. */

fread(&alu, sizeof(alumno), 1, ap);
/* Luego de posicionarnos en el registro que nos interesa, lo
leemos. */

printf("\nIngrese el promedio correcto del alumno: ");
scanf("%f", &alu.promedio);               /* Modificamos el registro con el
                                          nuevo promedio. */

fseek(ap, (d-1)*sizeof(alumno), 0);
/* Nos tenemos que posicionar nuevamente en el lugar correcto para
escribir el registro modificado. Observa que si no hacemos este
reposicionamiento escribir�amos el registro actualizado en la
siguiente posici�n. */

fwrite(&alu, sizeof(alumno), 1, ap);
}
