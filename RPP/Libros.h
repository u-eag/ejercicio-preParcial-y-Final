#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

typedef struct
{
    int idLibros; // Código de Libro (autoincremental arrancando en 100)
    char titulo[51];
    int idAutor;
    int isEmpty;
}Libros;

#endif // LIBROS_H_INCLUDED

int initLibros(Libros* list, int len);
int printLibros(Libros* list, int len);
int buscarLibros(Libros* list, int len, int* input);
int ordenarLibros(Libros* list, int len);


