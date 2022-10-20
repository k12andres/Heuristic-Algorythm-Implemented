#include <iostream>
#include <fstream>
#include <list>
#include "Familia.h"
#include "Solucion.h"
#define LIMITE 341
#define DIAS 8

using namespace std;

void procesar_dataset(string origen, list<Familia> & familias);
//DEBUG.
void mostrar_familias(const list<Familia> & familias);
void Ingresar_Preferencia (list<Familia> &familias, Solucion &S);
void Ingresar_Otro_Dia (list<Familia> &familias, Solucion &S);
void Ingresar_Familias (list<Familia> &familias, Solucion &S);


int main()
{
    list<Familia> familias;
    procesar_dataset("data\\familias-0.csv", familias);
    Solucion S;
    //mostrar_familias(familias);
    Ingresar_Familias (familias, S);

    //ordenar con merge
    //mostrar_familias(familias);
    return 0;
}

void Ingresar_Familias (list<Familia> &familias, Solucion &S)
{
    familias.sort();
    Ingresar_Preferencia (familias, S);
    Ingresar_Otro_Dia (familias, S);

    list<Familia> Aux(familias);
    cout<<endl<<endl<<endl;
    for (int i=1; i<101; i++)
    {
        cout<<"Para el dia "<<i<<" : "<<S.cant_personas(i)<<endl;
    }
    cout<<"El bono total es de: "<<S.devolver_bono()<<endl;
    S.imprimir_familias();
    S.transformacion(familias, Aux);
    cout<<S.devolver_bono()<<endl;
}

void Ingresar_Preferencia (list<Familia> &familias, Solucion &S)
{
    list<Familia>::iterator it2;
    list<Familia>::iterator it=familias.begin();
    while (it!=familias.end())
    {
        if (((it->obtener_miembros()) + S.cant_personas(it->obtener_dia_preferido_en(0))) < LIMITE)
        {
            S.agregar_familia(*it, 0);
            it2=it;
            it++;
            familias.erase(it2);
        }else
            it++;
    }
}

void Ingresar_Otro_Dia (list<Familia> &familias, Solucion &S)
{
    list<Familia>::iterator it2;
    for (int i=1; i<DIAS; i++)
    {
        list<Familia>::iterator it=familias.begin();
        while (it!=familias.end())
        {
            if (((it->obtener_miembros()) + S.cant_personas(it->obtener_dia_preferido_en(i))) < LIMITE)
            {
                S.agregar_familia(*it, i);
                it2=it;
                it++;
                familias.erase(it2);
            }else
                it++;
        }
    }
}

void procesar_dataset(string origen, list<Familia> & familias)
{
    ifstream archivo(origen.c_str());
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        //cabecera del csv
        getline(archivo, linea);
        //contamos cuantas columnas "dia" hay para determinar la cantidad de días de preferencia.
        unsigned int cantidad_dias = 0;
        string nombre_columna = "dia_";
        size_t pos = linea.find(nombre_columna);
        while (pos != string::npos) {
            cantidad_dias++;
            pos = linea.find("dia_", pos + nombre_columna.size());
        }

        //Leemos de una linea completa por vez (getline).
        while (getline(archivo, linea)){
            size_t pos_inicial = linea.find(',');
            string id = linea.substr(0, pos_inicial);

            pos_inicial++;
            size_t pos_final = linea.find(',', pos_inicial);
            int miembros = atoi(linea.substr(pos_inicial, pos_final).c_str());

            Familia f(id, miembros, cantidad_dias);

            for (unsigned int dia = 0; dia < cantidad_dias; dia++) {
                pos_inicial = pos_final + 1;
                pos_final = linea.find(',', pos_inicial);
                int preferencia = atoi(linea.substr(pos_inicial, pos_final).c_str());
                f.agregar_preferencia(preferencia);
            }
            familias.push_back(f);
        }
    }
}

void mostrar_familias(const list<Familia> & familias) {
    list<Familia>::const_iterator it = familias.begin();
    while (it != familias.end()) {
        cout << *it;
        it++;
    }
}
