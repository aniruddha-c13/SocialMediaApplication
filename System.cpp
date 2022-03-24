#include "System.h"

using namespace std;

// Initialize System object
System::System(string iname)
{
    appname = iname;
    cout << appname << endl;
}

// Method to get a user (object pointer) given a user ID
// Returns NULL if given user ID not found in current user list of application
User* System::getuserbyuserID(long long int iuserID)
{
    if(iuserID != -1)
    {
        for(auto iuser : users)
        {
            if(iuser->getID() == iuserID)
                return iuser;
        }
    }
    return NULL;
}

// Signup to add new non-existant user to users
void System::signUpUser(string iuserName, string ipassword)
{
    long long int iuserID = getuserIDbyname(iuserName);
    if(iuserID == -1)
        // Add user if it does not already exist
        users.push_back(new User(iuserName, ipassword));
    else
        // Print error if user already exists
        cout << "Access Denied" << endl;
}

// Login method, sets cursysuser
void System::signInUser(string iuserName, string ipassword)
{
    long long int iuserID = getuserIDbyname(iuserName);
    if(iuserID != -1)
    {
        // User exists
        // Get the user object
        User *iuser = getuserbyuserID(iuserID);
        // Check if the password is valid for given user
        if(ipassword == iuser->getpasswd())
            // If user exists and password matches make it currently logged-in system user
            cursysuser = iuser;
        else
            // If user exists but password does not match, print error
            cout << "Access Denied" << endl;
    }
    else
        // If user does not exist, print error
        cout << "Access Denied" << endl;
}

// Logout method, resets cursysuser
void System::signOutUser()
{
    cursysuser = NULL;
}

// Method to get user ID given a username
// Returns -1 if given username not found in current user list of application
long long int System::getuserIDbyname(string username)
{
    for(auto iuser : users)
    {
        if(iuser->getname() == username)
            return iuser->getID();
    }
    return -1;
}

// Method to add a followed user for currently logged-in system user
void System::userfollow(string followedname)
{
    // Get user object for currently logged-in system user
    User *curfollower = cursysuser;
    // Continue processing only if a valid user is logged-in (i.e. curfollower = cursysuser is not NULL)
    if(curfollower)
    {
        // Get user object for given user ID (obtained from input username)
        User *curfollowed = getuserbyuserID(getuserIDbyname(followedname));
        // Access control : Check user existance in current user list of application
        // Continue processing only if the user to be followed is valid (i.e. not NULL)
        if(curfollowed)
            // Add a follower-following relation between given users
            curfollower->followuser(curfollowed);
        else
            // User to be followed does not exist in current user list of application
            // Print invalid input error
            cout << "Invalid Input" << endl;
    }
    else
        // No currently logged-in system user
        // Print access denied error
        cout << "Access Denied" << endl;
}

// Method to remove followed user for currently logged-in system user
void System::userunfollow(string unfollowedname)
{
    // Get user object for currently logged-in system user
    User *curfollower = cursysuser;
    // Continue processing only if a valid user is logged-in (i.e. curfollower = cursysuser is not NULL)
    if(curfollower)
    {
        // Get user object for given user ID (obtained from input username)
        User *curunfollowed = getuserbyuserID(getuserIDbyname(unfollowedname));
        // Access control : Check user existance in current user list of application
        // Continue processing only if the user to be unfollowed is valid (i.e. not NULL)
        if(curunfollowed)
        {
            // Remove a follower-following relation between given users
            curfollower->unfollowuser(curunfollowed);
        }
        else
            // User to be unfollowed does not exist in current user list of application
            // Print invalid input error as such user cannot be in any "following" list of any user
            cout << "Invalid Input" << endl;
    }
    else
        // No currently logged-in system user
        // Print access denied error
        cout << "Access Denied" << endl;
}

// Add post for currently logged-in system user
void System::addpost(long long int year, string content)
{
    // Get user object for currently logged-in system user
    User *curuser = cursysuser;
    // Continue processing only if a valid user is logged-in (i.e. curuser = cursysuser is not NULL)
    if(curuser)
    {
        // Check if year is invalid (negative number)
        if(year <= 0)
            // If so print invalid input error
            cout << "Invalid Input" << endl;
        else
        {
            // If year is valid, invoke createpost method for given user
            Post *newpost = curuser->createpost(curuser->getID(), year, content);
            // Store pointer to newly created post
            posts.push_back(newpost);
        }
    }
    else
        // No currently logged in system user
        // Print access denied error
        cout << "Access Denied" << endl;
}

// Print user corresponding to input user ID
void System::printuser(long long int iuserID)
{
    for(auto iuser : users)
    {
        if(iuser->getID() == iuserID)
        {
            // Invoking overloaded output stream insertion operator for User
            cout << *iuser << endl;
            return;
        }
    }
    // Non existing user, print error
    cout << "Invalid Input" << endl;
    return;
}

// Print post corresponding to input post ID
void System::printpost(long long int ipostID)
{
    for(auto ipost : posts)
    {
        if(ipost->getID() == ipostID)
        {
            // Invoking overloaded output stream insertion operator for Post
            cout << *ipost << endl;
            return;
        }
    }
    // Non existing post, print error
    cout << "Invalid Input" << endl;
    return;
}

// Delete users created and allocated in System object
System::~System()
{
    // Delete all the users in the system
    for(auto curuser : users)
        delete curuser;
    // Delete pointers to users
    users.clear();
    // Delete pointers to posts
    posts.clear();
}

