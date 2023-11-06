__kernel void Dilatation(__global int* regionpointer, __global int(*_matrix)[100], __global int(*_transformed)[100])
{
    int _n = 100;
    int _m = 100;
    int WHITE = 1;
    int BLACK = 0;
    int regionsize=(*regionpointer);
    printf("ssssss");
    

    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _m; j++) {

            if (_matrix[i][j] == BLACK) {

                for (int k = i - regionsize / 2; k < i + regionsize / 2; k++)
                {
                    for (int l = j - regionsize / 2; l < j + regionsize / 2; l++)
                    {
                        if (k >= 0 && l >= 0 && k + regionsize / 2 < _n && l + regionsize / 2 < _m)
                            _transformed[k][l] = BLACK;
                    }
                }

            }
        }
    }
}






