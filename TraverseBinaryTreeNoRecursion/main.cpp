//
//  main.cpp
//  TraverseBinaryTreeNoRecursion
//
//  Created by chenyufeng on 10/2/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

/**
 *  使用非递归的方式遍历二叉树
 */

typedef struct TreeNode{
    int data;
    struct TreeNode *lChild;
    struct TreeNode *rChild;
    bool isVisited; // 是否被访问过的标记
}Node;

void CreateBinaryTree(Node **node)
{
    int num;
    cin >> num;

    if (num == -1)
    {
        return;
    }

    *node = new Node;
    (*node)->data = num;
    (*node)->lChild = NULL;
    (*node)->rChild = NULL;

    cout << "请输入"<< num << "的左孩子节点:";
    CreateBinaryTree(&((*node)->lChild));
    cout << "请输入"<< num << "的右孩子节点:";
    CreateBinaryTree(&((*node)->rChild));
}

// 先序遍历
/**
 *  首先把根节点入栈，并且在根节点出栈的时候访问根节点；判断根节点的右子树是否为空，若不为空，则右孩子入栈；判断根节点的左孩子是否为空，若不为空，则左孩子入栈。    当栈不为空时，重复以上操作。
 *
 */
void PreOrderNoRecursion(Node *node, stack<Node *> &sta)
{
    while (!sta.empty())
    {
        Node *temp = sta.top();
        cout << temp->data << " ";

        sta.pop();
        if (temp->rChild != NULL)
        {
            sta.push(temp->rChild);
        }

        if (temp->lChild != NULL)
        {
            sta.push(temp->lChild);
        }
    }
    return;
}

// 中序遍历
/**
 *  首先根节点入栈，判断根节点的左孩子是否为空，若不为空，则入栈，并不断移动node指针指向左孩子，直到左孩子节点为空。
    然后弹出栈顶元素并访问该元素。判断弹出元素的右孩子是否为空，若不为空，则把右孩子入栈，并把node指针指向右孩子。重复以上操作。
 */
void MidOrderNoRecursion(Node *node, stack<Node *>&sta)
{
    while (!sta.empty())
    {
        while (node->lChild != NULL)
        {
            sta.push(node->lChild);
            node = node->lChild;
        }

        Node *temp = sta.top();
        cout << temp->data << " ";
        sta.pop();
        if (temp->rChild != NULL)
        {
            sta.push(temp->rChild);
            node = temp->rChild;
        }
    }
}

// 后序遍历
/**
 *  在节点的结构体中加入一个参数isVisited,表示某个节点是否被访问过。
 
 首先根节点入栈，然后判断左孩子是否为空，若不为空，则左孩子入栈，并移动node到左孩子，直到左孩子为空。
 然后判断栈顶元素，如果栈顶元素没有右孩子或者右孩子已经被访问过，那么就访问该栈顶元素，并出栈；如果栈顶元素有右孩子并且右孩子没有被访问过，那么把右孩子入栈，把node指针指向右孩子。
 若栈不为空，则重复以上操作。

 *
 */
void PostOrderNoRecursion(Node *node, stack<Node *>&sta)
{
    while (!sta.empty())
    {
        while (node->lChild != NULL)
        {
            sta.push(node->lChild);
            node = node->lChild;
        }

        Node *temp = sta.top();
        if (temp->rChild == NULL || temp->rChild->isVisited == true)
        {
            cout << temp->data << " ";
            temp->isVisited = true;
            sta.pop();
        }
        else if(temp->rChild != NULL && temp->isVisited == false)
        {
            sta.push(temp->rChild);
            node = temp->rChild;
        }
    }
}

int main(int argc, const char * argv[])
{
    cout << "请输入二叉树的节点，输入-1结束:";
    Node *node;
    CreateBinaryTree(&node);

    cout << "非递归先序遍历的结果为：";
    stack<Node *> nodeStack;
    // 首先根节点入栈
    nodeStack.push(node);
    PreOrderNoRecursion(node, nodeStack);
    cout << endl;

    cout << "非递归中序遍历的结果为：";
    stack<Node *> nodeStackM;
    // 首先根节点入栈
    nodeStackM.push(node);
    MidOrderNoRecursion(node, nodeStackM);
    cout << endl;

    cout << "非递归后序遍历的结果为：";
    stack<Node *> nodeStackP;
    // 首先根节点入栈
    nodeStackP.push(node);
    PostOrderNoRecursion(node, nodeStackP);
    cout << endl;

    return 0;
}
