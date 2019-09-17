public class Horario{
    private String nombreDeAlumno;
    private int MAX_CREDITOS = 55;
    private int creditosCargados = 0;
    private Materia[] materias = new Materia[20];
    private int totalDeMaterias = 0;

    public Horario(String nombreDeAlumno){
        this.nombreDeAlumno = nombreDeAlumno;
    }
    public void addMateria(Materia materia){
        boolean error = false;
        boolean duplicado = false;
        if((creditosCargados + materia.getCreditos() ) <= MAX_CREDITOS){
            if (totalDeMaterias != 0) {
                for (int i = 0; i < totalDeMaterias; i++) {
                    if(materias[i] == materia){
                        error = true;
                        duplicado = true;
                        break;
                    }
                    else{
                        if(!(materias[i].compararMaterias(materia)) ){
                            error = true;
                            break;
                        }
                    }
                }
            }
            if(!error){
                this.materias[totalDeMaterias] = materia;
                totalDeMaterias++;
                System.out.println(materia.getNombreDeAsig() + " agregada!");
            }
            else{
                if(duplicado){
                    System.out.println(materia.getNombreDeAsig() + " duplicada");
                }
                else{
                    System.out.println(materia.getNombreDeAsig() + " tiene clases que chocan");
                }
            }
        }
        else{
            System.out.println("No puedes cargar esta materia porque supera tu limite de creditos");
        }
        
    }
    public void printHorario(){
        System.out.println("\nHorario de " + nombreDeAlumno + ": ");
        if(totalDeMaterias == 0){
            System.out.println("No tienes materias para este horario");
        }
        else{
            for(int i = 0; i < totalDeMaterias; i++){
                materias[i].printMateria();
                System.out.print("\n");
            }
        }
    }
}