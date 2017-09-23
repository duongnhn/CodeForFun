import java.util.HashMap;

public class LongestCommonSubsequence {

	public static HashMap<Character, Integer> convert(String a){
		HashMap<Character, Integer> hm = new HashMap<Character, Integer>();
		for (int i=0;i<a.length();i++){
			char ch = a.charAt(i);
			if (hm.containsKey(ch)){
				int val = hm.get(ch);
				hm.put(ch, val+1);
			}
			else hm.put(ch, 1);
		}
		return hm;
	}
	
	public static int getLongestCommonSubsequence(String a, String b){
		HashMap<Character, Integer> hmA = convert(a);
		HashMap<Character, Integer> hmB = convert(b);
		int count = 0;
		for (char c='a';c<='z';c++){
			int valA = 0, valB = 0;
			if (hmA.containsKey(c)) valA = hmA.get(c);
			if (hmB.containsKey(c)) valB = hmB.get(c);
			count += Math.abs(valA-valB);
		}
		return count;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(getLongestCommonSubsequence("abc", "bac"));
	}

}
