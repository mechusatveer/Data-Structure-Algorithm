// C based program to implement reverse DNS lookup
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
// There are atmost 11 different chars in a valid IP address
#define CHARS 11
 
// Maximum length of a valid IP address
#define MAX 50
 
// A utility function to find index of child for a given character 'c'
int getIndex(char c) { return (c == '.')? 10: (c - '0'); }
 
// A utility function to find character for a given child index.
char getCharFromIndex(int i) { return (i== 10)? '.' : ('0' + i); }
 
// Trie Node.
struct trieNode
{
    bool isLeaf;
    char *URL;
    struct trieNode *child[CHARS];
};
 
// Function to create a new trie node.
struct trieNode *newTrieNode(void)
{
    struct trieNode *newNode = new trieNode;
    newNode->isLeaf = false;
    newNode->URL = NULL;
    for (int i=0; i<CHARS; i++)
        newNode->child[i] = NULL;
    return newNode;
}
 
// This method inserts an ip address and the corresponding
// domain name in the trie. The last node in Trie contains the URL.
void insert(struct trieNode *root, char *ipAdd, char *URL)
{
    // Length of the ip address
    int len = strlen(ipAdd);
    struct trieNode *pCrawl = root;
 
    // Traversing over the length of the ip address.
    for (int level=0; level<len; level++)
    {
        // Get index of child node from current character
        // in ipAdd[].  Index must be from 0 to 10 where
        // 0 to 9 is used for digits and 10 for dot
        int index = getIndex(ipAdd[level]);
 
        // Create a new child if not exist already
        if (!pCrawl->child[index])
            pCrawl->child[index] = newTrieNode();
 
        // Move to the child
        pCrawl = pCrawl->child[index];
    }
 
    //Below needs to be carried out for the last node.
    //Save the corresponding URL of the ip address in the
    //last node of trie.
    pCrawl->isLeaf = true;
    pCrawl->URL = new char[strlen(URL) + 1];
    strcpy(pCrawl->URL, URL);
}
 
// This function returns URL if given IP address is present in DNS cache.
// Else returns NULL
char  *searchDNSCache(struct trieNode *root, char *ipAdd)
{
    // Root node of trie.
    struct trieNode *pCrawl = root;
    int  len = strlen(ipAdd);
 
    // Traversal over the length of ip address.
    for (int level=0; level<len; level++)
    {
        int index = getIndex(ipAdd[level]);
        if (!pCrawl->child[index])
            return NULL;
        pCrawl = pCrawl->child[index];
    }
 
    // If we find the last node for a given ip address, print the URL.
    if (pCrawl!=NULL && pCrawl->isLeaf)
        return pCrawl->URL;
 
    return NULL;
}
 
//Driver function.
int main()
{
    /* Change third ipAddress for validation */
    char ipAdd[][MAX] = {"107.108.11.123", "107.109.123.255",
                         "74.125.200.106"};
    char URL[][50] = {"www.samsung.com", "www.samsung.net",
                      "www.google.in"};
    int n = sizeof(ipAdd)/sizeof(ipAdd[0]);
    struct trieNode *root = newTrieNode();
 
    // Inserts all the ip address and their corresponding
    // domain name after ip address validation.
    for (int i=0; i<n; i++)
        insert(root,ipAdd[i],URL[i]);
 
    // If reverse DNS look up succeeds print the domain
    // name along with DNS resolved.
    char ip[] = "107.108.11.123";
    char *res_url = searchDNSCache(root, ip);
    if (res_url != NULL)
        printf("Reverse DNS look up resolved in cache:\n%s --> %s",
                ip, res_url);
    else
        printf("Reverse DNS look up not resolved in cache ");
    return 0;
}
Output:

Reverse DNS look up resolved in cache:
107.108.11.123 --> www.samsung.com
