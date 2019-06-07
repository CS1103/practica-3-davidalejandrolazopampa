//
// Created by David Lazo on 7/06/2019.
//

#ifndef PC3_MAP_H
#define PC3_MAP_H
#include <iterator>
#include <map>
using namespace std;
class seccion{
public:
    map<string,int> alumnos;
    void ejecutar(string,string);
    void ejecutar(string,string,int);
};

void seccion::ejecutar(string funcion,string nombre) {
    if (funcion == "L") {
        if (nombre == "ALL") {
            for (auto aux = alumnos.begin(); aux != alumnos.end(); aux++) {
                cout << aux->first << " " << aux->second<<"\n";
            }
        } else {
            for (auto aux = alumnos.begin(); aux != alumnos.end(); aux++) {
                if (aux->first == nombre)
                    cout << aux->first << " " << aux->second<<"\n";
            }
        }

    } else if (funcion == "D") {
        for (auto aux = alumnos.begin(); aux != alumnos.end(); aux++) {
            if (aux->first == nombre)
                alumnos.erase(aux);
        }

    }
}
void seccion::ejecutar(string funcion, string nombre, int nota  ) {
    if(funcion=="C"){
        alumnos.insert(pair<string,int>(nombre,nota));
    }

}
#endif //PC3_MAP_H
