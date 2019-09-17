#include <iostream>
#include <unordered_map> 

// Estructura de un dispositivo con sus respectivos métodos
struct Dispositivo{
    std::string nombre;
    std::string estado;
    std::string tipo;
    public:
        Dispositivo(std::string _nombre, std::string _estado, std::string _tipo);
        void setNombre(std::string _nombre);
        void setEstado(std::string _estado);
        void setTipo(std::string _tipo);
        std::string getNombre();
        std::string getEstado();
        std::string getTipo();
};
Dispositivo::Dispositivo(std::string _nombre, std::string _estado, std::string _tipo){
    nombre = _nombre;
    estado = _estado;
    tipo = _tipo;
}
void Dispositivo::setNombre(std::string _nombre){
    nombre = _nombre;
}
void Dispositivo::setEstado(std::string _estado){
    estado = _estado;
}
void Dispositivo::setTipo(std::string _tipo){
    tipo = _tipo;
}
std::string Dispositivo::getNombre(){
    return nombre;
}
std::string Dispositivo::getEstado(){
    return estado;
}
std::string Dispositivo::getTipo(){
    return tipo;
}


// Estructura de un usuario con sus respectivos métodos
struct Usuario{
    std::string nombre;
    std::string password;
    public:
        Usuario(std::string _nombre, std::string _password);
        std::string getNombre();
        void setNombre(std::string _nombre);
        void setPassword(std::string _password);
};
Usuario::Usuario(std::string _nombre, std::string _password){
    nombre = _nombre;
    password = _password;
}
std::string Usuario::getNombre(){
    return nombre;
}
void Usuario::setNombre(std::string _nombre){
    nombre = _nombre;
}
void Usuario::setPassword(std::string _password){
    password = _password;
}

// Estructura del controlador con sus respectivos métodos
struct Controlador{
    private:
        std::string nombre;
        std::string ubicacion;
        std::unordered_map<std::string, Dispositivo> dispositivos;
        std::unordered_map<std::string, Usuario> usuarios;
    public:
        Controlador(std::string _nombre, std::string _ubicacion);
        void addUsuario(Usuario _usuario);
        void addDispositvo(Dispositivo _dispositivo);
        void removeUsuario(Usuario _usuario);
        void removeDispositvo(Dispositivo _dispositivo);
        void printControlador();
        std::string getEstadoDispositivo(Dispositivo _dispositivo);
        void cambiarEstado(Dispositivo _dispositivo, std::string _status);
};
Controlador::Controlador(std::string _nombre, std::string _ubicacion){
    nombre = _nombre;
    ubicacion = _ubicacion;
}
void Controlador::addUsuario(Usuario _usuario){
    std::string nombre_usuario = _usuario.getNombre();
    usuarios.insert(make_pair(nombre_usuario, _usuario));
}
void Controlador::addDispositvo(Dispositivo _dispositivo){
    std::string nombre_dispositivo = _dispositivo.getNombre();
    dispositivos.insert(make_pair(nombre_dispositivo, _dispositivo));
}
std::string Controlador::getEstadoDispositivo(Dispositivo _dispositivo){
    std::string key = _dispositivo.getNombre();
    auto itr = dispositivos.find(key);
    std::string estado;
    if(itr == dispositivos.end()){
        estado = "Dispositivo no vinculado";
    }
    else{
        estado = itr->second.getEstado();
    }

    return estado;
}
void Controlador::printControlador(){
    std::unordered_map<std::string, Dispositivo>::iterator itr1;
    std::unordered_map<std::string, Usuario>::iterator itr2;

    std::cout << "Controlador " << nombre << " ubicado en " << ubicacion << std::endl;
    std::cout << "Dispositivos: " << std::endl;

    for(itr1 = dispositivos.begin(); itr1 != dispositivos.end(); itr1++){
        std::string dispositivo_nombre = itr1->first;
        std::string dispositivo_estado = itr1->second.getEstado();
        std::string dispositivo_tipo = itr1->second.getTipo();
        std::cout << "    Nombre: " << dispositivo_nombre << std::endl; 
        std::cout << "    Estado: " << dispositivo_estado << std::endl;
        std::cout << "    Tipo: " << dispositivo_tipo << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Usuarios: " << std::endl;
    for(itr2 = usuarios.begin(); itr2 != usuarios.end(); itr2++){
        std::cout << "    " << itr2->first << std::endl;
    } 
    std::cout << std::endl;
}
// void Controlador::cambiarStatus(Dispositivo _dispositivo, std::string _status);

// Funcion main
int main(int argc, char const *argv[])
{
    Usuario axel("Axel", "Chicharron");
    Dispositivo aire_acondicionado("Aire1", "apagado", "A/C");
    Dispositivo refri("Refri", "apagado", "Refrigerador");
    Controlador controlador_principal("Controlador", "Sala");

    controlador_principal.addUsuario(axel);
    controlador_principal.addDispositvo(aire_acondicionado);

    std::string estado;
    estado = controlador_principal.getEstadoDispositivo(aire_acondicionado);
    std::cout << "Estado de " << aire_acondicionado.getNombre( ) << ": " << estado << std::endl;

    estado = controlador_principal.getEstadoDispositivo(refri);
    std::cout << "Estado de " << refri.getNombre() << ": "<< estado << std::endl;

    controlador_principal.printControlador();
    return 0;
}

