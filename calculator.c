#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100
#define TRUE 1
#define FALSE 0

typedef struct NODE {
    struct NODE *father;
    struct NODE *left;
    struct NODE *right;
    char value[MAXLEN];
    int isLeaf;
} Node;

void newNode(Node *root, Node *father) {
    root->father = father;
    root->left = NULL;
    root->right = NULL;
    root->isLeaf = TRUE;
    if (father != NULL)
        father->isLeaf = FALSE;
}

// clear the string
void strClear(char *str, int n) {
    for (int i = 0; i < n; i++) {
        str[i] = '\0';
    }
}

void initCalcTree(Node *root, int order) {
    for (int i = 0; i < MAXLEN; i++) {
        if (root->value[i] == '(') {
            // Find the matching closing parenthesis
            int openParens = 0;
            int closePos = -1;
            for (int j = i + 1; j < MAXLEN && closePos == -1; j++) {
                if (root->value[j] == '(')
                    openParens++;
                else if (root->value[j] == ')') {
                    if (openParens == 0)
                        closePos = j;
                    else
                        openParens--;
                }
            }

            // Extract function name and argument
            int funcNameLength = i;
            char funcName[MAXLEN];
            strncpy(funcName, root->value, funcNameLength);
            funcName[funcNameLength] = '\0';

            // Split into two nodes: function name and argument
            Node *Left = (Node *)malloc(sizeof(Node));
            Node *Right = (Node *)malloc(sizeof(Node));
            newNode(Left, root);
            newNode(Right, root);

            strcpy(Left->value, funcName);
            strncpy(Right->value, &root->value[i + 1], closePos - i - 1);
            Right->value[closePos - i - 1] = '\0';

            root->left = Left;
            root->right = Right;

            strcpy(root->value, "func");

            initCalcTree(Right, 0);
            break;
        }
    }
}

int calcNode(Node *root) {
    if (root->isLeaf == TRUE)
        return atof(root->value);
    else {
        double a = calcNode(root->left);
        double b = calcNode(root->right);
        if (strcmp(root->left->value, "abs") == 0)
            return fabs(b);
        else if (strcmp(root->left->value, "sin") == 0)
            return sin(b);
        else if (strcmp(root->left->value, "cos") == 0)
            return cos(b);
        else if (strcmp(root->left->value, "tan") == 0)
            return tan(b);
    }
}

int main() {
    Node *root = (Node *)malloc(sizeof(Node));
    char str[MAXLEN];
    while (1) {
        fgets(str, MAXLEN, stdin);
        str[strlen(str) - 1] = '\0';  // Remove the trailing newline
        strcpy(root->value, str);
        initCalcTree(root, '\0');
        printf("%s=%f\n", str, calcNode(root));
    }
    return 0;
}
