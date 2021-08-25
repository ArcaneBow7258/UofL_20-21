package assignment2;
import java.text.DecimalFormat;
public class Problem2 {
public static void main(String[] args) {
	
	DecimalFormat fmt = new DecimalFormat("###.####");
	final double radius = 5;
	final double volume = (4.0/3.0)* Math.PI * Math.pow(radius, 3);
	final double surface_area = 4.0 * Math.PI * Math.pow(radius, 2);
	
	System.out.println("For a sphere of radius: " + fmt.format(radius));
	System.out.println("Its volume is: " + fmt.format(volume));
	System.out.println("Its surface area is: " + fmt.format(surface_area));
}
	
}
