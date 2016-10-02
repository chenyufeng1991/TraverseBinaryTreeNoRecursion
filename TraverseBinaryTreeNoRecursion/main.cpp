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



    return 0;
}














