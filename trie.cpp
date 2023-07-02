struct Node {
    
    Node * links[2];
    int val;
 
};
 
Node * naya() {
    Node * temp = new Node();
    temp -> val = 0;
    temp -> links[0] = NULL;
    temp -> links[1] = NULL;
    return temp;
}
 
 
template <typename T>
class Trie {
    private : Node * root = naya();
    public :
        int BIT;
        Trie(int sz) {
            root = naya();
            BIT = sz;
        }
        
        void insert(T num) {
            Node * node = root;
            for(T i = BIT; i >= 0; i --) {
                T bit = (num >> i) & 1;
                node -> val ++;
                if(node -> links[bit] == NULL) {
                    node -> links[bit] = naya();
                }
                node = node -> links[bit];
            }
            node -> val ++;
        }
        
        void remove(T num) {
            Node * node = root;
            for(T i = BIT; i >= 0; i --) {
                node -> val --;
                T bit = (num >> i) & 1;
                node = node -> links[bit];
            }
            node -> val --;
        }
        
        T maxxor(int num) {
            T res = 0;
            Node * node = root;
            for(T i = BIT; i >= 0; i --) {
                T bit = (num >> i) & 1;
                if(node -> links[!bit] && node -> links[!bit] -> val) {
                    res |= (static_cast<T>(1) << i);
                    node = node -> links[!bit];
                }
                else if(node -> links[bit] && node -> links[bit] -> val) node = node -> links[bit];
            }
            return res;
        }
        
        T minxor(T num) {
            T res = 0;
            Node * node = root;
            for(T i = BIT; i >= 0; i --) {
                T bit = (num >> i) & 1;
                if(node -> links[bit] && node -> links[bit] -> val) {
                    node = node -> links[bit];
                }
                else if(node -> links[!bit] && node -> links[!bit] -> val) {
                    res |= (static_cast<T>(1) << i);
                    node = node -> links[!bit];
                }
            }
            return res;
        }
                    
};