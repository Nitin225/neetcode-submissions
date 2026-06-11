
class MinStack {
public:
    class Node {
    public:
        int val;
        int mini;
        Node* next;

        Node(int v, int m){
            val = v;
            mini = m;
            next = nullptr;
        }
    };

    Node* head = nullptr;

    void push(int val){
        if(head == nullptr){
            head = new Node(val, val);
        } else {
            int currMin = min(val, head->mini);
            Node* newNode = new Node(val, currMin);
            newNode->next = head;
            head = newNode;
        }
    }

    void pop(){
        if(head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top(){
        return head->val;
    }

    int getMin(){
        return head->mini;
    }
};
