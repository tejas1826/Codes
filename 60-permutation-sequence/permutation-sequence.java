class Solution {
    public String getPermutation(int n, int k) {
        
        List<Integer> list = new ArrayList<>();
        int fact = 1;

        for(int i = 1;i<n;i++){
            list.add(i);
            fact *= i;
        }
        list.add(n);

        k = k - 1;

        StringBuilder s = new StringBuilder();

        while(true){
            int index = k/fact;
            s.append(list.get(index));
            list.remove(index);

            if(list.size() == 0)break;

            k = k % fact;
            fact = fact/list.size();
        }

        return s.toString();
    }

    public int fact(int n){
        if(n <= 1)return 1;
        
        return fact(n-1)*n;
    }
}