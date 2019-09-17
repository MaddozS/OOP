public class Hora{
    private int horas;
    private int minutos;

    public Hora(int horas, int minutos){
        this.horas = horas;
        this.minutos = minutos;
    }
    public int getHoras(){
        return horas;
    }
    public int getMinutos(){
        return minutos;
    }
    public void printHoras(){
        if(horas < 10){
            if(minutos < 10){
                System.out.print("0" + horas + ":0" + minutos);
            }
            else{
                System.out.print("0" + horas + ":" + minutos);
            }
        }
        else{
            if(minutos < 10){
                System.out.print(horas + ":0" + minutos);
            }
            else{
                System.out.print(horas + ":" + minutos);
            }
        }
            
    }
    public String compararHoras(Hora hora2){
        int hora1EnSegundos = (this.horas * 3600) + (this.minutos * 60);
        int hora2EnSegundos = (hora2.getHoras() * 3600) + (hora2.getMinutos() * 60);
        if(hora1EnSegundos > hora2EnSegundos){
            return "Mayor";
        }
        else if(hora1EnSegundos < hora2EnSegundos){
            return "Menor";
        }
        else{
            return "Iguales";
        }
    }
}