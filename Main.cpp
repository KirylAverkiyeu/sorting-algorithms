#include "Header.h"
int len = 0;
int range = 0;
int main()
{
        srand(time(NULL));
        cout << "Array size: ";
        cin >> len;
        int* arr = new int[len];
        for(int i = 0; i < len; i++)
        {
                arr[i] = rand()%501;
                if(arr[i]>range)
                {
                        range=arr[i];
                }
        }
        bubbleSort(arr);
        countingSort(arr);
        mergeSort(arr, 0, len);
        quickSort(arr, 0, len);
        return 0;
}

void bubbleSort(int* arr)
{
        for(int i = 1; i < len; ++i)
        {
                for(int j = 0; j < len-i; j++)
                {
                        if(arr[j] > arr[j+1])
                        {
                                int tmp = arr[j];
                                arr[j] = arr[j+1];
                                arr[j+1] = tmp;
                        }
                }
        }
}

void countingSort(int* arr)
{
        int C[range] = {0};
        int B[len];
        for(int j = 0; j < len; j++)
        {
                C[arr[j]]++;
        }
        for(int i = 0; i < range; i++)
        {
                C[i] += C[i-1];
        }
        for(int j = len-1; j >= 0; j--)
        {
                B[C[arr[j]]] = arr[j];
                C[arr[j]] = C[arr[j]]-1;
        }
}

void merge(int* arr,int p,int q,int r) {
        int n1 = q - p + 1;
        int n2 = r - q;
        int* L; int* R;
        L = new int[n1 + 1];
        R = new int[n2 + 1];
        for(int i = 1; i <= n1; i++) {
                L[i - 1] = arr[p + i - 1];
        }
        for(int j = 1; j <= n2; j++) {
                R[j - 1] = arr[q + j];
        }
        for(int i = 0,j = 0,k = p; k <= r; k++) {
                if(i < n1 && j < n2) {
                        if(L[i] <= R[j]) {
                                arr[k] = L[i];
                                i++;
                        } else {
                                arr[k] = R[j];
                                j++;
                        }
                } else if(i < n1) {
                        arr[k] = L[i];
                        i++;
                } else {
                        arr[k] = R[j];
                        j++;
                }
        }
        delete [] L; delete [] R;
}
void mergeSort(int* arr,int p,int r)
{
        int q;
        if(p<r) {
                q=(p+r)/2;
                mergeSort(arr,p,q);
                mergeSort(arr,q+1,r);
                merge(arr,p,q,r);
        }
}

void quickSort(int* arr, int left, int right)
{
        int i = left, j = right;
        int tmp;
        int pivot = arr[(left + right) / 2];
        while (i <= j)
        {
                while (arr[i] < pivot)
                        i++;
                while (arr[j] > pivot)
                        j--;
                if (i <= j)
                {
                        tmp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = tmp;
                        i++;
                        j--;
                }
        };
        if (left < j)
                quickSort(arr, left, j);
        if (i < right)
                quickSort(arr, i, right);

}
