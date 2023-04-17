#include <iostream>
#include <cstdlib>

using namespace std;

//Funcion para que el usuario seleccione cuantos palitos quitar
int jugador() {
    int palos;
    cout << "Ingrese cuantos palos desea quitar (1-3): ";
    cin >> palos;
    while (palos < 1 || palos > 3) {
        cout << "Ingrese una cantidad valida de palos (1-3): ";
        cin >> palos;
    }
    return palos;
}

//Funcion para que la maquina seleccione cuantos palitos quitar
int maquina(int palos) {
    int maquina = rand() % 3 + 1;
    if (palos < 3) {
        maquina = palos;
    }
    if (palos == 1) {
        maquina = 1;
    }
    return maquina;
}

int main() {
    int palitos = 0;
    cout << "Ingrese el numero de palos:";
    cin >> palitos;
    int jugadorActual = 1;
    cout << "Juego de los Palillos" << endl;
    cout << "=====================" << endl;
    while (palitos > 1) {
        cout << "Palitos restantes: ";
        for (int i = 0; i < palitos; i++) {
            cout << "|";
        }
        cout << endl;
        if (jugadorActual == 1) {
            int palitosQuitados = jugador();
            palitos -= palitosQuitados;
            jugadorActual = 2;
        }
        else {
            int palitosQuitadosMaquina = maquina(palitos);
            palitos -= palitosQuitadosMaquina;
            cout << "La maquina quita " << palitosQuitadosMaquina << " palos." << endl;
            jugadorActual = 1;
        }
    }
    cout << "Palos restantes: ";
    for (int i = 0; i < palitos; i++) {
        cout << "|";
    }
    cout << endl;
    if (jugadorActual == 1) {
        cout << "La maquina gana" << endl;
    }
    else {
        cout << "El jugador gana" << endl;
    }
    return 0;
}
