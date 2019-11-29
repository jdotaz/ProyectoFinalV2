#include <iostream>
#include <stdio.h>

using namespace std;

class Animal{
protected:
  //Instancias
  string codigoDelPropietario;
  string raza;
  string nombre;
  string color;
  int nacimiento[3];
  int sexo;

public:
  //Constructores
  Animal(){
    codigoDelPropietario="";
    raza="";
    nombre="";
    color="";
    nacimiento[0]=0;
    nacimiento[1]=0;
    nacimiento[2]=0;
    sexo=0;
  }
  Animal(string codigoDelPropietario_,string raza_,string nombre_,string color_,int day,int month, int year,int sexo_){
    codigoDelPropietario=codigoDelPropietario_;
    raza=raza_;
    nombre=nombre_;
    color=color_;
    nacimiento[0]=day;
    nacimiento[1]=month;
    nacimiento[2]=year;
    sexo=sexo_;
  }
  Animal(const Animal &otro){
    codigoDelPropietario=otro.codigoDelPropietario;
    raza=otro.raza;
    nombre=otro.nombre;
    color=otro.color;
    nacimiento[0]=otro.nacimiento[0];
    nacimiento[1]=otro.nacimiento[1];
    nacimiento[2]=otro.nacimiento[2];
    sexo=otro.sexo;
  }
  ~Animal(){}
  //Obtencion de datos
  string getCodigoDelPropietario(){
    return codigoDelPropietario;
  }
  string getRaza(){
    return raza;
  }
  string getNombre(){
    return nombre;
  }
  string getColor(){
    return color;
  }
  int getNacimiento(int pos){
    return nacimiento[pos];
  }
  int getSexo(){
    return sexo;
  }
  string getSexostr(){
    if (sexo==1){
      return "Macho";
    }
    return "Hembra";
  }
  //Edicion de datos
  void editRaza(string raza_){
    raza=raza_;
  }
  void editNombre(string nombre_){
    nombre=nombre_;
  }
  void editColor(string color_){
    color=color_;
  }
  void editNacimiento(int day,int month, int year){
    nacimiento[0]=day;
    nacimiento[1]=month;
    nacimiento[2]=year;
  }
  void editSexo(int sexo_){
    sexo=sexo_;
  }
  virtual void Informacion(){
    cout<<"   -Raza: "<<raza<<endl;
    cout<<"   -Nombre: "<<nombre<<endl;
    cout<<"   -Color: "<<color<<endl;
    cout<<"   -Nacimiento: "<<nacimiento[0]<<"/"<<nacimiento[1]<<"/"<<nacimiento[2]<<endl;
    if (sexo){
      cout<<"   -Sexo: Macho"<<endl;
    }else{
      cout<<"   -Sexo: Hembra"<<endl;
    }
  }
};

class Perro:public Animal{
public:
  Perro(string codigoDelPropietario_,string raza_,string nombre_,string color_,int day,int month, int year,int sexo_):Animal(codigoDelPropietario_,raza_,nombre_,color_,day,month,year,sexo_){}
  void Informacion(){
    cout<<"   -Especie: Perro"<<endl;
    Animal::Informacion();
  }
};

class Gato:public Animal{
public:
  Gato(string codigoDelPropietario_,string raza_,string nombre_,string color_,int day,int month, int year,int sexo_):Animal(codigoDelPropietario_,raza_,nombre_,color_,day,month,year,sexo_){}
  void Informacion(){
    cout<<"   -Especie: Gato"<<endl;
    Animal::Informacion();
  }
};
