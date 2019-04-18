#include<stack>
#include<queue>

/* getmin栈 */

class MinsStack{
    private:
        stack<int> data;
        stack<int> mindata;
    
    public:
        void Push(int num){
            data.push(num);
            if(mindata.top()>num)
                mindata.push(num);
            else{
                mindata.push(mindata.top());
            }
        }

        void Pop(){
            data.pop();
            mindata.pop();
        }

        int getmin(){
            return mindata.top();
        }
}

/* 两个栈实现队列 */

class Queue{
    private:
        stack<int> push_s;
        stack<int> pop_s;

    public:
        void Push(int num){
            push_s.push(num);
        }

        void Pop(){
            if(pop_s.size()<=0){
                while(!push_s.empty()){
                    int a = push_s.top();
                    push_s.pop();
                    pop_s.push(a);
                }
            }

            if(pop_s.size()==0){
                throw new Exception("The queque is empty");
            }

            pop_s.pop();
        }
}

/* 两个队列实现栈 */

class Stack{
    private：
        queue<int> Q1;
        queue<int> Q2;
    public:
        void Push(int num){
            Q1.push(num);
        }

        void Pop(){
            
            for(int i=0; i<Q1.size()-1;i++){
                Q2.push(Q1.front());
                Q1.pop();
            }
            Q1.pop();
            swap(Q1, Q2);
        }
}

/* 给定push顺序，判断pop顺序是否正确*/

bool PushPop(int* pushnums, int pushn, int* popnums, int popn){
    两个栈模拟，首先找到pop第一个元素
}

/* 翻转一个栈，空间复杂度为O(1)*/
void Reverse_stack(stack<int> s){
    if(!s.empty()){
        int a = s.top();
        s.pop();
        Reverse_stack(s);
        AddonetoBottom(s, a);
    }
}

void AddonetoBottom(stack<int> s, int n){
    if(s.empty())
        s.push(n);
    
    else{
        int a = s.top();
        s.pop();
        AddonetoBottom(s, n);
        s.push(a);
    }
}

/* 栈排序，堆顶最大 */

// 利用一个辅助栈，辅助站最终顺序和s相反。
void sortstack(stack<int> s){
    stack<int> tmp;
    if(s.size()<2)
        return;
    int first = s.top();
    s.pop();
    tmp.push(first);
    while(!s.empty()){
        int top = s.top();
        s.pop();
        if(tmp.top()>n){
            tmp.push(n);
        }
        else{
            int index = 0;
            while(tmp.top()<n){
                index++;
                s.push(tmp.top());
                tmp.pop();
            }
            tmp.push(n);
            for(int i = 0; i<index; ++i){
                tmp.push(s.top());
                s.pop();
            }
        }
    }
    while(!tmp.empty()){
        s.push(tmp.top());
        tmp.pop();
    }
}


/* 数组去除重复，返回长度 */
int removedup(int* A, int n){
    int index = 0;
    for(int i = 0; i< n; i++){
        if(A[index]!=A[i]){
            A[index] = A[i];
            index++;
        }
    }
    return index+1;
}

/* 旋转有序数组找到一个值 */

int search(int* A, int n, int target){
    int left = 0;
    int right = n-1;
    while(left<right){
        int middle = (left+right)/2;
        if(A[middle]==target)
            return middle;
        if(A[left]<A[middle]){
            if(A[left]<=target && A[middle]>target){
                right = middle-1;
            }
            else{
                left = middle+1;
            }
        }
        else{
            if(A[middle]<target && A[right]>target){
                left = middle+1;
            }
            else{
                right = middle-1;
            }
        }
    }
}


/* 两个有序数组合并后的第k大的数 */

//1.排序后合并

//2.双指针加计数器

int finde_k_twoarray_1(int* A, int n, int* B, int m, int k){
    int i,j=0;
    int tmp = 0;
    for(int index = 0; index<k; index++){
        if(A[i]>A[j]){
            tmp = A[i];
            i++;
        }
        else{
            tmp = A[j];
            j++;
        }
    }
}

//3.递归每次坎k/2
int finde_k_twoarray_2(int* A, int m, int *B, int n, int k){
    if(m>n)
        return finde_k_twoarray_2(B, n, A, m, k);
    if(m==0) 
        return B[k-1];
    
    if(k == 1)
        return min(A[0], B[0]);
    
    int ia = min(k/2, m);
    int ib = k-ia;
    if(A[ia-1]<B[ib-1])
        return finde_k_twoarray_2(A+ia, m-ia, B, n, k-ia);
    if(A[ia-1]<B[ib-1])
        return finde_k_twoarray_2(A, m, B, n-ib, k-ib);
    else
        return A[ia-1];
}


/* 无序数组最长的连续子序列*/

int longestCons(vector<int>& nums){
    unordered_map<int, bool> used;
    for(auto i : nums)
        used[i] = false;
    
    int longest = 0;

    for(int i = 0; i<nums.size(); i++){
        if(used[nums[i]])
            continue;
        
        int length = 1;
        used[nums[i]]=true;
        for(int j =nums[i]+1; used.find(j)!=used.end(); j++){
            length++;
            use[j]=true;
        }
        for(int k = nums[i]-1; used.find(k)!=used.end(); k--){
            length++;
            used[k]=true;
        }

        longest = max(longest, length);
    }

    return longest;
}

/* twosum 返回索引 */

//暴力

//哈希（返回索引优先）
int twosum(vector<int> nums, int target){
    unordered_map<int, int> mapping;
    vector<int> result;
    for(int i = 0; i<nums.size(); i++){
        mapping[nums[i]]=i;
    }
    for(int j = 0; j<nums.size(); j++){
        int gap = target-nums[j];
        if(mapping.find(gap)!=mapping.end()){
            result.push_back(j);
            result.push_back(mapping[gap]);
            break;
        }
    }
    return result;
}

//双指针左右夹逼（返回值优先）

/* threesum 返回所有值对*/

vector<vector<int>> threesum(vector<int> nums, int target){
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    auto begin = nums.begin();
    auto end = nums.end();
    for(auto a = begin; a<prev(end, 2); a++){
        auto b = next(a);
        auto c = prev(end);
        while(b<c){
            int gap = target-*a;
            if(*b + *c < gap)
                b++;
            if(*b + *c >gap)
                --c;
            else{
                result.push_back({*a, *b, *c});
                b++;
                c--;
            }
        }
    }

    result.earse(unique(result.begin(), result.end()), result.end());
    return result;
}


/* 下一个排列 */
（2，3，6，5，4，1）
找到3和4，交换，（2， 4，6，5，3，1），逆序（2， 4，1， 3，5，6)
void nextPer(vector<int> nums){

    // 从后往前找第一个不是递增的位置，上面是3，位置是1；
    for(int i = nums.size() - 1;i>0;i--){
        if(nums[i]>nums[i-1])
            break;
    }
    // 如果都是递增的，则返回正序递增的
    if(i==0){
        sort(nums.begin(), nums.end());
        return;
    }
    // 3的位置是i-1
    int tmp = nums[i-1];
    int min = INT_MAX;
    int minindex = i;
    // 找到位置后面比3大的最小值4
    for(int j = i+1; j<nums.size(); j++){
        if(nums[j]>tmp && nums[j]<min){
            minindex = j;
            min = nums[j];
        }
    }
    // 交换3和4，然后把3后所有逆序
    swap(nums[i-1], nums[minindex]);
    sort(nums.begin()+i, nums.end());
}

/* 第k个排列 */

利用上面的方法从第一个开始求k-1次下一个排列

/* 数组中单独出现的数字， 数组找只有一个数字出现了1次其它都是两次 0(N) 0(1) */

int onealltwo(vector<int> nums){
    int res = 0;
    for(auto i : nums)
        res ^= i;
    return res;
}










