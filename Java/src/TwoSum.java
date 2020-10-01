import java.util.HashMap;

public class TwoSum {

    public static int[] twoSum(int[] nums, int target) {
        int[] out = {0, 1};
        HashMap<Integer, Integer> ht = new HashMap<Integer, Integer>();
        for (int i=0;i<nums.length;i++){
        	ht.put(nums[i], i);
        }
        for (int i=0;i<nums.length;i++){
        	int val = target - nums[i];
        	if (ht.containsKey(val)){
           		out[1] = ht.get(val);
           		out[0] = i;
        		if (out[0] != out[1]) break;
        	}
        }
        return out;
    }
	
    public static int[] twoSumSorted(int[] nums, int target) {
        int[] out = {0, 1};
        int idx1 = 0;
        int idx2 = nums.length-1;
        while (idx1<idx2){
        	int sum = nums[idx1] + nums[idx2];
        	if (sum == target){
        		out[0] = idx1;
        		out[1] = idx2;
        		break;
        	}
        	if (sum < target){
        		idx1++;
        	}
        	else {
        		idx2--;
        	}
        }
        return out;
    }
    
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] in = {2,3,4};
		int target = 6;
		int[] out = twoSumSorted(in, target);
		System.out.println(out[0]+ " " + out[1]);
	}

}
