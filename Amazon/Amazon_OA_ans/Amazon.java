package com.robin.leetCode.companies;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Amazon {
    /**
    *@amazon=1
    *给一个searchWord和一个resultWord，问最少给searchWord末尾添加几个字符，可以让resultWord成为它的一个subsequence。
    *举个栗子：searchWord=“armaze”，resultWord=”amazon”，则应该返回2（添加on）。
    *思路是两个指针p1，p2分别遍历两个字符串，如果指向的字符相同，则将双指针同时向后移动一位，
    *反之只移动指向searchWord的指针，直到任意指针到达末尾。返回resultString的长度与resultString指针位置的差.
    */
    public int addChar(String search, String result){
        int p1 = 0, p2 = 0;
        while(p1 < search.length() && p2 < result.length()){
            if(search.charAt(p1) == result.charAt(p2)){
                p1++;
                p2++;
            }else{
                p1++;
            }
        }
        System.out.println("result.length=["+result.length()+"] p2=["+p2+"]");
        return result.length()-p2;
    }

    /**
    *@amazon=2
    * 给一串字符，"abcdefgabc"，然后用手机九宫格打出。
    * 手机九宫格可以是任何字母组合，唯一要求是每个键至少有两个字母，最多三个字母。
    * 换句话说，这里的键位不一定是我们常见的2=abc，3=def等等，可以是1=agq，2=bhj...任何顺序都可以。
    * 要求找出能打出输入字符串的最少按键次数。我的做法是贪心，先遍历一次统计每个字母出现的次数，再按次数排序，
    * 然后当然应该尽可能地把次数多的字母分布在九个数字的第一个位置上，so on and so forth。
    */
    public int nineTyping(String s){
        int result = 0;
        int[] arr = new int[26];
        for(int i=0;i<s.length();i++){
            arr[s.charAt(i)-'a'] ++;
        }
        Arrays.sort(arr);
        System.out.println(FastJsonUtils.toString(arr));
        int i=arr.length-1;
        while(arr[i] != 0 || i<0){
            if(i>=17){
                result = result + arr[i];
                System.out.println("+1 i=["+i+"] arr[i]=["+arr[i]+"] result=["+result+"]");
            }else if(i>=8 && i<17){
                result = result + arr[i] * 2;
                System.out.println("+2 i=["+i+"] arr[i]=["+arr[i]+"] result=["+result+"]");
            }else if(i<8){
                result = result + arr[i] * 3;
                System.out.println("+3 i=["+i+"] arr[i]=["+arr[i]+"] result=["+result+"]");
            }
            i--;
        }
        return result;
    }

    /**
    *@amazon=3
    * 给一个长度为n的数组表示n个月的股价，给定k值，给连续k月并且k个值各不一样的区间求和，找到最大和。
    * 例子：｛1，2，7，7,4,3,6｝，k=3，
    * 那总共有(1,2,7)(7,4,3)(4,3,6) 三个长度为k的连续区间并且每个区间没有重复数值，最大和是14。
    */
    public int maxStockSum(int stocks[], int k){
        int result = 0, i=0, j=k-1;
        Map<Integer, Integer> map = new HashMap<Integer, Integer> ();
        //子序列规则 不能有重复, 不能超过K个
        while(j<stocks.length){
            int sum = processStocks(stocks, i, j, map);
            result = Math.max(result, sum);
            map.clear();
            i++;
            j++;
        }
        return result;
    }

    public boolean isSubsequence(String s, String t) {
        boolean retBool = true;
        int[] sArr = new int[25];
        int[] tArr = new int[25];
        for(int i=0;i<s.length();i++){
            sArr[s.charAt(i)-'a']++;
        }
        System.out.println(FastJsonUtils.toString(sArr));
        return retBool;
    }

    public int processStocks(int[] stocks, int start, int end, Map<Integer, Integer> map){
        int sum = 0;
        for(;start <= end;start++){
            if(!map.containsKey(stocks[start])){
                map.put(stocks[start], stocks[start]);
                sum += stocks[start];
            }else{
                return 0;
            }
        }
        return sum;
    }

    /**
    *@amazon=4
    *给了三个list: locations,moveFrom, moveTo,
    *求从 moveFrom 到 moveTo 后， return 各个物品的位置 从小到大
    */
    public int[] moveData(int[] location, int[] from, int[] to){
        Set<Integer> set = new HashSet<Integer>();
        for(int x:location)
            set.add(x);
        for(int i=0;i<from.length;i++){
            if(set.contains(from[i])){
                set.remove(from[i]);
                set.add(to[i]);
            }
        }
        System.out.println(FastJsonUtils.toString(set));
        int[] result = new int[set.size()];
        int j=0;
        for(int x:set){
            result[j] = x;
            j++;
        }
        return result;
    }
    
    /**
    *@amazon=5
    *灰度 给一个2D array，array[i][j]表示在(i, j)点处的灰度值，0为白 1为黑，
    *(i, j)处的灰度值为第i行所有点灰度值 +第j列所有点灰度值之和 （黑+1，白-1），
    *求array中灰度值最大的点的灰度值为多少
    *思路: 两层for循环‍‌‍‌‍‍‌‌‌‍‍‍‍‍‌‍‌分别求出colsGrey[]和 rowsGrey[]然后再遍历一遍求max即可
    */
    public int maxGrayValue(int[][] arr){
        int[] row = new int[arr.length];
        int[] col = new int[arr[0].length];
        for(int i=0;i<row.length;i++){
            for(int j=0;j<col.length;j++){
                if(arr[i][j] == 1){
                    row[i] += 1;
                    col[j] += 1;
                }else{
                    row[i] -= 1;
                    col[j] -= 1;                    
                }
            }
        }
        System.out.println(FastJsonUtils.toString(row));
        System.out.println(FastJsonUtils.toString(col));
        int maxRow = 0, maxCol =0;
        for(int r:row){
            maxRow = Math.max(maxRow, r);
        }
        for(int c:col){
            maxCol = Math.max(maxCol, c);
        }    
        return maxRow+maxCol;
    }

    /**
    *@amazon=7
    *给两个字符串s和t，求问使用s所有的字母最多能够重组出几个t。
    *举个栗子：s=“mononom”，t=“mon”，则答案是2。s=abacbc,s=abc --> 2
    *思路是用两个counter统计s和t的字母出现频率，然后遍历t的所有字母，找到s中出现次数/t中出现次数的最小值（向‍‌‍‌‍‍‌‌‌‍‍‍‍‍‌‍‌下取整）
    */
    public int reArrangeWord(String s, String t){
        int result = Integer.MAX_VALUE;
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        Map<Character, Integer> tmap = new HashMap<Character, Integer>();
        for(char c:s.toCharArray()){
            map.put(c, map.getOrDefault(c, 0)+1);
        }
        for(char c:t.toCharArray()){
            tmap.put(c, tmap.getOrDefault(c, 0)+1);
        }
        for(Map.Entry<Character, Integer> ent : tmap.entrySet()){
            if(map.containsKey(ent.getKey())){
                int count = ent.getValue();
                if(count > 1){
                    result = Math.min(result, map.get(ent.getKey())/count);
                }else{
                    result = Math.min(result, map.get(ent.getKey()));
                }
            }else{
                return 0;
            }
        }
        return result;
    }

    /**
    *@amazon=8
    *计算Change of temperature
    *只记得example 假设三天的气温是【6 -2 5】
    *第一天 max([6],[6+(-2)+5]) = max(6,9) = 9
    *第二天 max([6+(-2)],[(-2)+5]]) = max(4,3) = 4
    *第三天 max([6-2+5],[5]) = max(9,5) = 9
    *最后return max(9,4,9)=9
    */
    public int changeOfTemprature(int[] grid){
        int[] prefix = new int[grid.length];
        prefix[0] = grid[0];
        for(int i=1;i<grid.length;i++){
            prefix[i] = grid[i] + prefix[i-1];
        }
        System.out.println(FastJsonUtils.toString(prefix));
        int max_agg = prefix[grid.length-1];
        for(int i=1;i<grid.length-1;i++){
            int tmp = Math.max(prefix[i], prefix[grid.length-1] -prefix[i-1]);
            System.out.println(tmp);    
            max_agg = Math.max(tmp, max_agg);
        }
        return max_agg;
    }

    /**
    *@amazon=9
    *以1开始的数组，后面每两个相邻数字直接差距不能>1，可以重新调整顺序和减少到>=1, 问数组的最后一个数字可能的最大值
    */
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        Arrays.sort(arr);
        arr[0] = 1;
        int result = arr[0];
        for(int i=1;i<arr.length;i++){
            arr[i] = Math.min(arr[i], arr[i-1]+1);
            result = Math.max(result, arr[i]);
        }
        System.out.println(FastJsonUtils.toString(arr));
        return result;
    }

    /**
    *@amazon=10
    *最少merge几个区间, 返回的是int：
    *function 名字： getNonInclusiveRetailor
    *Input: intervals = [[1,2],[2,3],[3,5],[4,5]]
    *Output: 1，[4， 5]  被merge掉了， 所以是结果是1
    */
    public int getNonInclusiveRetailor(int[][] arr){
        Arrays.sort(arr, (a,b)->(a[0]-b[0]));
        List<int[]> list = new ArrayList<int[]>();
        for(int[] x:arr){
            if(list.size() == 0){
                list.add(x);
            }else{
                int[] preInterval = list.get(list.size()-1);
                if(preInterval[1] >= x[0]){
                    preInterval[1] = Math.max(preInterval[1], x[1]);
                }else{
                    list.add(x);
                }
            }
        }
        //最终只剩 [1,5]
        System.out.println(FastJsonUtils.toString(list));
        return list.size();
    }

    /**
    *@amazon=11
    *求array的所有 连续subArray的max与 min差 的和
    *[1,3,2] -> 5
    *[1,3]=2, [1,3,2]=2, [2,3]=1,  2+2+1=5
    */
    public int subArraySum(int arr[]){
        int result = 0;
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        for(int i=0;i<arr.length;i++){
            List<Integer> subl = new ArrayList<Integer>();
            processContinusSubSet(list, subl, arr, i);
        }
        for(List<Integer > l:list){
            result += calculateSubSet(l);
        }
        return result;
    }

    public int calculateSubSet(List<Integer> list){
        int result = 0;
        if(list.size()>=2){
           int max = 0, min = Integer.MAX_VALUE;
           for(int x:list){
               max = Math.max(max, x);
               min = Math.min(min, x);
           } 
           result = max - min;
        }
        System.out.println("result="+result+" list="+FastJsonUtils.toString(list));
        return result;
    }

    public void processContinusSubSet(List<List<Integer>> result, List<Integer> list, int[] nums, int start){
        for(int i=start;i<nums.length;i++){
            list.add(nums[i]);
            result.add(new ArrayList<Integer>(list));
        }
    }

    public void processSubSet(int[] nums, int start, List<List<Integer>> result, List<Integer> list){
        result.add(new ArrayList<Integer>(list));
        for(int i=start;i<nums.length;i++){
            list.add(nums[i]);
            processSubSet(nums, i+1, result, list);
            list.remove(list.size() - 1);
        }
    }

    /**
    *@amazon=13
    *给一个string array, 对每个string，split into 2 strings，
    *找到后面部分和原来string的common prefix length，把所有分法的common prefix length加起来。
    *最后返回一个数组是每个string求得的sum of common prefix length
    */
    public int[] commonPrefix(String str){
        int[] result = new int[str.length()];
        result[0] = str.length();
        for(int i=1;i<str.length();i++){
            String prefix = str.substring(0,i);
            String suffix = str.substring(i);
            if(suffix.startsWith(prefix)){
                result[i] = prefix.length();
            }
            System.out.println("prefix=["+prefix+"] suffix=["+suffix+"]");
        }
        return result;
    }

    /**
    *@amazon=交换0,1到一侧. 共需要多少步.每次只能跟两边的位置交换.
    * 返回int
    *把0. 1移到两头,每次只能交换临近的，最少需要几步，0和1或左或右都可以，只要归到一侧就可以。
    *[0，1，0，1]，k=1 需要1步，
    *[0, 0, 1, 1] 需要0步。
    *[1, 1, 1, 1, 0, 0, 0, 1, 0, 1] 需要2步， [1, 1, 1, 1, 1, 1, 0, 0]
    */
    public int minMove2(int[] arr){
        int count0=0,count1=0,distance=0;
        for(int x:arr){
            if(x==1)
                count1 ++;
            if(x==0)
                distance += count1;
        }
        count0 = arr.length - count1;
        int reverse = count1*count0 - distance;
        return Math.min(distance, reverse); // Choose lowest no. of steps
    }

    //
    public int longestOnes(int[] A, int K) {
        int len = A.length, l = 0, num = 0, res = 0, right=0;
        for(int r = 0; r < len; r++) {
            if(A[r] == 0) {
                num++;
            }
            while(num > K) {
                if(A[l] == 0) {
                    num--;
                }
                System.out.println("~~~~~~~"+l);
                l++;
            }
            right = r;
            res = Math.max(res, r - l + 1);
        }
        System.out.println("left="+l+", right="+right);        
        return res;
    }

    /**
    *@amazon=16
    *
    */    
    public int minNetSocketPrice(int[] stocks){
        int result = 0;
        
        return result;
    }

    /**
    *@amazon=18
    *给一数组轮子. 可以组装成2种车-4轮,2轮. 如果轮子不是2,4的倍数则不能组装.
    *返回每一组轮子能组装成几辆车.
    *{6,3,2}->{2,0,1} say {1个4轮+1个两轮, 0个, 1个两轮}
    */
    public int[] findWheels(int[] vehicles) {
        for(int i =0; i<vehicles.length;i++) {
            if(vehicles[i]%2 != 0) {
                vehicles[i] = 0;
                continue;
            }
            int numOfWays = vehicles[i]/4 + 1;
            vehicles[i] = numOfWays;
        }
        return vehicles;
    }

    /**
    *@amazon=19
    *给一组数组, 删掉k个连续元素, 问剩下最小的和是多少?
    *例子: arr = [7, 3, 6, 1], k = 2, result = 7
    */
    public int sumOfRemain(int[] arr){
        int result = 0;
        
        return result;
    }
    
    /*
    public double maximumAverageSubtree(TreeNode root) {
        return maxAverage(root)[2];
    }
    
    /// [Index(0) -> Node Count, Index(1) = Sum Of Values of Nodes, Index(2) - Max Average]
    private double[] maxAverage(TreeNode root) {
        if(root == null) return new double[] {0, 0, Double.MIN_VALUE};
        
        double[] leftTree = maxAverage(root.left);
        double[] rightTree = maxAverage(root.right);
        
        //// Nodes from Left SubTree + Right SubTree + (Current Root) 1
        double nodeCount = leftTree[0] + rightTree[0] + 1;
        double valueSum = leftTree[1] + rightTree[1] + (double)root.val;
        /// Take Maximum between Avg Including current Node, Left SubTree Max Avg, Right SubTree Max Avg
        double maxAvg = Math.max(valueSum / nodeCount, Math.max(leftTree[2], rightTree[2]));
        
        /// Return {Node Count, Sum Of Values Of Nodes, Max Avg Until Now} above for current node
        return new double[] {nodeCount, valueSum, maxAvg};
    }
*/
    
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Amazon amazon = new Amazon();
        //int[] nums={1,2,3,4,5};
        /*
        int jewelsAndStones = amazon.jewelsAndStones("aA","aAAlfIDdisoa");
        System.out.println(jewelsAndStones);

        int countDigits = amazon.countDigits(235);
        System.out.println("countDigits="+countDigits);
        
        int[] arr = amazon.sortArrayAscend(nums);
        System.out.print(FastJsonUtils.toString(arr));
        
        int[] arr = amazon.replaceArray(nums);
        System.out.print(FastJsonUtils.toString(arr));
        
        int[] arr = amazon.reverseArray(nums);
        System.out.print(FastJsonUtils.toString(arr));
        
        //amazon.printPattern3(5);
        int[] arr = {2,2,1,2,1};
        int mead = amazon.maximumElementAfterDecrementingAndRearranging(arr);
        System.out.println("maximumElementAfterDecrementingAndRearranging="+mead);
        amazon.addChar("armaze", "amazon");
        
        amazon.nineTyping("abcdefgabchijklmnopqrstuvwxyznmlofdslaif");
        
        int[] stocks = {1,2,7,7,4,3,6};
        int maxStock = amazon.maxStockSum(stocks, 2);
        System.out.println("maxStock="+maxStock);
        
        int[] location = {1,6,7,8};
        int[] from = {1,7,2};
        int[] to = {2,9,5};
        int[] md = amazon.moveData(location, from, to);
        System.out.println(FastJsonUtils.toString(md));
        
        int[][] grid = {{1,0,1,1},{1,0,1,0},{1,0,0,1}};
        int mg = amazon.maxGrayValue(grid);
        System.out.println("maxGrayValue="+mg);
        
        int raw = amazon.reArrangeWord("aabacbcbcbc", "abc");
        System.out.println("reArrangeWord="+raw);
        
        int[] grid = {6,-2,5};
        int maxTemp = amazon.changeOfTemprature(grid);
        System.out.println("changeOfTemprature="+maxTemp);
        
        int[][] intervals = {{1,2},{2,3},{3,5},{4,5}};
        amazon.getNonInclusiveRetailor(intervals);
        
        int[] grid = {1,3,2};
        int maxSubArr = amazon.subArraySum(grid);
        System.out.println("subArraySum="+maxSubArr);
        
        int[] preArr = amazon.commonPrefix("abcabcd");
        System.out.println(FastJsonUtils.toString(preArr));

        int[] arr = {1, 1, 0, 1, 0, 1};//{1, 1, 1, 1, 0, 0, 1, 0, 1};
        int minMv = amazon.minMove2(arr);
        System.out.println("minMove="+minMv+" findMinSwaps="+fminMv);
        
        int[] arr = {1,1,1,0,0,0,1,1,1,1,0};//{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
        int ftm = amazon.longestOnes(arr, 3);
        System.out.println("flipToMax="+FastJsonUtils.toString(ftm));
        
        int[] stocks = {1, 3, 2, 3};
        amazon.minNetSocketPrice(stocks);
        
        int[] vehicles = {4,5,6};
        int[] result = amazon.findWheels(vehicles);
        System.out.println(FastJsonUtils.toString(result));
        
        int raw = amazon.reArrangeWord("aabaacbcbcbc", "aac");
        System.out.println("reArrangeWord="+raw);
        
        int count = amazon.nineTyping2("abacadefghibjhijklmnopqrstabacadefgh");
        System.out.println("nineTyping2="+count);
        */
        boolean iss = amazon.isSubsequence("abca", "ahbgdcia");
        System.out.println("392. Is Subsequence ="+iss);
    }

}
