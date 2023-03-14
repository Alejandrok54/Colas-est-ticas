#include <iostream>
#define TAM 50

class Constancia {
    private:
        std::string nombre;
        std::string carrera;
        int tma;
        float promG;
    public:
        Constancia():nombre(""),carrera(""),tma(-1),promG(-1) {};

        Constancia(const Constancia& c) {
            nombre = c.nombre;
            carrera = c.carrera;
            tma = c.tma;
            promG = c.promG;
            }

        Constancia& operator = (Constancia& c) {
            nombre = c.nombre;
            carrera = c.carrera;
            tma = c.tma;
            promG = c.promG;
            return *this;
            }

        friend bool operator==(Constancia& x,Constancia& y) {
            if(x.nombre.compare(y.nombre)==0 && x.carrera.compare(y.carrera)==0 && x.tma == y.tma && x.promG == y.promG) {
                return 1;
                }
            else {
                return 0;
                }

            }

        friend bool operator!=(Constancia& x,Constancia& y) {
            if(x.nombre.compare(y.nombre)==0 && x.carrera.compare(y.carrera)==0 && x.tma == y.tma && x.promG == y.promG) {
                return 0;
                }
            else {
                return 1;
                }

            }

        friend bool operator>(Constancia& x,Constancia& y) {
            if(x.tma > y.tma && x.promG > y.promG) {
                return 1;
                }
            else {
                return 0;
                }

            }

        friend bool operator<(Constancia& x,Constancia& y) {
            if(x.tma < y.tma && x.promG < y.promG) {
                return 1;
                }
            else {
                return 0;
                }

            }

        friend std::ostream & operator<<(std::ostream &O, Constancia &x) {
            O<<"\n Nombre: "<<x.nombre<<std::endl;
            O<<"\n Carrera: "<<x.carrera<<std::endl;
            O<<"\n Materias Aprobadas: "<<std::to_string(x.tma)<<std::endl;
            O<<"\n Promedio General: "<<std::to_string(x.promG)<<std::endl;
            return O;
            }
        friend std::istream & operator>>(std::istream &O, Constancia &x) {
            std::cout<<"\n Nombre: ";
            O>>x.nombre;
            std::cout<<"\n Carrera: ";
            O>>x.carrera;
            std::cout<<"\n Total de Materias Aprobadas: ";
            O>>x.tma;
            std::cout<<"\n Promedio General: ";
            O>>x.promG;
            return O;
            }

        std::string getNombre() const {
            return nombre;
            }


        std::string getCarrera() const {
            return carrera;
            }

        int getTma() const {
            return tma;
            }

        float getPromG() const {
            return promG;
            }

        void setNombre(const std::string& n) {
            nombre = n;
            }

        void setCarrera(const std::string& c) {
            carrera = c;
            }

        void setTma(const int& t) {
            tma = t;
            }

        void setPromG(const float& p) {
            promG = p;
            }
    };

//plantillas
template<class T>
class Cola {
    private:
        T datos[TAM];
        int ult;
        bool inserta(T, int);
        bool elimina(int);
        T recupera(int)const;
        int primero()const;
        int ultimo()const;
        void imprime()const;
    public:
        Cola():ult(-1) {}
        bool vacia()const;
        bool llena()const;
        bool  Queue(T&);
        bool Dequeue();
        T& Front();
    };

template<class T>
T& Cola<T>::Front() {
    return datos[primero()];
    }

template<class T>
bool Cola<T>::Dequeue() {
    if(vacia()) {
        return false;
        }
    else {
        elimina(primero());
        }
    return true;
    }

template<class T>
bool Cola<T>::Queue(T& elem) {
    if(llena()) {
        return false;
        }
    if(vacia()) {
        inserta(elem,0);
        }
    else {
        inserta(elem, ultimo()+1);
        }
    return true;
    }

template<class T>
void Cola<T>::imprime()const {
    if(!vacia()) {
        for(int i=0; i<=ult; i++) {
            Constancia x=datos[i];
            std::cout<<x<<std::endl;
            }
        }
    }

template<class T>
bool Cola<T>::vacia()const {
    return ult==-1;
    }

template<class T>
bool Cola<T>::llena()const {
    return ult==TAM-1;
    }

template<class T>
bool Cola<T>::inserta(T elem, int pos) {
    if(llena() || pos<0 || pos>ult+1) {
        std::cout<<"\n No se pudo insertar";
        return false;
        }
    int i=ult+1;
    while(i>pos) {
        datos[i]=datos[i-1];
        i--;
        }
    datos[pos]=elem;
    ult++;
    return true;
    }

template<class T>
bool Cola<T>::elimina(int pos) {
    if(vacia() || pos<0 || pos>ult) {
        std::cout<<"\n No se pudo eliminar";
        return false;
        }
    int i=pos;
    while(i<ult) {
        datos[i]=datos[i+1];
        i++;
        }
    ult--;
    return true;
    }

template<class T>
T Cola<T>::recupera(int pos)const {
    if(vacia() || pos<0 || pos>ult-1) {
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
        }
    else {
        return datos[pos];
        }
    }

template<class T>
int Cola<T>::primero()const {
    if(vacia()) {
        return -1;
        }
    return 0;
    }

template<class T>
int Cola<T>::ultimo()const {
    if(vacia()) {
        return -1;
        }
    return ult;
    }

int main() {
    Cola<Constancia> MiCola;
    Constancia x;
    int op;

    do{
        std::cout<<"1. Dar de alta solicitud de alumno"<<std::endl;
        std::cout<<"2. Elaborar una constancia"<<std::endl;
        std::cout<<"3. Salir"<<std::endl;
        std::cout<<"Opcion: ";std::cin>>op;

        switch(op){
        case 1:
            std::cin>>x;
            MiCola.Queue(x);
            break;
        case 2:
            if(MiCola.vacia()){
                std::cout<<"NO HAY ELEMENTOS EN LA COLA\n";
            }else{
                x = MiCola.Front();
                MiCola.Dequeue();
                std::cout<<"***********Constancia**********\nDatos del alumno: \n";
                std::cout<<x;
            }
        }
    }while(op!=3);


    return 0;
    }
