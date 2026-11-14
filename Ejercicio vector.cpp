#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class Estudiante {
private:
    string nombre;
    int nacimiento;
    float gpa;
    float presupuesto;

public:
    Estudiante() {
        nombre = "NN";
        nacimiento = 0;
        gpa = 0;
        presupuesto = 0;
    }

    Estudiante(string n, int a, float g, float p) {
        nombre = n;
        nacimiento = a;
        gpa = g;
        presupuesto = p;
    }

    string getNombre() const {
        return nombre;
    }
    int getNacimiento() const {
        return nacimiento;
    }
    float getGpa() const {
        return gpa;
    }
    float getPresupuesto() const {
        return presupuesto;
    }
    void setNombre(string n) {
        nombre = n;
    }
    void setNacimiento(int a) {
        nacimiento = a;
    }
    void setGpa(float g) {
        gpa = g;
    }
    void setPresupuesto(float p) {
        presupuesto = p;
    }
    float calcularIndice() const {
        return fabs(gpa - 3) * presupuesto;
    }
};

int main() {

    vector<Estudiante> estudiantes;
    int opcion;

    do {
        cout << "\n===== MENU DE ESTUDIANTES =====" << endl;
        cout << "1. Insertar estudiante" << endl;
        cout << "2. Eliminar estudiante" << endl;
        cout << "3. Actualizar estudiante" << endl;
        cout << "4. Ordenar estudiantes" << endl;
        cout << "5. Imprimir estudiantes" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1: {
                int tipo, modo;

                cout << "\n--- INSERTAR ESTUDIANTE ---" << endl;
                cout << "1. Insertar al final" << endl;
                cout << "2. Insertar en un indice" << endl;
                cout << "Seleccione: ";
                cin >> tipo;

                cout << "\n1. Con datos" << endl;
                cout << "2. Con datos por defecto" << endl;
                cout << "Seleccione: ";
                cin >> modo;

                Estudiante nuevo;

                if (modo == 1) {
                    string nombre;
                    int nacimiento;
                    float gpa, presupuesto;

                    cout << "\nNombre: ";
                    cin >> nombre;

                    cout << "Anio de nacimiento: ";
                    cin >> nacimiento;

                    cout << "GPA: ";
                    cin >> gpa;

                    cout << "Presupuesto: ";
                    cin >> presupuesto;

                    nuevo = Estudiante(nombre, nacimiento, gpa, presupuesto);
                }
                else if (modo != 2) {
                    cout << "Tipo de datos no valido." << endl;
                    break;
                }

                if (tipo == 1) {
                    estudiantes.push_back(nuevo);
                    cout << "Estudiante insertado al final." << endl;
                }
                else if (tipo == 2) {
                    int indice;

                    cout << "Ingrese el indice: ";
                    cin >> indice;

                    if (indice >= 0 && indice <= estudiantes.size()) {
                        estudiantes.insert(estudiantes.begin() + indice, nuevo);
                        cout << "Estudiante insertado correctamente." << endl;
                    }
                    else {
                        cout << "Indice no valido." << endl;
                    }
                }
                else {
                    cout << "Opcion no valida." << endl;
                }

                break;
            }

            case 2: {
                cout << "\n--- ELIMINAR ESTUDIANTE ---" << endl;

                if (estudiantes.empty()) {
                    cout << "No hay estudiantes para eliminar." << endl;
                    break;
                }

                int tipo;

                cout << "1. Eliminar el ultimo estudiante" << endl;
                cout << "2. Eliminar por indice" << endl;
                cout << "Seleccione: ";
                cin >> tipo;

                if (tipo == 1) {
                    estudiantes.pop_back();
                    cout << "Ultimo estudiante eliminado." << endl;
                }
                else if (tipo == 2) {
                    int indice;

                    cout << "Ingrese el indice: ";
                    cin >> indice;

                    if (indice >= 0 && indice < estudiantes.size()) {
                        estudiantes.erase(estudiantes.begin() + indice);
                        cout << "Estudiante eliminado correctamente." << endl;
                    }
                    else {
                        cout << "Indice no valido." << endl;
                    }
                }
                else {
                    cout << "Opcion no valida." << endl;
                }

                break;
            }

            case 3: {
                cout << "\n--- ACTUALIZAR ESTUDIANTE ---" << endl;

                if (estudiantes.empty()) {
                    cout << "No hay estudiantes para actualizar." << endl;
                    break;
                }

                int indice;

                cout << "Ingrese el indice del estudiante: ";
                cin >> indice;

                if (indice >= 0 && indice < estudiantes.size()) {
                    string nombre;
                    int nacimiento;
                    float gpa, presupuesto;

                    cout << "\nIngrese los nuevos datos:" << endl;

                    cout << "Nombre: ";
                    cin >> nombre;

                    cout << "Anio de nacimiento: ";
                    cin >> nacimiento;

                    cout << "GPA: ";
                    cin >> gpa;

                    cout << "Presupuesto: ";
                    cin >> presupuesto;

                    estudiantes[indice].setNombre(nombre);
                    estudiantes[indice].setNacimiento(nacimiento);
                    estudiantes[indice].setGpa(gpa);
                    estudiantes[indice].setPresupuesto(presupuesto);

                    cout << "Estudiante actualizado correctamente." << endl;
                }
                else {
                    cout << "Indice no valido." << endl;
                }

                break;
            }

            case 4: {
                cout << "\n--- ORDENAR ESTUDIANTES ---" << endl;

                if (estudiantes.empty()) {
                    cout << "No hay estudiantes para ordenar." << endl;
                    break;
                }

                int tipo;

                cout << "1. Ordenar por anio de nacimiento" << endl;
                cout << "2. Ordenar por GPA" << endl;
                cout << "3. Ordenar por presupuesto" << endl;
                cout << "4. Ordenar por indice de universidad" << endl;
                cout << "Seleccione: ";
                cin >> tipo;

                if (tipo == 1) {
                    sort(estudiantes.begin(), estudiantes.end(),
                        [](const Estudiante& a, const Estudiante& b) {
                            return a.getNacimiento() < b.getNacimiento();
                        });
                }
                else if (tipo == 2) {
                    sort(estudiantes.begin(), estudiantes.end(),
                        [](const Estudiante& a, const Estudiante& b) {
                            return a.getGpa() < b.getGpa();
                        });
                }
                else if (tipo == 3) {
                    sort(estudiantes.begin(), estudiantes.end(),
                        [](const Estudiante& a, const Estudiante& b) {
                            return a.getPresupuesto() < b.getPresupuesto();
                        });
                }
                else if (tipo == 4) {
                    sort(estudiantes.begin(), estudiantes.end(),
                        [](const Estudiante& a, const Estudiante& b) {
                            return a.calcularIndice() < b.calcularIndice();
                        });
                }
                else {
                    cout << "Opcion no valida." << endl;
                    break;
                }

                cout << "Estudiantes ordenados correctamente." << endl;

                break;
            }

            case 5: {
                cout << "\n--- LISTA DE ESTUDIANTES ---" << endl;

                if (estudiantes.empty()) {
                    cout << "No hay estudiantes registrados." << endl;
                }
                else {
                    for (int i = 0; i < estudiantes.size(); i++) {
                        cout << "\nIndice: " << i << endl;
                        cout << "Nombre: " << estudiantes[i].getNombre() << endl;
                        cout << "Nacimiento: " << estudiantes[i].getNacimiento() << endl;
                        cout << "GPA: " << estudiantes[i].getGpa() << endl;
                        cout << "Presupuesto: " << estudiantes[i].getPresupuesto() << endl;
                        cout << "Indice de universidad: "
                             << estudiantes[i].calcularIndice() << endl;
                    }
                }

                break;
            }

            case 6:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (opcion != 6);

    return 0;
}
