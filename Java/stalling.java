import java.util.*;

class stalling {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int iterationWays = 0;
		long numWays = 1;
		int numCows = in.nextInt();
		int[] cowHeights = new int[numCows];
		int[] stallHeights = new int[numCows];
		for (int i = 0; i < numCows; i++) {
			cowHeights[i] = in.nextInt();
		}
		for (int i = 0; i < numCows; i++) {
			stallHeights[i] = in.nextInt();
		}
		
		Arrays.sort(cowHeights);
		for (int i = 0; i < numCows; i++) {
			for (int j = 0; j < numCows; j++) {
				if (cowHeights[numCows - i - 1] <= stallHeights[j]) iterationWays++; 
			}
			numWays *= iterationWays;
			iterationWays = 0 - (i + 1);
		}
		
		System.out.println(numWays);
	}
}