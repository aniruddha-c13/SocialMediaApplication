#ifndef __USER_H
#define __USER_H

#include <bits/stdc++.h>
#include "Post.h"

using namespace std;

class User
{
private:
    // Static id for User objects
    static long long int userID;
    // Attributes
    // User id
    long long int id;
    // User name
    string name;
    // User password
    string passwd;
    // Posts of this user
    vector<Post *> myposts;
    // Users followed by this user
    vector<User *> followingusers;
public:
    // Constructor
    User(string iname, string ipassword);
    // Methods
    // Create post for this user
    Post* createpost(long long int iuserid, long long int iyear, string icontent);
    // Add user in followed users list for this user
    void followuser(User *iuser);
    // Remove user from followed users list for this user
    void unfollowuser(User *iuser);
    // Get attribute methods
    long long int getID();
    string getname();
    string getpasswd();
    // Friend function to overload output stream insertion operator
    friend ostream& operator<< (ostream& os, const User& user);
    // Destructor
    ~User();
};

// Function to overload output stream insertion operator
ostream& operator<< (ostream& os, const User& user);

#endif //__USER_H
