#include "Familia.h"
#include <ostream>
#include <vector>
#include <cassert>

using namespace std;

Familia::Familia(string id, unsigned int miembros, unsigned int cantidad_dias)
{
    this->id = id;
    this->miembros = miembros;
    this->indice_dias = 0;
    this->dias_preferencia = vector<unsigned int>(cantidad_dias, 0);
}

Familia::~Familia()
{
}

std::string Familia::obtener_id() const
{
    return this->id;
}

unsigned int Familia::obtener_miembros() const
{
    return this->miembros;
}

unsigned int Familia::obtener_cantidad_dias_elegidos() const
{
    return this->dias_preferencia.size();
}

unsigned int Familia::obtener_dia_preferido() const
{
    return this->dias_preferencia[0];
}

unsigned int Familia::obtener_dia_preferido_en(unsigned int indice) const
{
    assert(indice < this->dias_preferencia.size());
    return this->dias_preferencia[indice];
}

int Familia::obtener_indice_preferencia(unsigned int dia) const
{
    unsigned int indice = 0;
    bool encontrado = false;
    while (!encontrado && (indice < this->dias_preferencia.size())) {
        if (this->dias_preferencia[indice] == dia) {
            encontrado = true;
        } else
            indice++;
    }
    if (encontrado)
        return indice;

    return -1;
}

void Familia::agregar_preferencia(unsigned int dia_preferencia)
{
    assert(this->indice_dias < this->dias_preferencia.size());

    this->dias_preferencia[this->indice_dias] = dia_preferencia;
    this->indice_dias++;
}

ostream & operator << (ostream & salida, const Familia & familia)
{
    salida << "Familia " << familia.obtener_id() << endl;

    return salida;
}

bool Familia::operator < (const Familia & otraFamilia) const
{
    if (miembros<otraFamilia.miembros)
        return true;
    else return false;
}
