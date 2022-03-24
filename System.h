#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <bits/stdc++.h>
#include "User.h"
#include "Post.h"

using namespace std;

class System
{
private:
    // Attributes
    // posts maintain all the posts in the system
    vector<Post *> posts;
    // users maintain all the users in the system
    vector<User *> users;
    string appname;
    // Currently logged in system user
    User* cursysuser;
    // Get user corresponding to input user ID
    User* getuserbyuserID(long long int iuserID);
public:
    // Constructor
    System(string iname);
    // Methods
    // Signup to add new non-existant user to users
    void signUpUser(string iuserName, string ipassword);
    // Login method, sets cursysuser
    void signInUser(string iuserName, string ipassword);
    // Logout method, resets cursysuser
    void signOutUser();
    // Get user ID corresponding to input user name
    long long int getuserIDbyname(string username);
    // Method to add followed user for current logged-in user
    void userfollow(string followedname);
    // Method to remove followed user for current logged-in user
    void userunfollow(string unfollowedname);
    // Method to add post for current logged-in user
    void addpost(long long int year, string content);
    // Print user corresponding to input user ID
    void printuser(long long int iuserID);
    // Print post corresponding to input post ID
    void printpost(long long int ipostID);
    // Destructor
    ~System();
};

#endif //__SYSTEM_H
