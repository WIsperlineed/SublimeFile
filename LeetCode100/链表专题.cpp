



//哈希表存储

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_map<ListNode*,bool>tab;
        ListNode* p=head;
        int step=0;
        while(p){
            if(!tab[p]){//未出现
                tab[p]=true; 
            }else{//出现了重复元素
                return p;
            }
            p=p->next;
            step++;
        }
        
        
        return 0;
    }
};


//快慢指针
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*quick=head;
        while(quick && quick->next){
            quick=quick->next->next;//走两步
            slow=slow->next;//走一步
            if(quick==slow){
                break;
            }
        }
        if(quick && quick->next){               //有环
            while(head!=slow){
                head=head->next;
                slow=slow->next;
            }
            return head;
        }
        return NULL;
    }
};




class Solution {
public:
    void reorderList(ListNode* head) {
        unordered_map<ListNode*,ListNode*>hash;//extra space O(n)
        
        ListNode* p1=head;
        ListNode* p2=head;
        while(p2->next){//
            hash[p2->next]=p2;//build reverse hash
            p2=p2->next;
        }
        bool s=1;
        while(p1!=p2){
            if(s){//顺序
                ListNode* tmp=p1->next;
                p1->next=p2;
                p1=tmp;
            }else{//逆序
                ListNode* tmp=hash[p2];
                p2->next=p1;
                p2=tmp;
            }
            s=!s;
        }
        p1->next=0;
        
    }
};


//快速版本
class Solution {
public:
        void reorderList(ListNode* head) {
            if (!head) return;
            vector<ListNode*> vec;//使用了vec存储逆序，比unordered_map要快好
            ListNode* cur = head;

            while (cur) {
                vec.push_back(cur);
                cur = cur->next;
            }

            int left = 0;
            int right = vec.size() - 1;
            while (left < right) {
                vec[left]->next = vec[right];
                vec[right--]->next = vec[++left];
            }
            vec[left]->next = nullptr;
        }
};


优化：使用vector，下表索引，小于指针操作和哈希表时空开销




lc 19. 删除链表的倒数第 N 个结点


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(!head||!head->next)return nullptr;//特殊判断
            ListNode* p=head,* l=head;

            while(n--){
                l=l->next;
            }
            if(!l)return head->next;//关键点：前进n步后为空指针，返回head->next
        
            while(l->next){
                p=p->next;
                l=l->next;
            }
        
            ListNode* s=p->next;
            p->next=s->next;
            return head;
    }
};





21. 合并两个有序链表


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* res = l1->val < l2->val ? l1 : l2;
        res->next = mergeTwoLists(res->next, l1->val >= l2->val ? l1 : l2);
        return res;
    }
};


Fira Code





