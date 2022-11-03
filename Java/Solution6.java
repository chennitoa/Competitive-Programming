import java.util.Scanner;
import java.math.BigInteger;

public class Solution6 {
	public static int solution(String x) {
		int i = 0;
		BigInteger num = new BigInteger(x, 10);
		BigInteger four = new BigInteger("4", 10);
		BigInteger two = new BigInteger("2", 10);
		BigInteger one = new BigInteger("1", 10);
		while (num.intValue() != 1) {
			if (num.mod(four).intValue() == 3 && num.intValue() != 3) {
				i++;
				num = num.add(one);
			}
			if (num.mod(two).intValue() == 1) {
				i++;
				num = num.subtract(one);
			}
			else {
				i++;
				num = num.divide(two);
			}
	   }
	   return i;
	}
	public static void main(String args[]) {
		Scanner scnr = new Scanner(System.in);
		String s = scnr.next();
		int j = solution(s);
		System.out.println(j);
		scnr.close();
	}
}
