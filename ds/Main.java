import java.util.Scanner;

public class Main {

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int m = in.nextInt();
        int n = in.nextInt();
        int arr[][]=new int[m][n];

        for (int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                arr[i][j]=Integer.MAX_VALUE;
            }
        }
        for (int i = 0; i < m * n; i++)
        {
            insert(arr, m - 1, n - 1, in.nextInt());
        }


        int q = in.nextInt();
        int[] answers = new int[q];
        for (int i = 0; i < q; i++)
        {
            answers[i] = in.nextInt();
        }

        for (int k = 0; k < q; k++)
        {
            int i = m - 1;
            int j = 0;
            while (true)
            {
                if (i >=0 && j < n && answers[k] <= arr[m-1][n-1])
                {
                    if (arr[i][j] == answers[k])
                    {
                        System.out.println("y");
                        break;
                    }
                    else if (arr[i][j] < answers[k])
                    {
                        j++;
                    }
                    else {
                        i--;
                    }
                }
                else{
                    System.out.println("n");
                    break;
                }
            }
        }
    }


    public static void insert(int [][] arr, int i, int j, int key)
    {
        int x, y, max, temp;
        arr[i][j] = key;
        x = i;
        y = j;
        max = Integer.MAX_VALUE;
        while( (i > 0 || j > 0) && (max > arr[i][j]) )
        {
            temp = arr[x][y];
            arr[x][y] = arr[i][j];
            arr[i][j] = temp;
            i = x;
            j = y;
            if (i - 1 >= 0 && arr[i][j] < arr[i-1][j])
            {
                x = i -1;
                y = j;
            }
            if(j -1 >= 0 && arr[x][y] < arr[i][j-1])
            {
                x = i;
                y = j - 1;
            }
            max = arr[x][y];
        }
    }
}

