#include <iostream>
#include <unordered_map> 

// Estructura de un dispositivo con sus respectivos métodos
struct Dispositivo{
    std::string nombre;
    std::string estado;
    std::string tipo;
    public:
        Dispositivo(std::string _nombre, std::string _estado, std::string _tipo);
        std::string getLlave();
};
std::string getNombre(){
    return nombre;
}
Dispositivo:Dispositivo(std::string _nombre, std::string _estado, std::string _tipo){
    nombre = _nombre;
    estado = _estado;
    tipo = _tipo;
}

// Estructura de un usuario con sus respectivos métodos
struct Usuario{
    std::string nombre;
    std::string password;
    public:
        Usuario(std::string _nombre, std::string _password);
        std::string getNombre();
};
Usuario::Usuario(std::string _nombre, std::string _password){
    nombre = _nombre;
    password = _password;
}
std::string Usuario::getNombre(){
    return nombre;
}

// Estructura del controlador con sus respectivos métodos
struct Controlador{
    private:
        std::string nombre;
        std::string ubicacion;
        unordered_map<std::string, Dispositivo> dispositivos;
        unordered_map<std::string, Usuario> usuarios;
    public:
        Controlador(std::string _nombre, std::string _ubicacion);
        void addUsuario(Usuario _usuario);
        void addDispositvo(Dispositivo _dispositivo);
        void removeUsuario(Usuario _usuario);
        void removeDispositvo(Dispositivo _dispositivo);
        void printControlador();
        void getDispositivos();
        void getUsuarios();
        void cambiarStatus(Dispositivo _dispositivo, _status);
};
Controlador::Controlador(std::string _nombre, std::string _ubicacion){
    controlador = _nombre;
    ubicacion = _ubicacion;
    return controlador;
};
void addUsuario(Usuario _usuario){
    std::string nombre_usuario = _usuario.getNombre();
    usuarios.insert(make_pair(nombre_usuario, _usuario))
};
void addDispositvo(Dispositivo _dispositivo){
    str::string nombre_dispositivo = _dispositivo.getNombre();
    dispositivos.insert(make_pair(nombre_dispositivo, _dispositivo))
};
