import java.util.*;
import java.lang.*;

public class returning {
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int integer = input.nextInt();
		while (integer > 0) {
			System.out.println(Math.sqrt((double) integer));
			integer = input.nextInt();
		}
	}
}