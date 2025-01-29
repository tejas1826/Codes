class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> pascal = new ArrayList<>();
        
        for (int i = 1; i <= numRows; i++) {
            List<Integer> row = new ArrayList<>();
            row.add(1);
            int num = 1;
            for (int j = 1; j < i; j++) {
                num = (num * (i - j)) / j;
                row.add(num);
            }
            pascal.add(row);
        }
        return pascal;
    }
}