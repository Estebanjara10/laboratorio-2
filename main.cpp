#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include <string>



using namespace std;
long potenciaNum(long numero, long potencia);
long str_to_num(string n);
void num_to_str(int num, string& strx);

int main()
   {
    int opcion=1;
    int pesos[10]={50000,20000,10000,5000,2000,1000,500,200,100,50};
    char letras[200];
    string palabra;
    string strbase = "base";
    string n;
    int num;



    //
    srand(time(NULL));
    //

    while (opcion != 0){
     cout << endl << "seleccione una opcion" << endl;
     cout << "------------------------------"<<endl;
     cout << "1.Combinacion de billetes"<<endl;
     cout << "2.Letras aleatorias"<<endl;
     cout << "4.De string a Int"<<endl;
     cout << "5.De Int a string"<<endl;
     cout << "7.caracteres repetidos"<<endl;
     cout << "0.Para SALIR..."<<endl;
     cout << "------------------------------"<<endl;
     cin>>opcion;
     switch(opcion){
       case 1:
         int valor, entero;
         cout << "ingrese el valor" << endl;
         cin >> valor;
         for (int cont=0;cont < 10;cont++) {
            // paso 1:
            entero = (int)(valor/pesos[cont]); // se crea para ir haciendo divisiones de cada posicion del arreglo por el valor dado
            // paso 2:
            cout << "se necesitan " << entero <<" billetes de " << pesos[cont] <<endl;
            valor=(valor%pesos[cont]);
         }
         cout<< "Faltante: "<<valor<<endl;
         //
         break;
       case 2:
         // inicializa 200 letras aleatorias:
         cout << "VECTOR 200 LETRAS:" << endl;
         for (int i = 0; i < 200; i++){
             letras[i] = 'A' + rand() % (('Z' - 'A') + 1); // genera un numero entre 1-25 de acuerdo al ascii y los suma desde A(65) y Z(90)
             cout << letras[i];
         }
         cout << endl << "------------" << endl;
         // por cada letra del ABC recorrer el vector del 200:
         for (int i = 0; i <= 25; i++){
             //printf("La letra es: '%c' :: y la ABC es:'%c'\n", letras[i], 'A'+i);
             //printf("La ABC es: '%c'\n", 'A'+i);
             int cont = 0;
             char abc = 'A' + i;
             //printf("La ABC es: '%c'\n", abc);
             for(int k=0; k < 200;k++) { // recorrer el vector y contar las cantidad de veces que s erepite cada letra
                 if(abc == letras[k]) {
                    cont++;
                 }
             }
             cout << abc << " : " << cont << endl;
         }
         //
         break;
     case 4:
         cout << "ingrese los numeros: " << endl;
         cin >> n;
         cout << "la conversion es (entero): " << str_to_num(n) << endl;
         break;
     case 5:
         cout  << "ingrese los numeros:  " << endl;
         cin >> num;
         //cout << "el resultado es: " <<  (num%10)/1 << " " << (num%100)/10 << ""  <<  " " << (num%1000)/100 << endl;
         /*
         int temp=num; int l=1;
         while (temp>0) {
                 pote=potenciaNum(10,l);
                 //cout << temp%pote  << endl;
                 temp-=temp%pote;
                 l++;
         }
         l--;
         int digitos[l]; int div=1;
         string numstr="*", tempstr="";
         for (int i=0; i < l ;i++ ) {
             pote=potenciaNum(10,i+1);
             digitos[i]=num%pote/div;
             div=div*10;
             tempstr = numerosStr[digitos[i]];
             numstr.insert(0, tempstr);
             //cout << pote << " " <<  " " << digitos[i] << " "<< div << endl;
             //cout << numerosStr[digitos[i]] << endl;
         }*/
         // Se declara la cadena con texto por defecto para comprobar el cambio por referencia

         num_to_str(num, strbase);
         cout << "la conversion es (texto): " << strbase << endl;
         break;

     case 7:
         cout << "ingrese la palabra: " << endl;
         cin >> palabra;
         string nuevapal = "";
         for (int i=0;i<= (int)palabra.length();i++ ) {
             //
             bool letraExiste = false; // evalua en la nuevapal si ya la letra existe
             for (int k = 0; k < (int)nuevapal.length(); k++) {
                 if(nuevapal[k] == palabra[i]) {
                     letraExiste = true; // creacion de la bandera para verificar
                 }
             }
             if(!letraExiste) { // si la letra no esta en la nuevapal, la concatena y vuelve e inicia el ciclo
                 nuevapal += palabra[i];
             }
         }
         cout << "palabra original: " << palabra << endl;
         cout << "Palabra sin repetidos: " << nuevapal << endl;
         break;

     } // fin switch
   } // fin while
   return 0;
   //

} // fin main
long potenciaNum(long numero, long potencia)
{
    long resultado = numero;
    if(0 == potencia) {
        resultado = 1;
    }
    while (potencia > 1)
    {
        resultado = resultado * numero;
        potencia--;
    }
    return resultado;
}

long str_to_num(string n)
{
    int numeros[10]={'0','1','2','3','4','5','6','7','8','9'};
    int cont=0;  int final=0; int l=n.length();
    for (int i=0; i < l; i++){
        cont=potenciaNum(10, (l-1) - i); // contador de potencias de base 10--- 10^0, 10^1...
        // cout << "n[i]=" << n[i] << endl;
        // cout << "cont=" << cont << endl;

         for (int k=0; k<10 ;k++ ) { // ciclo para iterar en el vector numeros
               if (numeros[k]==n[i]) {
                  final+= k *cont;
               }
         }

     }
     return final;
}
void num_to_str(int num, string& strx) // direccion por parametros de referencia
   {
    int numerosStr[10]={'0','1','2','3','4','5','6','7','8','9'};
    //
    int temp=num; int l=1; int pote=0;
    while (temp>0) {
            pote=potenciaNum(10,l); // potencias base 10 para cada posicion del numero
            //cout << temp%pote  << endl;
            temp-=temp%pote;
            l++;
    }
    l--;
    int digitos[l]; int div=1;
    string numstr="*", tempstr="";
    for (int i=0; i < l ;i++ ) {
        pote=potenciaNum(10,i+1); // division del numero por posicion, separandolos asi en base 10
        digitos[i]=num%pote/div; // encontrar cada numero
        div=div*10;
        tempstr = numerosStr[digitos[i]]; // verificacion si existe el numero en el arreglo
        numstr.insert(0, tempstr); // se utiliza para ordenar el numero
        //cout << pote << " " <<  " " << digitos[i] << " "<< div << endl;
        //cout << numerosStr[digitos[i]] << endl;
    }
     strx = numstr; // valor de string con * para demostrar que si es cadena y se puede concatenar
     return ;
   }

/*
codigo arduino
int pesos[10]={50000,20000,10000,5000,2000,1000,500,200,100,50};
void setup()
{
  Serial.begin(9600);
  Serial.print("ingrese el valor: ");
  delay(6000);
}

void loop()
{
   int valor=Serial.read();
   Serial.print(valor);
   for (int cont=0;cont < 10;cont++) {
            // paso 1:
            int entero=Serial.read();
            //
            entero = (int)(valor/pesos[cont]);
            // paso 2:
            Serial.println ("se necesitan: "); Serial.println(entero); Serial.println(" billetes de "); Serial.println(pesos[cont]);
            //
            valor=(valor%pesos[cont]);

         }

           Serial.println ("Faltante: "); Serial.println(valor);

}
*/

