#include "node.h"
#include <stdio.h>
#include <algorithm>
#include <deque>

#include "students.h"



/**************************************************************************
 * Trädklättring.
 *
 *
 **************************************************************************/

void flashPreOrder(Node *pTree){

    if (pTree == nullptr)
        return;
    pTree->flash();
    flashPreOrder( pTree->_pLeft );
    flashPreOrder( pTree->_pRight );
}

void flashInOrder(Node *pTree){

    if (pTree == nullptr)
        return;
    flashInOrder( pTree->_pLeft );
    pTree->flash();
    flashInOrder( pTree->_pRight );

}

void flashPostOrder(Node *pTree){

    if (pTree == nullptr)
        return;
    flashPostOrder( pTree->_pLeft );
    flashPostOrder( pTree->_pRight );
    pTree->flash();
}


void flashNodesAtIncreasingDepth(Node *pTree){
    // Denna funktion skall inte vara rekursiv.
    // implementera den med hjälp av en FIFO-kö.
    // Så här kan du deklarera fifo-kön:
    // std::deque<Node*> que;
    // så här stoppar du in ett värde i kön
    // que.push_back( nodepekare );
    // så här läser du det värde som ligger främst
    // Node *p = que.front();
    // så här avlägsnar du det främsta värdet från kön
    // que.pop_front()

    std::deque<Node*> que;

    que.push_front(pTree);

    while (!que.empty()){
        Node *pTree = que.front();
        que.pop_front();

        if (pTree->_pLeft != nullptr)
            que.push_back(pTree->_pLeft);
        if (pTree->_pRight != nullptr)
            que.push_back(pTree->_pRight);

        pTree->flash();
    }
}

int numberOfNodes(Node *pTree){

    if (pTree == nullptr)
        return 0;

    return 1 + numberOfNodes(pTree->_pLeft) + numberOfNodes(pTree->_pRight);
}

int height(Node *pTree){
    // OBS höjden av ett träd som bara innehåller en rot-nod är 0.
    // Anropa gärna flash och verifiera att du bara besöker varje nod en gång

    pTree->flash();
    if (pTree == nullptr)
        return -1;

    int lHeight = height(pTree->_pLeft);
    int rHeight = height(pTree->_pRight);

    if (lHeight > rHeight)
        return (lHeight + 1);
    else return (rHeight + 1);
}


