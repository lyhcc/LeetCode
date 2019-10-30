class Solution{

    int cnt = 0;


    public String getPermutation(int n, int k) {

        int[] s = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            s[i] = i;
        }
        //show(s);
        return  permutation(s, 1, n, k);


    }
    private  void show(int[] a) {
        for (int i = 1; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }
    private String permutation(int[] s, int i, int n, int k) {
        int lft = i;
        int rht = n;
        s[0] = 10;
        while(true){
            cnt++;
            if (cnt == k) {
                String res = "";
                for (int j = 1; j < s.length; j++) {
                    res += s[j];
                }
                //System.out.println(res);
                return res;
            }
            rht = n;
            while (rht - 1 > 0 && s[rht] < s[rht - 1]) rht--;
            int idx = rht - 1;

            if (idx==0) {
                break;
            }
            lft = rht;
            while (lft<= n && s[idx] < s[lft]) lft++;
            lft--;
            System.out.println(idx + " " + lft);
            swap(s, idx, lft);
            Arrays.sort(s, idx + 1, n+1);
            //show(s);

        }
        return "";
    }

    public void swap(int[] a, int x, int y) {

        int tmp = a[x];
        a[x] = a[y];
        a[y] = tmp;
    }
