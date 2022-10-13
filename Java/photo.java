import java.util.*;

class photo {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int length = in.nextInt();
		int oddNumber = 0;
		int evenNumber = 0;
		int groups = 0;
		for (int i = 0; i < length; i++) {
			int number = in.nextInt();
			if (number % 2 == 0) {
				evenNumber++;
			}
			else {
				oddNumber++;
			}
		}
		
		if (evenNumber > oddNumber) {
			groups = oddNumber * 2 + 1;
		}
		else if (evenNumber == oddNumber) {
			groups = oddNumber * 2;
		}
		else {
			groups += evenNumber * 2;
			oddNumber -= evenNumber;
			if (oddNumber % 3 == 2) {
				groups ++;
			}
			else if (oddNumber % 3 == 1) {
				groups -= 1;
			}
			groups += 2 * ((int) (oddNumber / 3));
		}
		
		System.out.println(groups);
	}
}