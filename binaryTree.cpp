#include <bits/stdc++.h>
using namespace std;
template <class T>
struct node
{
    T info;
    node<T> *l;
    node<T> *r;
    node(T inf, node<T> *leftptr = nullptr, node<T> *rightptr = nullptr)
        : info(inf), l(leftptr), r(rightptr)
    {
    }
    ~node()
    {
        delete l;
        delete r;
    }
};
template <class T>
void inorderTraverse_Rec(node<T> *t)
{
    if (!t)
        return;
    inorderTraverse_Rec(t->l);
    cout << t->info;
    inorderTraverse_Rec(t->r);
}
template <class T>
void preorderTraverse_Rec(node<T> *t)
{
    if (!t)
        return;
    cout << t->info;
    preorderTraverse_Rec(t->l);
    preorderTraverse_Rec(t->r);
}
template <class T>
void postorderTraverse_Rec(node<T> *t)
{
    if (!t)
        return;
    postorderTraverse_Rec(t->l);
    postorderTraverse_Rec(t->r);
    cout << t->info;
}

template <class T>
void preorderTraverse_It(node<T> *root)
{
    if (root == NULL)
        return;
    stack<node<T> *> nodeStack;
    nodeStack.push(root);
    while (nodeStack.empty() == false)
    {
        struct node<T> *node = nodeStack.top();
        cout << node->info << " ";
        nodeStack.pop();
        if (node->r)
            nodeStack.push(node->r);
        if (node->l)
            nodeStack.push(node->l);
    }
}

template <class T>
void inorderTraverse_It(node<T> *root)
{
    if (root == NULL)
        return;
    stack<node<T> *> nodeStack;
    while (1)
    {
        if (root)
        {
            nodeStack.push(root);
            root = root->l;
        }

        else if (nodeStack.empty())
            return;

        else
        {
            root = nodeStack.top();
            cout << root->info << " ";
            nodeStack.pop();
            root = root->r;
        }
    }
}

template <class T>
void postorderTraverse_It(node<T> *root)
{
    stack<node<T> *> nodeStack;
    stack<T> out;
    nodeStack.push(root);
    node<T> *curr;
    while (nodeStack.empty() == false)
    {
        curr = nodeStack.top();
        out.push(curr->info);
        nodeStack.pop();
        if (curr->l)
            nodeStack.push(curr->l);
        if (curr->r)
            nodeStack.push(curr->r);
    }

    while (out.empty() == false)
    {
        cout << out.top() << " ";
        out.pop();
    }
}

template <class T>
int height_Rec(node<T> *root)
{
    if (root == NULL)
        return 0;
    else if (root->l != NULL || root->r != NULL)
    {
        return 1 + max(height_Rec(root->l), height_Rec(root->r));
    }
}

template <class T>
void levelOrderTraversal(node<T> *root)
{

    queue<node<T> *> q;
    q.push(root);
    node<T> *curr = NULL;
    while (q.empty() == false)
    {
        curr = q.front();
        q.pop();
        cout << curr->info << " ";
        if (curr->l)
            q.push(curr->l);
        if (curr->r)
            q.push(curr->r);
    }
}

template <class T>
int height_It(node<T> *root)
{
    if (root == NULL)
        return 0;
    queue<node<T> *> q;
    q.push(root);
    int nodecount;
    int height = 0;
    while (1)
    {
        nodecount = q.size();
        if (nodecount == 0)
            return height;
        height++;
        node<T> *curr;
        while (nodecount > 0)
        {
            curr = q.front();
            q.pop();
            if (curr->l)
                q.push(curr->l);
            if (curr->r)
                q.push(curr->r);
            nodecount--;
        }
    }

    return height - 1;
}

void MaxLevelIt(node<char> *root)
{
    if (root == NULL)
        return;
    queue<node<char> *> q;
    q.push(root);
    int nodecount;
    while (1)
    {
        char l_max = 'A';
        nodecount = q.size();
        if (nodecount == 0)
            return;
        node<char> *curr;
        while (nodecount > 0)
        {
            curr = q.front();
            q.pop();
            l_max = max(l_max, curr->info);
            if (curr->l)
                q.push(curr->l);
            if (curr->r)
                q.push(curr->r);
            nodecount--;
        }

        cout << l_max << " ";
    }
    cout << endl;
}

void MinLevelIt(node<char> *root)
{
    if (root == NULL)
        return;
    queue<node<char> *> q;
    q.push(root);
    int nodecount;
    while (1)
    {
        char l_min = 'Z';
        nodecount = q.size();
        if (nodecount == 0)
            return;
        node<char> *curr;
        while (nodecount > 0)
        {
            curr = q.front();
            q.pop();
            l_min = min(l_min, curr->info);
            if (curr->l)
                q.push(curr->l);
            if (curr->r)
                q.push(curr->r);
            nodecount--;
        }

        cout << l_min << " ";
    }
    cout << endl;
}

// template<class T>
// void MaxLevelRec(node<char>* root)
// {

// }

// template<class T>
// void MinLevelRec(node<char>* root)
// {

// }

// template<class T>
// void levelorder(node<T>*root,int lvl) {
// 	static int count=0;
// 	if(lvl==1) {
// 		if(!root) count++;
// 		else root->key = count;
// 		return;
// 	}
// 	if(!root) {
// 		int j=1;
// 		for(int i=lvl;i>1;i--) j<<=1;
// 		count+=j;
// 		return;
// 	}
// 	levelorder(root->l,lvl-1);
// 	levelorder(root->r,lvl-1);
// }

/* 2 */
// void ordernodes_rec(node* root)
// {
// 	int h = height(root);
// 	for(int i=1; i<=h; i++) levelorder(root, i);
// }
template <class T>
int getOneIt(node<T> *root)
{
    if (root == NULL)
        return 0;
    queue<node<T> *> q;
    int count = 0;
    q.push(root);
    node << T > * > curr;
    while (q.empty() == false)
    {
        curr = q.front();
        q.pop();
        if (curr->l == NULL && curr->r != NULL || curr->l != NULL && curr->r == NULL)
            count++;
        if (curr->l)
            q.push(curr->l);
        if (curr->r)
            q.push(curr->r);
    }

    return count;
}

template <class T>
int getOneRec(node<T> *root)
{
    int count = 0;
    if (root == NULL)
        return 0;
    if (root->l == NULL && root->r != NULL || root->l != NULL && root->r == NULL)
        count++;
    return count + getOneRec(root->l) + getOneRec(root->r);
}

template <class T>
int leaveCountIt(node<T> *root)
{
    if (root == NULL)
        return 0;
    queue<node<T> *> q;
    int count = 0;
    q.push(root);
    node << T > * > curr;
    while (q.empty() == false)
    {
        curr = q.front();
        q.pop();
        if (curr->l != NULL && curr->r != NULL)
            count++;
        if (curr->l)
            q.push(curr->l);
        if (curr->r)
            q.push(curr->r);
    }

    return count;
}

template <class T>
int leaveCountRec(node<T> *root)
{
    static int count = 0;
    if (root == NULL)
        return 0;
    if (root->l != NULL && root->r != NULL)
        count++;
    return count + getOneRec(root->l) + getOneRec(root->r);
}

template <class T>
void maxNodeIt(node<T> *root)
{
    if (root == NULL)
        return 0;
    vector<int> a;
    queue<node<T> *> curr, next;
    node<T> *v;
    curr.push(root);
    maxlen = 1;
    i = 0;
    a[i++] = 1;
    while (!curr.empty())
    {
        v = curr.fornt();
        curr.pop() if (v->l) next.push(v->l);
        if (v->r)
            next.push(v->r);
        if (curr.empty())
        {
            maxlen = max(next.size(), maxlen);
            arr[i++] = next.size();
            swap(next, curr);
        }
    }

    for (int j = 0; j < a.size(); j++)
    {
        if (a[j] == maxlen)
        {
            cout << j << " ";
        }
    }

    cout << endl;
}


template<class T>
int cntlvl_rec(node<T> *root, int lvl)
{
    if (!root)
        return 0;
    if (lvl == 1)
        return 1;
    return cntlvl_rec(root->l, lvl - 1) + cntlvl_rec(root->r, lvl - 1);
}

template<class T>
void cntnodes_rec(node<T> *root)
{
    int h = height_It(root);
    int maxlen = 0, k = 0;
    int arr[100];
    for (int i = 1; i <= h; i++)
    {
        int count = cntlvl_rec(root, i);
        maxlen = max(maxlen, count);
        arr[k++] = count;
    }
    for (int j = 0; j < k; j++)
        if (arr[j] == maxlen)
            cout << j + 1 << endl;
}

int main()
{
    node<char> *A = new node<char>('A');
    A->l = new node<char>('B');
    A->r = new node<char>('C');
    A->l->l = new node<char>('D');
    A->l->r = new node<char>('E');
    A->r->l = new node<char>('F');
    A->r->r = new node<char>('G');
    A->l->r->l = new node<char>('H');
    A->l->r->r = new node<char>('I');
    A->r->r->l = new node<char>('K');
    // postorderTraverse_It(A);
    // cout << endl;
    // inorderTraverse_It(A);
    // cout << endl;
    // preorderTraverse_It(A);
    // cout << endl;
    // levelOrderTraversal(A);
    // cout<<endl;
    // cout<<height_It(A)<<endl;
    // cout<<height_Rec(A)<<endl;

    return 0;
}
