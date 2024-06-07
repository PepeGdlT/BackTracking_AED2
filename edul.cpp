#include <iostream>
#include <vector>
#include <chrono>

#define NUM_TALLAS 6
#define MAX_HERMANOS 5
#define INVALID -1
using namespace std;
int voluntarios;


static const string tallasStArray[] = {"XS", "S", "M", "L", "XL","XXL"}; // Array de tallas

int tallaHash(string tallaSt) {
    // Buscar la talla en el array de tallas
    for(int i = 0; i < NUM_TALLAS; i++){
        if(tallaSt == tallasStArray[i]){
            return i;
        }
    }
    return -1;
}


void generar( int s[], int nivel){
    // Generar la talla para el voluntario
    s[nivel]++;
}

bool solucion(int s[], int nivel, string tablaTallas[][2],vector<int>& camisetasPorTalla) {
    // Obtener las tallas de la tabla
    int nTallas[2] = { tallaHash(tablaTallas[nivel][0]),tallaHash(tablaTallas[nivel][1])};
    // Verificar si es la ultima talla
    if (nivel == (voluntarios - 1)) {
        // Verificar si la talla asignada esta disponible y es valida
        if ((s[nivel] == nTallas[0] && camisetasPorTalla[nTallas[0]] > 0) ||
            (s[nivel] == nTallas[1] && camisetasPorTalla[nTallas[1]] > 0)) {
            return true;
        }
    }
    // Si no es el ultimo voluntario o la talla asignada no es valida, devolver false
    return false;
}

bool criterio(int s[], int nivel, string tablaTallas[][2], vector<int>& camisetasPorTalla){
    // Obtener las tallas de la tabla
    int nTallas[2] = { tallaHash(tablaTallas[nivel][0]),tallaHash(tablaTallas[nivel][1])};
    if (nivel < (voluntarios - 1)) {
        // Verificar si la talla asignada esta disponible y es valida
        if ((s[nivel] == nTallas[0] && camisetasPorTalla[nTallas[0]] > 0) ||
            (s[nivel] == nTallas[1] && camisetasPorTalla[nTallas[1]] > 0)) {
            return true;
        }
    }
    // Devolver false si estamos en el ultimo voluntario o la talla asignada no es valida
    return false;
}
int retroceder(int s[], int nivel, vector<int>& camisetasPorTalla){
    s[nivel] = INVALID;
    nivel--;
    if(nivel > INVALID) {
        camisetasPorTalla[s[nivel]]++;
    }

    return nivel;
}

bool masHermanos(int s[], int nivel) {
    // Verificar si el numero de hermanos actual es menor que el maximo permitido
    return MAX_HERMANOS > s[nivel];
}



bool backtracking(string tallas[][2], vector<int>& camisetasPorTalla, int nivel = 0) {

    int s[voluntarios];
    // Inicializamos la tupla solucion
    for (int i = 0; i < voluntarios; i++) {
        s[i] = -1;
    }
    // Inicializamos el nivel
    bool fin = false;
    while (!fin && nivel != -1) {

        // Generar la siguiente solucion
        generar(s, nivel);
        // Verificar si la solucion es valida
        if (solucion(s, nivel, tallas, camisetasPorTalla)) {
            fin = true;
        } else {

            if (criterio(s, nivel, tallas, camisetasPorTalla)) {
                // Si la solucion no es valida, retroceder
                camisetasPorTalla[s[nivel]]--;
                nivel++;
            } else {

                while (!masHermanos(s,nivel)) {
                    // Retroceder hasta encontrar una solucion valida
                    nivel = retroceder(s, nivel, camisetasPorTalla);
                    // Si no se puede retroceder mas, terminar
                    if (nivel == -1) break;
                }
            }
        }
    }

    return fin;
}

int main () {

    int numCasos;
    int camisetas;
    cin >> numCasos;
    while(numCasos > 0){
        cin >> camisetas; //N Camisetas
        cin >> voluntarios;//M voluntarios
        // Crear la matriz de tallas
        string tallas[voluntarios][2];
        for(int i = 0; i < voluntarios; i++){
            for(int j = 0; j < 2; j++){
                cin >> tallas[i][j];
            }
        }
        vector<int> camisetasPorTalla(6, camisetas / 6);
        for(int j =0; j<6;j++){
            camisetasPorTalla[j] = camisetas/6;
        }
        cout << "entra\n";
        auto start_time = chrono::high_resolution_clock::now();

        bool result = backtracking(tallas,camisetasPorTalla);
        auto end_time = chrono::high_resolution_clock::now();
        result ? cout << "YES" <<endl : cout << "NO"<< endl;
        auto duration_ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
        cout << "\nEl programa ha durado: " << duration_ms << " milisegundos." << endl;
        numCasos--;
    }
}

