#include "priority_queue.cpp"

int main()
{
    // ifstream inputFile("in1.txt");   // Open input file
    ifstream inputFile("in1.txt");
    outputFile.open("out1.txt"); // Open output file
    priority_queue<int> pq;

    while (!inputFile.eof())
    {
        /*outputFile << "Select an operation:" << endl;
        outputFile << "1. Insert" << endl;
        outputFile << "2. FindMax" << endl;
        outputFile << "3. ExtractMax" << endl;
        outputFile << "4. IncreaseKey" << endl;
        outputFile << "5. DecreaseKey" << endl;
        outputFile << "6. Print" << endl;
        outputFile << "7. Terminate and Sort" << endl; */
        int choice;
        inputFile >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            // outputFile << "Enter value to insert: ";
            inputFile >> value;
            pq.Insert(value);
            break;
        }
        case 2:
        {
            int maxVal = pq.FindMax();
            outputFile << "Max: " << maxVal << endl;
            break;
        }
        case 3:
        {
            int maxVal = pq.ExtractMax();
            outputFile << "Max: " << maxVal << " has been extracted." << endl;
            break;
        }
        case 4:
        {
            int index, newValue;
            // outputFile << "Enter index and new value: ";
            inputFile >> index >> newValue;
            pq.IncreaseKey(index, newValue);
            break;
        }
        case 5:
        {
            int index, newValue;
            // outputFile << "Enter index and new value: ";
            inputFile >> index >> newValue;
            pq.DecreaseKey(index, newValue);
            break;
        }
        case 6:
            // outputFile << "Current heap: ";
            pq.Print();
            break;
        case 7:
            pq.Sort();
            // outputFile << "Heap sorted: ";
            // pq.Print();
            return 0;
            // default:
            // outputFile << "Invalid choice. Try again." << endl;
        }
    }
    inputFile.close();  // Close input file
    outputFile.close(); // Close output file
    return 0;
}