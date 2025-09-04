public class Solution {
    private int _k;
    private int _nbValues;

    private bool extractValues(int[][] matrix, int[] result, int val, int valmax, int constVal, bool increase, bool isRow){
        if(increase){
            for(int idx = val; idx <= valmax; idx++)
                result[_k++] = !isRow ? matrix[idx][constVal] : matrix[constVal][idx];
        }
        else{
            for(int idx = val; idx >= valmax; idx--)
                result[_k++] = !isRow ? matrix[idx][constVal] : matrix[constVal][idx];
        }
        return _k == _nbValues;
    }

    public IList<int> SpiralOrder(int[][] matrix) {
        int x = 0;
        int y = 0;
        int xmax = matrix[0].Length-1;
        int ymax = matrix.Length-1;

        _nbValues = matrix.Length * matrix[0].Length;
        _k = 0;
        int[] result = new int[_nbValues];
        while(true){
            if(extractValues(matrix, result, x, xmax, y++, true, true))
                break;
            if(extractValues(matrix, result, y, ymax, xmax--, true, false))
                break;
            if(extractValues(matrix, result, xmax, x, ymax--, false, true))
                break;
            if(extractValues(matrix, result, ymax, y, x++, false, false))
                break;
        }
        return result;
    }
}

// refacto
public class Solution {
    private int _k, _nbValues;
    private int[] _result;

    private void Parkour(int[][] matrix, int val, int valmax, int constVal, bool increase, bool isRow){
        for(int idx = val; increase ? idx <= valmax : idx >= valmax; idx += increase ? 1 : -1)
            _result[_k++] = !isRow ? matrix[idx][constVal] : matrix[constVal][idx];
    }

    public IList<int> SpiralOrder(int[][] matrix) {
        int left = 0, top = 0, right = matrix[0].Length-1, bottom = matrix.Length-1;

        _nbValues = matrix.Length * matrix[0].Length;
        _result = new int[_nbValues];
        _k = 0;
        while(true){
            Parkour(matrix, left, right, top++, true, true);
            Parkour(matrix, top, bottom, right--, true, false);
            if (!(left < right && top < bottom)) break;
            Parkour(matrix, right, left, bottom--, false, true);
            Parkour(matrix, bottom, top, left++, false, false);
            if(left < right && top < bottom) break;
        }
        return _result;
    }
}