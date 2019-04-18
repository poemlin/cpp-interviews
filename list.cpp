



/* 链表结构体 */
struct ListNode{
    int data;
    ListNode* next;
    ListNode(int x):data(x), next(NULL){}
};


/* 单链表反转*/

ListNode* reverse_list(ListNode* head){
    ListNode* pre = nullptr;
    ListNode* cur = head;

    while(cur!=nullptr){
        // 保存当前节点下一个节点
        ListNode* post = cur->next;
        cur->next = pre;
        pre = cur;
        cur = cur->next;
        
    }
    return pre;

}


/* 单链表倒数k个元素 */

ListNode* last_k_1(ListNode* head, int k){
    int index = 0;
    ListNode* tmp = head;
    while(tmp!=nullptr){
        index++;
        tmp = tmp->next;
    }

    if(k>index)
        return;

    int n = 0;
    for(int i=0;i<index-k;i++){
        head = head->next;
    }
    return head;
}

// 需要询问面试官k是否大于链表长度，如果需要判断，则这个方法也需要遍历
ListNode* last_k_2(ListNode* head, int k){
    ListNode* p1, p2=head;
    for(int i=0;i<k;i++){
        p2 = p2->next;
    }
    while(p2!=nullptr){
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}


/*链表中间元素*/

ListNode* middle_list(ListNode* head){
    ListNode* p1 = head;
    ListNode* p2 = head;
    if(head == nullptr)
        return head;
    while(p2->next!=nullptr && p2->next->next!=nullptr){
        p1 = p1->next;
        p2 = p2->next->next;
    }

    return p1;
}


/* 删除无头单链表的一个节点 */
int delete_node(ListNode* pNode){
    pNode->data = pNode->next->data;
    // rm pNode->next
    pNode->next = pNode->next->next;
    delete pNode->next;
    return 0;
}

/* 不相交的有序链表合并 */
ListNode* merge_list(ListNode* head1, ListNode* head2){
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    while(head1 && head2){
        if(head1->data > head2->data){
            cur->next = head2;
            head2 = head2->next;
        }
        else{
            cur->next = head1;
            head1 = head1->next;
        }
    }

    cur->next = head1?head1:head2;
    return cur->next;
}

/* 找到节点的前驱节点 */

ListNode* find_pre(ListNode* head, ListNode* pNode){
    ListNode* pre = head;
    while(pre->next!=pNode){
        pre = pre->next;
    }
    return pre;
}


/* 判断链表是否有环 */

bool is_loop(ListNode* head){
    ListNode* p1 = head;
    ListNode* p2 = head;
    bool is = false;
    while(p2!=nullptr){
        p1 = p1->next;
        p2 = p2->next->next;
        if(p1 == p2){
            is = true;
            break;
        }
    }
    return is;
}

/* 环的长度 */
int length_loop(ListNode* head){
    if(!is_loop(head))
        return 0;
    else{
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p2!=nullptr){
            p1 = p1->next;
            p2 = p2->next;
            if(p1 == p2)
                break;
        }
        ListNode* tmp = p1;
        int length = 0;
        while(p1!=nullptr){
            length++;
            p1 = p1->next;
            if(p1 = tmp)
                break;
        }

        return length;
    }
}


/* 找到入环节点 */
ListNode* exit_loop(ListNode* head){
    int k = length_loop(head);
    return last_k_1(head, k);
}


/* 判断两个链表是否相交，找到相交节点 */

bool is_meet(ListNode* head1, ListNode* head2){
    if(head1==nullptr || head2==nullptr)
        return false;
    while(head1->next!=nullptr){
        head1 = head1->next;
    }
    while(head2->next!=nullptr){
        head2 = head2->next;
    }

    if(head1 == head2)
        return true;
    else
        return false;
}

int length_list(ListNode* head){
    if(head == NULL)
        return 0;
    else{
        index = 0;
        while(head!=NULL){
            index++;
            head = head->next;
        }
        return index;
    }
}
ListNode* exit_meet(ListNode* head1, ListNode* head2){
    if(!is_meet(head1, head2))
        return NULL;
    
    int l1 = length_list(head1);
    int l2 = length_list(head2);

    ListNode* p1 = head1;
    ListNode* p2 = head2;
    if(l1>l2){
        for(int i = 0;i<l1-l2; ++i){
            p1 = p1->next;
        }
        while(p1!=p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
    else{
        for(int i = 0;i<l2-l1; ++i){
            p2 = p2->next;
        }
        while(p1!=p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
    
}


/* 链表直接插入排序 */

ListNode* find_pos(ListNode* head, int x){
    ListNode* pre = NULL;
    ListNode* cur = head;
    while(cur!=nullptr && cur->data<x){
        pre = cur;
        cur = cur->next;

    }
    return pre;
}

ListNode* insert_sort(ListNode* head){
    ListNode* dummy = new ListNode(-1);
    for(ListNode* cur = head; head!=nullptr; cur = cur->next){
        ListNode* pos = find_pos(dummy, cur->data);
        ListNode* tmp = cur->next;
        cur->next = pos->next;
        pos->next = cur;
        cur = tmp;
    }

    return dummy->next;
}

/* 倒序输出链表 */

// 利用三个指针翻转链表，在输出

int reverse_out_1(ListNode* head){
    ListNode pNode = reverse_list(head);
    for(ListNode* cur = pNode; cur!=nullptr; cur = cur->next){
        cout<<cur->data<<' ';
    }
    return 0;
}

// 利用栈

int reverse_out_2(ListNode* head){
    stack<int> nums;
    for(ListNode* cur = head; cur!=nullptr; cur=cur->next){
        nums.push(cur->data);
    }
    for(int i =0; i<nums.size(); i++){
        cout<<nums.top()<<' ';
        nums.pop();
    }
    return 0；
}

// 递归

int reverse_out_3(ListNode* head){
    ListNode* pNode = head;
    if(pNode!=nullptr){
        if(pNode->next!=nullptr){
            reverse_out_3(pNode->next);
        }
    }
    cout<<pNode->data<<' ';
    return 0;
}


/* 有序链表变成平衡二叉树 */
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): data(x), left(NULL), right(NULL){}
};

TreeNode* buildTree(ListNode* begin, ListNode* end);

TreeNode* sortlistToBST(ListNode* head){
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return new TreeNode(head->data);
    
    return buildTree(head, NULL);
}

TreeNode* buildTree(ListNode* begin, ListNode* end){
    if(end == begin)
        return NULL;
    
    ListNode* p1 = head;
    ListNode* p2 = head;
    if(p2->next!=nullptr && p2->next->next!=nullptr){
        p1 = p1->next;
        p2 = p2->next;
    }
    p2 = p1->next;

    TreeNode* root = new TreeNode(p1->data);

    root->left = buildTree(begin, p1);
    root->right = buildTree(p2, end);

    return root;

}