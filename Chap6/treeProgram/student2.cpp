

#include "node.h"
#include <stdio.h>
#include <algorithm>
#include <deque>

#include "students.h"




/**************************************************************************
 * Sökträd.
 *
 *
 **************************************************************************/

void insertKeyToSearchtree(Node*& pTree, int key){

    if (pTree == nullptr)
        pTree = new Node(key, nullptr,nullptr);
    else if (key < pTree ->_key)
        insertKeyToSearchtree(pTree->_pLeft, key);
    else if (key > pTree->_key)
        insertKeyToSearchtree(pTree->_pRight, key);
}

bool contains(Node *pTree, int key){

    if (pTree == nullptr)
        return false;
    if (key < pTree->_key)
        return contains(pTree->_pLeft, key);
    if (key > pTree->_key)
        return contains(pTree->_pRight, key);

    return true;
}

Node* nodeWithMinimumKey(Node *pTree){
    // implementera denna ickerekursivt.

    if(pTree == nullptr)
        return nullptr;
    while(pTree ->_pLeft != nullptr)
        pTree = pTree->_pLeft;

    return pTree;
}

void removeKeyFromSearchtree(Node* &pTree, int key){

    if (pTree == nullptr)
        return;
    else if (key < pTree->_key)
        removeKeyFromSearchtree(pTree->_pLeft, key);
    else if (key > pTree->_key)
        removeKeyFromSearchtree(pTree->_pRight, key);

    if (pTree->_pLeft==nullptr || pTree->_pRight==nullptr)
    {
        Node *pOldNode = pTree;
        pTree = (pTree->_pLeft!=nullptr? pTree->_pLeft: pTree->_pRight);
        delete pOldNode;
    }
    else
    {
        pTree->_key = nodeWithMinimumKey(pTree->_pRight)->_key;
        removeKeyFromSearchtree(pTree->_pRight, pTree->_key);
    }

}

/*** redogörelse för experiment ***************************************

  Hur stort blir trädets höjd respektive genomsnittliga
  djup om man stoppar in 255 element (gör flera experiment)?

  Höjd = 19

  Genomsnittligt djup = 8.06

  Vid varje slumpning skapas samma träd för mig, problemet som kunde uppstå med datorer som kör Windows som du nämnde på föreläsningen.

  Varför är det genomsnittliga djupet intressant?

  Desto mindre djup desto snabbare söktid. Till exempel vid ett genomsnittligt djup på ca 8 som jag fick, krävs det i snitt 8 vägval.


******************************************************************************/



