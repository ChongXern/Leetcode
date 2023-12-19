import java.util.Scanner;

public class ImageSmoother {
    public int[][] imageSmoother(int[][] img) {
        int m = img.length;
        int n = img[0].length;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int total = 0;
                int cells = 0;
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            total += img[x][y] % 256;
                            cells++;
                        }
                    }
                }
                img[i][j] += (total / cells) * 256;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                img[i][j] /= 256;
            }
        }

        return img;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Input row size: ");
        int m = scanner.nextInt();
        System.out.print("Input col size: ");
        int n = scanner.nextInt();

        int[][] img = new int[m][n];
        System.out.println("Enter the matrix elements:");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                img[i][j] = scanner.nextInt();
            }
        }
        ImageSmoother smoother = new ImageSmoother();
        img = smoother.imageSmoother(img);

        System.out.println("Smoothened matrix:");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(img[i][j] + " ");
            }
            System.out.println();
        }
    }
}

