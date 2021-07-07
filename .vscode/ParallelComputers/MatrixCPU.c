/*
 * @Description: 矩阵乘法CPU的实现 Amxk * Bkxn = Cmxn
 * @Author: aLittleMango
 * @Date: 2021-07-02 14:49:30
 * @LastEditTime: 2021-07-02 15:36:33
 * @FilePath: \VSCode-C\.vscode\ParallelComputers\MatrixCPU.c
 */

#include <stdio.h>
/**
 * @description: 计算次数为m*n*k;时间复杂度o(n^3)
 * @param {*}
 * @return {*}
 */
void matrixMUlCpu(float* fpMatrixA, float*fpMatrixB, float*fpMatrixC,
int m, int n, int k)
{
    float sum = 0.0f;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < k; l++)
            {
                sum += fpMatrixA[i * k + l] * fpMatrixB[l * n + j];
            }
            fpMatrixC[i * n + j] = sum;
            sum = 0.0f;
        }
    }
}

/**
 * @description: 使用global memory kernel part  
 * @param {*}
 * @return {*}
 */

__global__ void matixMuxGlobalKernel(float* pfMatrixA, float* pfMatrixB, float* pfMatrixC,
int m, int n, int k)
{
    int nRow = blockIdx.y * blockDim.y + threadIdx.y;
    int nCol = blockIdx.x * blockDim.x + threadIdx.x;
    float fCVal = 0.0f;
    //矩阵A中读一行向量 矩阵B中读一列向量。
    //对两个向量做点积运算，即单层k次循环的乘累加，将结果写入矩阵C
    for (int i = 0; i < k; i++)
    {
        fCVal += pfMatrixA[nRow * k + i] * pfMatrixB[i * n + nCol];
    }

    pfMatrixC[nRow * n + nCol] = fCVal;
}