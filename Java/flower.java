import java.util.*;
// 1/22/2021 First Self-made contest program
class flower {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int[] flowers = new int[in.nextInt()];
		for (int i = 0; i < flowers.length; i++) {
			flowers[i] = in.nextInt();
		}
		int averageCount = 0;
		double total = 0;
		for (int i = 0; i < flowers.length; i++) {
			for (int z = i; z < flowers.length; z++) {
				for (int t = i; t <= z; t++) {
					total += flowers[t];
				}
				total = total / (z - i + 1);
				for (int t = i; t <= z; t++) {
					if (flowers[t] == total) {
						averageCount++;
						break;
					}
				}
				total = 0;
			}
		}
		System.out.println(averageCount);
	}
}