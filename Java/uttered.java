import java.util.*;

class uttered {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		String alphabet = in.nextLine();
		String word = in.nextLine();
		int repeat = 1;
		boolean end = false;
		for (int z = 0; z < word.length(); z++) {
			for (int i = 0; i < alphabet.length(); i++) {
				if (word.charAt(z) == alphabet.charAt(i)) {
					if (z < word.length()-1) {
						z++;
					}
					else {
						end = true;
					}
				}
			}
			if (end == true) {
				break;
			}
			repeat++;
			z--;
		}
	
		System.out.println(repeat);
	}
}