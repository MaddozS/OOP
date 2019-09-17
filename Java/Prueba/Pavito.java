public class Pavito{
	private int pavitoId;
	private String pavitoName;
	
	public Pavito(int pavitoId, String pavitoName){
		this.pavitoId = pavitoId;
		this.pavitoName = pavitoName;
	}
	public int getPavitoId(){
		return pavitoId;
	}
	public String getPavitoName(){
		return pavitoName;
	}
	public String printPavito(){
		return "No: "+pavitoId+
			"   Name: "+pavitoName;
	}
	public static void main(String args[]){
		Pavito pavito1 = new Pavito(1, "Axel");
		Pavito pavito2 = new Pavito(2, "Rodrigo");
		System.out.println(pavito1.printPavito());
		System.out.println(pavito2.printPavito());
	}
}