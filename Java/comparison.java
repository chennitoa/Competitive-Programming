import java.util.*;

class comparison {
	public static void main(String args[]) {
		boolean a = false;
		boolean b = false;
		System.out.println((a && (b || !a)) == a && b);
	}
}