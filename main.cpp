#include "pecl1.h"

int main(){
    int opcion=0;
    int numSimulaciones=1;
    int ejecuciones=10;
    srand(time(0));
    //Crear las furgonetas
    Pila *furgonetaDaganzo = new Pila();
    Pila *furgonetaMeco = new Pila();
    Pila *furgonetaLoeches = new Pila();
    Pila *furgonetaTorrejon = new Pila();
    //Crear los camiones
    Pila *camionMarruecos = new Pila();
    Pila *camionLibia = new Pila();
    Pila *camionGrecia = new Pila();
    //Crear el centro de clasificacion.
    Cola *centroDeClasificacion = new Cola();
    Estadistica *estadistica = new Estadistica();

    cout << "---------------------------------------------------------------------------" << endl;
    cout << "Bienvenido al programa de simulacion de un servicio de ayuda humanitaria:\n" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    do{
        printMenu(opcion);
        switch (opcion) {
            case 1:
                cin.ignore();
                for (int i=0; i < ejecuciones; i++) {
                    cout << "Paso de ejecucion: " << i << "------------------------------" << endl;

                    int contador = 0;
                    // uncomment for debug. JustInCase.
                    //cout << camionMarruecos.contarElementosPila();
                    while (contador < Nrep  && !centroDeClasificacion->vacia()  && (camionMarruecos->contarElementosPila()<20)  && (camionLibia->contarElementosPila())<20 && (camionGrecia->contarElementosPila()<20)) {
                        // uncomment for debug. JustInCase.
                        //cout << centroDeClasificacion.mostrarPrimero().Id  << endl;

                        if  (centroDeClasificacion->mostrarPrimero().Id.substr(0, 3) == "MAR") {
                            // uncomment for debug. JustInCase.
                            //cout << "el camion va a marruercos" << endl;
                            camionMarruecos->apilar(centroDeClasificacion->desencolar());
                            // uncomment for debug. JustInCase.
                            //cout << camionMarruecos->mostrarCima().Id  << endl;
                            }

                        else if  (centroDeClasificacion->mostrarPrimero().Id.substr(0, 3) == "GRE") {
                            // uncomment for debug. JustInCase.
                            //cout << "el camion va a grecia" << endl;
                            camionGrecia->apilar(centroDeClasificacion->desencolar());
                            // uncomment for debug. JustInCase.
                            //cout << camionGrecia->mostrarCima().Id  << endl;
                            }

                        else if  (centroDeClasificacion->mostrarPrimero().Id.substr(0, 3) == "LIB") {
                            // uncomment for debug. JustInCase.
                            //cout << "el camion va a Libia" << endl;
                            camionLibia->apilar(centroDeClasificacion->desencolar());
                            // uncomment for debug. JustInCase.
                            //cout << camionLibia->mostrarCima().Id  << endl;
                            }

                        contador++;
                    }

                    if (furgonetaDaganzo->vacia() && furgonetaMeco->vacia() && furgonetaLoeches->vacia() && furgonetaTorrejon->vacia() ) {
                        // uncomment for debug. JustInCase.
                        //cout << "Las furgonetas están vacias, hay que llenarlas\n" << endl;
                        simulacionCentroRecogida(numSimulaciones,"Daganzo",furgonetaDaganzo,estadistica);
                        simulacionCentroRecogida(numSimulaciones,"Meco",furgonetaMeco,estadistica);
                        simulacionCentroRecogida(numSimulaciones,"Loeches",furgonetaLoeches,estadistica);
                        simulacionCentroRecogida(numSimulaciones,"Torrejon",furgonetaTorrejon,estadistica);
                        // uncomment for debug. JustInCase.
                        //cout << furgonetaDaganzo.mostrarCima().CentroRef  << endl;
                    }
                    else {
                        // uncomment for debug. JustInCase.
                        //cout << "Las furgonetas están llenas, hay que vaciarlas llenarlas\n" << endl;
                        if (!furgonetaDaganzo->vacia()){
                                while (!furgonetaDaganzo->vacia()) {
                                        centroDeClasificacion->encolar(furgonetaDaganzo->desapilar());
                                        // uncomment for debug. JustInCase.
                                        //cout << centroDeClasificacion.mostrarPrimero().Id  << endl;
                                }
                                simulacionCentroRecogida(numSimulaciones,"Daganzo",furgonetaDaganzo,estadistica);
                            }
                        if (!furgonetaMeco->vacia()){
                                while (!furgonetaMeco->vacia()) {
                                        centroDeClasificacion->encolar(furgonetaMeco->desapilar());
                                }
                                simulacionCentroRecogida(numSimulaciones,"Meco",furgonetaMeco,estadistica);
                            }
                        if (!furgonetaLoeches->vacia()){
                                while (!furgonetaLoeches->vacia()) {
                                        centroDeClasificacion->encolar(furgonetaLoeches->desapilar());
                                }
                                simulacionCentroRecogida(numSimulaciones,"Loeches",furgonetaLoeches,estadistica);
                            }
                        if (!furgonetaTorrejon->vacia()){
                                while (!furgonetaTorrejon->vacia()) {
                                        centroDeClasificacion->encolar(furgonetaTorrejon->desapilar());
                                }
                                simulacionCentroRecogida(numSimulaciones,"Loeches",furgonetaTorrejon,estadistica);
                            }
                    }

                    // COPIA DE FURGONETAS PARA IMPRESION Y MANIPULACION
                    Pila *furgonetaDaganzoCopia = copiarPila(furgonetaDaganzo);
                    furgonetaDaganzo = invertirPila(furgonetaDaganzo);
                    furgonetaDaganzoCopia = invertirPila(furgonetaDaganzoCopia);

                    Pila *furgonetaMecoCopia = copiarPila(furgonetaMeco);
                    furgonetaMeco = invertirPila(furgonetaMeco);
                    furgonetaMecoCopia = invertirPila(furgonetaMecoCopia);

                    Pila *furgonetaLoechesCopia = copiarPila(furgonetaLoeches);
                    furgonetaLoeches = invertirPila(furgonetaLoeches);
                    furgonetaLoechesCopia = invertirPila(furgonetaLoechesCopia);

                    Pila *furgonetaTorrejonCopia = copiarPila(furgonetaTorrejon);
                    furgonetaTorrejon = invertirPila(furgonetaTorrejon);
                    furgonetaTorrejonCopia = invertirPila(furgonetaTorrejonCopia);

                    // LLAMADAS PARA LA IMPRESION DE FURGONETAS
                    printDatosFurgonetas(furgonetaDaganzoCopia,furgonetaMecoCopia,furgonetaLoechesCopia,furgonetaTorrejonCopia);

                    // COPIA DE CENTRODECLASISIFACION PARA IMPRESION Y MANIPULACION
                    Cola *centroDeClasificacionCopia = copiarCola(centroDeClasificacion);

                    // LLAMADA PARA LA IMPRESION DE CENTRO DE CLASIFICACION
                    printDatosCentroClasificacion(centroDeClasificacionCopia);

                    // COPIA DE CAMIONES PARA IMPRESION Y MANIPULACION
                    Pila *camionMarruecosCopia = copiarPila(camionMarruecos);
                    camionMarruecos = invertirPila(camionMarruecos);
                    camionMarruecosCopia = invertirPila(camionMarruecosCopia);

                    Pila *camionLibiaCopia = copiarPila(camionLibia);
                    camionLibia = invertirPila(camionLibia);
                    camionLibiaCopia = invertirPila(camionLibiaCopia);

                    Pila *camionGreciaCopia = copiarPila(camionGrecia);
                    camionGrecia = invertirPila(camionGrecia);
                    camionGreciaCopia = invertirPila(camionGreciaCopia);

                    // LLAMADAS PARA LA IMPRESION DE CAMIONES
                    printDatosCamiones(camionMarruecosCopia,camionLibiaCopia,camionGreciaCopia);


                    if (camionMarruecos->contarElementosPila() == 20){
                        cout << "Camion destino Marruecos lleno. Parte al aeropuerto." << camionMarruecos->contarElementosPila() << endl;
                        while (!camionMarruecos->vacia()) {
                            camionMarruecos->desapilar();
                        }
                    }

                    if (camionGrecia->contarElementosPila() == 20){
                        cout << "Camion destino Grecia lleno. Parte al aeropuerto." << camionGrecia->contarElementosPila()<< endl;
                        while (!camionGrecia->vacia()) {
                            camionGrecia->desapilar();
                        }
                    }

                    if (camionLibia->contarElementosPila()== 20){
                        cout << "Camion destino Libia lleno. Parte al aeropuerto." << camionLibia->contarElementosPila()<< endl;

                        while (!camionLibia->vacia()) {
                            camionLibia->desapilar();
                        }
                    }
                    cout << "Presiona Enter para continuar...\n";
                    cin.ignore();  // Espera a que el usuario presione Enter
                }
                break;
            case 2:
                    printEstadisticas(estadistica);
                    break;
            case 0:
                    cout << "Nos vemos. ;) " << endl ;
                    break;
            default:
                    cout << "La opción no estaba en el menu" << endl;
                    break;
            }
        } while(opcion!=0);

    return 0;
}
