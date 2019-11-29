#include <time.h>
#include <vector>

//funciones auxiliares
string minusculas(string porTransformar){
  string palabra=porTransformar;
  for(int i=0;i<palabra.length();i++){
    int n=static_cast<int>(palabra[i]);
    if ((n>=65)and(n<=90)){
      palabra[i]=static_cast<char>(n+32);
    }
  }
  return palabra;
}
ostream& operator<<(ostream &output, Propietario &o){
  output<<o.getNombre()<<" "<<o.getApellido();
  return output;
}
ostream& operator<<(ostream &output, Animal &o){
  output<<o.getNombre();
  return output;
}
bool operator>(string x,string y){
  string m=minusculas(x);
  string n=minusculas(y);
  return m[0]>n[0];
}
bool operator<(string x,string y){
  string m=minusculas(x);
  string n=minusculas(y);
  return m[0]<n[0];
}
template<class T>
void imprimirArrayPtrs(vector <T*>imprimir){
  for(int i=0;i<imprimir.size();i++){
    cout<<"   "<<i+1<<"."<<*(imprimir[i])<<endl;
  }
}
string codigosAleatorios(){
  srand(time(NULL));
  string codigo="AAAA0000";
  for(int i=0;i<4;i++){
    char let=65+rand()%(91-65);
    codigo[i]=let;
  }
  for(int i=5;i<8;i++){
    int num=0+rand()%(10);
    codigo[i]=to_string(num)[0];
  }
  return codigo;
}
bool Buscar(string palabra1, string palabra2){
  string p1,p2;
  if (palabra1.length()>palabra2.length()){
    p2=minusculas(palabra1);
    p1=minusculas(palabra2);
  }else{
    p1=minusculas(palabra1);
    p2=minusculas(palabra2);

  }
  for(int i=0;i<p2.length();i++){
    bool primeraLetra=false;
    if (p1[0]==p2[i]){
      primeraLetra=true;
    }
    if (primeraLetra){
      bool respuesta=true;
      for(int e=0;e<p1.length();e++){
        if (p1[e]!=p2[i+e]){
          respuesta=false;
        }
      }
      if (respuesta){
        return true;
      }
    }

  }
  return false;
}
bool SiNo(string pregunta){
  try{
    cout<<pregunta<<endl<<endl;
    cout<<"opcion: ";
    char opcion;
    cin>>opcion;
    if(opcion=='s'){
      return true;
    }else if(opcion=='n'){
      return false;
    }else{
      throw opcion;
    }
  }
  catch (char e){
    cout<<"La opcion no es valida."<<endl;
    system("pause");
    system("cls");
    return SiNo(pregunta);
  }
}
int OpcionesLista(int size, string pregunta){
  try{
    cout<<endl<<pregunta;
    int rpta;
    cin>>rpta;
    if(rpta>size){
      throw rpta;
    }else{
      return rpta-1;
    }
  }
  catch(int e){
    cout<<endl<<"              La opcion no es valida, intente de nuevo."<<endl;
    return OpcionesLista(size,pregunta);
  }
}
void editarInformacion(Propietario*porEditar){
  system("cls");
  cout<<"Que desea editar?"<<endl;
  cout<<"   1.Nombre"<<endl;
  cout<<"   2.Apellido"<<endl;
  cout<<"   3.Telefono"<<endl;
  cout<<"   4.Direccion"<<endl;
  int opcion;
  cout<<endl<<endl<<"opcion: ";
  cin>>opcion;
  switch(opcion){
    case 1:{
      system("cls");
      string nombre;
      fflush(stdin);
      cout<<"Ingrese el nuevo dato: ";
      getline(cin,nombre);
      (*porEditar).editNombre(nombre);
      cout<<endl<<"Dato cambiado correctamente."<<endl;
      system("pause");
      break;
    }
    case 2:{
      system("cls");
      string apellido;
      fflush(stdin);
      cout<<"Ingrese el nuevo dato: ";
      getline(cin,apellido);
      (*porEditar).editApellido(apellido);
      cout<<endl<<"Dato cambiado correctamente."<<endl;
      system("pause");
      break;
    }
    case 3:{
      system("cls");
      string telefono;
      fflush(stdin);
      cout<<"Ingrese el nuevo dato: ";
      getline(cin,telefono);
      (*porEditar).editTelefono(telefono);
      cout<<endl<<"Dato cambiado correctamente."<<endl;
      system("pause");
      break;
    }
    case 4:{
      system("cls");
      string direccion;
      fflush(stdin);
      cout<<"Ingrese el nuevo dato: ";
      getline(cin,direccion);
      (*porEditar).editDireccion(direccion);
      cout<<endl<<"Dato cambiado correctamente."<<endl;
      system("pause");
      break;
    }
  }
}
void editarInformacion(Animal*porEditar){
  system("cls");
  cout<<"Que desea editar?"<<endl;
  cout<<"   1.Raza"<<endl;
  cout<<"   2.Nombre"<<endl;
  cout<<"   3.Color"<<endl;
  cout<<"   4.Fecha de nacimiento"<<endl;
  cout<<"   5.Sexo"<<endl;
  int opcion;
  cout<<endl<<endl<<"opcion: ";
  cin>>opcion;
  switch(opcion){
    case 1:{
      system("cls");
      string raza;
      fflush(stdin);
      cout<<"Ingrese el nuevo dato: ";
      getline(cin,raza);
      (*porEditar).editRaza(raza);
      cout<<endl<<"Dato cambiado correctamente."<<endl;
      system("pause");
      break;
    }
    case 2:{
      system("cls");
      string nombre;
      fflush(stdin);
      cout<<"Ingrese el nuevo dato: ";
      getline(cin,nombre);
      (*porEditar).editNombre(nombre);
      cout<<endl<<"Dato cambiado correctamente."<<endl;
      system("pause");
      break;
    }
    case 3:{
      system("cls");
      string color;
      fflush(stdin);
      cout<<"Ingrese el nuevo dato: ";
      getline(cin,color);
      (*porEditar).editColor(color);
      cout<<endl<<"Dato cambiado correctamente."<<endl;
      system("pause");
      break;
    }
    case 4:{
      system("cls");
      int day;
      int month;
      int year;
      fflush(stdin);
      cout<<"Ingrese el nuevo dato: "<<endl;
      cout<<" Dia: ";
      cin>>day;
      cout<<" Mes: ";
      cin>>month;
      cout<<" Anio: ";
      cin>>year;
      (*porEditar).editNacimiento(day,month,year);
      cout<<endl<<"Dato cambiado correctamente."<<endl;
      system("pause");
      break;
    }
    case 5:{
      system("cls");
      int sexo;
      fflush(stdin);
      cout<<"Ingrese el nuevo dato: ";
      cin>>sexo;
      (*porEditar).editSexo(sexo);
      cout<<endl<<"Dato cambiado correctamente."<<endl;
      system("pause");
      break;
    }

  }
}
void burbujaNombre(vector<Propietario*>&arr,int tam){
  bool cambio=true;
  while (cambio){
    cambio=false;
    for(int i=0;i<tam-1;i++){
      if ((*arr[i]).getNombre()>(*arr[i+1]).getNombre()){
        Propietario*c=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=c;
        cambio=true;
      }
    }
    tam--;
  }
}
void burbujaInversoNombre(vector<Propietario*>&arr,int tam){
  bool cambio=true;
  while (cambio){
    cambio=false;
    for(int i=0;i<tam-1;i++){
      if ((*arr[i]).getNombre()<(*arr[i+1]).getNombre()){
        Propietario*c=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=c;
        cambio=true;
      }
    }
    tam--;
  }
}
void burbujaApellido(vector<Propietario*>&arr,int tam){
  bool cambio=true;
  while (cambio){
    cambio=false;
    for(int i=0;i<tam-1;i++){
      if ((*arr[i]).getApellido()>(*arr[i+1]).getApellido()){
        Propietario*c=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=c;
        cambio=true;
      }
    }
    tam--;
  }
}
void burbujaInversoApellido(vector<Propietario*>&arr,int tam){
  bool cambio=true;
  while (cambio){
    cambio=false;
    for(int i=0;i<tam-1;i++){
      if ((*arr[i]).getApellido()<(*arr[i+1]).getApellido()){
        Propietario*c=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=c;
        cambio=true;
      }
    }
    tam--;
  }
}

//funciones de utilidad
Propietario crearPropietario(vector<Propietario>&arrayPropietarios){
  system("cls");
  string nombre;
  string apellido;
  string telefono;
  string direccion;
  cout<<"   Ingrese el nombre del propietario: ";
  fflush(stdin);
  getline(cin,nombre);
  cout<<"   Ingrese el apellido del propietario: ";
  fflush(stdin);
  getline(cin,apellido);
  cout<<"   Ingrese el telefono del propietario: ";
  fflush(stdin);
  getline(cin,telefono);
  cout<<"   Ingrese la direccion del propietario: ";
  fflush(stdin);
  getline(cin,direccion);
  string codigoxd=codigosAleatorios();
  Propietario nuevoP(codigoxd,nombre,apellido,telefono,direccion);
  arrayPropietarios.push_back(nuevoP);
  return(nuevoP);
}
void crearAnimal(string codigoPropietario,vector<Animal>&arrayMascotas){
  system("cls");
  string raza;
  string nombre;
  string color;
  int day;
  int month;
  int year;
  int sexo;
  cout<<"Crear nuevo animal:"<<endl;
  cout<<"   Ingrese la raza del animal: ";
  fflush(stdin);
  getline(cin,raza);
  cout<<"   Ingrese el nombre del animal: ";
  fflush(stdin);
  getline(cin,nombre);
  cout<<"   Ingrese el color del animal: ";
  fflush(stdin);
  getline(cin,color);
  cout<<"   Ingrese la fecha de nacimiento del animal:"<<endl;
  cout<<"     -Dia: ";
  cin>>day;
  cout<<"     -Mes: ";
  cin>>month;
  cout<<"     -Ano: ";
  cin>>year;
  cout<<"   Ingrese el sexo del animal:"<<endl;
  cout<<"     1.Macho"<<endl;
  cout<<"     2.Hembra"<<endl;
  cin>>sexo;
  Animal nuevoA(codigoPropietario,raza,nombre,color,day,month,year,sexo);
  arrayMascotas.push_back(nuevoA);
  return;
}
vector <Propietario*> ArrayResultados(string comodin,vector<Propietario>&arrayPropietarios){
  vector <Propietario*> Coinciden;
  for(int i=0;i<arrayPropietarios.size();i++){
    if((Buscar(comodin,(arrayPropietarios[i]).getNombre()))or(Buscar(comodin,(arrayPropietarios[i]).getApellido()))){
      Coinciden.push_back(&arrayPropietarios[i]);
    }
  }
  return Coinciden;
}
vector <Propietario*> ArrayAuxiliar(vector<Propietario>&arrayPropietarios){
  vector <Propietario*> aux;
  for(int i=0;i<arrayPropietarios.size();i++){
    aux.push_back(&arrayPropietarios[i]);
  }
  return aux;
}
vector <Animal*> arrayMascotasResultado(string codigoDelPropietario,vector<Animal>&arrayMascotas){
  vector <Animal*> Coinciden;
  for(int i=0;i<arrayMascotas.size();i++){
    if((arrayMascotas[i]).getCodigoDelPropietario()==codigoDelPropietario){
      Coinciden.push_back(&arrayMascotas[i]);
    }
  }
  return Coinciden;
}
void manejoInformacionMascota(Animal*porManejar,vector<Propietario>&arrayPropietarios,vector<Animal>&arrayMascotas){
  system("cls");
  cout<<"DATOS DE LA MASCOTA"<<endl;
  (*porManejar).Informacion();
  cout<<endl<<endl<<endl<<endl<<"                                                     1.Editar"<<endl;
  cout<<"                                                     2.Eliminar"<<endl;
  cout<<"                                                     3.Salir"<<endl;
  int opcion;
  cout<<endl<<"                                                     opcion: ";
  cin>>opcion;
  switch (opcion) {
    case 1:{
      editarInformacion(porManejar);
      break;
    }
    case 2:{
      system("cls");
      if(SiNo("Seguro que desea eliminarlo? s/n")){
        for(int i=0;i<arrayMascotas.size();i++){
          if(((*porManejar).getCodigoDelPropietario()==(arrayMascotas[i]).getCodigoDelPropietario())and((*porManejar).getNombre()==(arrayMascotas[i]).getNombre())){
            arrayMascotas.erase(arrayMascotas.begin()+i);
          }
        }
        cout<<"Mascota Eliminado."<<endl;
      }else{
        return;
      }

      break;
    }
}
}
void manejoInformacion(Propietario*porManejar,vector<Propietario>&arrayPropietarios,vector<Animal>&arrayMascotas){
  system("cls");
  cout<<"DATOS DEL PROPIETARIO"<<endl;
  (*porManejar).Informacion();
  cout<<endl<<endl<<endl<<endl<<"                                                     1.Editar"<<endl;
  cout<<"                                                     2.Eliminar"<<endl;
  cout<<"                                                     3.Ver mascotas"<<endl;
  cout<<"                                                     4.Salir"<<endl;
  int opcion;
  cout<<endl<<"                                                     opcion: ";
  cin>>opcion;
  switch (opcion) {
    case 1:{
      editarInformacion(porManejar);
      break;
    }
    case 2:{
      system("cls");
      if(SiNo("Seguro que desea eliminarlo? s/n")){
        for(int i=0;i<arrayPropietarios.size();i++){
          if((*porManejar).getCodigo()==(arrayPropietarios[i]).getCodigo()){
            arrayPropietarios.erase(arrayPropietarios.begin()+i);
          }
        }
        cout<<"Propietario Eliminado."<<endl;
        system("pause");
      }else{
        return;
      }

      break;
    }
    case 3:{
      system("cls");
      vector <Animal*>Resultados=arrayMascotasResultado((*porManejar).getCodigo(),arrayMascotas);
      if(Resultados.size()==1){
        cout<<"Mascota de "<<(*porManejar).getNombre()<<endl;
      }else{
        cout<<"mascotas de"<<(*porManejar).getNombre()<<endl;
      }
      imprimirArrayPtrs<Animal>(Resultados);
      int rpta=OpcionesLista(Resultados.size(),"Opcion: ");
      manejoInformacionMascota(Resultados[rpta],arrayPropietarios,arrayMascotas);
  }
    case 4:{
      break;
    }
}
}

//funciones principales
void cargar(vector<Propietario>&arrayPropietarios){
  ifstream nuevo("TodosLosPropietarios.txt");
  int cantidad;
  nuevo>>cantidad;
  nuevo.ignore();
  for(int i=0;i<cantidad;i++){
    string codigo;
    string nombre;
    string apellido;
    string telefono;
    string direccion;
    getline(nuevo,codigo);
    getline(nuevo,nombre);
    getline(nuevo,apellido);
    getline(nuevo,telefono);
    getline(nuevo,direccion);
    Propietario nuevoP(codigo,nombre,apellido,telefono,direccion);
    arrayPropietarios.push_back(nuevoP);
  }
}
void cargar(vector<Animal>&arrayMascotas){
  ifstream nuevo("TodasLasMascotas.txt");
  int cantidad;
  nuevo>>cantidad;
  nuevo.ignore();
  for(int i=0;i<cantidad;i++){
    string codigoDelPropietario;
    string raza;
    string nombre;
    string color;
    int day;
    int month;
    int year;
    int sexo;
    getline(nuevo,codigoDelPropietario);
    getline(nuevo,raza);
    getline(nuevo,nombre);
    getline(nuevo,color);
    nuevo>>day;
    nuevo>>month;
    nuevo>>year;
    nuevo>>sexo;
    nuevo.ignore();
    Animal nuevoA(codigoDelPropietario,raza,nombre,color,day,month,year,sexo);
    arrayMascotas.push_back(nuevoA);
  }
}
void guardar(vector<Propietario>&arrayPropietarios){
  ofstream guar("TodosLosPropietarios.txt");
  guar<<arrayPropietarios.size()<<endl;
  for(int i=0;i<arrayPropietarios.size();i++){
    guar<<arrayPropietarios[i].getCodigo()<<endl;
    guar<<arrayPropietarios[i].getNombre()<<endl;
    guar<<arrayPropietarios[i].getApellido()<<endl;
    guar<<arrayPropietarios[i].getTelefono()<<endl;
    guar<<arrayPropietarios[i].getDireccion()<<endl;
  }

}
void guardar(vector<Animal>&arrayMascotas){
  ofstream guar("TodasLasMascotas.txt");
  guar<<arrayMascotas.size()<<endl;
  for(int i=0;i<arrayMascotas.size();i++){
    guar<<arrayMascotas[i].getCodigoDelPropietario()<<endl;
    guar<<arrayMascotas[i].getRaza()<<endl;
    guar<<arrayMascotas[i].getNombre()<<endl;
    guar<<arrayMascotas[i].getColor()<<endl;
    guar<<arrayMascotas[i].getNacimiento(0)<<endl;
    guar<<arrayMascotas[i].getNacimiento(1)<<endl;
    guar<<arrayMascotas[i].getNacimiento(2)<<endl;
    guar<<arrayMascotas[i].getSexo()<<endl;
  }

}
void MenuInscribir(vector<Propietario>&arrayPropietarios,vector<Animal>&arrayMascotas){
  system("cls");
  if(SiNo("El Propietario ya ha sido registrado? s/n:")){
    system("cls");
    cout<<"Ingrese el nombre o apellido del propietario: ";
    string comodin;
    cin>>comodin;
    vector <Propietario*>Resultados=ArrayResultados(comodin,arrayPropietarios);
    imprimirArrayPtrs<Propietario>(Resultados);
    if (Resultados.size()==0){
      cout<<endl<<"No se obtuvieron resultados."<<endl<<endl;
      system("pause");
      return;
    }
    int rpta=OpcionesLista(Resultados.size(),"Opcion: ");
    crearAnimal((*Resultados[rpta]).getCodigo(),arrayMascotas);
  }else{
    cout<<"inscribiendo propietario: "<<endl;
    Propietario nuevo=crearPropietario(arrayPropietarios);
    crearAnimal(nuevo.getCodigo(),arrayMascotas);


  }
}
void MenuBusqueda(vector<Propietario>&arrayPropietarios,vector<Animal>&arrayMascotas){
  system("cls");
  cout<<"Ingrese el nombre o apellido del propietario: ";
  string comodin;
  cin>>comodin;
  vector <Propietario*>Resultados=ArrayResultados(comodin,arrayPropietarios);
  imprimirArrayPtrs<Propietario>(Resultados);
  if (Resultados.size()==0){
    cout<<endl<<"No se obtuvieron resultados."<<endl<<endl;
    system("pause");
    return;
  }
  int rpta=OpcionesLista(Resultados.size(),"Cual desea ver: ");
  manejoInformacion(Resultados[rpta],arrayPropietarios,arrayMascotas);
}
void MenuBusquedaMascota(vector<Propietario>&arrayPropietarios,vector<Animal>&arrayMascotas){
  system("cls");
  cout<<"Ingrese el nombre o apellido del propietario: ";
  string comodin;
  cin>>comodin;
  vector <Propietario*>Resultados=ArrayResultados(comodin,arrayPropietarios);
  imprimirArrayPtrs<Propietario>(Resultados);
  if (Resultados.size()==0){
    cout<<endl<<"No se obtuvieron resultados."<<endl<<endl;
    system("pause");
    return;
  }
  int rpta=OpcionesLista(Resultados.size(),"Cual desea ver: ");
  system("cls");
  vector <Animal*>Mascotas=arrayMascotasResultado((*Resultados[rpta]).getCodigo(),arrayMascotas);
  if(Mascotas.size()==1){
    cout<<"Mascota de "<<(*Resultados[rpta]).getNombre()<<endl;
  }else{
    cout<<"mascotas de"<<(*Resultados[rpta]).getNombre()<<endl;
  }
  imprimirArrayPtrs<Animal>(Mascotas);
  int rpta2=OpcionesLista(Mascotas.size(),"Opcion: ");
  manejoInformacionMascota(Mascotas[rpta2],arrayPropietarios,arrayMascotas);
  system("pause");
}
void MenuListado(vector<Propietario>&arrayPropietarios,vector<Animal>&arrayMascotas){
  system("cls");
  vector <Propietario*>aux=ArrayAuxiliar(arrayPropietarios);
  int opcion;
  cout<<"Como desea que este ordenada la lista?"<<endl;
  cout<<"   1.Por nombre A-Z."<<endl;
  cout<<"   2.Por nombre Z-A."<<endl;
  cout<<"   3.Por apellido A-Z."<<endl;
  cout<<"   4.Por apellido Z-A."<<endl<<endl;
  cout<<"Opcion; ";
  cin>>opcion;

  switch(opcion){
    case 1:{
      system("cls");
      burbujaNombre(aux,aux.size());
      imprimirArrayPtrs<Propietario>(aux);
      int rpta=OpcionesLista(aux.size(),"Cual desea ver: ");
      manejoInformacion(aux[rpta],arrayPropietarios,arrayMascotas);
      break;
    }
    case 2:{
      system("cls");
      burbujaInversoNombre(aux,aux.size());
      imprimirArrayPtrs<Propietario>(aux);
      int rpta=OpcionesLista(aux.size(),"Cual desea ver: ");
      manejoInformacion(aux[rpta],arrayPropietarios,arrayMascotas);
      break;
    }
    case 3:{
      system("cls");
      burbujaApellido(aux,aux.size());
      imprimirArrayPtrs<Propietario>(aux);
      int rpta=OpcionesLista(aux.size(),"Cual desea ver: ");
      manejoInformacion(aux[rpta],arrayPropietarios,arrayMascotas);
      break;
    }
    case 4:{
      system("cls");
      burbujaInversoApellido(aux,aux.size());
      imprimirArrayPtrs<Propietario>(aux);
      int rpta=OpcionesLista(aux.size(),"Cual desea ver: ");
      manejoInformacion(aux[rpta],arrayPropietarios,arrayMascotas);
      break;
    }
  }
}
void MenuSalir(bool &bucle){
  system("cls");
  if(SiNo("Seguro que desea salir? s/n")){
    system("cls");
    cout<<"Adios :D."<<endl;
    bucle=false;
  }else{
    return;
  }

}
