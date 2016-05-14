#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ifstream answers;
    string line;
    //vector<string> results;
    vector<int> points;
    string name;
    int lineNumber = 1;

    answers.open ("answers.txt");
    if (answers.is_open())
    {
        //results.resize(42);
        points.resize(51);
        while (getline(answers, line))
        {
            if (lineNumber != 1 && lineNumber != 6 && lineNumber != 7 && lineNumber != 8 &&
                lineNumber != 15 && lineNumber != 16 && lineNumber != 34)
            {
                //results.push_back(line);
                if (lineNumber == 2)
                {
                    name = line.substr(23, string::npos);
                }

                else if (lineNumber == 3 || lineNumber == 4 || lineNumber == 5)
                {
                    cout << endl << line << endl << endl;
                    cout << "Enter the corresponding point value for this answer ";
                    if (lineNumber == 3)
                    {
                        cout << "(Democracies, Republics, Constitutional Monarchies = 25," << endl;
                        cout << "One-Party States, Benevolent/Enlightened Dictatorships/Monarchies = 10," << endl;
                        cout << "Totalitarian Regimes = 0): ";
                    }
                    else if (lineNumber == 4)
                    {
                        cout << "(Free-Market and Mixed Economy = 10, Socialist/Communist = 5): ";
                    }
                    else
                    {
                        cout << "(0-10% = 10, 11-20% = 9, 21-30% = 8, 31-40% = 7, 41-50% = 6, 51-60% = 5, 61-70% = 4, 71-80% = 3, 81-90% = 2, 90-95% = 1, 96-100% = 0) ";
                    }
                    cin >> points.at(lineNumber - 1);
                }
                else
                {
                    int pointVal;

                    if (lineNumber == 13 || lineNumber == 35 || lineNumber == 39 || lineNumber == 46 || lineNumber == 49)
                    {
                        pointVal == 7;
                    }
                    else if (lineNumber == 37 || lineNumber == 38 || lineNumber == 42 || lineNumber == 43 || lineNumber == 44 || lineNumber == 47 || lineNumber == 51)
                    {
                        pointVal = 5;
                    }
                    else if (lineNumber == 9 || lineNumber == 10 || lineNumber == 11 || lineNumber == 12 || lineNumber == 14 || lineNumber == 17 || lineNumber == 18 ||
                             lineNumber == 19 || lineNumber == 20 || lineNumber == 21 || lineNumber == 22 || lineNumber == 23 || lineNumber == 24 || lineNumber == 25 ||
                             lineNumber == 26 || lineNumber == 27 || lineNumber == 28 || lineNumber == 29 || lineNumber == 30 || lineNumber == 31 || lineNumber == 32 ||
                             lineNumber == 33)
                    {
                        pointVal = 25;
                    }
                    else
                    {
                        pointVal = 10;
                    }

                    int searchFrom = 0;
                    if (lineNumber == 45 || lineNumber == 46) searchFrom = 40;

                    if (line.find("(") == string::npos && line.find(",", searchFrom) == string::npos & line.find(";") == string::npos)
                    {
                        if (line.find("Yes") != string::npos)
                        {
                            points.at(lineNumber - 1) = pointVal;
                        }
                        else if (line.find("No") != string::npos)
                        {
                            points.at(lineNumber - 1) = 0;
                        }
                    }
                    else
                    {
                        cout << endl << line << endl << endl;
                        cout << "Out of " << pointVal << " points" << endl;
                        cout << "Enter the corresponding point value for this answer: ";
                        cin >> points.at(lineNumber - 1);
                    }
                }
            }
            ++lineNumber;
        }
        answers.close();

        int total = 0;

        for (int i = 0; i < points.size(); ++i)
        {
            //cout << points.at(i) << endl;
            total += points.at(i);
        }
        cout << "Total points: " << total << endl;

        ofstream out;
        out.open("Results.txt", ios::app);

        if (out.is_open())
        {
            out << name << ": " << total;

            if (total >= 740) out << " (Perfect)" << endl;
            else if (total >= 700 && total <= 739) out << " (Excellent)" << endl;
            else if (total >= 600 && total <= 699) out << " (Good)" << endl;
            else if (total >= 400 && total <= 599) out << " (Mediocre)" << endl;
            else if (total >= 200 && total <= 399) out << " (Bad)" << endl;
            else if (total >= 100 && total <= 199) out << " (Horrible)" << endl;
            else if (total <= 99) out << " (Nonexistent)" << endl;

            out.close();
        }
        else
        {
            cout << "Cannot open file for writing" << endl;
        }

    }
    else
    {
        cout << "Cannot open file for reading" << endl;
    }


    char input;

    cout << "Type anything to exit" << endl;
    cin >> input;


    return 0;
}
