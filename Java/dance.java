import java.util.*;

class dance {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int numCows = in.nextInt();
		int numMoves = in.nextInt();
		int[] begin = new int[numMoves];
		int[] end = new int[numMoves];
		for (int i = 0; i < numMoves; i++) {
			begin[i] = in.nextInt();
			end[i] = in.nextInt();
		}
		for (int i = 0; i < numCows; i++) {
			int position = i + 1;
			boolean[] positionsReached = new boolean[numCows];
			int locations = 0;
			positionsReached[position - 1] = true;
			for (int j = 0; j < 4; j++) {
				for (int z = 0; z < numMoves; z++) {
					if (position == begin[z]) {
						position = end[z];
						positionsReached[position - 1] = true;
					}
					else if (position == end[z]) {
						position = begin[z];
						positionsReached[position - 1] = true;
					}
				}
			}
			for (int j = 0; j < numCows; j++) {
				if (positionsReached[j] == true) {
					locations++;
				}
			}
			System.out.println(locations);
		}
	}
}
