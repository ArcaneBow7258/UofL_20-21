package assignment2;
import java.util.Scanner;
public class Problem1 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("Please enter your first name");
		String first = scan.next();
		
		System.out.println("Please enter your last name");
		String last = scan.next();
		
		String user = first.substring(0, 1) + last.substring(0,5) + (int)(Math.random()*89 + 10);
		System.out.println("Your username is:" + user);
		
		scan.close();
		
	}
}
