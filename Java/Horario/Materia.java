public class Materia{
    private String nombreDeAsig;
    private int creditos;
    private Clase[] clases = new Clase[6];
    private int totalDeClases = 0;

    public Materia(String nombreDeAsig, int creditos, Clase clases[]){
        this.nombreDeAsig = nombreDeAsig;
        this.creditos = creditos;
        for(Clase _clase : clases) {
            clases[totalDeClases] = _clase;
            totalDeClases++;
        }
        this.clases = clases;
    }

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
    public boolean compararMaterias(Materia _materia){
        boolean noChocan = true;
        for (int i = 0; i < totalDeClases; i++) {
            for (int j = 0; j < _materia.getTotalDeClases(); j++) {
                Clase[] claseAux = _materia.getClases();
                if(!(clases[i].compararClases(claseAux[j])) && clases[i].getDia() == claseAux[j].getDia()){
                    noChocan = false;
                    break;
                }
            }
            if(!noChocan){
                break;
            }
        }
        return noChocan;
    }
    public void printMateria(){

        System.out.println("Materia: "+nombreDeAsig + " - Creditos: "+creditos+" - Clases: ");
        for (int i = 0; i < totalDeClases; i++) {
            clases[i].printClase();
        }
    }
}