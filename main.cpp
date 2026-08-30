/*#include <iostream>
#include <string>

using namespace std;

class CleanlinessIssue
{
private:
    int issueId;
    string area;
    string issueType;
    int severity;
    string status;

public:
    void getIssue()
    {
        cout << "\nEnter Issue ID: ";
        cin >> issueId;

        cout << "Enter Area: ";
        cin >> area;

        cout << "Enter Issue Type: ";
        cin >> issueType;

        cout << "Enter Severity (1-5): ";
        cin >> severity;

        status = "Reported";
    }

    void putIssue()
    {
        cout << "\n----- ISSUE DETAILS -----" << endl;
        cout << "Issue ID: " << issueId << endl;
        cout << "Area: " << area << endl;
        cout << "Issue Type: " << issueType << endl;
        cout << "Severity: " << severity << endl;
        cout << "Status: " << status << endl;
    }
};

int main()
{
    CleanlinessIssue c;

    c.getIssue();
    c.putIssue();

    return 0;
}*/
/*#include <iostream>
#include <string>

using namespace std;

class CleanlinessIssue
{
private:
    int issueId;
    string area;
    string issueType;
    int severity;
    string status;

public:
    void getIssue()
    {
        cout << "\nEnter Issue ID: ";
        cin >> issueId;

        cout << "Enter Area: ";
        cin >> area;

        cout << "Enter Issue Type: ";
        cin >> issueType;

        cout << "Enter Severity (1-5): ";
        cin >> severity;

        status = "Reported";
    }

    void putIssue()
    {
        cout << "\n----- ISSUE DETAILS -----" << endl;
        cout << "Issue ID: " << issueId << endl;
        cout << "Area: " << area << endl;
        cout << "Issue Type: " << issueType << endl;
        cout << "Severity: " << severity << endl;
        cout << "Status: " << status << endl;
    }
};
int main()
{
    CleanlinessIssue issue1;
    int choice;

    do
    {
        cout << "\n================================" << endl;
        cout << "       CLEANSPOT SYSTEM" << endl;
        cout << "================================" << endl;

        cout << "1. Add Cleanliness Issue" << endl;
        cout << "2. View Issue" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            issue1.getIssue();
            break;

        case 2:
            issue1.putIssue();
            break;

        case 3:
            cout << "Thank you!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 3);

    return 0;
}*/
#include <iostream>
#include <string>

using namespace std;

class CleanlinessIssue
{
private:
    int issueId;
    string area;
    string issueType;
    int severity;
    string status;

public:

    void getIssue()
    {
        cout << "Enter Area: ";
        cin >> area;

        cout << "Enter Issue Type: ";
        cin.ignore();
        getline(cin, issueType);  

        do
        {
            cout << "Enter Severity (1-5): ";
            cin >> severity;

            if (severity < 1 || severity > 5)
            {
                cout << "Invalid severity! Please enter between 1 and 5." << endl;
            }

        } while (severity < 1 || severity > 5);

        status = "Reported";
    }

    void putIssue()
    {
        cout << "\n----- ISSUE DETAILS -----" << endl;
        cout << "Issue ID: " << issueId << endl;
        cout << "Area: " << area << endl;
        cout << "Issue Type: " << issueType << endl;
        cout << "Severity: " << severity << endl;
        cout << "Status: " << status << endl;
    }

    int getIssueId()
    {
        return issueId;
    }

    void setIssueId(int id)
    {
        issueId = id;
    }

    string getArea()
    {
        return area;
    }

    void updateStatus()
    {
        int statusChoice;

        cout << "\nSelect New Status:" << endl;
        cout << "1. Reported" << endl;
        cout << "2. In Progress" << endl;
        cout << "3. Resolved" << endl;
        cout << "Enter your choice: ";

        cin >> statusChoice;

        switch (statusChoice)
        {
        case 1:
            status = "Reported";
            break;

        case 2:
            status = "In Progress";
            break;

        case 3:
            status = "Resolved";
            break;

        default:
            cout << "Invalid status choice!" << endl;
            return;
        }

        cout << "Status updated successfully!" << endl;
    }

    void showPriority()
    {
        cout << "\nPriority: ";

        if (severity == 5)
        {
            cout << "CRITICAL" << endl;
        }
        else if (severity == 4)
        {
            cout << "HIGH" << endl;
        }
        else
        {
            cout << "NORMAL" << endl;
        }
    }
};

int main()
{
    CleanlinessIssue issues[10];

    int count = 0;
    int choice;
    int searchId;
    bool found;

    do
    {
        cout << "\n================================" << endl;
        cout << "       CLEANSPOT SYSTEM" << endl;
        cout << "================================" << endl;

        cout << "1. Add Cleanliness Issue" << endl;
        cout << "2. View All Issues" << endl;
        cout << "3. Search Issue by ID" << endl;
        cout << "4. Update Issue Status" << endl;
        cout << "5. Show Priority Issues" << endl;
        cout << "6. Area Issue Summary" << endl;
        cout << "7. Find Cleanliness Hotspot" << endl;
        cout << "8. Delete Issue by ID" << endl;
        cout << "9. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
        {
            if (count < 10)
            {
                int newId;

                cout << "\nEnter Issue ID: ";
                cin >> newId;

                found = false;

                for (int i = 0; i < count; i++)
                {
                    if (issues[i].getIssueId() == newId)
                    {
                        found = true;
                        break;
                    }
                }

                if (found == true)
                {
                    cout << "Issue ID already exists! Try another ID." << endl;
                }
                else
                {
                    issues[count].setIssueId(newId);
                    issues[count].getIssue();
                    count++;
                }
            }
            else
            {
                cout << "Maximum limit of 10 issues reached!" << endl;
            }

            break;
        }

        case 2:

            if (count == 0)
            {
                cout << "\nNo issues added yet!" << endl;
            }
            else
            {
                cout << "\n===== ALL ISSUES =====" << endl;

                for (int i = 0; i < count; i++)
                {
                    issues[i].putIssue();
                }
            }

            break;

        case 3:

            cout << "\nEnter Issue ID to search: ";
            cin >> searchId;

            found = false;

            for (int i = 0; i < count; i++)
            {
                if (issues[i].getIssueId() == searchId)
                {
                    cout << "\nIssue Found!" << endl;

                    issues[i].putIssue();

                    found = true;
                    break;
                }
            }

            if (found == false)
            {
                cout << "\nIssue not found!" << endl;
            }

            break;

        case 4:

            cout << "\nEnter Issue ID to update: ";
            cin >> searchId;

            found = false;

            for (int i = 0; i < count; i++)
            {
                if (issues[i].getIssueId() == searchId)
                {
                    issues[i].updateStatus();

                    found = true;
                    break;
                }
            }

            if (found == false)
            {
                cout << "\nIssue not found!" << endl;
            }

            break;

        case 5:

            if (count == 0)
            {
                cout << "\nNo issues added yet!" << endl;
            }
            else
            {
                cout << "\n===== ISSUE PRIORITIES =====" << endl;

                for (int i = 0; i < count; i++)
                {
                    cout << "\nIssue ID: "
                         << issues[i].getIssueId();

                    issues[i].showPriority();
                }
            }

            break;

        case 6:
        {
            if (count == 0)
            {
                cout << "\nNo issues added yet!" << endl;
            }
            else
            {
                cout << "\n===== AREA ISSUE SUMMARY =====" << endl;

                for (int i = 0; i < count; i++)
                {
                    int areaCount = 0;

                    for (int j = 0; j < count; j++)
                    {
                        if (issues[i].getArea() ==
                            issues[j].getArea())
                        {
                            areaCount++;
                        }
                    }

                    bool alreadyShown = false;

                    for (int k = 0; k < i; k++)
                    {
                        if (issues[i].getArea() ==
                            issues[k].getArea())
                        {
                            alreadyShown = true;
                            break;
                        }
                    }

                    if (alreadyShown == false)
                    {
                        cout << issues[i].getArea()
                             << " : "
                             << areaCount
                             << " issue(s)" << endl;
                    }
                }
            }

            break;
        }

        case 7:
        {
            if (count == 0)
            {
                cout << "\nNo issues added yet!" << endl;
            }
            else
            {
                int maxCount = 0;
                string hotspotArea;

                for (int i = 0; i < count; i++)
                {
                    int areaCount = 0;

                    for (int j = 0; j < count; j++)
                    {
                        if (issues[i].getArea() ==
                            issues[j].getArea())
                        {
                            areaCount++;
                        }
                    }

                    if (areaCount > maxCount)
                    {
                        maxCount = areaCount;
                        hotspotArea = issues[i].getArea();
                    }
                }

                cout << "\n===== CLEANLINESS HOTSPOT =====" << endl;
                cout << "Area: " << hotspotArea << endl;
                cout << "Total Issues: " << maxCount << endl;
                cout << "Attention Required!" << endl;
            }

            break;
        }

        case 8:
        {
            if (count == 0)
            {
                cout << "\nNo issues available to delete!" << endl;
            }
            else
            {
                cout << "\nEnter Issue ID to delete: ";
                cin >> searchId;

                found = false;

                for (int i = 0; i < count; i++)
                {
                    if (issues[i].getIssueId() == searchId)
                    {
                        for (int j = i; j < count - 1; j++)
                        {
                            issues[j] = issues[j + 1];
                        }

                        count--;

                        cout << "\nIssue deleted successfully!" << endl;

                        found = true;
                        break;
                    }
                }

                if (found == false)
                {
                    cout << "\nIssue not found!" << endl;
                }
            }

            break;
        }

        case 9:

            cout << "\nThank you for using CleanSpot!" << endl;

            break;

        default:

            cout << "Invalid choice!" << endl;
        }

    } while (choice != 9);

    return 0;
}