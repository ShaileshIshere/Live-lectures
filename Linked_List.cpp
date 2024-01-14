#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int dataue) : data(dataue), next(nullptr), prev(nullptr) {}
};

class solution{
public:
    Node* find_starting_point_of_loop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while(fast != nullptr) {
            fast = fast->next;
            if(fast != nullptr) {
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow) break;
        } 
        if(fast == nullptr) return nullptr;

        // here we can say that slow and fast are currently at the same position
        slow = head;

        // now we've to move slow and fast of 1 step
        while(fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};

int getLength(Node* head) {
        Node* temp = head;
        int len = 0;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }

Node* reverseKGroup(Node* head, int k) {
        if(head == NULL ) {
            return head;
        }
        if(head->next == NULL) {
            return head;
        }

        //1 case main solve karunga
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = curr->next;
        int pos = 1;
        
        int len = getLength(head);
        if(len < k) {
            return head;
        }

        while(pos <= k ){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            pos++;
        }

        Node* recursionKaAns = NULL;
        if(nextNode != NULL) {
            recursionKaAns = reverseKGroup(nextNode, k);
            head->next = recursionKaAns;
        }

        return prev;
}

Node* deleteDuplicates(Node* head) {
        if(head == nullptr || head->next == nullptr) 
            return head;

        Node* temp = head;
        while(temp != nullptr) {
            if(temp->next != nullptr && temp->data == (temp->next)->data) {
                 //remove
                Node* nextNode = temp->next;
                temp->next = nextNode->next;
                nextNode->next = nullptr;
                delete nextNode;
            }
            else {
                temp = temp->next;
            }
        }
        return head;
    }

void insert_at_head(Node *&head, Node *&tail, int data) {
    if(head == NULL) {
        Node *new_Node = new Node(data);
        head = new_Node;
        tail = new_Node;
    }
    else {
        Node *new_Node = new Node(data);
        new_Node->next = head;
        head->prev = new_Node;
        head = new_Node;
    }
}

void print_LL(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}

void connect_nodes(Node *head, Node *tail) {
    cout << "the loop created here" << endl;
    if (head != nullptr && tail != nullptr) {
        Node* temp = head;
        for(int i = 1; i < 4; i++){
            temp = temp->next;
            if (temp == nullptr) {
                return;
            }
        }
        tail->next = temp;
    }    
}

void remove_loop(Node* head) {
    cout << "the loop breaks here" << endl;
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr) {
        fast = fast->next;
        if(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow) break;
    }

    // here we can say that slow and fast are currently at the same position
    slow = head;

    // now we've to move slow and fast of 1 step
    while(fast != slow) {
    slow = slow->next;
    fast = fast->next;
    }
    Node* starting_point = fast;
    Node* temp = fast;
    while(temp->next != starting_point) {
        temp = temp->next;
    }
    temp->next = nullptr;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while(curr != nullptr) {
        Node* next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    return prev;
}

void add_one(Node* &head) {
    head = reverse(head);

    int carry = 1;
    Node* temp = head;
    while(temp->next != nullptr) {
        int total_sum = temp->data + carry;
        int digit = total_sum % 10;
        carry = total_sum / 10;
        temp->data = digit;
        temp = temp->next;
        if(carry == 0) break;
    }
    if(carry != 0) {
        int total_sum = temp->data + carry;
        int digit = total_sum % 10;
        carry = total_sum / 10;
        temp->data = digit;
        if(carry != 0) {
            Node* new_node = new Node(carry);
            temp->next = new_node;
        }
    }

    head = reverse(head);
}

int main() {

    // basic initialization of linked list
    Node* head = nullptr;
    Node* tail = nullptr;
    // for (int i = 9; i > 0; i--) {
    //     insert_at_head(head, tail, i);
    // }
    // print_LL(head);

    // reverse Nodes in K group
    // Node* ans = reverseKGroup(head, 1);
    // print_LL(ans);

    // add (1) to a linked list
    // insert_at_head(head, tail, 9);
    // insert_at_head(head, tail, 9);
    // insert_at_head(head, tail, 1);
    // print_LL(head);
    // add_one(head);
    // print_LL(head);

    // find the starting point of loop
    // connect_nodes(head, tail);
    // solution sol;
    // Node* ans = sol.find_starting_point_of_loop(head);
    // if (ans != nullptr) {
    //     cout << "Loop detected at: " << ans->data << endl;
    // }
    // else {
    //     cout << "No loop detected" << endl;
    // }
    
    // remove data of the existing loop
    // remove_loop(head);
    // print_LL(head);

    // remove duplicates
    insert_at_head(head, tail, 4);
    insert_at_head(head, tail, 3);
    insert_at_head(head, tail, 3);
    insert_at_head(head, tail, 2);
    insert_at_head(head, tail, 2);
    insert_at_head(head, tail, 1);
    print_LL(head);
    // Node* ans = deleteDuplicates(head);
    // print_LL(head);

    return 0;
}