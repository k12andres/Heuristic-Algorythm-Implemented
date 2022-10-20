#ifndef FAMILIA_H
#define FAMILIA_H

#include <iostream>
#include <ostream>
#include <vector>

/**
 * La clase Familia se utiliza para representar una posible visita al parque.
 * Se compone de un identificador, la cantidad de miembros y los dias preferidos (en orden) elegidos.
 **/
class Familia
{
    public:
        /**
         * Constructor de la clase.
         * id: identificador de la familia.
         * miembros: cantidad de miembros que componen la familia.
         * cantidad_dias: cantidad de d�as que ser�n elegidos por la familia.
         **/
        Familia(std::string id, unsigned int miembros, unsigned int cantidad_dias);

        virtual ~Familia();

        /**
         * Retorna el identificador de la familia.
         **/
        std::string obtener_id() const;

        /**
         * Retorna la cantidad de miembros de la familia.
         **/
        unsigned int obtener_miembros() const;

        /**
         * Retorna la cantidad de d�as preferidos elegidos por la familia.
         **/
        unsigned int obtener_cantidad_dias_elegidos() const;

        /**
         * Retorna el dia preferido de la familia.
         **/
        unsigned int obtener_dia_preferido() const;

        /**
         * Retorna el dia preferido de la familia seg�n el �ndice.
         **/
        unsigned int obtener_dia_preferido_en(unsigned int indice) const;

        /**
         * Dado un d�a de visita retorna el orden en el cu�l se encuentra en los d�as de preferencia.
         * return: �ndice en los d�as de preferencia de existir el d�a pasado, -1 en caso contrario.
         **/
        int obtener_indice_preferencia(unsigned int dia) const;

        /**
         * A�ade un nuevo dia de preferencia.
         * dia_preferido: dia de preferencia.
         **/
        void agregar_preferencia(unsigned int dia_preferido);

        bool operator < (const Familia &otraFamilia) const;


    private:
        std::string id;
        unsigned int miembros;
        std::vector<unsigned int> dias_preferencia;
        unsigned int indice_dias;
};

/**
 * Operador de salida para consola.
 * Presenta los datos de la familia.
 **/
std::ostream & operator << (std::ostream & salida, const Familia & f);


#endif // FAMILIA_H
