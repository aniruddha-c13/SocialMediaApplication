#include <bits/stdc++.h>
#include "System.h"

using namespace std;

int main()
{
    System *sys = NULL;
    // Variables to extract input keywords and corresponding parameters
    string instr;
    string keyword;
    string appname;
    string username;
    string password;
    string contents;
    string followerusername;
    string followedusername;
    string unfollowedusername;
    size_t pos;
    size_t pos2;
    long long int year;
    long long int userID;
    long long int postID;

    // Redirect cout and capture output for printing after all processing
    streambuf* origCoutStreamBuf = cout.rdbuf();
    ostringstream strCout;
    cout.rdbuf(strCout.rdbuf());

    // Get input line to be parsed
    getline(cin, instr);
    // Stop reading input on EXIT keyword
    while(instr.find("EXIT") != 0)
    {
        if(instr.find("CREATE") == 0)
        {
            // Extract - Create application inputs
            pos = instr.find(" ");
            keyword = instr.substr(0, pos);
            appname = instr.substr(pos + 1);
            // Create system object
            sys = new System(appname);
        }
        else if(sys && (instr.find("SIGNUP") == 0))
        {
            // Extract - signup inputs
            pos = instr.find(" ");
            keyword = instr.substr(0, pos);
            pos2 = instr.find(" ", pos + 1);
            username = instr.substr(pos + 1, pos2 - pos - 1);
            password = instr.substr(pos2 + 1);
            // Invoke sign up method for system object
            sys->signUpUser(username, password);
        }
        else if(sys && (instr.find("SIGNIN") == 0))
        {
            // Extract - signin inputs
            pos = instr.find(" ");
            keyword = instr.substr(0, pos);
            pos2 = instr.find(" ", pos + 1);
            username = instr.substr(pos + 1, pos2 - pos - 1);
            password = instr.substr(pos2 + 1);
            // Invoke sign in method for system object
            sys->signInUser(username, password);
        }
        else if(sys && (instr.find("SIGNOUT") == 0))
        {
            // Invoke sign out (current) user method for system object
            sys->signOutUser();
        }
        else if(sys && (instr.find("FOLLOW") == 0))
        {
            // Extract - Follow user inputs
            pos = instr.find(" ");
            keyword = instr.substr(0, pos);
            followedusername = instr.substr(pos + 1);
            // Invoke userfollow method for system object
            sys->userfollow(followedusername);
        }
        else if(sys && (instr.find("UNFOLLOW") == 0))
        {
            // Extract - Unfollow user inputs
            pos = instr.find(" ");
            keyword = instr.substr(0, pos);
            unfollowedusername = instr.substr(pos + 1);
            // Invoke userunfollow method for system object
            sys->userunfollow(unfollowedusername);
        }
        else if(sys && (instr.find("POST") == 0))
        {
            // Extract - Create Post inputs
            pos = instr.find(" ");
            keyword = instr.substr(0, pos);
            pos2 = instr.find(" ", pos + 1);
            year = stoll(instr.substr(pos + 1, pos2 - pos - 1));
            contents = instr.substr(pos2 + 1);
            // Invoke addpost method for system object
            sys->addpost(year, contents);
        }
        else if(sys && (instr.find("PRINTUSER") == 0))
        {
            // Extract - user ID input
            pos = instr.find(" ");
            keyword = instr.substr(0, pos);
            userID = stoll(instr.substr(pos + 1));
            // printuser method invokes output stream insertion operator overloaded for user
            sys->printuser(userID);
        }
        else if(sys && (instr.find("PRINTPOST") == 0))
        {
            // Extract - post ID input
            pos = instr.find(" ");
            keyword = instr.substr(0, pos);
            postID = stoll(instr.substr(pos + 1));
            // printpost method invokes output stream insertion operator overloaded for post
            sys->printpost(postID);
        }
        // Get next input line to be parsed
        getline(cin, instr);
    }
    // Restore original cout
    cout.rdbuf(origCoutStreamBuf);
    // Print captured output
    cout << strCout.str();
    // Destruct all allocated objects via destructors
    delete sys;

    return 0;
}

