public class Clase{
    private int dia;
    private Hora inicio;
    private Hora fin;
    private String[] dias = {"Lunes","Martes","Miercoles","Jueves","Viernes"};

    public Clase(int dia, Hora inicio, Hora fin){
        this.dia = dia;
        this.inicio = inicio;
        this.fin = fin;
    }
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
    public boolean compararClases(Clase _clase){
        Hora inicioAux = _clase.getInicio();
        Hora finAux = _clase.getFin();
        if(fin.compararHoras(inicioAux) != "Mayor"){
            return true;
        }
        else{
            if(inicio.compararHoras(finAux) != "Menor"){
                return true;
            }
            else{
                return false;
            }
        }
    }
}