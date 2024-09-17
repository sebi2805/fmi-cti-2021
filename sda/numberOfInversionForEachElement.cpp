map<int, int> m;
long long merge(int *a, int *b, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    long long count = 0;

    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }

        else
        {
            // cout << a[i] << " " << a[j] << " " << m[a[i]] << endl;
            m[a[i]]++;
            b[k] = a[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        cout << mid << " " << a[i] << " " << i << endl;
        b[k] = a[i];
        k++;
        m[a[i]] = mid - i + 1;
        i++;
    }

    while (j <= right)
    {
        b[k] = a[j];
        k++;
        j++;
    }

    for (i = left; i <= right; i++)
    {
        a[i] = b[i];
    }

    return count;
}

void mergeSort(int *a, int *b, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a, b, left, mid);
        mergeSort(a, b, mid + 1, right);
        merge(a, b, left, mid, right);
    }
}

int main()
{
    int a[] = {3, 2, 8, 1, 4, 7, 10};
    int n = sizeof(a) / sizeof(a[0]);

    int *b = new int[n];

    mergeSort(a, b, 0, n - 1);
    std::cout << "Inversion counts for each element:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << ": " << m[a[i]] << std::endl;
    }

    delete[] b;
    return 0;
}
