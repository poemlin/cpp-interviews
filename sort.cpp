
/* 合并两个有序数组 */

void merge(vector<int> nums1, vector<int> nums2){
    int m = nums1.size();
    int n = nums2.size();
    int i1 = m-1;
    int i2 = n-1;
    int icur = n+m-1;

    while(i1>=0 && i2>=0){
        nums1[icur--] = nums[i1]>nums[i2]?nums[i1--]:nums[i2--];
    }
    // 短的还剩
    while(i2>=0){
        num[icur--] = nums[i2--];
    }
}



/* 直接插入排序
每一次将一个新的元素插入到已经前面排好序的数组中，直到数组有序。
数组越接近有序效率越高。
稳定 */

void insert_sort(vector<int> nums){
    for(int i = 0; i<nums.size(); i++)
        for(int j = i; j>0; j--){
            if(nums[j]<nums[j-1])
                swap(num[j], nums[j-1]);
            else
                break;
        }
}


/* 希尔排序
缩小增量的直接插入排序，相当于不断增小的增量划分子序列，对原数据
进行预排序，使数据基本有序，最后再进行一次直接插入排序 */
void shellSort(int *ary,int len)
{
    int i,j;
    int increment = len;//增量
    int key;
    while(increment > 1)//最后在增量为1并且是执行了情况下停止。
    {
        increment = increment/3 + 1;//根据公式

        for (i=increment;i<len;i++)//从[0]开始，对相距增量步长的元素集合进行修改。
        {
            key = ary[i];
            //以下和直接插入排序类似。
            j=i-increment;
            while(j >= 0)
            {
                if (key < ary[j] )
                {
                    int temp = ary[j];
                    ary[j] = key;
                    ary[j+increment] = temp;
                }
                j=j-increment;
            }
        }
    }
}


/* 冒泡排序 */
void bubble_sort(vector<int> nums){
    n = nums.size();
    // 排序n个数，一般需要n-1躺冒泡
    for(int i = 0; i<n-1; i++)
        // 每一躺排序数目都是递减
        for(int j = 0; j<n-1-i; j++){
            if(nums[j]>nums[j+1])
                swap(nums[j], nums[j+1]);
        }
}


/* 堆排序 */

//对指定元素进行调整，满足大顶性质：父亲>左右

void adjust(vector<int> nums, int len, int index){
    int left = 2*index+1;
    int rigth = 2*index+2;
    maxindex = index;
    if(left<len && nums[left]>nums[maxindex])
        maxindex = left;
    if(right<len && nums[right]>nums[maxindex])
        maxindex = right;
    if(maxindex != index){
        swap(nums[maxindex], nums[index]);
        // 对这个与父节点交换的位置
        adjust(nums, len, maxindex);
    }
}

void heap_sort(vector<int> nums, int n){
    // 对每一个非叶子节点进行调整，形成一个大顶堆
    for(int i = n/2-1; i>=0; i--){
        adjust(nums, n, i);
    }

    for(int j = n-1; j>0; j--){
        // 把堆顶和最后一个元素互换
        swap(nums[0], nums[j]);
        // 只需对堆顶元素进行调整
        adjust(nums, j, 0);
    }
}


/* 数组归并排序 */
void merge_sort_array(int* A, int l, int r){
    if(l>=r)
        return;
    int mid = (l+r)/2;
    merge_sort_array(A, l, mid);
    merge_sort_array(A, mid+1, r);

    merge(A, l, mid, r);
}
void merge(int* A, int l, int m, int r){
    int[] B = new int[A.size()];
    int mid = m+1
    int k = 0;
    while(l<=m && mid<=r){
        if(A[l]<A[mid])
            B[k++] = A[l++];
        else
            B[k++] = A[mid++]
    }
}


/* 快速排序 */
void quick_sort(int* A, int low, int high){
    if(low>=high)
        return;
    int q = partition(A, low, high);
    quick_sort(A, low, q-1);
    quick_sort(A, q+1, high);
}

int partition(int* A, int low, int high){
    int tmp = A[high];
    int pre = low-1;
    for(int i = 0; i<A.size(); i++){
        if(A[i]<tmp){
            pre++;
            swap(A[i], A[pre]);
        }
    }
    swap(A[high], A[pre+1]);
    return pre+1;
}

/* 桶排序 */
int[] countingSort(int[] A, int n) {
    //找数组中的最大值和最小值，确定桶的个数
    int max=A[0];
    int min=A[0];
    for(int i=0;i<n;i++){
        if(A[i]>max)
            max=A[i];
        if(A[i]<min)
            min=A[i];
    }
    //定义桶数组B并初始化
    int[] B= new int[max-min+1];
    for(int i=0;i<max-min+1;i++)
        B[i]=0;
    //把数组A的元素装到对应桶里
    for(int i=0;i<n;i++){
        B[A[i]-min]++;
    }
    //把所有桶倒出来
    for(int i=0,j=0;j<max-min+1;j++){
        //倒桶j
        for(int k=B[j];k>0;k--){
            A[i++]=j+min;
        }
    }
    return A;
}
