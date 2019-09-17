public class Materia{
    //Información relacionado con el horario que se crea
    private String nombreDeAsig;
    private int creditos;
    private Clase[] clases = new Clase[6];
    private int totalDeClases = 0;

    // Constructor
    public Materia(String nombreDeAsig, int creditos, Clase clases[]){
        this.nombreDeAsig = nombreDeAsig;
        this.creditos = creditos;
        for(Clase _clase : clases) {
            clases[totalDeClases] = _clase;
            totalDeClases++;
        }
        this.clases = clases;
    }
    // getters
    public String getNombreDeAsig(){
        return nombreDeAsig;
    }
    public Clase[] getClases(){
        return clases;
    }
    public int getTotalDeClases(){
        return totalDeClases;
    }
    public int getCreditos(){
        return creditos;
    }
    // Comparador con la materia con una que se pase como parametro
    public boolean compararMaterias(Materia _materia){
        boolean noChocan = true;
        // Se itera cada clase que tiene la materia principal
        for (int i = 0; i < totalDeClases; i++) {
            // Se itera cada clase que tiene la materia que pasa como parametro
            for (int j = 0; j < _materia.getTotalDeClases(); j++) {
                Clase[] claseAux = _materia.getClases();
                // Se compara cada clase de la materia que pasa como parametro con
                // con todas las clases que tiene la materia principal
                // NO DEBE: concidir en el dia y que la clase no choque de ninguna manera
                //          con la que se compara
                if(!(clases[i].compararClases(claseAux[j])) && clases[i].getDia() == claseAux[j].getDia()){
                    noChocan = false;
                    break;
                }
            }
            if(!noChocan){
                break;
            }
        }
        // Se retorna true si no chocan, y false si hay un choque en las clases
        return noChocan;
    }
    public void printMateria(){

        System.out.println("Materia: "+nombreDeAsig + " - Creditos: "+creditos+" - Clases: ");
        for (int i = 0; i < totalDeClases; i++) {
            clases[i].printClase();
        }
    }
}