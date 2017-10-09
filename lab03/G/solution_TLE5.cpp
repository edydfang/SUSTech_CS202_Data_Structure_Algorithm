#include <iostream>

// Size-balanced tree

using namespace std;

template<typename Type>
struct SBNode{
    int   size;
    Type  key;
    SBNode<Type>* lchild, *rchild;
    SBNode(){}
    SBNode( SBNode<Type>*l, SBNode<Type>*r, int s, Type k ):
        lchild(l), rchild(r), size(s), key(k) {}
};

template<typename Type>
class SBTree{
    private:
        SBNode<Type>* root;
        SBNode<Type>* _null;
        
        void left_rotate ( SBNode<Type>*& root );
        void right_rotate( SBNode<Type>*& root );
        void maintain( SBNode<Type>*& root, bool style );
        void insert( SBNode<Type>*& root, Type key );
        void erase ( SBNode<Type>*& root, Type key );
        void clear ( SBNode<Type>* root );
        void travel( SBNode<Type>* root );
        
    public:
        SBTree ();
        ~SBTree();
        
        void insert( Type key );       //  插入元素 
        void erase ( Type key );       //  删除元素
        Type get_rank( int k  );       //  获得第 k 个元素 
        Type get_min();                //  获得最小元素
        Type get_max();                //  获得最大元素
        void clear();                  //  清空 
        void travel();                 //  遍历 
};

template<typename Type>
Type SBTree<Type>::get_rank( int k ){
    SBNode<Type>* tmp= root;
    for( ;; ){
        if( tmp->lchild->size> k ) tmp= tmp->lchild;
        else if( k> tmp->lchild->size ){
            k-= tmp->lchild->size+ 1;
            tmp= tmp->rchild; }
        else break;}
    return tmp->key;
}

template<typename Type>
void SBTree<Type>::clear( SBNode<Type>* root ){
    if( root!= _null ){
        clear( root->lchild );
        clear( root->rchild );
        delete root; }
}

template<typename Type>
void SBTree<Type>::clear(){
    clear(root); delete _null; }

template<typename Type>
void SBTree<Type>::travel( SBNode<Type>* root ){
    if( root!= _null ){
        travel( root->lchild );
        cout << root->key << "  ";
        travel( root->rchild ); }
}

template<typename Type>
void SBTree<Type>::travel(){
    travel( root ); }

template<typename Type>
Type SBTree<Type>::get_min(){
    if( root== _null ) return Type();
    SBNode<Type>* tmp= root;
    while( tmp->lchild!= _null ) tmp= tmp->lchild;
    return tmp->key;
}

template<typename Type>
Type SBTree<Type>::get_max(){
    if( root== _null ) return Type();
    SBNode<Type>* tmp= root;
    while( tmp->rchild!= _null ) tmp= tmp->rchild;
    return tmp->key;
}

template<typename Type>
void SBTree<Type>::erase( Type key ){
    erase( root, key ); }

template<typename Type>
void SBTree<Type>::erase( SBNode<Type>*& root, Type key ){
    if( root== _null ) return;    root->size--;
    if( root->key== key ){
        SBNode<Type>* tmp;
        if( root->lchild!= _null && root->rchild== _null ){
            tmp= root;  root= tmp->lchild; delete tmp; }
        else if( root->lchild== _null && root->rchild== _null ){
            tmp= root; root= _null; delete tmp; }
        else {
            tmp= root->rchild; 
            while( tmp->lchild!= _null ) tmp= tmp->lchild;
            root->key= tmp->key; erase( root->rchild, tmp->key );}
    }
    else if( key< root->key ) erase( root->lchild, key );
    else erase( root->rchild, key );
}

template<typename Type>
void SBTree<Type>::insert( SBNode<Type>*& root, Type key ){
    if( root== _null ){
     root= new SBNode<Type>( _null, _null, 1, key ); return; }
    root->size++;
    if( key< root->key ) insert( root->lchild, key );
    else                 insert( root->rchild, key );
    maintain( root, key>= root->key );
}

template<typename Type>
void SBTree<Type>::insert( Type key ){
    insert( root, key ); }

template<typename Type>
SBTree<Type>::SBTree(){
    _null= new SBNode<Type>();
    root= _null; 
    root->lchild= root->rchild= _null;
    root->size= 0;
}

template<typename Type>
SBTree<Type>::~SBTree(){
    clear();
}

template<typename Type>
void SBTree<Type>::left_rotate( SBNode<Type>*& root ){
    SBNode<Type>* tmp= root->rchild;
    root->rchild= tmp->lchild;  tmp->lchild= root;
    tmp->size= root->size;
    root->size= root->lchild->size+ root->rchild->size+ 1;
    root= tmp;
}

template<typename Type>
void SBTree<Type>::right_rotate( SBNode<Type>*& root ){
    SBNode<Type>* tmp= root->lchild;
    root->lchild= tmp->rchild;  tmp->rchild= root;
    tmp->size= root->size;
    root->size= root->lchild->size+ root->rchild->size+ 1;
    root= tmp;
}

template<typename Type>
void SBTree<Type>::maintain( SBNode<Type>*& root, bool style ){
    if( root== _null ) return;
    if( !style ){
        if( root->lchild->lchild->size> root->rchild->size )
        right_rotate( root );
        else if( root->lchild->rchild->size> root->rchild->size ){
            left_rotate( root->lchild );
            right_rotate( root );
           }else return;
        }
    else {
        if( root->rchild->rchild->size> root->lchild->size )
        left_rotate( root );
        else if( root->rchild->lchild->size> root->lchild->size ){
            right_rotate( root->rchild );
            left_rotate( root ); 
        }else return;
    }
   maintain(root->lchild, false);  maintain(root->rchild, true);
   maintain(root, false);          maintain(root, true);
}


int main()
{
    int T, i, j, n;
    cin >> T;
    for (i = 0; i < T; i++)
    {
        cin >> n;
        int tmp;
        SBTree<int> binarytree; 
        for (j = 0; j < n; j++)
        {
            cin >> tmp;
            //cout << "test"<<endl;
            binarytree.insert(tmp);
            if (j % 2 == 0)
            {
                cout << binarytree.get_rank(j/2);
                if (j != n - 1 && j != n - 2)
                    cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

