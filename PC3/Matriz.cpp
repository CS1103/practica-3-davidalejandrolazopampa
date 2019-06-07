//
// Created by David Lazo on 7/06/2019.
//

#include <type_traits>
#include "Matriz.h"
#include <iostream>
using namespace std;

//Constructor por omisi�n
Matriz::Matriz(){
    filas = 0;
    columnas = 0;
    elementos = NULL;
}

//Constructor por copia
Matriz::Matriz(const Matriz& mat){
    int i,j;
    filas = mat.filas;
    columnas = mat.columnas;
    elementos = new float * [filas*columnas];
    for(i=0; i<filas; i++){
        elementos[i] = new float[columnas];
        for(j=0; j<columnas; j++){
            elementos[i][j] = mat.elementos[i][j];
        }
    }
}
Matriz::Matriz(const int f, const int c){
    int i, j;
    filas = f;
    columnas = c;
    elementos = new float * [filas*columnas];
    for(i=0; i<filas; i++){
        elementos[i] = new float[columnas];
    }
}

//Destructor
Matriz::~Matriz(){
    delete [] elementos;
}

float Matriz::Elemento(const int i, const int j){
    return this->elementos[i][j];
}

int Matriz::Filas(){
    return filas;
}

int Matriz::Columnas(){
    return columnas;
}

void Matriz::Mostrar(){
    int i, j;
    for(i=0; i<filas; i++){
        for(j=0; j<columnas; j++){
            cout<<elementos[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void Matriz::Inicializar(){
    //srand(time(NULL));
    int i, j;
    for(i=0; i<filas; i++){
        for(j=0; j<columnas; j++){
            elementos[i][j] = rand()%9;
        }
    }
}

//Sobrecarga de Operadores
Matriz Matriz::operator = (const Matriz &mat){
    int i,j;
    if(this->filas != 0 || this->columnas != 0)
        delete [] this->elementos;

        this->filas = mat.filas;
        this->columnas = mat.columnas;
        this->elementos = new float * [this->filas*this->columnas];
        for(i=0; i<this->filas; i++){
            this->elementos[i] = new float[columnas];
            for(j=0; j<this->columnas; j++){
                this->elementos[i][j] = mat.elementos[i][j];
            }
        }
        return *this;

}


Matriz Matriz::operator + (const Matriz &m) {
    int i, j;
    if (this->filas == m.filas && this->columnas == m.columnas) {
        Matriz res(m);
        for (i = 0; i < m.filas; i++)
            for (j = 0; j < m.columnas; j++)
                res.elementos[i][j] += this->elementos[i][j];
        return res;
    } else {
        Matriz res;
        return res;
    }
}