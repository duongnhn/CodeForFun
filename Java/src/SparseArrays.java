import java.util.HashMap;
import java.util.Scanner;

public class SparseArrays {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		HashMap<String, Integer> hm = new HashMap<String, Integer>();
		for (int i=0;i<n;i++){
			String s = in.next();
			if (hm.containsKey(s)){
				int val = hm.get(s);
				hm.put(s, val+1);
			} else {
				hm.put(s, 1);
			}
		}
		int q = in.nextInt();
		for (int i=0;i<q;i++){
			String s = in.next();
			if (hm.containsKey(s)){
				int val = hm.get(s);
				System.out.println(val);
			}
			else {
				System.out.println(0);
			}
		}
	}

}
