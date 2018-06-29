#include "Parque.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
using namespace std;

int ** leerEspera() {
    int ** matriz;
    int filas = 36;
    int columnas = 8;
    std::ifstream entrada;
    int i = -1;
    int hora, Bumeran, Choconcitos, Torre, conchas, SkyMaster;
    int Pulpo, disko, Splash;

    matriz = new int*[filas];
    for (int i = 0; i < filas; i++)
        matriz[i] = new int[columnas];

    entrada.open("espera.csv", ios::in);
    entrada >> hora >> Torre >> Splash >> Bumeran >> Choconcitos >> Pulpo >> conchas
            >> disko >> SkyMaster;

    while (!entrada.eof()) {
        i++;

        matriz[i][0] = Torre;
        matriz[i][1] = Splash;
        matriz[i][2] = Bumeran;
        matriz[i][3] = Choconcitos;
        matriz[i][4] = Pulpo;
        matriz[i][5] = conchas;
        matriz[i][6] = disko;
        matriz[i][7] = SkyMaster;
        entrada >> hora >> Torre >> Splash >> Bumeran >> Choconcitos >> Pulpo >> conchas
                >> disko >> SkyMaster;
    }

    matriz[i][0] = Torre;
    matriz[i][1] = Splash;
    matriz[i][2] = Bumeran;
    matriz[i][3] = Choconcitos;
    matriz[i][4] = Pulpo;
    matriz[i][5] = conchas;
    matriz[i][6] = disko;
    matriz[i][7] = SkyMaster;


    return matriz;
}

int** intervaloEspera(int* * const espera, int inicio, int final) {
    int filas = final - inicio;
    int columnas = 8;
    int** matriz = new int*[filas];

    for (int i = 0; i < filas; i++)
        matriz [i] = new int [columnas];

    int h = 0;

    for (int i = inicio; i < final; i++) {
        for (int j = 0; j < columnas; j++)
            matriz [h][j] = espera [i][j];

        h++;
    }
    return matriz;
}

int** leerTraslado() {
    int ** matriz;
    int tamano = 9;
    std::ifstream entrada;
    int i = -1;
    int Bumeran, Choconcitos, Torre, conchas, SkyMaster;
    int Pulpo, disko, Splash, salida;

    matriz = new int* [tamano];

    for (int i = 0; i < tamano; i++)
        matriz[i] = new int [tamano];

    entrada.open("traslado.csv", ios::in);

    entrada >> Torre >> Splash >> Bumeran >> Choconcitos >> Pulpo >> conchas
            >> disko >> SkyMaster >> salida;

    while (!entrada.eof()) {
        i++;

        matriz[i][0] = Torre;
        matriz[i][1] = Splash;
        matriz[i][2] = Bumeran;
        matriz[i][3] = Choconcitos;
        matriz[i][4] = Pulpo;
        matriz[i][5] = conchas;
        matriz[i][6] = disko;
        matriz[i][7] = SkyMaster;
        matriz[i][8] = salida;


        entrada >> Torre >> Splash >> Bumeran >> Choconcitos >> Pulpo >> conchas
                >> disko >> SkyMaster >> salida;
    }



    return matriz;
}

int* leerDisfrute() {
    std::ifstream entrada;
    int Bumeran, Choconcitos, Torre, conchas, SkyMaster;
    int Pulpo, disko, Splash;

    int * disfrute = new int[8];
    entrada.open("disfrute.csv", std::ios::in);

    entrada >> Torre >> Splash >> Bumeran >> Choconcitos >> Pulpo >> conchas
            >> disko >> SkyMaster;

    disfrute[0] = Torre;
    disfrute[1] = Splash;
    disfrute[2] = Bumeran;
    disfrute[3] = Choconcitos;
    disfrute[4] = Pulpo;
    disfrute[5] = conchas;
    disfrute[6] = disko;
    disfrute[7] = SkyMaster;


    return disfrute;
}

void imprimirResultado(std::vector<int> atracciones, Parque p) {
    std::cout << "\n~ ~ ~ ~ ~ ~ ~ RESULTADOS OBTENIDOS ~ ~ ~ ~ ~ ~ ~ \n" << std::endl;
    std::cout << "\nRuta a seguir:  \n\n";

    int j = 1;

    for (std::vector<int>::iterator i = atracciones.begin(); i != atracciones.end(); i++) {
        std::cout << j << " ";
        switch (*i) {
            case 0:
                std::cout << "~ Torre" << std::endl;
                break;
            case 1:
                std::cout << "~ splash" << std::endl;
                break;
            case 2:
                std::cout << "~ bumeran" << std::endl;
                break;
            case 3:
                std::cout << "~ choconcitos" << std::endl;
                break;
            case 4:
                std::cout << "~ pulpo" << std::endl;
                break;
            case 5:
                std::cout << "~ conchas" << std::endl;
                break;
            case 6:
                std::cout << "~ disko" << std::endl;
                break;
            case 7:
                std::cout << "~ skymaster" << std::endl;
                break;

        }
        j++;
    }
    std::cout << "Cantidad maxima de atracciones a visitar: " << p.atraccionesMaximas << std::endl;
}

int horaLlegada(int opcion) {
    switch (opcion) {
        case 9:
            return 0;
            break;
        case 905:
            return 1;
            break;
        case 910:
            return 2;
            break;
        case 915:
            return 3;
            break;
        case 920:
            return 4;
            break;
        case 925:
            return 5;
            break;
        case 930:
            return 6;
            break;
        case 935:
            return 7;
            break;
        case 940:
            return 8;
            break;
        case 945:
            return 9;
            break;
        case 950:
            return 10;
            break;
        case 955:
            return 11;
            break;
        case 10:
            return 12;
            break;
        case 1005:
            return 13;
            break;
        case 1010:
            return 14;
            break;
        case 1015:
            return 15;
            break;
        case 1020:
            return 16;
            break;
        case 1025:
            return 17;
            break;
        case 1030:
            return 18;
            break;
        case 1035:
            return 19;
            break;
        case 1040:
            return 20;
            break;
        case 1045:
            return 21;
            break;
        case 1050:
            return 22;
            break;
        case 1055:
            return 23;
            break;
        case 11:
            return 24;
            break;
        case 1105:
            return 25;
            break;
        case 1110:
            return 26;
            break;
        case 1115:
            return 27;
            break;
        case 1120:
            return 28;
            break;
        case 1125:
            return 29;
            break;
        case 1130:
            return 30;
            break;
        case 1135:
            return 31;
            break;
        case 1140:
            return 32;
            break;
        case 1145:
            return 33;
            break;
        case 1150:
            return 34;
            break;
        case 1155:
            return 35;
            break;
    }
}

int horaSalida(int opcion, int horaLlegada) {
    switch (opcion) {
        case 15:
            return horaLlegada + (3);
            break;
        case 20:
            return horaLlegada + (4);
            break;
        case 25:
            return horaLlegada + (5);
            break;
        case 30:
            return horaLlegada + (6);
            break;
        case 35:
            return horaLlegada + (7);
            break;
        case 40:
            return horaLlegada + (8);
            break;
        case 45:
            return horaLlegada + (9);
            break;
        case 50:
            return horaLlegada + (10);
            break;
        case 55:
            return horaLlegada + (11);
            break;
        case 60:
            return horaLlegada + (12);
            break;
        case 65:
            return horaLlegada + (13);
            break;
        case 70:
            return horaLlegada + (14);
            break;
        case 75:
            return horaLlegada + (15);
            break;
        case 80:
            return horaLlegada + (16);
            break;
        case 85:
            return horaLlegada + (17);
            break;
        case 90:
            return horaLlegada + (18);
            break;
        case 95:
            return horaLlegada + (19);
            break;
        case 100:
            return horaLlegada + (20);
            break;
        case 105:
            return horaLlegada + (21);
            break;
            break;
        case 110:
            return horaLlegada + (22);
            break;
            break;
        case 115:
            return horaLlegada + (23);
            break;
        case 120:
            return horaLlegada + (24);
            break;
             case 125:
            return horaLlegada + (25);
            break;
            case 130:
            return horaLlegada + (26);
            break;
            case 135:
            return horaLlegada + (27);
            break;
              case 140:
            return horaLlegada + (28);
            break;
             case 145:
            return horaLlegada + (29);
            break;
             case 150:
            return horaLlegada + (30);
            break;
              case 155:
            return horaLlegada + (31);
            break;
              case 160:
            return horaLlegada + (32);
            break;
              case 165:
            return horaLlegada + (33);
            break;
             case 170:
            return horaLlegada + (34);
            break;
             case 175:
            return horaLlegada + (35);
            break;
        case 180:
            return horaLlegada + (36);
            break;

    }
}

int main() {
    Parque parque;
    string opcion = "s";
    int entrada = 0;
    int salida = 0;
    int ** espera = leerEspera();

    int ** traslado = leerTraslado();
    int * disfrute = leerDisfrute();
    //int a = 1;
    //int b = 1;
    //int cont = 1;
    std::cout << "\n -------- VISITA DEL PROFESOR CASSASOLA AL PARQUE DE DIVERSIONES --------\n" << std::endl;
    std::cout << "Desea visitar el parque? s/n \n";

    std::cin >> opcion;

    do {
        std::cout << "\nPor favor indique su hora de llegada (de 9 a 11:50 en multiplos de 5 min )\n";
        std::cin >> entrada;
        entrada = horaLlegada(entrada);
        std::cout << "\nCuantos minutos desea permanecer en el parque? (60(1hora) 120(2 horas) 180(3 horas))\n";
        std::cin >> salida;
        salida = horaSalida(salida, entrada);
        //entrada = horaLlegada(a);
        //salida = horaSalida(b,entrada);
        int ** esperaInt = intervaloEspera(espera, entrada, salida);
        double t1, t0;
        t0 = clock();
        std::vector <int> resultado = parque.busquedaExhaustiva((const int**) esperaInt, salida - entrada, 8, disfrute, (const int**) traslado);
        t1 = clock();
        double time = (double(t1 - t0));
        imprimirResultado(resultado, parque);

        cout << "tiempo" << time << endl;

        std::cout << "\nDesea seleccionar algun otro horario? s/n \n ";
        std::cin >> opcion;

    } while (opcion == "s");
    return 0;
}
