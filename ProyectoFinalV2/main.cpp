#include "Clases/Propietario.cpp"
#include "Clases/Animal.cpp"
#include "funciones.cpp"

int main(){
  vector <Propietario> arrayPropietarios;
  vector <Animal> arrayMascotas;
  cargar(arrayPropietarios);
  cargar(arrayMascotas);
  system("color 08");//color de la ventana
  system("mode con: cols=70 lines=20");//tamaño de la ventana
  srand(time(NULL));//inicio la aleatoriedad
  bool bucle=true;
  int opcion;//opciones en general

  while (bucle) {
    guardar(arrayPropietarios);
    guardar(arrayMascotas);
    system("cls");
    cout<<"                       Bienvenido al Sistema ObVet"<<endl<<endl;
    cout<<"                            Menu Principal"<<endl<<endl;
    cout<<"Eliga una opcion:"<<endl;
    cout<<"   1.Inscribir Mascota nueva."<<endl;
    cout<<"   2.Buscar Propietario."<<endl;
    cout<<"   3.Buscar Mascota."<<endl;
    cout<<"   4.Listar Propietarios."<<endl;
    cout<<"   5.Salir."<<endl;
    cout<<endl<<"Opcion:";
    cin>>opcion;
    switch(opcion){
      case 1:{
        MenuInscribir(arrayPropietarios,arrayMascotas);
        break;
      }
      case 2:{
        MenuBusqueda(arrayPropietarios,arrayMascotas);
        break;
      }
      case 3:{
        MenuBusquedaMascota(arrayPropietarios,arrayMascotas);
        break;
      }
      case 4:{
        MenuListado(arrayPropietarios,arrayMascotas);
        break;
      }
      case 5:{
        MenuSalir(bucle);
        break;
      }
    }
  }
  return 0;
}
