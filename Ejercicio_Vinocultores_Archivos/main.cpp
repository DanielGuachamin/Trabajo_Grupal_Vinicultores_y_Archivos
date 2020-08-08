#include <iostream>
#include <fstream>

using namespace std;

double Tipo_tamaUva(char a);
void Guardar();

int main() {
  Guardar();
}
void Guardar()
{
  ofstream Archivo_Uvas;
  string NombreArchivo;
  cout << "Ingrese el nombre de su archivo (.txt): ";
  getline(cin,NombreArchivo);
  Archivo_Uvas.open(NombreArchivo.c_str(), ios::out);

  if(Archivo_Uvas.fail())
  {
    cout << "El archivo no abrio exitosamente" << endl;
  }

  double precio_cargado, ganancia, precio_inicial;
  char tipo;
  int kilos;
  cout << "\n* * * Asociación de Vinicultores * * *" << endl;
  cout << "\nIngrese el precio inicial de la Uva: ";
  cin >> precio_inicial;
  cout << "\nIngrese la cantidad de Uva en kilos: ";
  cin >> kilos;
  do
  {
    cout << "\nIngrese el tipo de Uva (A o B): ";
    cin >> tipo;
    if((tipo != 'A') && (tipo != 'B'))
    {
      cout << "\nEliga un tipo de Uva correcto" << endl;
    }
  } while((tipo != 'A') && (tipo != 'B'));
  precio_cargado = Tipo_tamaUva(tipo);
  ganancia = (precio_inicial + precio_cargado) * kilos;

  Archivo_Uvas << "Precio inicial de Uva: $" << precio_inicial << '\n';
  Archivo_Uvas << "Kilos de Uva: " << kilos << '\n' ;
  Archivo_Uvas << "Tipo de Uva: " <<tipo << '\n';
  Archivo_Uvas << "Precio cargado al precio inicial: " << precio_cargado << "¢" << '\n';
  Archivo_Uvas << "Ganancia obtenida: $" << ganancia;

  cout << "\nGanancia obtenida: $" << ganancia;

  Archivo_Uvas.close();
}
double Tipo_tamaUva(char a)
{
  double precio;
  int tamanio;
  do
  {
    cout << "\nIngrese el tamaño de Uva (1 o 2): ";
    cin >> tamanio;
    if((tamanio != 1) && (tamanio != 2))
    {
      cout << "\nEliga un tamaño de Uva correcto" << endl;
    }
  } while((tamanio != 1) && (tamanio != 2));
  if(a == 'A')
  {
    if(tamanio == 1)
    {
      precio = 0.20;
    }
    else
    {
      precio = 0.30;
    }
  }
  else
  {
    if(tamanio == 1)
    {
      precio = -0.30;
    }
    else
    {
      precio = -0.50;
    }
  }
  return precio;
}
