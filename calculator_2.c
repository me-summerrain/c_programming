#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXLEN 100
#define TRUE 1
#define FALSE 0

typedef struct NODE
{
    struct NODE *father;
    struct NODE *left;
    struct NODE *right;
    char value[MAXLEN];
    int isLeaf;
} Node;

void freeTree(Node *root);
void newNode(Node *root, Node *father);
void strClear(char *str, int n);
void initCalcTree(Node *root, int order);
double calcNode(Node *root);

void newNode(Node *root, Node *father)
{
    root->father = father;
    root->left = NULL;
    root->right = NULL;
    memset(root->value, '\0', sizeof(root->value)); // initialize value
    root->isLeaf = TRUE;
    if (father != NULL)
        father->isLeaf = FALSE;
}

void strClear(char *str, int n)
{
    for (int i = 0; i < n; i++)
    {
        str[i] = '\0';
    }
}

void initCalcTree(Node *root, int order)
{
    for (int i = 0; i < MAXLEN && root->value[i] != '\0'; i++)
    {
        if (root->value[i] == '(')
        {
            int openParens = 0;
            int closePos = -1;
            for (int j = i + 1; j < MAXLEN && closePos == -1 && root->value[j] != '\0'; j++)
            {
                if (root->value[j] == '(')
                    openParens++;
                else if (root->value[j] == ')')
                {
                    if (openParens == 0)
                        closePos = j;
                    else
                        openParens--;
                }
            }

            int funcNameLength = i < MAXLEN ? i : MAXLEN - 1; // Added a check here to avoid buffer overflow
            char funcName[MAXLEN];
            strncpy(funcName, root->value, funcNameLength);
            funcName[funcNameLength] = '\0';

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

double calcNode(Node *root) // Return type changed to double
{
    if (root->isLeaf == TRUE)
        return atof(root->value);
    else
    {
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
        else
            return 0; // Default return value in case no condition is met
    }
}

void freeTree(Node *root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    Node *root = (Node *)malloc(sizeof(Node));
    char str[MAXLEN];
    while (fgets(str, MAXLEN, stdin) != NULL)
    {
        str[strlen(str) - 1] = '\0';
        newNode(root, NULL);
        strcpy(root->value, str);
        initCalcTree(root, '\0');
        printf("%s=%f\n", str, calcNode(root));
        freeTree(root);
        root = (Node *)malloc(sizeof(Node));
    }
    free(root);
    return 0;
}
