#include <iostream>
#include "Matriz.h"
#include <deque>
#include <map>
#include <fstream>
#include <sstream>
#include "map.h"
using namespace std;
//Pregunta 3
class  seccion1{
    map<string,int> mapa;
public:
    void funcion(ifstream &direccion){
        string primera_cosa;
        while (direccion>>primera_cosa){

            if (primera_cosa=="C"){
                string nombre;
                int puntaje;
                direccion>>nombre;
                direccion>>puntaje;
                mapa[nombre]=puntaje;
            }
            else{
                if (primera_cosa=="L"){
                    string nombre;
                    direccion>>nombre;
                    if (nombre=="All"){
                        for (auto it=mapa.begin(); it!=mapa.end(); ++it)
                            cout << it->first << " => " << it->second << '\n';
                        cout<<"aqui termino la funcion"<<endl;
                    }
                    else{
                        for (auto it=mapa.begin(); it!=mapa.end(); ++it)
                            if (it->first==nombre){
                                cout << it->first << " => " << it->second << '\n';
                                cout<<"aqui termino la funcion"<<endl;
                            }
                    }
                }
                else{
                    if (primera_cosa=="D"){
                        string nombre;
                        direccion>>nombre;
                        mapa.erase(nombre);
                    }
                }
            }
        }
    }


};


//Pregunta 2 con Template
template <typename D>
deque<D> generar(deque<D> list, int dq){
    D mini;
    int i,j;
    deque<D> result = {};
    for (i = 0; i < list.size()-dq+1; i++) {
        mini = list[i];
        for ( j = 0; j < dq; j++) {
            int dav=i+j;
            if (list[dav] < mini){
                mini = list[dav];
            }
        }
        result.push_back(mini);
    }
    return result;
}

int main() {

    cout<<"Pregunta1............!!!"<<endl;
    int fila1,fila2,columna1,columna2;
    cout<<"Ingrese Matris 1 fila"<<endl;
    cin>>fila1;
    cout<<"Ingrese Matris 1 columna"<<endl;
    cin>>columna1;
    cout<<"Ingrese Matris 2 fila"<<endl;
    cin>>fila2;
    cout<<"Ingrese Matris 2 columna"<<endl;
    cin>>columna2;

    Matriz  m1(fila1, columna1), m2(fila2, columna2), m3;

    m1.Inicializar();
    m2.Inicializar();

    m1.Mostrar();
    cout << endl;
    m2.Mostrar();
    m3 = m1 + m2;
    cout << endl;
    m3.Mostrar();

    cout<<"Pregunta2............!!!"<<endl;
    deque<int> listaDav = {5, 1, 4, 8, 2, 4};
    auto x = generar(listaDav, 3);
    cout<< "Deque es : ";
    for (int k = 0; k < x.size(); ++k) {
        cout << x[k] << " ";
    }
    cout<<endl;
    cout<<"Pregunta3............!!!"<<endl;

    ifstream a;
    a.open("prueba.txt");
    seccion1 b;
    b.funcion(a);
    return 0;

}