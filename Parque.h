#ifndef PARQUE
#define PARQUE
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Parque {
public:

    Parque() {
    }

    ~Parque() {
    }

    int atraccionesMaximas;

    std::vector<int> busquedaExhaustiva(const int** espera, int m, int n, const int* disfrute, const int** traslado) {
        crearEspera(espera, m, n);
        tiempoFinal = m;
        numAtracciones = n;
        crearDisfrute(disfrute, n);
        crearTraslado(traslado, n);
        atraccionesMaximas = fase(-1, 0);
        return sigma;
    }

    std::vector<int> programacionDinamica(const int** espera, int m, int n, const int* disfrute, const int** traslado) {
    }

    std::vector<int> algoritmoAvido(const int** espera, int m, int n, const int* disfrute, const int** traslado);

private:

    int** espera;
    int* disfrute;
    int** traslado;
    int tiempoFinal, numAtracciones;
    std::vector <int> sigma;

    int fase(int atraccion, int tiempo) {
        int cantidad = 0;
        int cantidadMaxima = 0;
        std::vector <int> sigmaMax;
        if (atraccion != -1) {
            if ((tiempo + traslado[atraccion][numAtracciones]) == tiempoFinal)
                return 1;
            if ((tiempo + traslado[atraccion][numAtracciones]) >= tiempoFinal)
                return 0;
        }

        //Entrada
        if (atraccion == -1) {
            for (int j = 0; j <= numAtracciones - 1; j++) {
                if ((traslado[0][j] + tiempo) < tiempoFinal) {
                    cantidad = fase(j, tiempo + traslado[0][j] + espera[traslado[0][j] + tiempo] [j] + disfrute[j]);
                    if (cantidad != 0) {
                        if (cantidad >= cantidadMaxima) {
                            cantidadMaxima = cantidad;
                            sigma.insert(sigma.begin(), j);
                            sigmaMax = sigma;
                            sigma.clear();
                        }
                    }
                }
            }
        } else {
            for (int j = 0; j <= numAtracciones - 1; j++) {
                if (atraccion != j && (traslado[atraccion + 1][j] + tiempo) < tiempoFinal) {
                    cantidad = fase(j, tiempo + traslado[atraccion + 1][j] + espera[traslado[atraccion + 1][j] + tiempo] [j] + disfrute[j]);
                    if (cantidad != 0) {
                        if (cantidad >= cantidadMaxima) {
                            cantidadMaxima = cantidad;
                            sigma.insert(sigma.begin(), j);
                            sigmaMax = sigma;
                            sigma.clear();
                        }
                    }
                }
            }
        }

        if (atraccion != -1)
            cantidadMaxima++;
        sigma = sigmaMax;
        return cantidadMaxima;
    }

    void crearEspera(const int** M, int m, int n) {
        int filas = m;
        int columnas = n;
        espera = new int*[filas];

        for (int i = 0; i < filas; i++)
            espera [i] = new int [columnas];

        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++)
                espera [i][j] = M [i][j];
        }
    }

    void crearTraslado(const int** M, int n) {
        int filas = n + 1;
        int columnas = n + 1;
        traslado = new int*[filas];

        for (int i = 0; i < filas; i++)
            traslado [i] = new int [columnas];

        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++)
                traslado [i][j] = M [i][j];
        }
    }

    void crearDisfrute(const int* vec, int n) {
        int columnas = n;
        disfrute = new int [columnas];

        for (int i = 0; i < columnas; i++)
            disfrute [i] = vec [i];
    }
};
#endif