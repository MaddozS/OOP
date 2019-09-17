public class Main{
    public static void main(String[] args) {
        Horario horarioDeAxel = new Horario("Axel Anaya");
        
        //Creacion del la materia de algebra lineal
        Hora inicioAlg1 = new Hora(12,0);
        Hora finAlg1 = new Hora(13,0);
        Hora inicioAlg2 = new Hora(7,30);
        Hora finAlg2 = new Hora(9,0);
        Hora inicioAlg3 = new Hora(10,30);
        Hora finAlg3 = new Hora(12,0);
        Clase claseDeAlg1 = new Clase(2, inicioAlg1, finAlg1);
        Clase claseDeAlg2 = new Clase(3, inicioAlg2, finAlg2);
        Clase claseDeAlg3 = new Clase(4, inicioAlg3, finAlg3);
        Clase[] clasesDeAlg = {claseDeAlg1, claseDeAlg2, claseDeAlg3};
        Materia algebraLineal = new Materia("Algebra Lineal", 8, clasesDeAlg);

        //Creacion del la materia de arquitectura en computadoras
        Hora inicioArq1 = new Hora(10,30);
        Hora finArq1 = new Hora(12,0);
        Hora inicioArq2 = new Hora(12,0);
        Hora finArq2 = new Hora(13,30);
        Hora inicioArq3 = new Hora(9,0);
        Hora finArq3 = new Hora(10,30);
        Clase claseDeArq1 = new Clase(2, inicioArq1, finArq1);
        Clase claseDeArq2 = new Clase(3, inicioArq2, finArq2);
        Clase claseDeArq3 = new Clase(5, inicioArq3, finArq3);
        Clase[] clasesDeArq = {claseDeArq1, claseDeArq2, claseDeArq3};
        Materia arquitectura = new Materia("Arquitectura", 8, clasesDeArq);

        //Creacion del la materia de teoria de la computacion
        Hora inicioTeoria1 = new Hora(10,30);
        Hora finTeoria1 = new Hora(12,0);
        Hora inicioTeoria2 = new Hora(7,30);
        Hora finTeoria2 = new Hora(9,0);
        Hora inicioTeoria3 = new Hora(7,30);
        Hora finTeoria3 = new Hora(9,0);
        Clase claseDeTeoria1 = new Clase(1, inicioTeoria1, finTeoria1);
        Clase claseDeTeoria2 = new Clase(4, inicioTeoria2, finTeoria2);
        Clase claseDeTeoria3 = new Clase(5, inicioTeoria3, finTeoria3);
        Clase[] clasesDeTeoria = {claseDeTeoria1, claseDeTeoria2, claseDeTeoria3};
        Materia teoria = new Materia("Teoria en la computacion", 8, clasesDeTeoria);
       

        horarioDeAxel.addMateria(algebraLineal);
        horarioDeAxel.addMateria(algebraLineal);
        horarioDeAxel.addMateria(arquitectura);
        horarioDeAxel.addMateria(teoria);
        horarioDeAxel.printHorario();
    }
}