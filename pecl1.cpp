#include "pecl1.h"


// Funciones
void printMenu(int &opcion){
    cout << "Introduzca una de las siguientes opciones: " << endl;
    cout << "1) Comenzar la simulacion." << endl;
    cout << "2) Ver estadisitcas de la simulacion." << endl;
    cout << "0) Salir del programa de simulacion" << endl;
    cin >> opcion;

}

bool aleatorio_50_50() {
    if (rand() % 2 == 0)
        return true;
    else {
        return false;
    }
}

string generadorIDCaja(string origen){
    string id="";
    string localizaciones[] = { "MAR", "GRE", "LIB"};
    id = localizaciones[rand() % 3];
    int idnumber = rand() % 10000;
    id = id + to_string(idnumber);

    if (origen == "Daganzo") {
        id = id + "D";
    } else if (origen == "Meco") {
        id = id + "M";
    } else if (origen == "Loeches") {
        id = id + "L";
    } else if (origen == "Torrejon") {
        id = id + "T";
    } else {
        id = id + "Null";
    }

    return id;
}

string randomProductos (){

    string productos[] = {  "harina", "pasta", "legumbres", "leche", "medicinas", "higiene", "agua",
                            "aceite", "sal", "azucar", "galletas", "latas_cons", "iluminacion",
                            "herramientas", "combustible", "tiendas_camp", "ropa", "mantas", "limpieza"
                        };
    string producto = productos[rand() % 19];
    return producto;
}

string fechaCaducidad(string producto) {

    string fechaCaducidad;

    if (producto == "higiene" || producto == "iluminacion" || producto == "herramientas" ||
        producto == "combustible" || producto == "tiendas_camp" || producto == "ropa" ||
        producto == "mantas" || producto == "limpieza" || producto == "azúcar" || producto == "sal") {
        fechaCaducidad = "12/2100";
    } else if (producto == "harina" || producto == "leche" || producto == "galletas") {
        int anyo = 2023;
        int mes = 1 + (std::rand() % 12);
        fechaCaducidad = std::to_string(mes) + "/" + std::to_string(anyo);
    } else if (producto == "pasta" || producto == "legumbres" || producto == "medicinas" ||
               producto == "aceite" || producto == "agua" || producto == "latas_cons") {
        int anyo = 2023 + (std::rand() % 5);
        int mes = 1 + (std::rand() % 12);
        fechaCaducidad = std::to_string(mes) + "/" + std::to_string(anyo);
    }
    else {
        fechaCaducidad = "12/2100";
    }
    return fechaCaducidad;
}

void simulacionCentroRecogida(int numSimulaciones,string CentroRegociga,Pila* furgoneta, Estadistica *estadistica){
    for (int i=0; i< numSimulaciones; i++){
        if (aleatorio_50_50()) {
                for (i=0;i < Nc;i++){
                        Caja nuevaCaja;
                        nuevaCaja.Id=generadorIDCaja(CentroRegociga);
                        nuevaCaja.CentroRef="Alcala";
                        nuevaCaja.Contenido=randomProductos();
                        nuevaCaja.FechaConsumo=fechaCaducidad(nuevaCaja.Contenido);
                        furgoneta->apilar(nuevaCaja);
                        actualizareEstadisitcas(nuevaCaja,estadistica);
                }
        }
    }
}

void actualizareEstadisitcas(Caja caja, Estadistica* estadistica){
    if  (caja.Id.substr(0, 3) == "MAR"){
            estadistica->marruecosDestino+=1;
    }
    if  (caja.Id.substr(0, 3) == "GRE"){
            estadistica->libiaDestino+=1;
    }
    if  (caja.Id.substr(0, 3) == "LIB"){
            estadistica->greciaDestino+=1;
    }
    if  (caja.Id.back() == 'D'){
            estadistica->daganzoOrigen+=1;
    }
    if  (caja.Id.back() == 'M'){
            estadistica->mecoOrigen+=1;
    }
    if  (caja.Id.back() == 'L'){
            estadistica->loechesOrigen+=1;
    }
    if  (caja.Id.back() == 'T'){
            estadistica->torrejonOrigen+=1;
    }
    if  (caja.Contenido == "harina"){
            estadistica->harina+=1;
    }
    if  (caja.Contenido == "pasta"){
            estadistica->pasta+=1;
    }
    if  (caja.Contenido == "legumbres"){
            estadistica->legumbres+=1;
    }
    if  (caja.Contenido == "leche"){
            estadistica->leche+=1;
    }
    if  (caja.Contenido == "medicinas"){
            estadistica->medicinas+=1;
    }
    if  (caja.Contenido == "higiene"){
            estadistica->higiene+=1;
    }
    if  (caja.Contenido == "agua"){
            estadistica->agua+=1;
    }
    if  (caja.Contenido == "aceite"){
            estadistica->aceite+=1;
    }
    if  (caja.Contenido == "sal"){
            estadistica->sal+=1;
    }
    if  (caja.Contenido == "azucar"){
            estadistica->azucar+=1;
    }
    if  (caja.Contenido == "galletas"){
            estadistica->galletas+=1;
    }
    if  (caja.Contenido == "latas_cons"){
            estadistica->latas_cons+=1;
    }
    if  (caja.Contenido == "iluminacion"){
            estadistica->iluminacion+=1;
    }
    if  (caja.Contenido == "herramientas"){
            estadistica->herramientas+=1;
    }
    if  (caja.Contenido == "combustible"){
            estadistica->combustible+=1;
    }
    if  (caja.Contenido == "tiendas_camp"){
            estadistica->tiendas_camp+=1;
    }
    if  (caja.Contenido == "ropa"){
            estadistica->ropa+=1;
    }
    if  (caja.Contenido == "mantas"){
            estadistica->mantas+=1;
    }
    if  (caja.Contenido == "limpieza"){
            estadistica->limpieza+=1;
    }
 }

//Destructor
Cola::~Cola()
{
    while(frente) desencolar();
}
//Añadir elemento en la cola
void Cola::encolar(Caja v)
{
    pNodo nuevo;
    nuevo = new Nodo(v); // Se crea un nodo nuevo
// Si cola no vacía, se añade el nuevo a continuación de ultimo
    if(final) final->siguiente = nuevo;
//El último elemento de la cola es el nuevo nodo
    final= nuevo;
// Si frente es NULL, la cola está vacía y el nuevo nodo pasa a ser el primero
    if(!frente) frente = nuevo;
}


//Leer elemento de la cola
Caja Cola::desencolar()
{
    pNodo nodo; //Var aux para manipular nodo
    Caja v; //Var aux para retorno del valor
// Nodo apunta al primer elemento de la pila
    nodo = frente;
    Caja vacio={"","","",""};
    if(!nodo) return vacio; // Si no hay nodos en la pila se devuelve 0
//Se asigna a frente la dirección del segundo nodo
    frente = nodo->siguiente;
//Se guarda el valor de retorno
    v = nodo->valor;
    delete nodo; // Se borra el nodo
// Si cola vacía, ultimo debe ser NULL también
    if(!frente) final = NULL;
    return v;
}

//Mostrar Primero Cola
Caja Cola::mostrarPrimero()
{
    Caja vacio={"","","",""};
    if(!frente) return vacio; // Si no hay nodos en la pila se devuelve 0, lo asumimos solo para este ejemplo.
    return (frente->valor);
}

bool Cola::vacia(){
    if (frente==NULL){
        return true;
    }
    else{
        return false;
    }
}

Cola* copiarCola(Cola* colaOriginal) {
    Cola* colaCopia = new Cola(); // Creamos una nueva cola para la copia

    Cola* colaTemporal = new Cola(); // Creamos una cola temporal para mantener la original

    while (!colaOriginal->vacia()) {
        Caja elemento = colaOriginal->desencolar();
        colaTemporal->encolar(elemento);
        colaCopia->encolar(elemento);
    }

    // Restauramos la cola original desde la cola temporal
    while (!colaTemporal->vacia()) {
        Caja elemento = colaTemporal->desencolar();
        colaOriginal->encolar(elemento);
    }

    // Liberamos la memoria de la cola temporal
    delete colaTemporal;

    return colaCopia; // Devolvemos la cola copiada
}

int Cola::contarElementosCola() {
    int contador = 0;
    pNodo actual = frente;

    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }

    return contador;
}

//Destructor de la Pila
Pila::~Pila()
{
    while(cima) desapilar();
}
//Meter elemento en la Pila
void Pila::apilar(Caja v)
{
    pNodo nuevo; //Var aux para manipular el nuevo nodo
//Se crea un nodo nuevo
    nuevo = new Nodo(v, cima);
//El comienzo de la pila es el nuevo nodo
    cima = nuevo;
}

//Sacar elemento de la Pila
Caja Pila::desapilar()
{
    pNodo nodo; //Var aux para manipular el nodo
    Caja v; //Var aux para el retorno del valor del nodo
    Caja vacio={"","","",""};

    if(!cima) return vacio; // Si no hay nodos en la pila se devuelve 0, lo asumimos solo para este ejemplo.
// Nodo apunta al primer elemento de la pila
    nodo = cima;
//Se asigna a pila toda la pila menos el primer elemento
    cima= nodo->siguiente;
//Se guarda el retorno del valor del nodo
    v = nodo->valor;
//Se borra el nodo
    delete nodo;
    nodo = nullptr;
    return v;
}

//Mostrar cima Pila
Caja Pila::mostrarCima()
{
    Caja vacio={"","","",""};
    if(!cima) return vacio; // Si no hay nodos en la pila se devuelve 0, lo asumimos solo para este ejemplo.
    return (cima->valor);
}

bool Pila::vacia(){
    if (cima==NULL){
        return true;
    }
    else{
        return false;
    }
}

int Pila::contarElementosPila(){
    int contador =0;
    pNodo actual = cima;
    while (actual != NULL)
    {
        contador++;
        actual = actual->siguiente;
    }

    return contador;
}

/* Opción recursiva: (Al crearlo en la memoria estática, parece optimo usar iterativa).
int contarElementosPila(Pila pila){
    if (pila.vacia()){
        return 0;
    }
    else {
        pila.desapilar();
        return 1 + contarElementosPila(pila);
    }
}
*/

Pila *copiarPila(Pila *pilaOriginal) {
    Pila *pilaCopia = new Pila();
    Pila *pilaTemporal = new Pila();

    while (!pilaOriginal->vacia()) {
        Caja elemento = pilaOriginal->desapilar();
        pilaTemporal->apilar(elemento);
    }

    while (!pilaTemporal->vacia()) {
        Caja elemento = pilaTemporal->desapilar();
        pilaCopia->apilar(elemento);
        pilaOriginal->apilar(elemento);
    }
    delete pilaTemporal;

    return pilaCopia;
}

Pila* invertirPila(Pila* pilaOriginal) {
    Pila* pilaInvertida = new Pila();
    Pila* pilaTemporal = new Pila();

    while (!pilaOriginal->vacia()) {
        Caja elemento = pilaOriginal->desapilar();
        pilaTemporal->apilar(elemento);
    }

    while (!pilaTemporal->vacia()) {
        Caja elemento = pilaTemporal->desapilar();
        pilaInvertida->apilar(elemento);
    }

    delete pilaTemporal;

    return pilaInvertida;
}

void printEstadisticas(Estadistica* estadistica){

    cout << "+------------------------+----------------+\n";
    cout << "|       Destino          |      Cantidad  |\n";
    cout << "+------------------------+----------------+\n";
    cout << "| Marruecos              | " << setw(14) << estadistica->marruecosDestino << " |\n";
    cout << "| Libia                  | " << setw(14) << estadistica->libiaDestino << " |\n";
    cout << "| Grecia                 | " << setw(14) << estadistica->greciaDestino << " |\n";
    cout << "+------------------------+----------------+\n";
    cout << "| Origen                 |      Cantidad  |\n";
    cout << "+------------------------+----------------+\n";
    cout << "| Daganzo                | " << setw(14) << estadistica->daganzoOrigen << " |\n";
    cout << "| Meco                   | " << setw(14) << estadistica->mecoOrigen << " |\n";
    cout << "| Loeches                | " << setw(14) << estadistica->loechesOrigen << " |\n";
    cout << "| Torrejon               | " << setw(14) << estadistica->torrejonOrigen << " |\n";
    cout << "+------------------------+----------------+\n";
    cout << "| Productos              |      Cantidad  |\n";
    cout << "+------------------------+----------------+\n";
    cout << "| Harina                 | " << setw(14) << estadistica->harina << " |\n";
    cout << "| Pasta                  | " << setw(14) << estadistica->pasta << " |\n";
    cout << "| Galletas               | " << setw(14) << estadistica->galletas << " |\n";
    cout << "| Legumbres              | " << setw(14) << estadistica->legumbres << " |\n";
    cout << "| Leche                  | " << setw(14) << estadistica->leche << " |\n";
    cout << "| medicinas              | " << setw(14) << estadistica->medicinas << " |\n";
    cout << "| higiene                | " << setw(14) << estadistica->higiene << " |\n";
    cout << "| agua                   | " << setw(14) << estadistica->agua << " |\n";
    cout << "| aceite                 | " << setw(14) << estadistica->aceite << " |\n";
    cout << "| sal                    | " << setw(14) << estadistica->sal << " |\n";
    cout << "| azucar                 | " << setw(14) << estadistica->azucar << " |\n";
    cout << "| galletas               | " << setw(14) << estadistica->galletas << " |\n";
    cout << "| latas_cons             | " << setw(14) << estadistica->latas_cons << " |\n";
    cout << "| iluminacion            | " << setw(14) << estadistica->iluminacion << " |\n";
    cout << "| herramientas           | " << setw(14) << estadistica->herramientas << " |\n";
    cout << "| combustible            | " << setw(14) << estadistica->combustible << " |\n";
    cout << "| tiendas_camp           | " << setw(14) << estadistica->tiendas_camp << " |\n";
    cout << "| ropa                   | " << setw(14) << estadistica->ropa << " |\n";
    cout << "| mantas                 | " << setw(14) << estadistica->mantas << " |\n";
    cout << "| limpieza               | " << setw(14) << estadistica->limpieza << " |\n";
    cout << "+------------------------+----------------+\n";
    cout << "\n" ;

     int max_valor_pais = max({estadistica->marruecosDestino, estadistica->libiaDestino, estadistica->greciaDestino});
     if (max_valor_pais == 0 ){
            cout << "Aun no tenemos datos suficientes." << endl;
     }
     else if (max_valor_pais == (estadistica->marruecosDestino) ){
            cout << "La gente esta siendo mas solidaria con la poblacion de  Marruecos." << endl;
     }
     else if (max_valor_pais == (estadistica->libiaDestino) ){
            cout << "La gente esta siendo mas solidaria con la poblacion de  Libia." << endl;
     }
     else{
            cout << "La gente esta siendo mas solidaria con la poblacion de  Grecia." << endl;
     }

     int max_valor_origen = max({estadistica->daganzoOrigen, estadistica->mecoOrigen, estadistica->loechesOrigen, estadistica->torrejonOrigen});
     if (max_valor_origen == 0 ){
            cout << "Aun no tenemos datos suficientes." << endl;
     }
     else if (max_valor_origen == (estadistica->daganzoOrigen) ){
            cout << "La poblacion mas solidaria es Danzo." << endl;
     }
     else if (max_valor_origen == (estadistica->mecoOrigen) ){
            cout << "La poblacion mas solidaria es Meco." << endl;
     }
     else if (max_valor_origen == (estadistica->loechesOrigen) ){
            cout << "La poblacion mas solidaria es Loeche." << endl;
     }
     else{
            cout << "La poblacion mas solidaria es Torrejon." << endl;
     }
     cout << "\n" ;
}

void printDatosFurgonetas(Pila* furgoneta1,Pila* furgoneta2,Pila* furgoneta3, Pila* furgoneta4){

cout << "Contenido de las furgonetas:" << endl;

cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
cout << "|" << setw(35) << "Furgoneta de Daganzo"
     << setw(15) << "|"
     << setw(35) << "Furgoneta de Meco"
     << setw(15) << "|"
     << setw(35) << "Furgoneta de Loeches"
     << setw(15) << "|"
     << setw(35) << "Furgoneta de Torrejon"
     << setw(15) << "|" << endl;
cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
cout << "|" << setw(10) << "ID Caja |"
     << setw(10) << "Centro_ref |"
     << setw(14) << "Contenido |"
     << setw(14) << "Fecha cons |"
     << setw(10) << "ID Caja |"
     << setw(10) << "Centro_ref |"
     << setw(14) << "Contenido |"
     << setw(14) << "Fecha cons |"
     << setw(10) << "ID Caja |"
     << setw(10) << "Centro_ref |"
     << setw(14) << "Contenido |"
     << setw(14) << "Fecha cons |"
     << setw(10) << "ID Caja |"
     << setw(10) << "Centro_ref |"
     << setw(14) << "Contenido |"
     << setw(14) << "Fecha cons |" << endl;
cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
for (int i=0; i < Nc; i++) {
    if (furgoneta1->vacia()) {
        cout << "|" << setw(10) << "--- |"
                    << setw(12) << "--- |"
                    << setw(14) << "--- |"
                    << setw(14) << "--- |" ;
    }
    else {
        cout << "|" << setw(10) << furgoneta1->mostrarCima().Id + "|"
        << setw(10) << furgoneta1->mostrarCima().CentroRef
        << setw(2) << "|"
        << setw(13) << furgoneta1->mostrarCima().Contenido << "|"
        << setw(13) << furgoneta1->mostrarCima().FechaConsumo << "|" ;
    }

    if (furgoneta2->vacia()){
     cout << setw(10) << "--- |"
     << setw(12) << "--- |"
     << setw(14) << "--- |"
     << setw(14) << "--- |"  ;
     }
    else {
        cout  << setw(10) << furgoneta2->mostrarCima().Id + "|"
        << setw(10) << furgoneta2->mostrarCima().CentroRef
        << setw(2) << "|"
        << setw(13) << furgoneta2->mostrarCima().Contenido << "|"
        << setw(13) << furgoneta2->mostrarCima().FechaConsumo << "|" ;
    }
    if (furgoneta3->vacia()){
     cout << setw(10) << "--- |"
     << setw(12) << "--- |"
     << setw(14) << "--- |"
     << setw(14) << "--- |"  ;
     }
    else {
        cout  << setw(10) << furgoneta3->mostrarCima().Id + "|"
        << setw(10) << furgoneta3->mostrarCima().CentroRef
        << setw(2) << "|"
        << setw(13) << furgoneta3->mostrarCima().Contenido << "|"
        << setw(13) << furgoneta3->mostrarCima().FechaConsumo << "|" ;
    }
    if (furgoneta4->vacia()){
     cout << setw(10) << "--- |"
     << setw(12) << "--- |"
     << setw(14) << "--- |"
     << setw(14) << "--- |" << endl;
     }
    else {
        cout << setw(10) << furgoneta4->mostrarCima().Id + "|"
        << setw(10) << furgoneta4->mostrarCima().CentroRef
        << setw(2) << "|"
        << setw(13) << furgoneta4->mostrarCima().Contenido << "|"
        << setw(13) << furgoneta4->mostrarCima().FechaConsumo << "|" << endl;
    }

    furgoneta1->desapilar();
    furgoneta2->desapilar();
    furgoneta3->desapilar();
    furgoneta4->desapilar();

}
cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
cout << "\n" ;
cout << "\n" ;
}


void printDatosCentroClasificacion(Cola* centroDeClasificacion1){

cout << "Contenido del centro de Clasificacion:" << endl;
cout << "---------------------------------------------------" << endl;
cout << "|" << setw(10) << "ID Caja |"
     << setw(10) << "Centro_ref |"
     << setw(14) << "Contenido |"
     << setw(14) << "Fecha cons |" << endl;
cout << "---------------------------------------------------" << endl;
int numCC= centroDeClasificacion1->contarElementosCola();
for (int i=0; i < numCC; i++) {
    if (centroDeClasificacion1->vacia()) {
        cout << "|" << setw(10) << "--- |"
                    << setw(12) << "--- |"
                    << setw(14) << "--- |"
                    << setw(14) << "--- |" << endl;
    }
    else {
        cout << "|" << setw(10) << centroDeClasificacion1->mostrarPrimero().Id + "|"
        << setw(10) << centroDeClasificacion1->mostrarPrimero().CentroRef
        << setw(2) << "|"
        << setw(13) << centroDeClasificacion1->mostrarPrimero().Contenido << "|"
        << setw(13) << centroDeClasificacion1->mostrarPrimero().FechaConsumo << "|" << endl;
    }

    centroDeClasificacion1->desencolar();
}
cout << "---------------------------------------------------" << endl;
cout << "\n" ;
cout << "\n" ;
}


void printDatosCamiones(Pila* camion1,Pila* camion2,Pila* camion3){

cout << "Contenido de los camiones:" << endl;

cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
cout << "|" << setw(35) << "Camion Marruecos"
     << setw(15) << "|"
     << setw(35) << "Camion Libia"
     << setw(15) << "|"
     << setw(35) << "Camion Grecia"
     << setw(15) << "|" << endl;
cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
cout << "|" << setw(10) << "ID Caja |"
     << setw(10) << "Centro_ref |"
     << setw(14) << "Contenido |"
     << setw(14) << "Fecha cons |"
     << setw(10) << "ID Caja |"
     << setw(10) << "Centro_ref |"
     << setw(14) << "Contenido |"
     << setw(14) << "Fecha cons |"
     << setw(10) << "ID Caja |"
     << setw(10) << "Centro_ref |"
     << setw(14) << "Contenido |"
     << setw(14) << "Fecha cons |" << endl;
cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
for (int i=0; i < Ncam; i++) {
    if (camion1->vacia()) {
        cout << "|" << setw(10) << "--- |"
                    << setw(12) << "--- |"
                    << setw(14) << "--- |"
                    << setw(14) << "--- |" ;
    }
    else {
        cout << "|" << setw(10) << camion1->mostrarCima().Id + "|"
        << setw(10) << camion1->mostrarCima().CentroRef
        << setw(2) << "|"
        << setw(13) << camion1->mostrarCima().Contenido << "|"
        << setw(13) << camion1->mostrarCima().FechaConsumo << "|" ;
    }

    if (camion2->vacia()){
     cout << setw(10) << "--- |"
     << setw(12) << "--- |"
     << setw(14) << "--- |"
     << setw(14) << "--- |"  ;
     }
    else {
        cout  << setw(10) << camion2->mostrarCima().Id + "|"
        << setw(10) << camion2->mostrarCima().CentroRef
        << setw(2) << "|"
        << setw(13) << camion2->mostrarCima().Contenido << "|"
        << setw(13) << camion2->mostrarCima().FechaConsumo << "|" ;
    }
    if (camion3->vacia()){
     cout << setw(10) << "--- |"
     << setw(12) << "--- |"
     << setw(14) << "--- |"
     << setw(14) << "--- |" << endl;
     }
    else {
        cout << setw(10) << camion3->mostrarCima().Id + "|"
        << setw(10) << camion3->mostrarCima().CentroRef
        << setw(2) << "|"
        << setw(13) << camion3->mostrarCima().Contenido << "|"
        << setw(13) << camion3->mostrarCima().FechaConsumo << "|" << endl;
    }


    camion1->desapilar();
    camion2->desapilar();
    camion3->desapilar();

}
cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
cout << "\n" ;
cout << "\n" ;
}
