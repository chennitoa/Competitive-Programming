import java.util.LinkedList;
import java.util.Scanner;

public class Solution7 {
	
	public static int dfs(int floor, int maxFlow, int[] level, int[][] capacity, int[][] path, boolean[] isExit) {
		int totalFlow = 0;
		if (isExit[floor]) return maxFlow;
		for (int i = 0; i < path.length; i++) {
			if (i != floor && path[floor][i] - capacity[floor][i] > 0 && (level[i] == level[floor] + 1 || isExit[i])) {
				int j = dfs(i, Math.min(maxFlow, path[floor][i] - capacity[floor][i]), level, capacity, path, isExit);
				capacity[floor][i] = j;
				maxFlow -= j;
				totalFlow += j;
			}
		}
		return totalFlow;
	}
	
	public static int solution(int[] entrances, int[] exits, int[][] path) {
		LinkedList<Integer> queue = new LinkedList<Integer>();
		boolean[] isExit = new boolean[path.length];
		for (int i = 0; i < exits.length; i++) {
			isExit[exits[i]] = true;
		}
		int[] level = new int[path.length];
		for (int i = 0; i < entrances.length; i++) {
			queue.addLast(entrances[i]);
			level[entrances[i]] = 1;
		}
		while (queue.size() != 0) {
			while (isExit[queue.peekFirst()]) {
				queue.removeFirst();
				if (queue.size() == 0) break;
			}
			if (queue.size() == 0) break;
			for (int i = 0; i < path.length; i++) {
				if (level[i] == 0 && path[queue.peekFirst()][i] > 0) {
					queue.addLast(i);
					level[i] = level[queue.peekFirst()] + 1;
				}
			}
			queue.removeFirst();
		}
		int[][] capacity = new int[path.length][path[0].length];
		
		boolean blocked = false;
		int it = 0;
		while (!blocked) {
			it++;
			if (it ==51) break;
			System.out.println(it + "th iteration.");
			for (int i = 0; i < entrances.length; i++) {
				dfs(entrances[i], Integer.MAX_VALUE, level, capacity, path, isExit);
			}
			for (int i = 0; i < path.length; i++) {
				level[i] = 0;
			}
			for (int i = 0; i < entrances.length; i++) {
				queue.addLast(entrances[i]);
				level[entrances[i]] = 1;
			}
			while (queue.size() != 0) {
				while (isExit[queue.peekFirst()]) {
					queue.removeFirst();
					if (queue.size() == 0) break;
				}
				if (queue.size() == 0) break;
				for (int i = 0; i < path.length; i++) {
					if (level[i] == 0 && path[queue.peekFirst()][i] - capacity[queue.peekFirst()][i] > 0) {
						queue.addLast(i);
						level[i] = level[queue.peekFirst()] + 1;
					}
				}
				queue.removeFirst();
			}
			boolean foundBlock = true;
			for (int i = 0; i < exits.length; i++) {
				if (level[exits[i]] != 0) foundBlock = false;
			}
			if (foundBlock) blocked = true;
		}
		
		int maxFlow = 0;
		for (int i = 0; i < exits.length; i++) {
			for (int j = 0; j < path.length; j++) {
				if (exits[i] != j) maxFlow += capacity[j][exits[i]];
			}
		}
		return maxFlow;
	}

	public static void main(String args[]) {
		Scanner scnr = new Scanner(System.in);
		System.out.println("Number of entrances: ");
		int a = scnr.nextInt();
		System.out.println("Entrances: ");
		int[] ent = new int[a];
		for (int i = 0; i < a; i++) {
			ent[i] = scnr.nextInt();
		}
		System.out.println("Number of exits: ");
		int b = scnr.nextInt();
		System.out.println("Exits: ");
		int[] ext = new int[b];
		for (int i = 0; i < b; i++) {
			ext[i] = scnr.nextInt();
		}
		System.out.println("Dimensions of path: ");
		int c = scnr.nextInt();
		int d = scnr.nextInt();
		System.out.println("Path: ");
		int[][] path = new int[c][d];
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < d; j++) {
				path[i][j] = scnr.nextInt();
			}
		}
		scnr.close();
		System.out.println("Calculating solution: ");
		System.out.println(solution(ent, ext, path));
	}
	
}
