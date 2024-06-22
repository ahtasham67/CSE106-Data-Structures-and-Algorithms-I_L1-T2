#include"2105067_BST.cpp"
int main()
{
    ifstream inputFile("in.txt");   // Open input file
    outputFile.open("out.txt");     // Open output file

    BST<int> bst;
    while (1)
    {
        string str1, str2;
       inputFile >> str1 >> str2;
        /*if (!(inputFile >> str1 >> str2))
            break; // Break the loop when no more input is available*/

        if (str1 == "F")
        {
            int val = stoi(str2);
            if (bst.find(val))
                outputFile << "found" << endl;
            else
                outputFile << "not found" << endl;
        }
        else if (str1 == "I")
        {
            int val = stoi(str2);
            bst.insert(val);
            outputFile << "(";
            bst.print();
            outputFile << ")";
            outputFile << endl;
        }
        else if (str1 == "D")
        {
            int val = stoi(str2);
            bst.Delete(val);
            outputFile << "(";
            bst.print();
            outputFile << ")";
            outputFile << endl;
        }
        else if (str1 == "T")
        {
            if (str2 == "In")
            {
                bst.inOrder();
                outputFile << endl;
            }
            if (str2 == "Pre")
            {
                bst.preOrder();
                outputFile << endl;
            }
            if (str2 == "Post")
            {
                bst.postOrder();
                outputFile << endl;
            }
        }
    }
    inputFile.close();  // Close input file
    outputFile.close(); // Close output file
    return 0;
}