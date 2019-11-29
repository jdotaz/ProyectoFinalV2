#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

class Propietario {
private:
  //Instancias
  string codigo;
  string nombre;
  string apellido;
  string telefono;
  string direcccion;

public:
  //Constructores
  Propietario(){
    codigo="";
    nombre="";
    apellido="";
    telefono="";
    direcccion="";
  }
  Propietario(string codigo_,string nombre_,string apellido_,string telefono_,string direcccion_):codigo(codigo_),nombre(nombre_),apellido(apellido_),telefono(telefono_),direcccion(direcccion_)
    {}


  Propietario(const Propietario &otro){
    codigo=otro.codigo;
    nombre=otro.nombre;
    apellido=otro.apellido;
    telefono=otro.telefono;
    direcccion=otro.direcccion;
  }
  ~Propietario(){
  }


  //Obtencion de datos
  string getCodigo(){
    return codigo;
  }
  string getNombre(){
    return nombre;
  }
  string getApellido(){
    return apellido;
  }
  string getTelefono(){
    return telefono;
  }
  string getDireccion(){
    return direcccion;
  }



  //Edicion de datos
  void editNombre(string nombre_){
    nombre=nombre_;
  }
  void editApellido(string apellido_){
    apellido=apellido_;
  }
  void editTelefono(string telefono_){
    telefono=telefono_;
  }
  void editDireccion(string direcccion_){
    direcccion=direcccion_;
  }

//Otras
  void Informacion(){
    cout<<"   -Nombre: "<<nombre<<endl;
    cout<<"   -Apellido: "<<apellido<<endl;
    cout<<"   -Telefono: "<<telefono<<endl;
    cout<<"   -Direccion: "<<direcccion<<endl;
  }
};
