class Solution{
    ArrayList<String> resList = new ArrayList<>();
    int cnt = 0;
    public  void permutation(int[] a, int k, int n, int target) {
        if (k == n + 1) {

            cnt++;
            show(a);
            String res = "";
            for (int i = 1; i < a.length; i++) {
                res += a[i];
            }
            resList.add(res);
        } else {
            for (int i = k; i <= n; i++) {
                Arrays.sort(a,k,i);
                swap(a, k, i);
                show(a);
                permutation(a, k + 1, n, target);

                swap(a, k, i);
                
            }
        }

    }

    private  void show(int[] a) {
        for (int i = 1; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

    public void swap(int[] a, int x, int y) {

        int tmp = a[x];
        a[x] = a[y];
        a[y] = tmp;
    }

    public String getPermutation(int n, int k) {

        int[] s = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            s[i] = i;
        }
        //show(s);
        permutation(s, 1, n, k);

        Collections.sort(resList);
        System.out.println(resList.get(k - 1));
        return resList.get(k - 1);
    }
}
