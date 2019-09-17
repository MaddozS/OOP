public class Clase{
    //Información relacionado con el horario que se crea
    private int dia;
    private Hora inicio;
    private Hora fin;
    private String[] dias = {"Lunes","Martes","Miercoles","Jueves","Viernes"};
    
    // Constructor
    public Clase(int dia, Hora inicio, Hora fin){
        this.dia = dia;
        this.inicio = inicio;
        this.fin = fin;
    }
    // getters
    public Hora getInicio(){
        return inicio;
    }
    public Hora getFin(){
        return fin;
    }
    public int getDia(){
        return dia;
    }
    public void printClase(){
        System.out.println("Dia: " + dias[dia-1]);
        System.out.print("Inicio: ");
        inicio.printHoras();
        System.out.print(" - Fin: ");
        fin.printHoras();
        System.out.println("");
    }
    // Se compara una clase con la que se pasa de parametro
    public boolean compararClases(Clase _clase){
        Hora inicioAux = _clase.getInicio();
        Hora finAux = _clase.getFin();
        // Se hace esta comparacion, la cual indica que toda la clase que se pasa como parametro
        // esta justo despues de la principal
        if(fin.compararHoras(inicioAux) != "Mayor" && inicio.compararHoras(finAux) == "Menor"){
            return true;
        }
        // En caso de que la condicion sea falsa, puede indicar que la clase que
        // pasa como parametro esta justo antes de la clase principal
        else if(inicio.compararHoras(finAux) != "Menor" && fin.compararHoras(inicioAux) == "Mayor"){
            return true;
        }
        // Si todas las condicionales sean falsas, la clase de parametro choca con la principal
        else{
            return false;
        }
    }
}