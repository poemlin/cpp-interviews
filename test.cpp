
/* 链表结构体 */
struct ListNode{
    int data;
    ListNode* next;
    ListNode(int x): data(x), next(NULL){}
};


/* 单链表翻转 */

ListNode* reverse_list(ListNode* head){
    ListNode* cur = head;
    ListNode* pre = nullptr;
    while(cur!=nullptr){
        // 记录下一个节点
        ListNode* post = cur->next;
        // 反转
        cur->next = pre;
        pre = cur;
        cur = post;
    }
    return pre;
}

/* 倒数k个元素 */

ListNode* last_k_1(ListNode* head, int k){
    ListNode* pNode = head;
    int count = 0;
    while(pNode!=nullptr){
        count++;
        pNode = pNode->next;
    }
    ListNode* ptarget = head;
    for(int nm = count-k+1; nm>0;nm--){
        ptarget =  ptarget->next;
    }
    return ptarget;
}

ListNode* last_k_2(ListNode* head, int k){
    ListNode* p1, p2 = head;
    for(;k>0;k--)
        p2 = p2->next;
    while(p2!=nullptr){
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}


ListNode* middle_list(ListNode* head){
    ListNode* p1 = head;
    ListNode* p2 = head;
    if(head == nullptr)
        return head;
    while(p2->next != nullptr && p2->next->next!=nullptr){
        p1 = p1->next;
        p2 = p2->next->next;
    }
    return p1;
}

int delete_list(ListNode* pNode){
    pNode->data = pNode->next->data;
    // 删除下一个节点
    ListNode* pnext = pNode->next;
    pNode->next = pnext->next;
    delete pnext;
    return 0;
}

ListNode* merge_list(ListNode* head1, ListNode* head2){
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    while(head1 && head2){
        if(head1->data < head2->data){
        cur->next = head1;
        head1 = hea1->next;
    }
        else{
            cur->next = head2;
            head2 = head2->next;
        }
        cur = cur->next;
    }
    cur->next = head1 ? head1 : head2
    return dummy->next;

}

ListNode* pre_node(ListNode* head, ListNode* pNode){
    ListNode* p = head;
    while(p->next!=pNode){
        p = p->next;
    }
    return p;
}

bool is_loop(ListNode* head){
    bool is = false;
    ListNode* p1,p2 = head;
    while(p2->next != nullptr && p2->next->next != nullptr){
        p1 = p1->next;
        p2 = p2->next->next;
        if(p1 == p2){
            is = true;
            break;
        }
    }
    return is;
}

int length_loop(ListNode* head){
    ListNode*  p1, p2 = head;
    while(p2->next!=nullptr && p2->next->next!=nullptr){
        p1 = p1->next;
        p2->next->next;
        if(p1 == p2){
            break;
        }
    }

    ListNode* pNode = p1;
    int count = 1;
    while(p1->next!=pNode){
        p1 = p1->next;
        count++;
    }
    return count;
}

ListNode* in_loop(ListNode* head){
    if(is_loop(head){
        int k = length_loop(head);
        return last_k_2(head, k);
    }
    else{
        return nullptr;
    }
}

ListNode* last_node(ListNode* head){
    ListNode* pNode = head;
    while(pNode->next!=nullptr){
        pNode = pNode->next;
    }
    return pNode;
}
bool is_meet(ListNode* head1, ListNode* head2){
    if(last_node(head1)==last_node(head2)){
        return true;
    }
    else{
        return false;
    }
}


ListNode* insert_list_sort(ListNode* head){
    ListNode* dummy = new ListNode(-1);
    for(ListNode* cur = head; cur!=nullptr; cur = cur->next){
        ListNode* pos = find_pos(dummy, cur->data);
        cur->next = pos->next;
        pos->next = cur;
    }
}

ListNode* find_pos(ListNode* head, int x){
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while(cur!=nullptr && cur->data < x){
        pre = cur;
        cur = cur->next;
    }
    return pre;
}



// 合并两个有序数组

void merge(vector<int> nums1, vector<int> nums2){
    
    int m = nums1.size();
    int n = nums2.size();
    // 记录两个数组的末尾指针
    int l1 = m-1;
    int l2 = n-1;

    // 记录插入位置的末尾指针，从任意一个数组这个位置开始插入
    int cur = l1 + l2 - 1;

    while(l1>=0 && l2>=0){
        nums1[cur] = nums1[l1]>nums2[l2] ? nums1[l1--] : nums2[l2--];
        cur--;
    }

    // 被插入数组没空，则无需操作。插入数组为空 则把剩余插入

    while(l2>=0){
        nums1[cur--] = nums[l2--];
    }
}


// 直接插入排序
// 遍历每一个元素，将每一个元素插入到前面已经有序的序列中
// 数组越有序 效率 越高
// 从末尾插入，不动则跳出，动则继续
void insert_sort(vector<int> nums){
    // 遍历每一个元素
    for(int i = 0; i<nums.size(); i++)
        for(int j = i; j>0; j--){
            // 小雨下一个位置则交换
            if(nums[j]<nums[j-1]){
                swap(nums[j], nums[j-1])
            }
            // 不需要交换，则已经有序
            else
                break;
        }
}


// 冒泡排序
// n个数一般要进行n-1次冒泡排序，

void bubble_sort(vector<int> nums){
    // n-1躺
    for(int i = 0; i<nums.size()-1; i++){
        // 每趟遍历所有元素，并且元素数量递减
        for(int j = 0; j<n-1-i; j++){
            if(nums[j]>nums[j+1])
                swap(nums[j], nums[j+1])
    }
}


//堆排序
// 调整某个元素，使其满足父亲》左右
void adjust(vector<int> nums, int len, int index){
    int left = 2*index+1;
    int right = 2*index+2;
    int maxindex = index;
    // 找到最新的大元素
    if(left<len && nums[left]>nums[maxindex])
        maxindex = left;
    if(right<len && nums[right]>nums[maxindex])
        maxindex = right;
    
    if(maxindex != index){
        swap(nums[maxindex], nums[index]);
        // 改变的位置（小元素）重新递归调整
        adjust(nums, len, maxindex);
    }
}

void heap_sort(vector<int> nums){
    int n = nums.size();
    // 对每一个非叶子节点调整，最终形成一个堆
    // 初始jiandui
    for(int i = n/2-1; i>=0; i--){
        adjust(nums, n, i);
    }

    for(int i = n-1; i>0; i--){
        swap(nums[0], nums[i]);
        adjust(nums, i, 0);
    }
}

// 数组归并排序

void merge_sort(vector<int> nums, int l, int r){
    int m = (l+r)/2;
    merge_sort(nums, l, m);
    merge_sort(nums, m+1, r);
    merge(nums, l, m, r);
}

void merge(vector<int> nums, int l, int m, int r){
    
}

// 快速排序

void quick_sort(int*  A, int low, int high){
    // 找partition
    int p = partition(A, low, high);
    quick_sort(A, low, p);
    quick_sort(A, p+1, high);
}

int partition(int *A, int low, int high){
    // 朴素快排，最高位置作为分水岭
    int temp = A[high];
    int pre = low-1;
    for(int i = 0; i<A.size(); i++){
        if(A[i]<A[temp]){
            pre++;
            swap(A[i], A[pre]);
        }
    }
    swap(A[high], A[pre+1]);
    return pre+1;
}

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): data(x), left(nullptr), right(nullptr){}
};

// 树的三种递归遍历

void pre(TreeNode* root){
    if(root == nullptr)
        return;
    
    cout<<root->data;
    pre(root->left);
    pre(root->right);
}

void in()

void post()


// 栈 先序

vector<int> pre(TreeNode* root){
    vector<int> result;
    stack<TreeNode*> s;
    if(root!=nullptr){
        s.push(root);
    }

    while(!s.empty()){
        TreeNode* p = s.top();
        s.pop();
        result.push_back(p->data);
        if(p->right!=nullptr)
            s.push(p->right);
        if(p->left!=nullptr)
            s.push(p->left);
    }

    return result;
}


// 栈 中序
 vector<int> in(TreeNode* root){
     vector<int> result;
     stack<TreeNode*> s;

     TreeNode* p = root;
     if(!s.empty() || p!=nullptr){
         if(p!=nullptr){
             s.push(p);
             p = p->left;
         }

         else{
             p = s.top();
             s.pop();
             result.push_back(p->data);
             p = p->right;
         }
     }

     return result;
 }


// 层序遍历
// 使用队列

vector<vector<int>> level(TreeNode* root){
    vector<vector<int>> result;
    queue<TreeNode*> q;
    if(root!=nullptr){
        q.push(root)
    }
    while(!q.empty()){
        vector<int> thislevel;
        for(int i=0; i<q.size(); i++){
            TreeNode t = q.front();
            q.pop();
            thislevel.push_back(t->data);
            if(t->left!=nullptr)
                q.push(t->left);
            if(t->right!=nullptr)
                q.push(t->right)
        }
        result.push_back(thislevel)

    }
    return result;
}

TreeNode* invert_tree(TreeNode* root){
    TreeNode* tmp = root->left;

    root->left = invert_tree(root->right);
    root->right = invert_tree(tmp);

    return root;
}

int Tree_length_max(TreeNode* root){
    if(root == nullptr)
        return 0;
    
    int left_len = Tree_length_max(root->left);
    int right_len = Tree_length_max(root->right);

    return 1 + (left_len>right_len?left_len:right_len);
}



struct ListNode{
    int data;
    ListNode* next;
    ListNode(int x): data(x), next(NULL){}
};


ListNode* reverse_list(ListNode* head){
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while(cur!=nullptr){
        ListNode* nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    return pre;
}


ListNode* middle_list(ListNode* head){
    ListNode* p1,p2 = head;
    while(p1->next!=nullptr && p1->next-next!=nullptr){
        p2 = p2->next;
        p1 = p1->next->next;
    }
    return p1;
}


ListNode* merge_list(ListNode* head1, ListNode* head2){
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    while(head1!=nullptr && head2!=nullptr){
        if(head1->data < head2->data){
            cur->next = head1;
            head1 = head1->next;
        }
        else{
            cur->next = head2;
        }
        cur = cur->next;
    }
    return dummy->next;
}


bool is_loop(ListNode* head){
    ListNode* p1, p2 = head;

}


struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): data(x), left(nullptr), right(nullptr){}
};

void pre(TreeNode* root){
    
}


void insert_sort(vector<int> nums){
    for(int i = 0; i<nums.size(); i++){
        for(int j = i; j>0; j--){
            if(nums[j]<nums[j-1])
                swap(nums[j], nums[j-1]);
            else
                break;
        }
    }
}
