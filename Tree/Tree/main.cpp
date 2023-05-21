#include <iostream>
#include <vector>

const std::string language = "0123456789ABCDEFGHIJKLMNOP!@#$%^&*()QRSTUVWXYZ";

//struct node
struct Node {

    std::string data;
    Node* parent, * left, * right;

    Node(std::string value) {
        data = value;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

// searching word
Node* search(Node* root, std::string value) {

    if (root == nullptr || root->data == value) {
        return root;
    }
    else
    {
        if (search(root->left, value))
            return search(root->left, value);

        if (search(root->right, value))
            return search(root->right, value);

        return nullptr;
    }

    return nullptr;

}

//advanced searching
Node* advancedSearch(Node* root, std::string value)
{

    if (root == nullptr || root->data == value) {
        return root;
    }
    else
    {
        if (root->data.size() < value.size())
            return nullptr;
        else
        {
            std::string part = root->data.substr(0, value.size());
            if (part == value)
                return root;
        }

        if (advancedSearch(root->left, value))
            return advancedSearch(root->left, value);

        if (advancedSearch(root->right, value))
            return advancedSearch(root->right, value);

        return nullptr;
    }

    return nullptr;

}

//checking word
bool allowed(std::string node)
{
    for (int i = 0; i < node.size(); i++)
    {
        bool was = false;

        for (int j = 0; j < language.size(); j++)
        {
            if (node[i] == language[j])
            {
                was = true;
                break;
            }
        }

        if (!was)
            return false;
    }

    return true;
}


//checking alfabeth
bool greater(std::string first, std::string second)
{
    int min = first.size();
    if (second.size() < min)  
        min = second.size();

    if (first.substr(0, min) == second.substr(0, min))  
    {
        if (first.size() < second.size())
            return true;
        else
            return false;
    }

    for (int i = 0; i < min; i++)  
    {
        int scoreA = -1, scoreB = -1;

        for (int j = 0; j < language.size(); j++)
        {
            if (first[i] == language[j])
                scoreA = j;

            if (second[i] == language[j])
                scoreB = j;

            if (scoreA != -1 && scoreB != -1)
                break;
        }

        if (scoreA < scoreB)
            return true;
        else if (scoreA > scoreB)
            return false;
    }

    return false;
}

//insert
bool addNode(Node*& root, std::string value)
{
    if (allowed(value) && (!search(root, value)))
    {
        Node* newNode = new Node(value);

        if (root)
        {
            Node* parent = root;
            Node* child = root;

            while (child)
            {
                parent = child;

                if (greater(value, child->data))
                    child = child->right;
                else
                    child = child->left;
            }

            newNode->parent = parent;

            if (greater(value, parent->data))
                parent->right = newNode;
            else
                parent->left = newNode;

            return true;

        }
        else
        {
            root = newNode;
            return true;
        }
    }

    return false;
}

//edit
bool editWord(Node* root, std::string node, std::string changed)
{
    if (search(root, node))
    {
        if (allowed(changed))
        {
            if (!search(root, changed))
            {
                root->data = changed;
                return true;
            }
        }
    }

    return false;
}

int main() {
    Node* treeRoot = nullptr;

    std::cout << "\tAdding\n";
    //good
    std::cout << "ABW4!!W0 added status " << addNode(treeRoot, "ABW4!!W0") << "\n";
    std::cout << "JKP@#90A added status " << addNode(treeRoot, "JKP@#90A") << "\n";

    //bad 
    std::cout << "ABW4!!W0 added status " << addNode(treeRoot, "ABW4!!W0") << "\n";
    std::cout << "Impossible added status " << addNode(treeRoot, "Impossible") << "\n";
    std::cout << "JKP@#90A added status " << addNode(treeRoot, "JKP@#90A") << "\n";
    std::cout << "ABW4!!W0 added status " << addNode(treeRoot, "ABW4!!W0") << "\n";

    std::cout << "\n\tEdit\n";
    //good
    std::cout << "ABW4!!W0 for AA editing status " << editWord(treeRoot, "ABW4!!W0", "AA") << "\n";
    //bad
    std::cout << "JKP@#90A for impossible editing status " << editWord(treeRoot, "JKP@#90A", "impossible") << "\n";
    std::cout << "JKP@#90A for AA czyli istniejace editing status " << editWord(treeRoot, "JKP@#90A", "AA") << "\n";
    std::cout << "not existed for CC  editing status " << editWord(treeRoot, "BB", "AA") << "\n";

    std::cout << "\n\tSearch\n";
    //good
    if (search(treeRoot, "AA"))
        std::cout << "AA occurrence status " << "1\n";
    else
        std::cout << "AA occurrence status "  "0\n";
    //bad
    if (search(treeRoot, "A"))
        std::cout << "A occurrence status "  "1\n";
    else
        std::cout << "A occurrence status "  "0\n";

    std::cout << "\n\tAdvanced search\n";
    //good
    if (advancedSearch(treeRoot, "J"))
        std::cout << " Starting on J occurrence status "  "1\n";
    else
        std::cout << " Starting on J occurrence status "  "0\n";
    //bad
    if (advancedSearch(treeRoot, "B"))
        std::cout << " Starting on B occurrence status " << "1\n";
    else
        std::cout << " Starting on B occurrence status "  "0\n";

    return 0;

}