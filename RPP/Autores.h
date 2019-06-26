#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

typedef struct
{
    int idAutor; // Código de Autor (autoincremental arrancando en 1000)
    char nombre[31];
    char apellido[31];
    int isEmpty;
}Autores;

int initAutores(Autores* list, int len);
int printAutores(Autores* list, int len);
int ordenarAutores(Autores* list, int len);

#endif // AUTORES_H_INCLUDED


