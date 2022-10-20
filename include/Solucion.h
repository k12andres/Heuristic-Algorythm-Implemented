#ifndef SOLUCION_H
#define SOLUCION_H
#include "vector"
#define CONST 100
#define LIMITE 341


using namespace std;

class Solucion
{
    public:
        Solucion();//Constructores
        Solucion(int bono);

        virtual ~Solucion();//Destructor

        //Metodos modificadores.
        void agregar_familia (Familia F, int pos_preferencia); //Es para sumar la familia y ademas para no repetirla
        void familia_usada(Familia F, int pos_preferencia);//En caso de retroceso vuelvo a tener en cuenta esa familia y resto al bono si se sumo algo.
        void transformacion(list<Familia> F,list<Familia> A);

        //Operador =
        Solucion &operator = (Solucion &otraSolucion);

        //Metodos observadores.
        void imprimir_familias () const;//Imprime las familias en sus posiciones.
        int devolver_bono() const; //Devuelve el monto del bono
        int cant_personas(int dia) const; //Devuelve la cantidad de personas en un dia

    private:
        int bono_obtenido;
        int personas[CONST];
        vector<Familia> familias[CONST];
};


void Solucion::transformacion (list<Familia> F, list<Familia> A)
{
    list<Familia>::iterator it=F.begin();
    list<Familia>::iterator it2=A.begin();
    vector<Familia>::iterator it3=familias[it->obtener_dia_preferido()].end()-1;
    int i=0;
    while (it3->obtener_dia_preferido()==it->obtener_dia_preferido_en(i))
    {
        ++i;
        it3=familias[it->obtener_dia_preferido_en(i)-1].end()-1;
    }
}


Solucion::Solucion()
{
    bono_obtenido=0;
    for(int i=0; i<CONST; i++)
    {
        personas[i]=0;
    }
}

Solucion::Solucion(int bono)
{
    bono_obtenido=bono;
    for(int i=0; i<CONST; i++)
    {
        personas[i]=0;
    }
}

Solucion::~Solucion()
{
    //dtor
}


void Solucion::imprimir_familias() const
{
    for (int dia=0; dia<CONST; dia++)
    {
        cout<<"Para el dia "<<dia+1<<":";
        for (vector<Familia>::const_iterator it3=familias[dia].begin(); it3!=familias[dia].end(); it3++)
        {
            cout<<"  "<< *it3;
        }
        cout<<endl<<endl;
    }
}


Solucion & Solucion::operator=(Solucion &otraSolucion)
{
    bono_obtenido=otraSolucion.bono_obtenido;
    for (int i=0; i<CONST; i++)
    {
        familias[i]=otraSolucion.familias[i];
        personas[i]=otraSolucion.personas[i];

    }
    return *this;
}


void Solucion::familia_usada(Familia F, int pos_preferencia)
{
    familias[F.obtener_dia_preferido_en(pos_preferencia)-1].pop_back();
    if (pos_preferencia > 0)
    {
        bono_obtenido-= 25+ (10*F.obtener_miembros())+(5*pos_preferencia);
    }
    personas[F.obtener_dia_preferido_en(pos_preferencia)-1]= personas[F.obtener_dia_preferido_en(pos_preferencia)-1]-F.obtener_miembros();
}


void Solucion::agregar_familia(Familia F, int pos_preferencia)
{
    familias[F.obtener_dia_preferido_en(pos_preferencia)-1].push_back(F);
    if (pos_preferencia > 0)
    {
        bono_obtenido+= 25 + (10*F.obtener_miembros())+(5*pos_preferencia);
    }
    personas[F.obtener_dia_preferido_en(pos_preferencia)-1]= personas[F.obtener_dia_preferido_en(pos_preferencia)-1]+F.obtener_miembros();
}


int Solucion::cant_personas(int dia) const
{
    return personas[dia-1];
}


int Solucion::devolver_bono() const
{
    return bono_obtenido;
}
#endif // SOLUCION_H
