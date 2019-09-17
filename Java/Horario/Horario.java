public class Horario{
    //Información relacionado con el horario que se crea
    private String nombreDeAlumno;
    private int MAX_CREDITOS = 55;
    private int creditosCargados = 0;
    private Materia[] materias = new Materia[20];
    private int totalDeMaterias = 0;

    //Constructor de la clase
    public Horario(String nombreDeAlumno){
        this.nombreDeAlumno = nombreDeAlumno;
    }
    //Funcion para añadir una materia
    public void addMateria(Materia materia){
        boolean error = false;
        boolean duplicado = false;
        // Verifica si los creditos de la materia que se quiere agregar más los que ya se tienen
        // no superan los creditos maximos
        if((creditosCargados + materia.getCreditos() ) <= MAX_CREDITOS){
            // Se itera cada materia ya agregada
            for (int i = 0; i < totalDeMaterias; i++) {
                // Se checa que la materia no sea exactamente a una que
                // ya esté en el horario
                if(materias[i] == materia){
                    error = true;
                    duplicado = true;
                    break;
                }
                else{
                    // Si no son iguales, se verifica que no choquen en horarios
                    if(!(materias[i].compararMaterias(materia)) ){
                        error = true;
                        break;
                    }
                }
            }
            // Si no hubo ningun error, se agrega y se le avisa al usuario
            if(!error){
                this.materias[totalDeMaterias] = materia;
                totalDeMaterias++;
                System.out.println(materia.getNombreDeAsig() + " agregada!");
            }
            
            // Si no se agrego, se le dice porque
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
    public void removeMateria(Materia materia){
        boolean encontrado = false;
        for (int i = 0; i < totalDeMaterias; i++) {
            // Busca exactamente la misma materia dentro del horario
            if(materias[i] == materia){
                // Si la encuentra, entonces todas las demás se recorren eliminando
                // a materia que se quiere quitar
                for (int j = i; j < totalDeMaterias; j++) {
                    if(i+1 < totalDeMaterias){
                        materias[j] = materias[j+1];
                        materias[j+1] = null;
                    }
                }
                totalDeMaterias--;
                encontrado = true;
                break; 
            }
        }
        if(!encontrado){
            System.out.println(materia.getNombreDeAsig() +  " no está en el horario");
        }
        else{
            System.out.println(materia.getNombreDeAsig() + " removida");
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