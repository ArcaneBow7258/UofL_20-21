package assignment2;

public class Problem4 {
	
	
	
	
	public static void main(String[] args) {
		Flight flight1 = new Flight("Southwest", 1, "Louisvlle", "Chicago");
		Flight flight2 = new Flight("United", 2, "New York", "Florida");
		Flight flight3 = new Flight("Delta", 0, "Unkown", "Unknown");
		
		System.out.println(flight1.toString());
		
		//Flight 2 changed Airlines
		System.out.println();
		System.out.println();
		
		
		System.out.println(flight2.toString());
		flight2.setName("Southwest");
		System.out.println("Flight 2's airline has been changed to " + flight2.getName());
		System.out.println(flight2.toString());
		
		//Flight 3 gets initialized
		System.out.println();
		System.out.println();
		System.out.println(flight3.toString());
		
		flight3.setNumber(3);
		flight3.setOrigin(flight1.getDestination());
		flight3.setDestination(flight1.getOrigin());
		System.out.println("Flight 1's return flight will be flight 3");
		System.out.println(flight3.toString());
		
		
	}
}
