import java.util.*;

public class ABC {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int[] numbers = new int[7];
		for (int i = 0; i < 7; i++) {
			numbers[i] = in.nextInt();
		}

		int greatest = 0;
		int small1 = 2147483647;
		int small2 = 2147483647;
		
		for (int i = 0; i < 7; i++) {
			if (greatest < numbers[i]) {
				greatest = numbers[i];
			}
		}
		
		for (int i = 0; i < 7; i++) {
			if (small1 > numbers[i]) {
				small1 = numbers[i];
			}
		}
		
		for (int i = 0; i < 7; i++) {
			if (small1 == numbers[i]) {
				numbers[i] = 2147483647;
				small1 = small1 + small2;
				small2 = small1 - small2;
				small1 = small1 - small2;
			}
		}
		
		for (int i = 0; i < 7; i++) {
			if (small1 > numbers[i]) {
				small1 = numbers[i];
			}
		}
		
		System.out.println(small2 + " " + small1 + " " + (greatest - small1 - small2));
	}
	
	
}