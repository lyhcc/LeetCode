 public static int[][] generateMatrix(int n) {
        int[][] a = new int[n][n];

        int c=1;

        a[0][0]=c;
        int i = 0, j = 0;
        while(c<=(n*n)){

            while(c+1<=(n*n)&&j+1<n&&a[i][j+1]==0){a[i][j+1]=c+1;c++;j++;}


            while(c+1<=(n*n)&&i+1<n&&a[i+1][j]==0){a[i+1][j]=c+1;c++;i++;}


            while(c+1<=(n*n)&&j-1>=0&&a[i][j-1]==0){a[i][j-1]=c+1;c++;j--;}


            while(c+1<=(n*n)&&i-1>=0&&a[i-1][j]==0){a[i-1][j]=c+1;c++;i--;}

            if(c>=(n*n)) break;
        }
        return a;
    }