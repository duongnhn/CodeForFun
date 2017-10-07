import java.util.Arrays;
import java.util.Collections;

public class MinimumAbsDiff {

    static int minimumAbsoluteDifference(int n, int[] arr) {
        // Complete this function
    	int min = Integer.MAX_VALUE;
    	int length = arr.length;
    	Arrays.sort(arr);
    	for (int i=1;i<length;i++){
			int diff = Math.abs(arr[i]-arr[i-1]);
			if (diff < min){
				min = diff;
			}
			if (min == 0) break;
    	}
    	return min;
    }
    
    static int removeDup(int[] nums){
    	int length = 0;
    	int n = nums.length;
    	int i = 0;
    	while (i<n-1){
    		i++;
    		int cur = nums[length];
    		if (nums[i] > cur){
    			length++;
    			nums[length] = nums[i];
    		}
    	}
    	return length+1;
    }
	
    static int removeElement(int[] nums, int val) {
        int i = 0;
        int n = nums.length;
        int j = n-1;
        while (i < j){
            if (nums[i] == val && nums[j] != val){
                nums[i] = nums[j];
                nums[j] = val;
            }
            if (nums[i] != val) i++;
            if (nums[j] == val) j--;            
        }
        n--;
        while (n >= 0 && nums[n]==val){
        	n--;
        }
        return n+1;
    }
    
    static boolean check(int mm, int dd){
    	int a = mm/10;
    	int b = mm%10;
    	int c = dd/10;
    	int d = dd%10;
    	if (a==b || a==c || a==d) return false;
    	if (b==c || b==d) return false;
    	if (c==d) return false;
    	return true;
    }
    
    static void print(int n){
    	int count = 0;
    	for (int mm=1;mm<=12;mm++){
    		for (int dd=1;dd<=31;dd++){
    			if (check(mm,dd)){
    				count++;
    				String st = ""+mm;  
    				if (mm < 10) 
    					st = "0"+st;
    				if (dd < 10) 
    					st = st+"0"+dd;
    				else 
    					st = st+dd;
    				System.out.println(st);
    				if (count == n) return;
    			}
    		}
    	}
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
        print(1000);
	}		

}
