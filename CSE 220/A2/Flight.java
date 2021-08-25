package assignment2;

public class Flight {
	private String name;
	private int number;
	private String origin;
	private String destination;
	//Constructor
	public Flight(String flightName, int flightNum, String originCity, String destCity) {
		name = flightName;
		number = flightNum;
		origin = originCity;
		destination = destCity;
	}
	//Getters================
	public String getName(){
		return name;
	}
	public int getNumber(){
		return number;
	}
	public String getOrigin(){
		return origin;
	}
	public String getDestination(){
		return destination;
	}
	//Setters================
	public void setName(String flightName){
		name = flightName;
	}
	public void setNumber(int flightNum){
		number = flightNum;
	}
	public void setOrigin(String originCity){
		origin = originCity;
	}
	public void setDestination(String destCity){
		destination = destCity;
	}
	//FULL================
	public String toString() {
		return "Airline Name: " + name + ", Flight Number: "+ number +", Origin: " +origin+ ", Destination: " + destination;
	}
}
