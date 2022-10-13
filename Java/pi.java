import java.util.*;
import java.lang.*;

public class pi {
	double lastValue = 0;
	static double currentValue;
	
	public static double calculateArea(int n) {
		currentValue = n * Math.cos((Math.PI/2) - (Math.PI/n)) * Math.sin((Math.PI/2) - (Math.PI/n));
		return currentValue;
	}
	
	public static void main(String args[]) {
		for(int s = 3; s < 100; s++) {
			//Area calculation divided by r to find pi
			System.out.println(pi.calculateArea(s));
			System.out.println("Difference is: " + (pi.calculateArea(s) - pi.calculateArea(s-1)));
		}
		
	}
	
}