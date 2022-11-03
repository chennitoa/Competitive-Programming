import java.util.Scanner;
import java.util.HashMap;

public class Solution5 {
	static HashMap<String, Boolean> hMap = new HashMap<String, Boolean>();
	public static int solution(int[] l) {
		solve(l, -1, -1, -1);
		return hMap.size();
	}
	public static void solve(int[] l, int a, int b, int c) {
		if (a == -1) {
			for (int i = 0; i < l.length; i++) {
				solve(l, i, b, c);
			}
		}
		else if (b == -1) {
			for (int i = a + 1; i < l.length; i++) {
				if (l[i] % l[a] == 0) {
					solve(l, a, i, c);
				}
			}
		}
		else if (c == -1) {
			for (int i = b + 1; i < l.length; i++) {
				if (l[i] % l[b] == 0) {
					solve(l, a, b, i);
				}
			}
		}
		else {
			String s = l[a] + " " + l[b] + " " + l[c];
			if (!hMap.containsKey(s)) {
				System.out.println("Found triple " + l[a] + " " + l[b] + " " + l[c] + " at " + a + " " + b + " " + c);
				hMap.put(s, true);
			}
		}
	}
	public static void main(String args[]) {
		Scanner scnr = new Scanner(System.in);
		int n = scnr.nextInt();
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = scnr.nextInt();
		}
		int j = solution(p);
		System.out.println(j);
		scnr.close();
	}
}
