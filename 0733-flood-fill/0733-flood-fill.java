
class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {

        int m = image.length;
        int n = image[0].length;

        int oldColor = image[sr][sc];

        if (oldColor == color)
            return image;

        dfs(image, sr, sc, oldColor, color, m, n);

        return image;
    }

    void dfs(int[][] image, int i, int j, int oldColor, int color, int m, int n) {

        if (i < 0 || j < 0 || i >= m || j >= n)
            return;

        if (image[i][j] != oldColor)
            return;

        image[i][j] = color;

        dfs(image, i + 1, j, oldColor, color, m, n);
        dfs(image, i - 1, j, oldColor, color, m, n);
        dfs(image, i, j + 1, oldColor, color, m, n);
        dfs(image, i, j - 1, oldColor, color, m, n);
    }
}
