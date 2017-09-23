import java.math.BigInteger;
import java.util.HashMap;

public class Primality {

    static int verifyItems(String[] origItems, float[] origPrices, String[] items, float[] prices) {
    	HashMap<String, Float> hm = new HashMap<String, Float>();
    	int count = 0;
    	int n = origItems.length;
    	int m = items.length;
    	for (int i = 0;i<n;i++){
    		hm.put(origItems[i], origPrices[i]);
    	}
    	for (int i=0;i<m;i++){
    		float t = hm.get(items[i]);
    		if (t != prices[i]) count++;
    	}
    	return count;

    }
	
    public static int getLongestCommonSubstring(String a, String b){
		int m = a.length();
		int n = b.length();
	 
		int max = 0;
	 
		int[][] dp = new int[m][n];
	 
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(a.charAt(i) == b.charAt(j)){
					if(i==0 || j==0){
						dp[i][j]=1;
					}else{
						dp[i][j] = dp[i-1][j-1]+1;
					}
	 
					if(max < dp[i][j])
						max = dp[i][j];
				}
	 
			}
		}

		return max;
    }
    
    static int[] getMinimumDifference(String[] a, String[] b) {
        int n = a.length;
        int[] arr = new int[n];
        for (int i=0;i<n;i++){
            int la = a[i].length();
            int lb = b[i].length();
            if (la != lb) {
            	arr[i] = -1;
            }
            else {
            	int l = getLongestCommonSubstring(a[i], b[i]);
            	arr[i] = la-l;
            }
        }
        return arr;
    }    
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		BigInteger n = new BigInteger("123");
		if (n.isProbablePrime(10))
			System.out.println("prime");
		else System.out.println("not prime");
	}

}
