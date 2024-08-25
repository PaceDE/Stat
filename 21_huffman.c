#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 100

// Structure for a Huffman tree node
struct TreeNode {
    char data;
    unsigned freq;
    struct TreeNode *left, *right;
};

// Structure for a min heap node
struct MinHeapNode {
    struct TreeNode *treeNode;
    struct MinHeapNode *next;
};

// Structure for a min heap
struct MinHeap {
    struct MinHeapNode *head;
    int size;
};

// Function to create a new Huffman tree node
struct TreeNode* createTreeNode(char data, unsigned freq) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Function to create a new min heap node
struct MinHeapNode* createMinHeapNode(struct TreeNode* treeNode) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->treeNode = treeNode;
    node->next = NULL;
    return node;
}

// Function to create a min heap
struct MinHeap* createMinHeap() {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->head = NULL;
    minHeap->size = 0;
    return minHeap;
}

// Function to insert a new min heap node
void insertMinHeapNode(struct MinHeap* minHeap, struct MinHeapNode* node) {
    if (!minHeap->head || minHeap->head->treeNode->freq > node->treeNode->freq) {
        node->next = minHeap->head;
        minHeap->head = node;
    } else {
        struct MinHeapNode* current = minHeap->head;
        while (current->next && current->next->treeNode->freq <= node->treeNode->freq) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
    minHeap->size++;
}

// Function to extract the minimum value node from the heap
struct TreeNode* extractMin(struct MinHeap* minHeap) {
    if (!minHeap->head) return NULL;
    struct MinHeapNode* temp = minHeap->head;
    minHeap->head = minHeap->head->next;
    struct TreeNode* treeNode = temp->treeNode;
    free(temp);
    minHeap->size--;
    return treeNode;
}

// Function to build a Huffman tree
struct TreeNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct TreeNode *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap();

    for (int i = 0; i < size; ++i) {
        insertMinHeapNode(minHeap, createMinHeapNode(createTreeNode(data[i], freq[i])));
    }

    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = createTreeNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeapNode(minHeap, createMinHeapNode(top));
    }

    return extractMin(minHeap);
}

// Function to print Huffman codes from the root of Huffman tree
void printCodes(struct TreeNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Function to perform Huffman coding
void huffmanCoding(char data[], int freq[], int size) {
    struct TreeNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_NODES], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char data[MAX_TREE_NODES];
    int freq[MAX_TREE_NODES];
    int n;

    printf("Enter the number of characters: ");
    scanf("%d", &n);

    printf("Enter the characters and their frequencies:\n");
    for (int i = 0; i < n; ++i)
        scanf(" %c %d", &data[i], &freq[i]);

    huffmanCoding(data, freq, n);

    return 0;
}
