import java.util.Scanner;

public class Solution4 {
	public static int solution(int[][] map) {
        int[][] distance = new int[map.length][map[0].length];
        int[][] distanceC = new int[map.length][map[0].length];
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[0].length; j++) {
                distance[i][j] = Integer.MAX_VALUE;
                distanceC[i][j] = Integer.MAX_VALUE;
            }
        }
        distance[0][0] = 1;
        draw(map, distance, distanceC, 0, 0, 1, false);
//        System.out.println("Printing arrays");
//        for (int i = 0; i < map.length; i++) {
//        	for (int j = 0; j < map[0].length; j++) {
//        		System.out.print(distance[i][j] + " ");
//        	}
//        	System.out.println("");
//        }
//        System.out.println("");
//        for (int i = 0; i < map.length; i++) {
//        	for (int j = 0; j < map[0].length; j++) {
//        		System.out.print(distanceC[i][j] + " ");
//        	}
//        	System.out.println("");
//        }
        return Math.min(distance[map.length - 1][map[0].length - 1], distanceC[map.length - 1][map[0].length - 1]);
    }
    public static void draw(int[][] map, int[][] distance, int[][] distanceC, int x, int y, int i, boolean crossed) {
//    	System.out.println("At coords " + x + ", " + y + ", Crossed = " + crossed + ", length = " + i);
        if (crossed) {
            distanceC[x][y] = i;
            if (x + 1 < map.length && (distanceC[x + 1][y] > i + 1 && distance[x + 1][y] > i + 1)) {
                 if (map[x + 1][y] == 0) draw(map, distance, distanceC, x + 1, y, i + 1, true);
            }
            if (x - 1 >= 0 && (distanceC[x - 1][y] > i + 1 && distance[x - 1][y] > i + 1)) {
                if (map[x - 1][y] == 0) draw(map, distance, distanceC, x - 1, y, i + 1, true);
            }
            if (y + 1 < map[0].length && (distanceC[x][y + 1] > i + 1 && distance[x][y + 1] > i + 1)) {
                if (map[x][y + 1] == 0) draw(map, distance, distanceC, x, y + 1, i + 1, true);
            }
            if (y - 1 >= 0 && (distanceC[x][y - 1] > i + 1 && distance[x][y - 1] > i + 1)) {
                if (map[x][y - 1] == 0) draw(map, distance, distanceC, x, y - 1, i + 1, true);
            }
        }
        else {
            distance[x][y] = i;
            if (x + 1 < map.length && distance[x + 1][y] > i + 1) {
                if (map[x + 1][y] == 0) {
                    draw(map, distance, distanceC, x + 1, y, i + 1, false);
                }
                else {
                    draw(map, distance, distanceC, x + 1, y, i + 1, true);
                }
            }
            if (x - 1 >= 0 && distance[x - 1][y] > i + 1) {
                if (map[x - 1][y] == 0) {
                    draw(map, distance, distanceC, x - 1, y, i + 1, false);
                }
                else {
                    draw(map, distance, distanceC, x - 1, y, i + 1, true);
                }
            }
            if (y + 1 < map[0].length && distance[x][y + 1] > i + 1) {
                if (map[x][y + 1] == 0) {
                    draw(map, distance, distanceC, x, y + 1, i + 1, false);
                }
                else {
                    draw(map, distance, distanceC, x, y + 1, i + 1, true);
                }
            }
            if (y - 1 >= 0 && distance[x][y - 1] > i + 1) {
                if (map[x][y - 1] == 0) {
                    draw(map, distance, distanceC, x, y - 1, i + 1, false);
                }
                else {
                    draw(map, distance, distanceC, x, y - 1, i + 1, true);
                }
            }
        }
    }
    public static void main(String args[]) {
    	Scanner scnr = new Scanner(System.in);
    	System.out.println("Code running!");
    	int n = scnr.nextInt();
    	int m = scnr.nextInt();
    	int[][] map = new int[n][m];
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			map[i][j] = scnr.nextInt();
    		}
    	}
    	System.out.println(solution(map));
    	scnr.close();
    }
}
