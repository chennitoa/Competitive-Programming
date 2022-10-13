import java.util.*;

class spaced {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int size = in.nextInt;
		int[][] pretty = new int[size][size];
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				pretty[x][size - y - 1] = in.nextInt;
			}
		}
		
	}
}