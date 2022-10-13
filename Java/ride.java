/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: achenni1
LANG: JAVA
TASK: gift1
*/
import java.io.*;
import java.util.*;

class gift1 {
  public static void main (String [] args) throws IOException {
    BufferedReader f = new BufferedReader(new FileReader("gift1.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gift1.out")));
	StringTokenizer st = new StringTokenizer(f.readLine());
	final int NP = Integer.parseInt(f.readLine());
	
	String[] names = new String[NP]
	HashMap<Integer, String> gifters = new Hashmap<Integer, String>
	for (int i = 0; i < NP; i++) {
		gifters.put(names[i], 0);
	}
	


}


 
