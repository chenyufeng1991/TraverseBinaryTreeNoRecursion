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














